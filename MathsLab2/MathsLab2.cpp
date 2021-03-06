#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "Functions.h"

using namespace std;

int main(){

	vector<vector<double>> matrix;

	ifstream fin ("input.txt");

	vector<double> currentVector;
	double currentNumber;

	for (int i = 0; i < numberOfValues; ++i) {
		for (int j = 0; j < numberOfValues; ++j) {
			fin >> currentNumber;
			currentVector.push_back (currentNumber);
		}

		matrix.push_back (currentVector);
		currentVector.clear ();
	};
	
	fin.close ();

	vector<double> initialStateVector1 = { 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.2, 0.2 };
	vector<double> initialStateVector2 = { 0.05, 0.05, 0.3, 0.1, 0.2, 0.1, 0.05, 0.15 };

	cout << "Vector 1: ";
	vector<double> finalVector = findFinalVector (initialStateVector1, matrix);
	printVector (finalVector);

	cout << "Vector 2: ";
	finalVector = findFinalVector (initialStateVector2, matrix);
	printVector (finalVector);


	system ("pause");
    return 0;
}

