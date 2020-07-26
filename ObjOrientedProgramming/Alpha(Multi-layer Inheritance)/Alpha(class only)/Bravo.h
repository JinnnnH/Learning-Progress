/*-----------------------------------------------------------
		Bravo
-------------------------------------------------------------
-status: bool
-total: float
-------------------------------------------------------------
+Bravo() : Alpha()
+Bravo(bool, float, int, string) : Alpha(int, string) 
+setStatus(tf: bool): void
+setTotal(sum: float): void
+getStatus(): int
+getTotal(): float
-----------------------------------------------------------*/

#ifndef BRAVO_H
#define BRAVO_H
#include <iostream>
#include "Alpha.h"
#include <string>
using namespace std;

class Bravo : public Alpha {
private:
	bool status;
	float total;

public:
	Bravo() : Alpha(){
		status = false;
		total = 0.0;
	}
	Bravo(bool tf, float sum, int num, string str) : Alpha(num, str) {
		status = tf;
		total = sum;
	}
	void setStatus(bool tf) { status = tf; }
	void setTotal(float sum) { total = sum; }
	int getStatus() { return status; }
	float getTotal() { return total; }
};
#endif
