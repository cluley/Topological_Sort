#pragma once

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Graph {
public:
	Graph(ifstream& idxs);
	~Graph();
	void top_sort(int start);
private:
	int vrtcs = 0;
	bool* used = nullptr;
	int** mtx = nullptr;
	list<int> order;
	template <typename T>
	void deleter(T array);
	void dfs(int v);
};