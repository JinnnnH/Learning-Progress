/*----------------------------------------------------------------------------------
		Charlie
------------------------------------------------------------------------------------
-situation: string
-balance: float
------------------------------------------------------------------------------------
+Charlie() : Bravo()
+Charlie(string, float, bool, float, int, string) : Bravo(bool, float, int, string)
+setSituation(string situ): void
+setBalance(float balan): void
+getSituation(): string
+getBalance(): float
-----------------------------------------------------------------------------------*/

#ifndef CHARLIE_H
#define CHARLIE_H
#include <iostream>
#include "Bravo.h"
#include <string>
using namespace std;

class Charlie : public Bravo{
private:
	string situation;
	float balance;

public:
	Charlie() : Bravo(){
		situation = "";
		balance = 0.0;
	}
	Charlie(string situ, float balan, bool tf, float sum, int num, string str) : Bravo(tf, sum, num, str) {
		situation = situ;
		balance = balan;
	}
	void setSituation(string situ) { situation = situ; }
	void setBalance(float balan) { balance = balan; }
	string getSituation() { return situation; }
	float getBalance() { return balance; }
};
#endif
