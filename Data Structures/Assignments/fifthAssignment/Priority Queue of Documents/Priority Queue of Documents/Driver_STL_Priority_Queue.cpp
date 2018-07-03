/*
	Written by Robby Sanchez
	Exercise 5: Priority Queue of Documents (Extra Credit Assignment)
*/
#include <queue> // to use STL priority queue
#include "Document.h"
#include<string>
#include <functional> // Provide greater...

//#define MINHEAP // to sort in Ascending order (min Heap)

void Document_pq();
int main()
{
	Document_pq();
	cout << "\n\n\n";
	system("pause");
	return 0;
}


void Document_pq()
{
#ifndef MINHEAP
	priority_queue<Document> pq; // default descending order (max Heap)
#else
	priority_queue<Document, vector<Document>, greater<Document> > pq; // min Heap
#endif
	Document documents[] = { Document(400, "Love Harder", HIGH), Document(110, "Harry And Potter ", HIGH),
		Document(100, "25th Hours", HIGH), 
		Document(700, "Terminator", LOW) };

	cout << "USING Document:\n" <<
		"Emptying the priority queue:\n";

	for (int i = 0; i < sizeof(documents) / sizeof(Document); ++i){
		pq.push(documents[i]);
	}

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}

