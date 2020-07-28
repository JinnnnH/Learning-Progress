/*-----------------------------------------------------------
		Check
-------------------------------------------------------------
-Payee: string
-Date: string
-Amount: double
-Memo: string
-CheckNumber: int
-HolderName: string
-HolderAddress: string
-HolderCity: string
-BankName: string
-------------------------------------------------------------
+Check()
+Check(string, string, double, string, int)
+setPayee(payee: string): void
+setDate(date: string): void
+setAmount(amt: double): void
+setMemo(memo: string): void
+setCheckNumber(check: int): void
+getPayee(): string
+getDate(): string
+getAmount(): double
+getMemo(): string
+getCheckNumber(): int
+getHolderName(): string
+getHolderAddress(): string
+getHolderCity(): string
+getBankName(): string
+ConvertAmount(amt: double): string
+PrintCheck(): void
-----------------------------------------------------------*/

#ifndef CHECK_H
#define CHECK_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Check {
private:
	string Payee;
	string Date;
	double Amount;
	string Memo;
	int CheckNumber;
	string HolderName;
	string HolderAddress;
	string HolderCity;
	string BankName;

public:
	//contructors
	Check() {
		Payee = "";
		Date = "";
		Amount = 0;
		Memo = "";
		CheckNumber = 0;
		HolderName = "Mark Dietrich";
		HolderAddress = "123 Any Street";
		HolderCity = "Oakland, CA 94607";
		BankName = "Bank of the West";
	}
	Check(string payee, string date, double amt, string memo, int check) {
		Payee = payee;
		Date = date;
		Amount = amt;
		Memo = memo;
		CheckNumber = check;
		HolderName = "Mark Dietrich";
		HolderAddress = "123 Any Street";
		HolderCity = "Oakland, CA 94607";
		BankName = "Bank of the West";
	}

	//accessors
	void setPayee(string payee)
		{Payee = payee;}
	void setDate(string date)
		{Date = date;}
	void setAmount(double amt)
		{Amount = amt;}
	void setMemo(string memo)
		{Memo = memo;}
	void setCheckNumber(int check)
		{CheckNumber = check;}

	//mutators
	string getPayee()
		{return Payee;}
	string getDate()
		{return Date;}
	double getAmount()
		{return Amount;}
	string getMemo()
		{return Memo;}
	int getCheckNumber()
		{return CheckNumber;}
	string getHolderName()
		{return HolderName;}
	string getHolderAddress()
		{return HolderAddress;}
	string getHolderCity()
		{return HolderCity;}
	string getBankName()
		{return BankName;}


	//this function will convert number into words
	string ConvertAmount(double amt){
		int num = amt * 100;																					//for later calculation
		string str;
		vector<string>Num{ "", "One ", "Two ", "Three ", "Four ", "Five ",
				"Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ",
				"Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
				"Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
		vector<string>Tens{ "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ",
				"Sixty ", "Seventy ", "Eighty ", "Ninety " };

		if (amt == 0) {
			return str = "Zero";
		}
		else {
			(amt / 1000 >= 1)? str = Num.at(amt/1000) + "thousand ": str = str;									//manipulating the thousands
			((num / 10000 )% 10 >= 1)? str += Num.at((num / 10000) % 10) + " hundred " : str = str;				//manipulating the hundreds
			((num / 1000 )% 10 >= 1) ? str += Tens.at((num / 1000) % 10) + Num.at(num/100 % 10): str = str;		//manipulating the tens and digits
			(num % 100) ? str += "and " + to_string((num%100)) + "/100 dollars": str = str;						//manipulating the decimals
		}

		for (int i = 1; i < str.length(); i++) {
			str.at(i) = tolower(str.at(i));
		}
		return str;
	}

	//print function
	void PrintCheck() {
		cout  << setfill('-') << setw(90) << ""<<endl;
		cout << left << setw(40) << setfill(' ')<< getHolderName() << right 
			 << setw(45) << "Check #" << getCheckNumber() << endl;

		cout << left << getHolderAddress() << endl;

		cout << getHolderCity() << right << setw(72) << "Date: " + getDate();

		cout << endl << endl;

		cout << setw(40) << left << "Pay to the order of: " + getPayee() << right 
			 << setw(42)<< fixed << setprecision(2) << "$"  << getAmount() << endl;
		cout << left << ConvertAmount(getAmount()) << endl;

		cout << endl << endl;

		cout << getBankName() << endl;

		cout << left <<setw(40)<<"Memo: " + getMemo();
		cout << right << setw(36) << right << "Signature: " << getHolderName() << endl;

		cout << setfill('-') << setw(90)<<"" << endl;

		cout << endl << endl;
	}

};

#endif