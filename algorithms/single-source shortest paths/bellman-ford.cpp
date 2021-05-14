# include <iostream>
# include <queue>
# define INFINITY 2147483647
# define UNVISITED 0
# define VISITED 1
using namespace std;

class Edge {
	int vert, wt;
public:
	Edge() { vert = -1; wt = -1; }
	Edge(int v, int w) { vert = v; wt = w; }
	int vertex() { return vert; }
	int weight() { return wt; }
};

class Graph {
private:
	int numVertex, numEdge;
	int **matrix;
	int *mark;
public:
	Graph(int numVert) { Init(numVert); }
	~Graph() {
		delete [] mark;
		for (int i = 0; i < numVertex; i++)
			delete [] matrix[i];
		delete [] matrix;
	}
	
	void Init(int n) {
		int i;
		numVertex = n;
		numEdge = 0;
		mark = new int[n];
		
		for (i = 0; i < numVertex; i++)
			mark[i] = UNVISITED;
		matrix = (int**) new int*[numVertex];
		
		for (i = 0; i < numVertex; i++)
			matrix[i] = new int[numVertex];
		
		for (i = 0; i < numVertex; i++)
			for (int j = 0; j < numVertex; j++)
				matrix[i][j] = 0;
	}
	
	int n() { return numVertex; }
	int e() { return numEdge; }

	int first(int v) {
		for (int i = 0; i < numVertex; i++)
			if (matrix[v][i] != 0) return i;
		return numVertex;
	}

	int next(int v, int w) {
		for(int i = w + 1; i < numVertex; i++)
			if (matrix[v][i] != 0)
				return i;
		return numVertex;
	}
	
	void setEdge(int v1, int v2, int wt) {
		if (matrix[v1][v2] == 0) numEdge++;
		matrix[v1][v2] = wt;
		
	}

	void delEdge(int v1, int v2) {
		if (matrix[v1][v2] != 0) numEdge--;
		matrix[v1][v2] = 0;
	}

	bool isEdge(int i, int j) { return matrix[i][j] != 0; }
	int weight(int v1, int v2) { return matrix[v1][v2]; }
	int getMark(int v) { return mark[v]; }
	void setMark(int v, int val) { mark[v] = val; }
	
	void graphTraverse() {
		for (int v = 0; v < n(); v++)
			setMark(v, UNVISITED);
	}	
		
	void DFS(int v) {
		graphTraverse();
		DFShelp(v);
	}
	
	void DFShelp(int v) {
		cout << v << " ";
		setMark(v, VISITED);
		
		for (int w = first(v); w < n(); w = next(v, w))
			if (getMark(w) == UNVISITED)
				DFShelp(w);	
	}
	
	void BFS(int start) {
		graphTraverse();
		BFShelp(start);
	}
	
	void BFShelp(int start) {
		int v, w;
		queue<int> Q;
		
		Q.push(start);
		setMark(start, VISITED);
		while (Q.size() != 0) {
			v = Q.front();
			Q.pop();
			cout << v << " ";
			for (int w = first(v); w < n(); w = next(v, w))
				if (getMark(w) == UNVISITED) {
					setMark(w, VISITED);
					Q.push(w);
				}
		}
	}
	
	void topsort() {
		int Count[n()];
		queue<int> Q;
		int v, w;
		for (v = 0; v < n(); v++) Count[v] = 0;
		
		for (v = 0; v < n(); v++)
			for (w = first(v); w < n(); w = next(v,w))
				Count[w]++;
		
		for (v = 0; v < n(); v++)
			if (Count[v] == 0)
				Q.push(v);
				
		while (Q.size() != 0) {
			v = Q.front();
			Q.pop();
			cout << v << " ";
			for (w = first(v); w < n(); w = next(v,w)) {
				Count[w]--;
				if (Count[w] == 0)
					Q.push(w);
			}
		}
		cout << endl;
	}
	
	void bellmanford(int *D, int source) {
		int i, j, k;
		
		for (int i = 0; i < n(); i++)
			D[i] = INFINITY;
		
		D[source] = 0;
		for (k = 0; k < (n() - 1); k++) {
			for (i = 0; i < n(); i++) {
				for (j = first(i); j < n(); j = next(i, j)) {
					if (D[j] > (D[i] + weight(i, j)))
						D[j] = D[i] + weight(i, j);
				}
			}
		}
		
		int negativeCycles = 0;
		for (i = 0; i < n(); i++) {
			for (j = first(i); j < n(); j = next(i, j)) {
				if (D[j] > (D[i] + weight(i, j)))
					negativeCycles++;
			}
		}
		
		if (negativeCycles) cout << negativeCycles << "found" << endl;	
	}

};


int main() {
	Graph myGraph(5);
	int distances[5];
	
	cout << "Let's add some vertices to this graph..." << endl; 
	myGraph.setEdge(0, 1, -1);
	myGraph.setEdge(0, 2, 4);
	myGraph.setEdge(1, 2, 3);
	myGraph.setEdge(1, 3, 2);
	myGraph.setEdge(1, 4, 2);
	myGraph.setEdge(3, 1, 1);
	myGraph.setEdge(4, 3, -3);
	myGraph.setEdge(3, 2, -5);
	
	cout << "Now let's get the shortest path from all vertices to 0" << endl;
	myGraph.bellmanford(distances, 0);
	
	for (int distance = 0; distance < 5; distance++)
		cout << distances[distance] << " ";


	return 0;
}
