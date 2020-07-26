/*-----------------------------------------------------------
		Alpha
-------------------------------------------------------------
-number: int
-sentence: string
-------------------------------------------------------------
+Alpha()
+Alpha(int, string)
+setNumber(num: int): void
+setSentence(str: string): void
+getNumber(): int
+getSentence(): string
-----------------------------------------------------------*/

#ifndef ALPHA_H
#define ALPHA_H
#include <iostream>
#include <string>
using namespace std;

class Alpha {
private:
	int number;
	string sentence;

public:
	Alpha() {
		number = 0;
		sentence = "";
	}
	Alpha(int num, string str) {
		number = num;
		sentence = str;
	}
	void setNumber(int num) { number = num; }
	void setSentence(string str) { sentence = str; }
	int getNumber() { return number; }
	string getSentence() { return sentence; }
};
#endif
