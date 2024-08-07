/*
Israel Showell
Start Date: 3-29-2024
End Date: 4-9-2024
Project:
Predicting Iris Flowers using Vectors

Version: 1.2.0


Description:
This program exercises Machine Learning by taking in values for a new Iris flower.
It uses data from the famous iris dataset, and then processes the new input.
Afterwards, it will show how confidient it is in its prediction, and then add the new flower in as the
type it is most sure that it is.

This program uses Na�ve Bayes and Statistical Modeling to make its predictions.

NOTE:
This is the newer version of the first code I made. This one uses vectors to increase readability.
*/


//Libraries used to provide functionalilty for the program
#include <iostream> //Cout, Cin
#include <fstream> //File Streaming
#include <cstring> //Cstrings Management
#include <string> //String Management
#include <math.h> //Additional Mathematical Functions
#include <cmath> //Additional Mathematical Functions
#include <vector> //Used for better memory management
#include <iomanip>  //Used to format output

//My custom header file
#include "Prediction.h"

//This is techinally bad practice, but I didn't want to type std:: on each line 
using namespace std;


int main()
{
    //Flower1 object
    Flower Flower1;

    //Number of Records in CSV file
    int records = 0;
    int choice = 0;

    //Will hold the number of each flower type from the dataset
    double numberoftype_Set = 0;
    double numberoftype_Ver = 0;
    double numberoftype_Vir = 0;

    //Used to hold the density calculations for each flower type
    double density_setosa[6];
    double density_ver[6];
    double density_vir[6];


    //Keeps track of the Type in the CSV file
    string iris_s = "Iris-setosa";
    string iris_ver = "Iris-versicolor";
    string iris_vir = "Iris-virginica";

    //Manages data from CSV file
    vector<vector<string>> datasetinfo;

    //Manages input from user
    vector<vector<double>> input;

    

//MENU:  do {
    //Calls the gatherdata member function and passes the proper parameters
    Flower1.gatherdata(datasetinfo, numberoftype_Set, numberoftype_Ver, numberoftype_Vir, records);
    choice = 0;

    //Provides the prompts for the user
    cout << "Welcome to Israel's Iris Flower Predictor!" << endl;
    cout << "Number of detected records from CSV file: " << records << endl;
    cout << "Current number of Setosas: " << numberoftype_Set << endl;
    cout << "Current number of Versicolors: " << numberoftype_Ver << endl;
    cout << "Current number of Virginicas: " << numberoftype_Vir << endl;
    cout << "Please enter 1 to run the prediction program, or anything else to end the program!" << endl;

    cin >> choice;

    //Just to avoid input errors
    cin.ignore();
    
    if (choice == 1) {

        //Used for later in the program!
        double results[3];
        string userarr[5];
        Flower1.gatherinput(input, userarr);
       
        //Setosa values being calculated
        Flower1.samplemean(datasetinfo, iris_s, numberoftype_Set, records, input); 
        Flower1.samplevariance(datasetinfo, iris_s, numberoftype_Set, records, input);
        Flower1.standarddeviation(input);
        Flower1.densityfunction(input);

        //Sends the data for the densities from the 2D vector to the 1D array for simplicity
        for (int i = 0; i < 4; i++) {
            density_setosa[i] = input[4][i];
        }
        
        // Starting from the second row, clears the content of each row in the vector 
        for (int i = 1; i < input.size(); ++i) {
            input[i].clear();
        }

        //Versicolor values being calculated
        Flower1.samplemean(datasetinfo, iris_ver, numberoftype_Ver, records, input);
        Flower1.samplevariance(datasetinfo, iris_ver, numberoftype_Ver, records, input);
        Flower1.standarddeviation(input);
        Flower1.densityfunction(input);

        //Sends the data for the densities from the 2D vector to the 1D array for simplicity
        for (int i = 0; i < 4; i++) {
            density_ver[i] = input[4][i];
        }

        // Starting from the second row, clears the content of each row in the vector 
        for (int i = 1; i < input.size(); ++i) {
            input[i].clear();
        }


        //Virginica values being calculated
        Flower1.samplemean(datasetinfo, iris_vir, numberoftype_Vir, records, input);
        Flower1.samplevariance(datasetinfo, iris_vir, numberoftype_Ver, records, input);
        Flower1.standarddeviation(input);
        Flower1.densityfunction(input);

        //Sends the data for the densities from the 2D vector to the 1D array for simplicity
        for (int i = 0; i < 4; i++) {
            density_vir[i] = input[4][i];
        }

        // Starting from the second row, clears the content of each row in the vector s
        for (int i = 1; i < input.size(); ++i) {
            input[i].clear();
        }

        //Runs the likeihood and confidence functions
        Flower1.likeihood(density_setosa, density_ver,density_vir,numberoftype_Set, numberoftype_Ver,numberoftype_Vir, records);
       
        Flower1.confidence(density_setosa, density_ver, density_vir);


        //Puts the confidence values in a secondary 1D array to finally send the output to the user
        results[0] = density_setosa[5];
        results[1] = density_ver[5];
        results[2] = density_vir[5];

        //Basic logic to check which flower type is most likely to
        //be the correct answer
        if (results[0] >= results[1] && results[0] >= results[2]) {
            cout << "The program has generated these results: " << endl;

            //Formats the confidence as a percentage for better readability
            cout << fixed << setprecision(3) << results[0] * 100 << '%' << " is how confident the program is that your entered flower is a Setosa." << endl;
            cout << fixed << setprecision(3) << results[1] * 100 << '%' << " is how confident the program is that your entered flower is a Versicolor." << endl;
            cout << fixed << setprecision(3) << results[2] * 100 << '%' << " is how confident the program is that your entered flower is a Virginica." << endl;
           
            //Saves the predicted flower type with the user's inputted attribute values
            userarr[4] = "Iris-setosa";

            cout << "Thus, your flower is most likely a Setosa!" << endl;
        }
        else if (results[1] >= results[0] && results[1] >= results[2]) {
            cout << "The program has generated these results: " << endl;

            //Formats the confidence as a percentage for better readability
            cout << fixed << setprecision(3) << results[0] * 100 << '%' << " is how confident the program is that your entered flower is a Setosa." << endl;
            cout << fixed << setprecision(3) << results[1] * 100 << '%' << " is how confident the program is that your entered flower is a Versicolor." << endl;
            cout << fixed << setprecision(3) << results[2] * 100 << '%' << " is how confident the program is that your entered flower is a Virginica." << endl;
           
            //Saves the predicted flower type with the user's inputted attribute values
            userarr[4] = "Iris-versicolor";

            cout << "Thus, your flower is most likely a Versicolor!" << endl;
        }
        else {
            cout << "The program has generated these results: " << endl;
            
            //Formats the confidence as a percentage for better readability
            cout << fixed << setprecision(3) << results[0] * 100 << '%' << " is how confident the program is that your entered flower is a Setosa." << endl;
            cout << fixed << setprecision(3) << results[1] * 100 << '%' << " is how confident the program is that your entered flower is a Versicolor." << endl;
            cout << fixed << setprecision(3) << results[2] * 100 << '%' << " is how confident the program is that your entered flower is a Virginica." << endl;
            
            //Saves the predicted flower type with the user's inputted attribute values
            userarr[4] = "Iris-virginica";

            cout << "Thus, your flower is most likely a Virginica!" << endl;
        }

        cout << endl;
        cout << "Please enter 1 to add the flower as a " << userarr[4] <<" to the CSV file, or anything else to continue!" << endl;
        cout << "Please note; Once a flower has been added, the next flower you enter will be influnced by the new entry!" << endl;

        int choice2 = 0;

        cin >> choice2;

        cin.ignore();

        //This controls the functions of adding the flower to the database
        if (choice2 == 1) {
            
            Flower1.senddata(userarr,records);

            //This was used to support adding multiple flowers in one session, however I removed that functionality for now
            datasetinfo.erase(datasetinfo.begin() + 1, datasetinfo.end());
            datasetinfo[0].clear();
        }
        else {
            cout << "Flower was NOT added to the dataset!" << endl;

            //This was used to support adding multiple flowers in one session, however I removed that functionality for now
            datasetinfo.erase(datasetinfo.begin() + 1,datasetinfo.end());
            datasetinfo[0].clear();
        }
    }
    cout << "The program has ended! Please rerun it to predict a new flower!" << endl;
system("PAUSE");
}

