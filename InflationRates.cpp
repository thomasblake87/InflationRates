/*
* The user enters the price of the item from the current year, last year, and the year before.
* 
* The program will use the input to determine the rates of inflation, then it will display those rates and write if inflation is increasing or decreasing
* 
* It will output the percent change and whether it is decreasing, increasing, or steady
*/

#include <iostream>

using namespace std;

// Precons - None. Post cons - Prices each year
// Function to get input prices
void getPrices(float& y1, float& y2, float& y3) {
    cout << "Enter the current price of the item: ";
    cin >> y1;
    cout << "Enter the price of the item one year ago: ";
    cin >> y2;
    cout << "Enter the price of the item two years ago: ";
    cin >> y3;
}

//Precons - Y1 Y2 and Y3 have been defined. Post cons - Numbers after being formulad
// Function to calculate inflation rates
void calcRates(float y1, float y2, float y3, float& y1toy2, float& y2toy3) {
    y1toy2 = ((y1 - y2) / y2) * 100;
    y2toy3 = ((y2 - y3) / y3) * 100;
}

// Precons - y1toy2 and y2toy3 being defined; y1 y2 and y3 being defined. Post cons - Same as outputs
// Function to output results
void outputResults(float y1toy2, float y2toy3) {
    string trend;
    if (y1toy2 > y2toy3) {
        trend = "increasing";
    }
    else if (y1toy2 < y2toy3) {
        trend = "decreasing";
    }
    else {
        trend = "stable";
    }
    cout << "Inflation rate for the first year: " << y1toy2 << "%" << endl;
    cout << "Inflation rate for the second year: " << y2toy3 << "%" << endl;
    cout << "The inflation trend is " << trend << endl;
}

// No precons or postcons
// call functions
int main() {
    float y1, y2, y3;
    getPrices(y1, y2, y3);

    float y1toy2, y2toy3;
    calcRates(y1, y2, y3, y1toy2, y2toy3);

    outputResults(y1toy2, y2toy3);
}