// Challenge 1 - CO2 Emissions Calculator

#include <iostream>  // For input and output
#include <iomanip>   // For decimal formatting
#include <string>    // For text variables

using namespace std;

// Ask the user for the distance in miles
double getDistance() {
    double distance;

    // Keep asking until a valid distance is entered
    while (true) {
        cout << "Enter distance travelled in miles: ";
        cin >> distance;

        if (cin.fail() || distance < 0) {
            cout << "Invalid distance. Please try again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            return distance;
        }
    }
}

// Ask the user to select the fuel type
string getFuelType() {
    string fuelType;

    // Keep asking until a valid fuel type is entered
    while (true) {
        cout << "Enter fuel type (diesel or petrol): ";
        cin >> fuelType;

        if (fuelType == "diesel" || fuelType == "petrol") {
            return fuelType;
        }
        else {
            cout << "Invalid fuel type. Please try again." << endl;
        }
    }
}

// Calculate the total CO2 emissions
double calculateCO2(double distance, string fuelType) {
    // Calculate how much fuel is used
    double fuelUsed = (distance / 100) * 9.66;
    double emissionsPerLitre;

    // Check which fuel type was selected
    if (fuelType == "diesel") {
        emissionsPerLitre = 2.68;
    }
    else {
        emissionsPerLitre = 2.31;
    }

    // Return the total CO2 emissions
    return fuelUsed * emissionsPerLitre;
}

// Main program
int main() {
    cout << "=== CO2 Emissions Calculator ===" << endl;

    // Get the distance and fuel type
    double distance = getDistance();
    string fuelType = getFuelType();

    // Calculate the emissions
    double totalCO2 = calculateCO2(distance, fuelType);

    // Display the result with 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Estimated CO2 emissions: "
         << totalCO2 << " kg" << endl;

    return 0;
}

