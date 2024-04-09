#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Flower
{
public:
	Flower();
	~Flower();
	void gatherinput(vector<vector<double>>& input);
	void gatherdata(vector<vector<string>>&datasetinfo, double&numberoftype_Set, double& numberoftype_Ver, double& numberoftype_Vir,int &numberofrecords);
	void samplemean(vector<vector<string>>& datasetinfo, string type, double numberoftype, int records,vector<vector<double>>& input);
	void samplevariance(vector<vector<string>>& datasetinfo, string type, double numberoftype, int records, vector<vector<double>>& input);
	void standarddeviation(vector<vector<double>>& input);
	void densityfunction(vector<vector<double>>& input);
	void likeihood(double arr[], double arr2[], double arr3[], double numberoftype_Set, double numberoftype_Ver, double numberoftype_Vir, double records);
	void confidence(double arr[], double arr2[], double arr3[]);
private:
	int COL = 5;
	const long int PI = 3.14159265359;
};