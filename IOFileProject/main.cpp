#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void ReadTempsF(vector<pair<string, int>> &TempList) {
    ifstream TempsFarFS;
    string cityName;
    int TemperatureF;
    int TemperatureC;
    string cityAndTemp;

    TempsFarFS.open("FahrenheitTemperature.txt");

    if (!TempsFarFS.is_open()) {
        cout << "Could not open file reviews.txt." << endl;
    }
    else {
        TempsFarFS >> cityName;
        TempsFarFS >> TemperatureF;

        while (!TempsFarFS.fail()) {
            TempList.emplace_back(cityName, TemperatureF);
            TempsFarFS >> cityName;
            TempsFarFS >> TemperatureF;
        }

        TempsFarFS.close();
    }
}



void DisplayTemps(vector <pair<string, int>> &TempList) {
    cout << endl << "CITY TEMPERATURES IN FARENHEIT: " << endl << endl;
    for (const auto& pair : TempList) {
        cout <<"City: "<<pair.first << " Temperature: " << pair.second << endl;
    }
    }

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
    string newReview;

    // Read reviews from file into reviews vector and display
    ReadTempsF(TempList);
    DisplayTemps(TempList);
    SaveTempC(TempList);

    return 0;
}