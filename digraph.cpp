#include "digraph.h"

Graph::Graph(ifstream& idxs) {
	idxs >> vrtcs;
	used = new bool[vrtcs]();

	mtx = new int* [vrtcs]();

	for (int i = 0; i < vrtcs; i++) {
		mtx[i] = new int[vrtcs]();
	}

	for (int i = 0; i < vrtcs; ++i) {
		for (int j = 0; j < vrtcs; ++j) {
			idxs >> mtx[i][j];
		}
	}
}

template <typename T>
void Graph::deleter(T array) {
	delete[] array;
	array = nullptr;
}

Graph::~Graph() {
	for (int i = 0; i < vrtcs; ++i) {
		delete[] mtx[i];
	}

	deleter(mtx);
	deleter(used);
}

void Graph::dfs(int v) {
	if (used[v]) {
		return;
	}
	else {
		used[v] = true;

		for (int i = 0; i < vrtcs; ++i) {
			if (mtx[v][i] && !used[i]) {
				dfs(i);
			}
		}

		order.push_front(v + 1);
	}
}

void Graph::top_sort(int start) {
	cout << "Топологический порядок вершин: ";

	dfs(start - 1);

	for (int i = 0; i < vrtcs; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}

	for (int n : order) {
		cout << n << ' ';
	}
}