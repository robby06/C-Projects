#ifndef DOCUMENT_H // multiple inclusion guard
#define DOCUMENT_H

#include<string>
#include <iostream>
#include <iomanip> //  // Provide setw() and setprecision() functions
using namespace std;
enum priority{LOW,HIGH};

class Document
{
private:
	int Page_Count;
	string Title;
	priority p;
public:
	// Constructor:
		Document(int count,string pageTitle, priority prior ) :Page_Count(count), Title(pageTitle), p(prior){}

		// Default unary predicate (less: max Heap):
		bool operator<(const Document& d2) const{
			//When priority of document is equal then document of low page count 
			//will be remove first
			if (p == d2.p){
				if (Page_Count > d2.Page_Count){
					return true;
				}
			}
			else if (p < d2.p){
					return true;
				}
			
			return false;
		}
		// Unary predicate (greater: min Heap):
		bool operator>(const Document& d2) const{
			if (p == d2.p){
				if (Page_Count < d2.Page_Count){
					return true;
				}
			}else if (p > d2.p){
				return true;
			}
			
			return false;

		}

		friend ostream & operator<<(ostream & os, Document & D){
			os << setw(18) << right << D.Title << " " << setw(10) << right << D.Page_Count << " ";
			if (D.p == HIGH){
				cout << setw(30) << "High Priority" << endl;
			}
			else{
				cout << setw(30) << "Low Priority" << endl;
			}
			
			return os;

		}
};

#endif DOCUMENT_H