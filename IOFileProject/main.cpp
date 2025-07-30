#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


//The function used to read the fahrenheit file and assign city name and record temperatures
void ReadTempsF(vector<pair<string, int>> &TempList) {
    ifstream TempsFahrFS;
    string cityName;
    int TemperatureF;

    TempsFahrFS.open("FahrenheitTemperature.txt");  //Open the file

    if (!TempsFahrFS.is_open()) {  //check to see if fileopen successfully, if not, error message displays
        cout << "Could not open file reviews.txt." << endl;
    }
    else {
        TempsFahrFS >> cityName; //start recording each city and temperature in fahrenheit
        TempsFahrFS >> TemperatureF;

        while (!TempsFahrFS.fail()) { //keep running loop until EOF is reached
            TempList.emplace_back(cityName, TemperatureF); //used emplace to create a pair within the vector
            TempsFahrFS >> cityName;
            TempsFahrFS >> TemperatureF;
        }

        TempsFahrFS.close(); //close file
    }
}


//This function will display our original file's contents
void DisplayTemps(vector <pair<string, int>> &TempList) {
    cout << endl << "CITY TEMPERATURES IN FAHRENHEIT: " << endl << endl;
    for (const auto& pair : TempList) {
        cout <<"City: "<<pair.first << " Temperature: " << pair.second << endl;
    }
    }


//This function will take the temperatures from the original file, convert them to celsius and write them to a new file
void SaveTempC(vector<pair<string, int>> &TempList) {
    ofstream TEMPCFS;
    TEMPCFS.open("CelsiusTemperature.txt");

    if (TEMPCFS.is_open()) {
        // File opened successfully, proceed to write
    } else {
        // Handle error, e.g., print an error message
        std::cerr << "Error: Unable to open file." << std::endl;
    }

    cout << endl << "TEMPERATURES CONVERTED TO CELSIUS: " << endl << endl;
    for (const auto& pair : TempList) {
        cout <<"City: "<<pair.first << " Temperature: " << (pair.second - 32) * 5/9 << endl;
        TEMPCFS << pair.first << " Temperature: " << (pair.second - 32) * 5/9  << endl;
    }

    cout << endl << "Saving converted Temperatures to \"CelsiusTemperature.txt\"..." << endl;
    TEMPCFS.close();
}



int main() {
    vector <pair<string, int>> TempList;

    ReadTempsF(TempList);
    DisplayTemps(TempList);
    SaveTempC(TempList);


    return 0;
}
