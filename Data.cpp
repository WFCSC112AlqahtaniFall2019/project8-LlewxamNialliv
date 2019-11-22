//data from Kaggle, This dataset contains emission data of Green House Gases (in tonnes) of different countries from year 1750 - 2019.
//https://www.kaggle.com/srikantsahu/co2-and-ghg-emission-data

#include <ostream>
#include "Data.h"
#include <string>
using namespace std;

Data::Data() { //default constructor
    //assign variables with default data
    Country = "No Name";
    GHG_Emission_tonnes = -1;
    year = -1;
    ZeroEmission = true;
}

Data::Data(string C, int GHG_E, int y) {
    //assign data to the variables accordingly
    Country = C;
    GHG_Emission_tonnes = GHG_E;
    year = y;
    if(GHG_Emission_tonnes == 0){
        ZeroEmission = true;
    } else{
        ZeroEmission = false;
    }
}

bool operator > (const Data &Country1, const Data &Country2) {
    if(Country1.GHG_Emission_tonnes > Country2.GHG_Emission_tonnes){
        return true;
    }
    else{
        return false;
    }
}

bool operator <= (const Data &Country1, const Data &Country2) {
    if(Country1.GHG_Emission_tonnes <= Country2.GHG_Emission_tonnes){
        return true;
    }
    else{
        return false;
    }
}

ostream& operator << (ostream& os, const Data Country) { // output stream operator
    //print data
    os << Country.Country;
    os << " emitted " << Country.GHG_Emission_tonnes << "tonnes of Green House Gases in ";
    os << Country.year;
}