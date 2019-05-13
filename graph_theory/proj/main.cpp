#include "graph.h"

#include <iostream>
#include <cstdint>

using namespace std;

int main(void) {
	uint32_t numV, numE;
	cin >> numV >> numE;
	
	Graph myGraph(numV);
	
	while(numE--) {
		uint32_t vertex1, vertex2;
		
		cin >> vertex1 >> vertex2;
		
		Vertex &v1 = myGraph.getVertex(vertex1-1);
		Vertex &v2 = myGraph.getVertex(vertex2-1);
		
		v1.addNeighbour(vertex2-1);
		v2.addNeighbour(vertex1-1);
	}
	
	myGraph.countNumShips();
	cout << myGraph.getNumRecons() << " " << myGraph.getNumFrigates() << " ";
	cout << myGraph.getNumBombers() << " " << myGraph.getNumTrans() << "\n";
	cout << "0\n";
	
	return 0;
}