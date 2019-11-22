#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include "data.h"
using namespace std;


int main() {

    cout << "" << endl;

    Data GHG_Emission;
    stack <Data> Stack;
    queue <Data> Queue;
    priority_queue <Data> finalsortedList;

    ofstream myfile;
    myfile.open("../test.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();

    ifstream inFile; //create input stream and out put streams
    inFile.open("../emission data.csv");

    ofstream stacked;
    stacked.open("../stacked.txt");

    ofstream queued;
    queued.open("../queued.txt");

    ofstream sorted;
    sorted.open("../sorted.txt");

    if (!inFile.is_open()){ // open check for files
        cout << "Fail to open input file" << endl;
        return  1;
    }

    if (!stacked.is_open()){ //different exceptions
        cout << "Fail to open stack file" << endl;
        return 10;
    }

    if (!queued.is_open()){
        cout << "Fail to open queue file" << endl;
        return 100;
    }

    if (!sorted.is_open()){
        cout << "Fail to open sort file" << endl;
        return 1000;
    }

    cout << "All Good." << endl;

    cout << "...Reading emission data.csv..." << endl;

    while (!inFile.eof()) {
        string Country1;
        getline(inFile, Country1, ',');
        string Year1;
        getline(inFile,Year1, ',');
        string GHG_Emission_tonnes1;
        getline(inFile, GHG_Emission_tonnes1, ',');

        int year = stoi(Year1); //turn string into int
        int GHG_E = stoi(GHG_Emission_tonnes1);

        Data nextCountry = Data(Country1, year, GHG_E);

        Stack.push(nextCountry);

        Queue.push(nextCountry);//push tail for queue

        finalsortedList.push(nextCountry); //insert in sorted for sorted list
    }

    cout << "Writing data in stack into Stack.txt" << endl;
    while (!Stack.empty()){
        stacked << Stack.top() << endl;
        Stack.pop();
    }
    //prints then removes the element from queue
    cout << "Writing data in queue into Queue.txt" << endl;
    while (!Queue.empty()){
        queued << Queue.front() << endl;
        Queue.pop();
    }
    //prints then removes the element from the priority queue
    cout << "Writing data in priority queue into Sorted.txt" << endl;
    while (!finalsortedList.empty()){
        sorted << finalsortedList.top() << endl;
        finalsortedList.pop();
    }

    inFile.close ();
    stacked.close();
    queued.close ();
    sorted.close ();

    return 0;
}