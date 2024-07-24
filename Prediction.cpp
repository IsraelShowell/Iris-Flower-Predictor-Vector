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
    //Class constructor
	//Leaving this constructor empty
}

Flower::~Flower() {
	//Class deconstructor
    //Leaving this deconstructor empty
}

void Flower::gatherinput(vector<vector<double>>& input, string userarr[]) {
    //This creates the row vectors to manage the data
    vector<double> newRow;
    vector<double> newRow2;
    vector<double> newRow3;
    vector<double> newRow4;
    vector<double> newRow5;

    //Input variable for the user
	double inputvar = 0;

    //Each block gets an input, converts it for later and adds the variable to the row
    cout << "Please enter in the Iris Sepal Length: ";
    cin >> inputvar;
    userarr[0] = to_string(inputvar);
    newRow.push_back(inputvar);

    //Each block gets an input, converts it for later and adds the variable to the row
    cout << "Please enter in the Iris Sepal Width: ";
    cin >> inputvar;
    userarr[1] = to_string(inputvar);
    newRow.push_back(inputvar);

    //Each block gets an input, converts it for later and adds the variable to the row
    cout << "Please enter in the Iris Petal Length: ";
    cin >> inputvar;
    userarr[2] = to_string(inputvar);
    newRow.push_back(inputvar);

    //Each block gets an input, converts it for later and adds the variable to the row
    cout << "Please enter in the Iris Petal Width: ";
    cin >> inputvar;
    userarr[3] = to_string(inputvar);
    newRow.push_back(inputvar);

    //This adds the vectors to the input vector, thus creating the 2D vector
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

            //Reads the data from the CSV to the 2D array,
            //Which will serve as the "CSV" for the program
            getline(irisdataset, data2, ',');

            newRow.push_back(data2);

            j++;

            //Reads the data from the CSV to the 2D array,
            //Which will serve as the "CSV" for the program
            getline(irisdataset, data3, ',');

            newRow.push_back(data3);

            j++;

            //Reads the data from the CSV to the 2D array,
            //Which will serve as the "CSV" for the program
            getline(irisdataset, data4, ',');

            newRow.push_back(data4);

            j++;

            //Reads the data from the CSV to the 2D array,
            //Which will serve as the "CSV" for the program
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
            //Adds the newRow to the dataset
            datasetinfo.push_back(newRow);

            //Clears the newRow to make space for the next entries
            newRow.clear();
        }
    }
    //Closes the file after completing the transfer
    irisdataset.close();
}


void Flower::samplemean(vector<vector<string>>& datasetinfo, string type, double numberoftype, int records, vector<vector<double>>& input) {
    //Each spmean is for each column!
    //So spmean is for sepal width
    //spmean2 is for sepal length, etc
    double spmean = 0, spmean2 = 0, spmean3 = 0, spmean4 = 0;

    //Each sum is for each column!
    //So sum is for sepal width
    //sum2 is for sepal length, etc
    double sum = 0, sum2 = 0, sum3 = 0, sum4 = 0;

    
    //This converts each value from the dataset vector to a double if it matches the type of flower that is sent through
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum += stod(datasetinfo[i][0]);

        }
    }
  
    //This converts each value from the dataset vector to a double if it matches the type of flower that is sent through
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum2 += stod(datasetinfo[i][1]);
        }
    }
    
    //This converts each value from the dataset vector to a double if it matches the type of flower that is sent through
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum3 += stod(datasetinfo[i][2]);
        }
    }
    
    //This converts each value from the dataset vector to a double if it matches the type of flower that is sent through
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum4 += stod(datasetinfo[i][3]);
        }
    }
    
    //Saves each sample mean for each column for the correct flower type
    spmean = (1.0 / numberoftype) * (sum);
    spmean2 = (1.0 / numberoftype) * (sum2);
    spmean3 = (1.0 / numberoftype) * (sum3);
    spmean4 = (1.0 / numberoftype) * (sum4);
    
    //Adds each sample mean to the second row of the input vector
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
    double variance = 0, variance2 = 0, variance3 = 0, variance4 = 0;
    double sum = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    
    //This converts each value from the dataset vector to a double if it matches the type of flower that is sent through
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum += pow((stod(datasetinfo[i][0]) - input[1][0]), 2);
        }
    }
    
    //This converts each value from the dataset vector to a double if it matches the type of flower that is sent through
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum2 += pow((stod(datasetinfo[i][1]) - input[1][1]), 2);
        }
    }

    //This converts each value from the dataset vector to a double if it matches the type of flower that is sent through
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum3 += pow((stod(datasetinfo[i][2]) - input[1][2]), 2);
        }
    }

    //This converts each value from the dataset vector to a double if it matches the type of flower that is sent through
    for (int i = 0; i < records; i++) {
        if (datasetinfo[i][4] == type) {
            sum4 += pow((stod(datasetinfo[i][3]) - input[1][3]), 2);
        }
    }
    
    //Saves each variance for each column for the correct flower type
    variance = (1.0 / (numberoftype - 1)) * sum;

    //cout << variance << endl;

    variance2 = (1.0 / (numberoftype - 1)) * sum2;

    variance3 = (1.0 / (numberoftype - 1)) * sum3;

    variance4 = (1.0 / (numberoftype - 1)) * sum4;

    //Adds each sample mean to the third row of the input vector
    input[2].push_back(variance);
    input[2].push_back(variance2);
    input[2].push_back(variance3);
    input[2].push_back(variance4);
    
}


void Flower::standarddeviation(vector<vector<double>>& input) {

    double stddev = sqrt(input[2][0]), stddev2 = sqrt(input[2][1]), stddev3 = sqrt(input[2][2]), stddev4 = sqrt(input[2][3]);

    //Adds each standard deviation to the fourth row of the input vector
    input[3].push_back(stddev);
    //cout << stddev << endl;

    input[3].push_back(stddev2);

    input[3].push_back(stddev3);

    input[3].push_back(stddev4);
    
}

void Flower::densityfunction(vector<vector<double>>& input) {

    //Each densityf is for each column!
    //So densityf is for sepal width
    //densityf2 is for sepal length, etc
    double densityf = 0, densityf2 = 0, densityf3 = 0, densityf4 = 0;
    
    //this does the calculation to find out the density function for each column
    densityf = pow((1.0 / (sqrt(2.0 * PI) * input[3][0])), exp(-1.0 * pow((input[0][0] - input[1][0]), 2.0) / (2.0 * pow(input[1][0], 2))));
    
    densityf2 = pow((1.0 / (sqrt(2.0 * PI) * input[3][1])), exp(-1.0 * pow((input[0][1] - input[1][1]), 2.0) / (2.0 * pow(input[1][1], 2))));
    
    densityf3 = pow((1.0 / (sqrt(2.0 * PI) * input[3][2])), exp(-1.0 * pow((input[0][2] - input[1][2]), 2.0) / (2.0 * pow(input[1][2], 2))));
    
    densityf4 = pow((1.0 / (sqrt(2.0 * PI) * input[3][3])), exp(-1.0 * pow((input[0][3] - input[1][3]), 2.0) / (2.0 * pow(input[1][3], 2))));
    

    //Adds each standard deviation to the fifth row of the input vector
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

    //Likeihood of Versicolor will be stored at the 5th spot in the array
    arr2[4] = arr2[0] * arr2[1] * arr2[2] * arr2[3] * (numberoftype_Ver / records);

    /*Debugging Statements
    cout << "Like: " << arr2[0] << endl;
    cout << "Like: " << arr2[1] << endl;
    cout << "Like: " << arr2[2] << endl;
    cout << "Like: " << arr2[3] << endl;
    cout << "Like: " << arr2[4] << endl;
    */
    //Likeihood of Virginica will be stored at the 5th spot in the array
    arr3[4] = arr3[0] * arr3[1] * arr3[2] * arr3[3] * (numberoftype_Vir / records);

}

void Flower::confidence(double arr[], double arr2[], double arr3[]) {


    //Probabiltes of Setosa will be stored at the end of the array
    arr[5] = arr[4] / (arr[4] + arr2[4] + arr3[4]);

    //Probabiltes of Versicolor will be stored at the end of the array
    arr2[5] = arr2[4] / (arr2[4] + arr[4] + arr3[4]);

    //Probabiltes of Virginica will be stored at the end of the array
    arr3[5] = arr3[4] / (arr3[4] + arr2[4] + arr[4]);

}


void Flower::senddata(string userarr[], int& records) {
    //Activates the files we use for this program
    ofstream numberofrecords;
    ofstream irisdataset;

    //Opens the files
    numberofrecords.open("numberofrecords.txt");
    irisdataset.open("OriginalIrisDataset.csv", ios_base::app);

    if (!numberofrecords.is_open() || !irisdataset.is_open()) {
        cout << "We ran into an error opening one of the files!" << endl;
        cout << "Flower was NOT added to the dataset!" << endl;
        return;
    }
    else {
        cout << "Flower was successfully added to the dataset!" << endl;
    }

    //Loops through the array to add each value
    for (int i = 0; i <= 4; i++) {

        if (i == 4) {
            //Makes sure that the type is saved as a string
            irisdataset << userarr[i] <<"\n";
        }
        else {
            //Makes sure that the double values are saved as doubles in the CSV file
            irisdataset << stod(userarr[i])<<",";
        }
        //Makes sure to seperate the values in the CSV file
    }
    //Adds one to the record count
    records += 1;

    //Saves the new record count to the txt file
    numberofrecords << records;

    //Closes the files
    numberofrecords.close();
    irisdataset.close();

}
