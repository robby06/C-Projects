/*
	Written by Robby Sanchez
	Exercise 5: Using Priority Queues 
*/
#include <queue> // to use STL priority queue
#include "Date.h"
#include<string>
#include <functional> // Provide greater...
#define MINHEAP // to sort in Ascending order (min Heap)
void do_String_pq();
void do_char_pq();
void do_number_pq();
void do_Date_pq();

int main()
{
	do_char_pq();
	cout << "\n\n\n";
	do_number_pq();
	cout << "\n\n\n";
	do_Date_pq();
	cout << "\n\n";
	do_String_pq();
	cout << "\n\n";
	system("pause");
	return 0;
}



void do_String_pq()
{
#ifndef MINHEAP
	priority_queue<string> pq; // default descending order (max Heap)
#else
	priority_queue<string, vector<string>, greater<string> > pq; // min Heap
#endif
	string strings[] = { "Welcome Back", "Apple", "Pleasure is all mine" };
	cout << "USING String:\n" <<
		"Emptying the priority queue:\n";

	for (int i = 0; i < sizeof(strings) / sizeof(string); ++i){
		pq.push(strings[i]);
	}

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}
}


void do_char_pq()
{
	// Create a priority queue pq to store single characters, 
	// and initialize the queue to be empty:
#ifndef MINHEAP
	priority_queue<char> pq; // default descending order (max Heap)
#else
	priority_queue<char, vector<char>, greater<char> > pq; // min Heap
#endif
	// in the order of a keyboard:
	char arr[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
		'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
		'z', 'x', 'c', 'v', 'b', 'n', 'm' };
	cout << "USING LETTERS:\n" <<
		"Inserting and showing the top value:\n";

	for (int i = 0; i < sizeof(arr); i++)
	{
		pq.push(arr[i]);
		cout << pq.top() << " "; // Print highest priority string
	}
	cout << "\n\nEmptying the priority queue:\n";

	while (!pq.empty())
	{
		cout << pq.top() << " "; // Print highest priority string
		pq.pop(); // Remove highest priority string
	}
}

void do_number_pq()
{
	// Create a priority queue pq to store integers,
	// and initialize the queue to be empty:
#ifndef MINHEAP
	priority_queue<int> pq; // default descending order (max Heap)
#else
	priority_queue<int, vector<int>, greater<int> > pq; // min Heap
#endif
	int arr[] = { 49, 24, 31, 17, 2, 7, 9, 98, 40, 16, 21 };
	cout << "USING NUMBERS:\n" <<
		"Emptying the priority queue:\n";

	for (int i = 0; i<sizeof(arr) / sizeof(int); i++)
		pq.push(arr[i]);

	while (!pq.empty())
	{
		cout << pq.top() << " "; // Print highest priority integer
		pq.pop(); // Remove highest priority integer
	}
}

void do_Date_pq()
{
	// Create a priority queue pq to store Dates,
	// provide predicate and initialize the queue to be empty:
#ifndef MINHEAP
	priority_queue<Date> pq; // default descending order (max Heap)
#else
	priority_queue<Date, vector<Date>, greater<Date> > pq; // min Heap
#endif
	Date d[] = { Date(4, 1, 2012), Date(3, 21, 2013), Date(6, 24, 2011),
		Date(7, 15, 2010), Date(12, 31, 2010), Date(12, 31, 2010),
		Date(1, 1, 2011) };
	cout << "USING DATES:\n" <<
		"Emptying the priority queue:\n";

	for (int i = 0; i < sizeof(d) / sizeof(Date); ++i)
		pq.push(d[i]);

	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}

