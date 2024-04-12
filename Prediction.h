#pragma once

/*
Israel Showell
Start Date: 3-29-2024
End Date: 4-9-2024
Project:
Predicting Iris Flowers using Vectors

Version: 1.1.0


Description:
This program exercises Machine Learning by taking in values for a new Iris flower.
It uses data from the famous iris dataset, and then processes the new input.
Afterwards, it will show how confidient it is in its prediction, and then add the new flower in as the
type it is most sure that it is.

This program uses Naïve Bayes and Statistical Modeling to make its predictions.

NOTE:
This is the a newer version of the first code I made. This one uses vectors to increase readability.
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

//This class is mostly used to clean up the other two files in the program
class Flower
{
public:
	Flower(); //Constructor

	~Flower();//Deconstructor

	//Gathers input from user
	void gatherinput(vector<vector<double>>& input, string userarr[]); 

	//Gathers and prepares data from CSV file
	void gatherdata(vector<vector<string>>&datasetinfo, double&numberoftype_Set, double& numberoftype_Ver, double& numberoftype_Vir,int &numberofrecords);

	//Finds the sample mean for each column, expect the type column
	void samplemean(vector<vector<string>>& datasetinfo, string type, double numberoftype, int records,vector<vector<double>>& input);

	//Finds the sample variance for each column, expect the type column
	void samplevariance(vector<vector<string>>& datasetinfo, string type, double numberoftype, int records, vector<vector<double>>& input);

	//Finds the standard deviation for each column, expect the type column
	void standarddeviation(vector<vector<double>>& input);

	//Calculates the density function for each type
	void densityfunction(vector<vector<double>>& input);

	//Finds the most likely flower type for the inputted flower
	void likeihood(double arr[], double arr2[], double arr3[], double numberoftype_Set, double numberoftype_Ver, double numberoftype_Vir, double records);

	//Calculates the confidence in its results
	void confidence(double arr[], double arr2[], double arr3[]);

	//Sends new flower to the CSV file
	void senddata(string userarr[], int &records);

private:

	//Default COL and PI values
	int COL = 5;
	const long int PI = 3.14159265359;
};