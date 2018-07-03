// FILE: graph.h
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

// uncomment ONLY ONE of the following definitions:
//#define BOOK_SAMPLE // uncomment to run the book sample
//#define AIRLINE_SAMPLE // uncomment to run the airline sample
#define TRAFFIC
class graph {
private:
	// MEMBER DATA

#ifdef TRAFFIC
	static const int nbrVertices = 16;
#endif

#ifdef BOOK_SAMPLE
	static const int nbrVertices = 7; // for textbook sample
#endif

#ifdef AIRLINE_SAMPLE
	static const int nbrVertices = 13; // for airline sample
#endif
	vector<list<int>*> edges; // empty dynamic array of pointers to list of ints
	int count_vertices, count_edges;
	int source, destination;

	struct vertex {
		int vertex_index;
		bool known;
		int dist;
		int path;
	};

	// PRIVATE MEMBER METHODS
	void add_vertex(string label) {
		int new_vertex_number;
		new_vertex_number = count_vertices;
		count_vertices++;
		edges.push_back(new list<int>);
	}

	void add_edge(int source, int target) {
		count_edges++;
		edges[source]->push_back(target);
	}

public:
	string Vertex_Names[nbrVertices];

	// CONSTRUCTOR
	graph() {
		count_vertices = count_edges = 0;
		source = -1;
		destination = -1;

#ifdef BOOK_SAMPLE // for textbook sample
		cout << "BOOK SAMPLE RUNNING...\n";
		Vertex_Names[0] = "V1";
		Vertex_Names[1] = "V2";
		Vertex_Names[2] = "V3";
		Vertex_Names[3] = "V4";
		Vertex_Names[4] = "V5";
		Vertex_Names[5] = "V6";
		Vertex_Names[6] = "V7";

		add_vertex(Vertex_Names[0]); // V1
		add_vertex(Vertex_Names[1]);// V2
		add_vertex(Vertex_Names[2]);// V3
		add_vertex(Vertex_Names[3]);// V4
		add_vertex(Vertex_Names[4]);// V5
		add_vertex(Vertex_Names[5]);// V6
		add_vertex(Vertex_Names[6]);// V7

		add_edge(0, 1);
		add_edge(2, 0);
		add_edge(1, 4);
		add_edge(2, 5);
		add_edge(6, 5);
		add_edge(4, 6);
		add_edge(3, 2);
		add_edge(3, 4);
		add_edge(0, 3);
		add_edge(1, 3);
		add_edge(3, 5);
		add_edge(3, 6);
#endif
#ifdef TRAFFIC  
		Vertex_Names[0] = "A1";
		Vertex_Names[1] = "A2";
		Vertex_Names[2] = "A3";
		Vertex_Names[3] = "A4";
		Vertex_Names[4] = "B1";
		Vertex_Names[5] = "B2";
		Vertex_Names[6] = "B3";
		Vertex_Names[7] = "B4";
		Vertex_Names[8] = "C1";
		Vertex_Names[9] = "C2";
		Vertex_Names[10] = "C3";
		Vertex_Names[11] = "C4";
		Vertex_Names[12] = "D1";
		Vertex_Names[13] = "D2";
		Vertex_Names[14] = "D3";
		Vertex_Names[15] = "D4";

		for (int i = 0; i < 16; i++) {
			add_vertex(Vertex_Names[i]); // V1
		}

		add_edge(0, 1);
		add_edge(1, 5);
		add_edge(14, 13);
		add_edge(13, 10);
		add_edge(10, 6);
		add_edge(6, 3);
		add_edge(14, 10);
		add_edge(10, 11);
		add_edge(8, 9);
		add_edge(9, 5);
		add_edge(15, 14);
		add_edge(14, 13);
		add_edge(13, 9);
		add_edge(9, 5);
		add_edge(5, 1);
		add_edge(1, 2);
		add_edge(14, 13);
		add_edge(13, 9);
		add_edge(9, 10);
		add_edge(10, 11);
		add_edge(7, 8);
		add_edge(8, 9);
		add_edge(9, 1);
		add_edge(1, 2);
		add_edge(2, 3);
		add_edge(9, 10);
		add_edge(10, 11);
		add_edge(11, 7);
		add_edge(7, 6);
		add_edge(6, 5);

#endif
#ifdef AIRLINE_SAMPLE // for airline sample
		cout << "AIRLINE SAMPLE RUNNING...\n";
		Vertex_Names[0] = "Los Angeles";
		Vertex_Names[1] = "San Francisco";
		Vertex_Names[2] = "Denver";
		Vertex_Names[3] = "Dallas";
		Vertex_Names[4] = "Houston";
		Vertex_Names[5] = "Seattle";
		Vertex_Names[6] = "Chicago";
		Vertex_Names[7] = "Atlanta";
		Vertex_Names[8] = "Miami";
		Vertex_Names[9] = "New York";
		Vertex_Names[10] = "Boston";
		Vertex_Names[11] = "Detroit";
		Vertex_Names[12] = "Washington D.C.";

		add_vertex(Vertex_Names[0]); // Los Angeles
		add_vertex(Vertex_Names[1]);// San Francisco
		add_vertex(Vertex_Names[2]);// Denver
		add_vertex(Vertex_Names[3]);// Dallas
		add_vertex(Vertex_Names[4]);// Houston
		add_vertex(Vertex_Names[5]);// Seattle
		add_vertex(Vertex_Names[6]);// Chicago
		add_vertex(Vertex_Names[7]);// Atlanta
		add_vertex(Vertex_Names[8]);// Miami
		add_vertex(Vertex_Names[9]);// New York
		add_vertex(Vertex_Names[10]);// Boston
		add_vertex(Vertex_Names[11]);// Detroit
		add_vertex(Vertex_Names[12]);// Washington D.C.

		add_edge(0, 1);// Los Angeles(0) to San Francisco(1)
		add_edge(1, 0);// San Francisco(1) to Los Angeles(0)
		add_edge(2, 0);// Denver(2) to Los Angeles(0)
		add_edge(0, 2);// Los Angeles(0) to Denver(2)
		add_edge(1, 5);// San Francisco(1) to Seattle(5)
		add_edge(2, 5);// Denver(2) to Seattle(5)
		add_edge(10, 5);// Boston(10) to Seattle(5)
		add_edge(5, 10);// Seattle(5) to Boston(10)
		add_edge(3, 0);// Dallas(3) to Los Angeles(0)
		add_edge(0, 3);// Los Angeles(0) to Dallas(3)
		add_edge(8, 4);// Miami(8) to Houston(4)
		add_edge(8, 9);// Miami(8) to New York City(9)
		add_edge(9, 8);// New York City(9) to Miami(8)
		add_edge(7, 12);// Atlanta(7) to Washington, DC(12)
		add_edge(6, 7);// Chicago(6) to Atlanta(7)
		add_edge(1, 2);// San Francisco(1) to Denver(2)
		add_edge(11, 2);// Detroit(11) to Denver(2)
		add_edge(6, 9);// Chicago(6) to New York City(9)
		add_edge(2, 6);// Denver(2) to Chicago(6)
		add_edge(7, 2);// Atlanta(7) to Denver(2)
		add_edge(7, 3);// Atlanta(7) to Dallas(3)
		add_edge(3, 7);// Dallas(3) to Atlanta(7)
		add_edge(7, 4);// Atlanta(7) to Houston(4)
		add_edge(4, 7);// Houston(4) to Atlanta(7)
		add_edge(12, 8);// Washington, DC(12) to Miami(8)
		add_edge(10, 11);// Boston(10) to Detroit(11)
#endif
	} // end constructor

	// DESTRUCTOR
	~graph() {
		for (int i = 0; i < count_vertices; i++) {
			delete edges[i]; // remove lists from free store
		}
		edges.clear(); // vector not on free store
	}

	// CONSTANT MEMBER FUNCTIONS
	int size() {
		return count_vertices;
	}

	void compute_itinerary(int s, int target) {
		if (s == target) {
			cout << "Destination same as departure!\n";
			return;
		}
		int iterations = 0; // for statistics
		vertex V[nbrVertices]; // table
		for (int i = 0; i < count_vertices; i++) // initialize table
				{
			V[i].vertex_index = i;
			V[i].known = false;
			V[i].dist = -1;
			V[i].path = -1;
		}
		V[s].dist = 0; // source to itself

		// for each distance:
		for (int currDist = 0; currDist < count_vertices; currDist++) {
			for (int v = 0; v < count_vertices; v++) // for each vertex
					{
				//iterations++; // will show n * n...
				// if unknown and at currDist:
				if (!V[v].known && V[v].dist == currDist) {
					V[v].known = true;
					// for each adjacent vertex:
					for (list<int>::iterator itr = edges[v]->begin();
							itr != edges[v]->end(); itr++) {
						iterations++; // will show n...
						if (V[*itr].dist == -1) // distance not defined yet
								{
							V[*itr].dist = currDist + 1; // define distance
							V[*itr].path = v; // path from v
						}
					}
				}
			}
		}
		cout << "\nNumber of elements n: " << count_vertices
				<< "\nSize*size  (n*n) = " << count_vertices * count_vertices
				<< "\nTotal number of edges = " << count_edges;
		cout << "\nIterations = " << iterations << endl;

		// Display itinerary:
		if (V[target].path >= 0 && V[target].known == true) {
			string iti[nbrVertices];
			iti[0] = Vertex_Names[target];
			int t = target, stops = 1;
			for (; V[t].path >= 0; t = V[t].path, stops++)
				iti[stops] = Vertex_Names[V[t].path]; // reverse order
			cout << "The following itinerary is suggested:\n";
			while (stops--)
				cout << iti[stops] << " - ";
			cout << "\b\b\b   \n";
			cout << "Number of edges required: " << V[target].dist << endl
					<< endl;
		} else
			cout << "No itinerary was found to get to " << Vertex_Names[target]
					<< "!\n\n";
	}
};
// end class graph

