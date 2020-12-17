/*
Drew Goldman
dag5wd
9/29/2020
inlab4.cpp
*/

#include <stdio.h>
#include <string>
#include <climits>
#include <cfloat>
#include <iostream>
using namespace std;

void tableDump(string (*arr)[5], string (*arr1)[4]);

int main(){
	// Replace the empty strings below with
	// the values you found while experimenting.
	string nonPointers[6][5] = {
		{"int", "4", "2,147,483,647", "0x00000000", "0x00000001"},
		{"unsigned int", to_string(sizeof(unsigned int)), "4,294,967,295", "0x00000000", "0x00000001"},
		{"float", to_string(sizeof(float)), "2^128", "0x00000000", "0x3F800000"},
		{"double", to_string(sizeof(double)), "2^1024", "0x0000000000000000", "0x3FF0000000000000"},
		{"char", to_string(sizeof(char)), to_string(CHAR_MAX), "0x30", "0x31"},
		{"bool", to_string(sizeof(bool)), "1", "0x00", "0x01"},
	};

	string pointers[3][4] = {
		{"int*", to_string(sizeof(int*)), "0xFFFFFFFFFFFFFFFF", "0x0000000000000000"},
		{"char*", to_string(sizeof(char*)), "0xFFFFFFFFFFFFFFFF", "0x0000000000000000"},
		{"double*", to_string(sizeof(double*)), "0xFFFFFFFFFFFFFFFF", "0x0000000000000000"},
	};

	tableDump(nonPointers, pointers);
	return 0;
}

void tableDump(string (*arr)[5], string (*arr1)[4]){
	for(int i = 0; i < 6; i++){
		printf("Size of %s: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
		printf("Max value of %s: %s\n", arr[i][0].c_str(), arr[i][2].c_str());
		printf("Zero of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][3].c_str());
		printf("One of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][4].c_str());
	}

	printf("-----------------------------------------------------------------------------\n");

	for(int i = 0; i < 3; i++){
		printf("Size of %s: %s\n", arr1[i][0].c_str(), arr1[i][1].c_str());
		printf("Max value of %s: %s\n", arr1[i][0].c_str(), arr1[i][2].c_str());
		printf("NULL of type %s is stored as: %s\n", arr1[i][0].c_str(), arr1[i][3].c_str());
	}
}

