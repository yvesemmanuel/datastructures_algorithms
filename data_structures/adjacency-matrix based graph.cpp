# include <iostream>
# include <queue>
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

class Graphm {
private:
	int numVertex, numEdge;
	int **matrix;
	int *mark;
public:
	Graphm(int numVert) { Init(numVert); }
	~Graphm() {
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
		if (wt > 0) {
			if (matrix[v1][v2] == 0) numEdge++;
			matrix[v1][v2] = wt;
		}
		else cout << "Illegal weight value." << endl;
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
};


int main() {
	Graphm myGraph(10);
	
	cout << "Let's add some vertices to this graph..." << endl; 
	myGraph.setEdge(0, 4, 1);
	myGraph.setEdge(0, 2, 5);
	myGraph.setEdge(2, 3, 7);
	myGraph.setEdge(2, 1, 4);
	myGraph.setEdge(2, 5, 2);
	myGraph.setEdge(1, 5, 6);
	myGraph.setEdge(3, 5, 8);
	myGraph.setEdge(4, 5, 2);
	myGraph.setEdge(9, 10, -3);
	
	cout << endl;
	cout << "DFS traverse" << endl;
	myGraph.DFS(0);
	
	cout << endl;
	cout << endl;
	
	cout << "BFS traverse" << endl;
	myGraph.BFS(0);

	return 0;
}
