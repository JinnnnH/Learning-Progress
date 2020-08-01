/*-----------------------------------------------------------
		PublishedWork
-------------------------------------------------------------
-author: string
-yearPublished: int
-------------------------------------------------------------
+PublishedWork()
+PublishedWork(string, int)
+PrintPublished() void
+setAuthor(str: string): void
+setYearPublished(yy: int): void
+getAuthor(): string
+getYearPublished(): int
-----------------------------------------------------------*/

#ifndef PUBLISHEDWORK_H
#define PUBLISHEDWORK_H
#include <iostream>
#include <string>
using namespace std;

class PublishedWork {
private:
	string author;
	int yearPublished;

public:
	PublishedWork() {
		author = "";
		yearPublished = 0;
	}
	PublishedWork(string au, int yy){
		author = au;
		yearPublished = yy; 
	}
	void PrintPublished() {
		cout << "\t> Author of the app: " << author << endl;
		cout << "\t> year of publishment: " << yearPublished << endl;
	}
	void setAuthor(string au) {author = au;}
	void setYearPublished(int yy) { yearPublished = yy; }
	string getAuthor() { return author; }
	int getYearPublished() { return yearPublished; }
};
#endif
