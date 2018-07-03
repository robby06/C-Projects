/*
	Written by Robby Sanchez
	Assignment 6: Using Graphs
*/
// FILE: UnweightedShortestPath.cpp
#include <iostream>
#include<cstring>
#include "graph.h"
using namespace std;

int main() {
	graph Map;
	int first, second;
	char column1;
	char column2;
#ifdef TRAFFIC
	cout << "TRAFFIC RUNNING..." << endl;
#endif
	while (true) {

#ifdef TRAFFIC
		cout << "Enter Q to quit\n";
		cout << "From intersection  <enter column from A to D>: ";
		cin >> column1;
		if (column1 == 'Q') {
			cout << "Illegal entry\n";
			break;
		}

		if (!(column1 == 'A' || column1 == 'B' || column1 == 'C'
				|| column1 == 'D')) {
			cout << "Illegal entry\n";
			continue;
		}
		cout << "<enter row from 1 to 4>: ";
		cin >> first;
		--first;
		if (first > 4 || first < -1) {
			cout << "Illegal entry\n";
			continue;

		}
		switch (column1) {
		case 'B':
			first = 4 + first;
			break;
		case 'C':
			first = 8 + first;
			break;
		case 'D':
			first = 12 + first;
			break;
		default:
			break;
		}
#endif
#ifdef BOOK_SAMPLE // for textbook sample
		cout << "Enter 0 to quit\n";
		cout << "From Vertex (enter number from 1 to " << Map.size() << "): ";
		cin >> first;
		--first; // set actual index
#endif

#ifdef AIRLINE_SAMPLE // for airline sample
		cout << "Enter -1 to quit\n";
		cout << "From city (enter number from 0 to " << Map.size() - 1 << "): ";
		cin >> first;
#endif
		if (first >= Map.size() || first < -1) {
			cout << "Illegal entry\n";
			continue;
		}
		if (first == -1)
			break;
		cout << "From " << Map.Vertex_Names[first]
				<< " to intersection  <enter column from A to D>: ";
#ifdef BOOK_SAMPLE // for textbook sample
		cout << " To Vertex? (from 1 to " << Map.size() << "): ";
		cin >> second;
		--second; // set actual index
#endif
#ifdef AIRLINE_SAMPLE // for airline sample
		cout << " to city? (from 0 to " << Map.size() - 1 << "): ";
		cin >> second;
#endif
#ifdef TRAFFIC
		cin >> column2;

		if (!(column2 == 'A' || column2 == 'B' || column2 == 'C'
				|| column2 == 'D')) {
			cout << "Illegal entry\n";
			continue;
		}
		cout << "<enter row from 1 to 4>: ";
		cin >> second;
		second--;

		switch (column2) {
		case 'B':
			second = 4 + second;
			break;
		case 'C':
			second = 8 + second;
			break;
		case 'D':
			second = 12 + second;
			break;
		default:
			break;
		}

#endif

		if (second >= Map.size() || second < 0) {
			cout << "Illegal entry\n";
			continue;
		} else
			cout << Map.Vertex_Names[second] << endl; // display destination
		Map.compute_itinerary(first, second);
	} // end of while loop

	system("pause");
	return 0;
}
