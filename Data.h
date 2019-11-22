//data from Kaggle, This dataset contains emission data of Green House Gases (in tonnes) of different countries from year 1750 - 2019.
//https://www.kaggle.com/srikantsahu/co2-and-ghg-emission-data

#ifndef PROJECT7_DATA_H
#define PROJECT7_DATA_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Data {

    friend ostream& operator << (ostream& os, Data Country);

public:
    Data(); //default constructor
    Data(string C, int GHG_E, int y); //alternative constructor

    friend bool operator > (const Data &Country1, const Data &Country2);//operator overloading for comparison
    friend bool operator <= (const Data &Country1, const Data &Country2);

private:
    //data that we care
    string Country;
    int GHG_Emission_tonnes;
    int year;
    bool ZeroEmission;
};



#endif //PROJECT7_DATA_H

