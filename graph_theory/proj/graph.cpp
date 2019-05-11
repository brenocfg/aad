#include "graph.h"

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

uint32_t Graph::getTypeOfComponent(vector<uint32_t> &component) {
	uint32_t deg1_count = 0;
	uint32_t deg2_count = 0;
	uint32_t total_deg = 0;
	
	for (const auto &id : component) {
		Vertex &v = getVertex(id);
		
		total_deg += v.getDegree();
		if (v.getDegree() == 1) {
			deg1_count++;
		}
		if (v.getDegree() == 2) {
			deg2_count++;
		}
	}
	
	uint32_t comp_size = component.size();
	
	if ((total_deg/2) == (comp_size - 1)) {
		if (deg1_count == 2) {
			return 0;
		}
		else {
			return 1;
		}
	}
	
	else if (((total_deg/2) == comp_size) && ((total_deg/2) == deg2_count)) {
		return 3;
	}
	
	return 2;
}

void Graph::countNumShips() {
	unordered_set<uint32_t> to_visit;
	unordered_set<uint32_t> visited;
	
	for (int i = 0; i < _num_v; i++) {
		to_visit.insert(i);
	}
	
	while(!to_visit.empty()) {
		vector<uint32_t> component;
		stack<uint32_t> visStack;
		
		auto it = to_visit.begin();
		visStack.push(*it);
		
		while(!visStack.empty()) {
			uint32_t v_id = visStack.top();
			visStack.pop();
			if (visited.count(v_id) == 0) {
				visited.insert(v_id);
				to_visit.erase(v_id);
				component.push_back(v_id);
				Vertex &v = getVertex(v_id);
				for (auto const &neigh : v.getNeighbours()) {
					visStack.push(neigh);
				}
			}
		}

		uint32_t t = getTypeOfComponent(component);
		switch(t) {
			case 0: {
				_num_recon += 1;
				break;
			}
			case 1: {
				_num_frig += 1;
				break;
			}
			case 2: {
				_num_bomb += 1;
				break;
			}
			case 3: {
				_num_trans +=1;
				break;
			}
		}
	}
}

uint16_t Graph::getNumRecons() const {
	return _num_recon;
}

uint16_t Graph::getNumFrigates() const {
	return _num_frig;
}

uint16_t Graph::getNumBombers() const {
	return _num_bomb;
}
uint16_t Graph::getNumTrans() const {
	return _num_trans;
}

Vertex::Vertex(uint32_t id) : _id(id) {
	_degree = 0;
}

uint32_t Vertex::getDegree() const {
	return _degree;
}

const vector<uint32_t> &Vertex::getNeighbours() const {
	return _neighs;
}

void Vertex::addNeighbour(uint32_t v) {
	_neighs.push_back(v);
	_degree += 1;
}

Graph::Graph(uint32_t num_v) : _num_v(num_v) {
	_verts.reserve(num_v);
	for (int i = 0; i < num_v; i++) {
		_verts.push_back(Vertex(i));
	}
	
	_num_recon = 0;
	_num_frig = 0;
	_num_bomb = 0;
	_num_trans = 0;
}

uint32_t Graph::getNumVertices() const {
	return _num_v;
}

Vertex &Graph::getVertex(uint32_t id) {
	return _verts[id];
}