#include "digraph.h"

int main(int argc, char** argv) {
	ifstream idxs("input2.txt");

	if (!idxs.is_open()) {
		cout << "Файл input поврежден." << endl;
		return 1;
	}

	Graph graph(idxs);

	graph.top_sort(6);

	return 0;
}