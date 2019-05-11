#pragma once

#include <cstdint>
#include <vector>

using namespace std;

class Vertex {
public:
	/*constructor*/
	Vertex(uint32_t id);
	
	/*returns the degree of the vertices (number of adjacent vertices)*/
	uint32_t getDegree() const;
	
	/*returns reference to the vertex's list of neighbours*/
	const vector<uint32_t> &getNeighbours() const;
	
	/*adds an edge between this vertex and another vertex*/
	void addNeighbour(uint32_t v);
	
private:
	uint32_t _degree;
	uint32_t _id;
	vector<uint32_t> _neighs;
};

class Graph {
public:
	/*constructor, takes number of vertices in the graph as input*/
	Graph(uint32_t num_v);
	
	/*returns number of vertices in the graph*/
	uint32_t getNumVertices() const;
	
	/*returns number of each type of ship in the graph*/
	uint16_t getNumRecons() const;
	uint16_t getNumFrigates() const;
	uint16_t getNumBombers() const;
	uint16_t getNumTrans() const;
	
	/*returns reference to specific vertex*/
	Vertex &getVertex(uint32_t id);
	
	/*counts number of each ship type in the graph*/
	void countNumShips();
	
	uint32_t	 getTypeOfComponent(vector<uint32_t> &component);

private:
	uint32_t _num_v;
	vector<Vertex> _verts;
	
	uint16_t _num_recon;
	uint16_t _num_frig;
	uint16_t _num_bomb;
	uint16_t _num_trans;
};