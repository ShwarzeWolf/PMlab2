#include <vector>
#include <fstream>
#include "Functions.h"

using namespace std;


double findAverageValue (const vector<double> & values) {
	double sum = 0.0;

	for (auto i = values.begin (); i != values.end (); ++i)
		sum += *i;

	return sum / numberOfValues;
}

double findStandartDeviation (const vector<double> & values) {
	double averageValue = findAverageValue (values);

	vector<double> M;
	//double dispersionSumSquare = 0.0;

	for (auto i = values.begin (); i != values.end (); ++i)
		M.push_back( pow(*i - averageValue, 2));

	return sqrt(findAverageValue (M));
}

vector<double> multiplyVectorOnMatrix (const vector<double> & a, const vector<vector<double>> & b) {

	vector<double> result;
	double sum = 0.0;

	for (int i = 0; i < numberOfValues; ++i) {

		for (int j = 0; j < numberOfValues; ++j)
			sum += a[j] * b[j][i];

		result.push_back (sum);
		sum = 0.0;
	};

	return result;
}

void printVector (const vector<double> & a) {
	for (auto i = a.begin (); i != a.end (); ++i)
		cout << *i << ' ';

	cout << endl;
}

vector<double> findFinalVector (const vector<double> & values, const vector<vector<double>> & matrix) {
	ofstream fout ("outputVector.txt");

	vector<double> previousStep = values;
	vector<double> currentStep = multiplyVectorOnMatrix (previousStep, matrix);

	fout << findStandartDeviation (previousStep) << '\n';

	for (int i = 0; i < numberOfSteps; ++i) {
		fout << findStandartDeviation (currentStep) << '\n';

		if (abs (findStandartDeviation (currentStep) - findStandartDeviation (previousStep)) <= accuracy)
			break;

		previousStep = currentStep;
		currentStep = multiplyVectorOnMatrix (previousStep, matrix);
	}

	fout.close ();

	return currentStep;
}