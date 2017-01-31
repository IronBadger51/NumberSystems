// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	vector<int> solution;
	vector<int> sol2;
	int base1;
	int base2;
	int rem = 0;
	int sum = 0;
	int count = 0;
	int decCount = 0;
	bool negative = false;
	bool decimal = false;
	std::string inpt;
	cout << "Input the base of the input: ";
	cin >> base1;
	cout << endl;
	cout << "Enter number to calculate(integers only right now): ";
	cin >> inpt;
	cout << endl;
	char ch[1024];
	int num[1024];
	int dec[1024];
	
	strncpy_s(ch, inpt.c_str(), sizeof(ch));

	//////////////////////////////////////
	if (ch[0] == '-') {
		negative = true;
		for (int i = 0; i < strlen(ch); i++) {
			ch[i] = ch[i + 1];
		}
	}
	for (int i = 0; i < strlen(ch); i++) {
		if (ch[i] == '.') {
			//set up for decimal conversion
			decimal = true;
			i++;
			int j = 0;
			while (i < strlen(ch)) {
				dec[j] = ch[i]-48;
				cout << dec[j] << endl;
				decCount++;
				j++;
				i++;
			}
			break;
		}
		num[i] = (int)ch[i] - 48;
		count++;
		//cout << num[i] << endl;
	}
	for (int i = 0; i < count; i++) {//strlen(ch) for count
		if (abs(num[i]) >= base1) {
			cout << "invalid input: out of bounds of base: " <<num[i]<< endl;
			system("pause");
			return 0;
		}
		num[i] = num[i] * pow(base1, (count - (i + 1)));
		cout << num[i] << endl;
		sum += num[i];
		cout << sum << endl;
	}

	/////////////////////////////conversion/////////
	cout << "enter the base to calculate to: ";
	cin >> base2;
	cout << endl;
	count = 0;
	while (sum>0){
		rem = sum % base2;
		solution.push_back(rem);
		//cout << "mod: " << rem << endl; //number added

		sum = (sum / base2);
		//cout << sum << endl;/where the sum is currently
		count++;
	}
	/////////////////decimal//////////////////
	
	for (int i = 0; i < decCount; i++) {
		if (abs(dec[i]) >= base1) {
			cout << "invalid input: out of bounds of base: " << dec[i] << endl;
			system("pause");
			break;
		}
		///////////////////////////HELP HERE???//////////////////////////
		dec[i] = dec[i] * pow(base1, -(i));
		cout << dec[i] << endl;
		sum += dec[i];
		cout << sum << endl;
	}

	cout << endl;
	decCount = 0;
	while (sum>0) {
		rem = sum % base2;
		sol2.push_back(rem);
		cout << "dec mod: " << rem << endl;

		sum = (sum / base2);
		cout << sum << endl;
		decCount++;
	}




	////////////SOLUTION////////////////////
	cout << "answer: "<< endl;

	if (negative == true) {cout << "-";}

	for (int i = 0; i < count; i++) {
		cout << solution.back()<< " ";
		solution.pop_back();
	}
	if (decimal == true) { cout << ". "; }
	for (int i = 0; i < decCount; i++) {
		cout << sol2.back() << " ";
		sol2.pop_back();
	}
	cout << endl;
	system("pause");
    return 0;
}

