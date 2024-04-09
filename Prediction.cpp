

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <cmath>
#include <vector>
#include <fstream>
#include "Prediction.h"
using namespace std;


Flower::Flower() {
    //vector<double> newRow;
    //input.push_back(newRow);
	//Leaving this constructor empty
}

Flower::~Flower() {
	//Class deconstructor
}

void Flower::gatherinput(vector<vector<double>>& input) {
    vector<double> newRow;
    vector<double> newRow2;
    vector<double> newRow3;
    vector<double> newRow4;
    vector<double> newRow5;
	double inputvar = 0;
    cout << "Please enter in the Iris Sepal Length: ";
    cin >> inputvar;
    newRow.push_back(inputvar);
    cout << "Please enter in the Iris Sepal Width: ";
    cin >> inputvar;
    newRow.push_back(inputvar);
    cout << "Please enter in the Iris Petal Length: ";
    cin >> inputvar;
    newRow.push_back(inputvar);
    cout << "Please enter in the Iris Petal Width: ";
    cin >> inputvar;
    newRow.push_back(inputvar);


    input.push_back(newRow);
    input.push_back(newRow2);
    input.push_back(newRow3);
    input.push_back(newRow4);
    input.push_back(newRow5);

}


void Flower::gatherdata(vector<vector<string>>& datasetinfo, double& numberoftype_Set, double& numberoftype_Ver, double& numberoftype_Vir, int& records) {
    //Holds each new row that gets generated
    vector<string> newRow;

    //Used to gather the data from the csv columns
    string data;
    string data2;
    string data3;
    string data4;
    string data5;

    //Activates the files we use for this program
    ofstream numberofrecords;
    ifstream irisdataset;

    //Opens the files
    numberofrecords.open("numberofrecords.txt");
    irisdataset.open("OriginalIrisDataset.csv");

    //Checks how many records are in the CSV file.
    if (numberofrecords.is_open()) {
        while (getline(irisdataset, data)) {
            records++;
        }
    }
    //Adds the number of records to the text file.
    //This is for future development to make the code run faster
    numberofrecords << records;

    //Closes the files
    numberofrecords.close();
    irisdataset.close();

    //Reopens the CSV file to avoid errors
    irisdataset.open("OriginalIrisDataset.csv");

    //if (irisdataset.is_open()) {
    //Was causing extra errors
    int x = 0;
    for (int i = 0; i < records; i++) {

        for (int j = 0; j < COL; j++) {
            //Reads the data from the CSV to the 2D array,
            //Which will serve as the "CSV" for the program
            getline(irisdataset, data, ',');

            newRow.push_back(data);

            j++;

            getline(irisdataset, data2, ',');

            newRow.push_back(data2);

            j++;

            getline(irisdataset, data3, ',');

            newRow.push_back(data3);

            j++;

            getline(irisdataset, data4, ',');

            newRow.push_back(data4);

            j++;

            getline(irisdataset, data5, '\n');

            newRow.push_back(data5);

            //Counts how many setosa, versicolor, and virginicas there are.
            if (data5 == "Iris-setosa") {
                numberoftype_Set++;
            }
            else if (data5 == "Iris-versicolor") {
                numberoftype_Ver++;
            }
            else if (data5 == "Iris-virginica") {
                numberoftype_Vir++;
            }

            datasetinfo.push_back(newRow);

            newRow.clear();
        }
    }
    irisdataset.close();
}


void Flower::samplemean(vector<vector<string>>& datasetinfo, string type, double numberoftype, int records, vector<vector<double>>& input) {
    //Each spmean is for each column!
    //So spmean is for sepal width
    //spmean2 is for sepal length, etc
    //Same for the sums
    double spmean = 0;

    double spmean2 = 0;

    double spmean3 = 0;

    double spmean4 = 0;

    double sum = 0;

    double sum2 = 0;

    double sum3 = 0;

    double sum4 = 0;

    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum += stod(datasetinfo[i][0]);

        }
    }
  

    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum2 += stod(datasetinfo[i][1]);
        }
    }
    
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum3 += stod(datasetinfo[i][2]);
        }
    }
    
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum4 += stod(datasetinfo[i][3]);
        }
    }
    
    spmean = (1.0 / numberoftype) * (sum);
    spmean2 = (1.0 / numberoftype) * (sum2);
    spmean3 = (1.0 / numberoftype) * (sum3);
    spmean4 = (1.0 / numberoftype) * (sum4);
    //cout << sum << endl;
    //cout << spmean << endl;

    input[1].push_back(spmean);
    
    input[1].push_back(spmean2);
    
    input[1].push_back(spmean3);
    
    input[1].push_back(spmean4);
    
}


void Flower::samplevariance(vector<vector<string>>& datasetinfo, string type, double numberoftype, int records, vector<vector<double>>& input) {
    //Each variance is for each column!
    //So variance is for sepal width
    //variance2 is for sepal length, etc
    //Same for the sums
    double variance = 0;
    double sum = 0;

    double variance2 = 0;
    double sum2 = 0;

    double variance3 = 0;
    double sum3 = 0;

    double variance4 = 0;
    double sum4 = 0;
    
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum += pow((stod(datasetinfo[i][0]) - input[1][0]), 2);
        }
    }
    
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum2 += pow((stod(datasetinfo[i][1]) - input[1][1]), 2);
        }
    }

    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum3 += pow((stod(datasetinfo[i][2]) - input[1][2]), 2);
        }
    }

    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum4 += pow((stod(datasetinfo[i][3]) - input[1][3]), 2);
        }
    }
    
    variance = (1.0 / (numberoftype - 1)) * sum;

    //cout << variance << endl;

    variance2 = (1.0 / (numberoftype - 1)) * sum2;

    variance3 = (1.0 / (numberoftype - 1)) * sum3;

    variance4 = (1.0 / (numberoftype - 1)) * sum4;

    input[2].push_back(variance);
    input[2].push_back(variance2);
    input[2].push_back(variance3);
    input[2].push_back(variance4);
    
}


void Flower::standarddeviation(vector<vector<double>>& input) {
    double stddev = sqrt(input[2][0]);

    double stddev2 = sqrt(input[2][1]);

    double stddev3 = sqrt(input[2][2]);

    double stddev4 = sqrt(input[2][3]);

    
    input[3].push_back(stddev);

    //cout << stddev << endl;

    input[3].push_back(stddev2);

    input[3].push_back(stddev3);

    input[3].push_back(stddev4);
    
}

void Flower::densityfunction(vector<vector<double>>& input) {
    double densityf = 0;

    double densityf2 = 0;

    double densityf3 = 0;

    double densityf4 = 0;
    
    densityf = pow((1.0 / (sqrt(2.0 * PI) * input[3][0])), exp(-1.0 * pow((input[0][0] - input[1][0]), 2.0) / (2.0 * pow(input[1][0], 2))));
    
    densityf2 = pow((1.0 / (sqrt(2.0 * PI) * input[3][1])), exp(-1.0 * pow((input[0][1] - input[1][1]), 2.0) / (2.0 * pow(input[1][1], 2))));
    
    densityf3 = pow((1.0 / (sqrt(2.0 * PI) * input[3][2])), exp(-1.0 * pow((input[0][2] - input[1][2]), 2.0) / (2.0 * pow(input[1][2], 2))));
    
    densityf4 = pow((1.0 / (sqrt(2.0 * PI) * input[3][3])), exp(-1.0 * pow((input[0][3] - input[1][3]), 2.0) / (2.0 * pow(input[1][3], 2))));
    

    input[4].push_back(densityf);

    input[4].push_back(densityf2);

    input[4].push_back(densityf3);

    input[4].push_back(densityf4);
    
}

void Flower::likeihood(double arr[], double arr2[], double arr3[], double numberoftype_Set, double numberoftype_Ver, double numberoftype_Vir, double records) {

    //Likeihood of Setosa will be stored at the 5th spot in the array 
    arr[4] = arr[0] * arr[1] * arr[2] * arr[3] * (numberoftype_Set / records);
    
    /*Debugging Statements
    cout << "Like: " << arr[0] << endl;
    cout << "Like: " << arr[1] << endl;
    cout << "Like: " << arr[2] << endl;
    cout << "Like: " << arr[3] << endl;
    cout << "Like: " << arr[4] << endl;
    */

    //Likeihood of Setosa will be stored at the 5th spot in the array
    arr2[4] = arr2[0] * arr2[1] * arr2[2] * arr2[3] * (numberoftype_Ver / records);

    /*Debugging Statements
    cout << "Like: " << arr2[0] << endl;
    cout << "Like: " << arr2[1] << endl;
    cout << "Like: " << arr2[2] << endl;
    cout << "Like: " << arr2[3] << endl;
    cout << "Like: " << arr2[4] << endl;
    */
    //Likeihood of Setosa will be stored at the 5th spot in the array
    arr3[4] = arr3[0] * arr3[1] * arr3[2] * arr3[3] * (numberoftype_Vir / records);

}

void Flower::confidence(double arr[], double arr2[], double arr3[]) {


    //Probabiltes of Setosa will be stored at the end of the array
    arr[5] = arr[4] / (arr[4] + arr2[4] + arr3[4]);

    //Likeihood of Setosa will be stored at the end of the array
    arr2[5] = arr2[4] / (arr2[4] + arr[4] + arr3[4]);

    //Likeihood of Setosa will be stored at the end of the array
    arr3[5] = arr3[4] / (arr3[4] + arr2[4] + arr[4]);

}