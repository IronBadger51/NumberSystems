// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
// Need to add HEX support, just output, input complete!!!
//Almost done!
//break for base <=1 o
//add grand op loop
//print decimal in right order
//use more vectors

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
	char chOut[1024];
	char outHex = '0';
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
	double dec[1024];
	double decSum = 0;;
	
	strncpy_s(ch, inpt.c_str(), sizeof(ch));

	//////////////check for negative///////////////////
	if (ch[0] == '-') {
		negative = true;
		for (int i = 0; i < strlen(ch); i++) {
			ch[i] = ch[i + 1];
		}
	}
	//////////////////////////////////////////////////

	//////////////////Storage and convert to base 10///////////////////
	for (int i = 0; i < strlen(ch); i++) {//main loop
		if (ch[i] == '.') {//decimal sub loop
			decimal = true;
			i++;
			int j = 0;
			if (ch[i] >= 'A') {
				dec[j] = (int)ch[i] - 55;
				decCount++;
				continue;
			}
			while (i < strlen(ch)) {
				dec[j] = ch[i]-48;
				decCount++;
				j++;
				i++;
			}
			break;
		}
		/// normal loop
		if (ch[i] >= 'A') {
			num[i] = (int)ch[i] - 55;
			count++;
			continue;
		}
		num[i] = (int)ch[i] - 48;
		count++;
	}
	for (int i = 0; i < count; i++) {//strlen(ch) for count
		if (abs(num[i]) >= base1) {
			cout << "invalid input: out of bounds of base: " <<num[i]<< endl;
			system("pause");
			return 0;
		}
		num[i] = num[i] * pow(base1, (count - (i + 1)));
		sum += num[i];
	}
	/////////////////////////////CONVERSION/////////
	cout << "enter the base to calculate to: ";
	cin >> base2;
	cout << endl;
	count = 0;
	while (sum>0){
		rem = sum % base2;
		solution.push_back(rem);
		sum = (sum / base2);
		count++;
	}
	///////////////////////////////////////////////////



	/////////////////DECIMAL//////////////////	
	for (int i = 0; i < decCount; i++) {
		if (abs(dec[i]) >= base1) {
			cout << "invalid input: out of bounds of base: " << dec[i] << endl;
			system("pause");
			break;
		}
		dec[i] = (dec[i] * (1/pow(base1, i+1)));

		cout <<"decimal: "<< dec[i] << endl;
		decSum += dec[i];
		//cout << decSum << endl;
	}
	////////////CONVERSION/////////////////////
	cout << endl;
	decCount = 0;
	while (decSum>0) {
		rem = 0;
	decSum = decSum * base2;
	cout << "decSum*base2: " << decSum << endl;
		if (decSum >= 1) {
			rem = trunc(decSum);
			//cout << "dec mod: " << rem << endl;
			decSum = decSum - rem;
			//cout << "decSum - rem: " << decSum << endl;
		}
		//sol2.push_back(rem);

		if (rem >= 10)
			chOut[decCount] = (char)(rem + 55);
		else
			chOut[decCount] = char(rem + 48);



		//cout << decSum << endl;
		decCount++;
	}
	////////////////END DECIMAL/////////////////////////////



	//////////// PRINT SOLUTION////////////////////
	cout << "answer: "<< endl;

	if (negative == true) {cout << "-";}

	for (int i = 0; i < count; i++) {
		//cout << solution.back()<< " ";
		//solution.pop_back();
		rem = solution.back();
		if (rem >= 10)
			outHex = (char)(rem + 55);
		else
			outHex = char(rem + 48);
		cout << outHex;
		solution.pop_back();
	}
	if (decimal == true) { cout << ". "; }
	/*for (int i = 0; i < decCount; i++) {
		rem = sol2.back();
		if (rem >= 10)
			outHex = (char)(rem + 55);			
		else
			outHex = char(rem + 48);
		cout<<outHex;
		sol2.pop_back();
	}*/
	for (int i = 0; i < decCount; i++)
		cout << chOut[i];
	cout << endl;
	system("pause");
    return 0;
}

