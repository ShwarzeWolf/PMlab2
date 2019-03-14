#pragma once
#include <vector>
#include <fstream>
#include <iostream>

const int numberOfValues = 8;
const int numberOfSteps = 1000;
const double accuracy = 0.00000000001;

double findAverageValue (const std::vector<double> & values);

double findStandartDeviation (const std::vector<double> & values);

std::vector<double> findFinalVector (const std::vector<double> & values, const std::vector<std::vector<double>> & matrix);

std::vector<double> multiplyVectorOnMatrix (const std::vector<double> & a, const std::vector<std::vector<double>> & b);

void printVector (const std::vector<double> & a);