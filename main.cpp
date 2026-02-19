#include <iostream>
#include <string>

using namespace std;

// The Appliance Class
class Appliance {
private:
    string name;
    double powerRating; // in Watts
    double usageHours;  // 0 to 24 hours

public:
    // Default constructor
    Appliance() {
        name = "Unknown";
        powerRating = 0.0;
        usageHours = 0.0;
    }

    // Setters with Validation Rules
    bool setName(string n) {
        if (n.empty()) {
            cout << "Error: Appliance name cannot be empty.\n";
            return false;
        }
        name = n;
        return true;
    }

    bool setPowerRating(double watts) {
        if (watts <= 0) {
            cout << "Error: Power rating must be greater than zero.\n";
            return false;
        }
        powerRating = watts;
        return true;
    }

    bool setUsageHours(double hours) {
        if (hours < 0 || hours > 24) {
            cout << "Error: Usage hours must be between 0 and 24.\n";
            return false;
        }
        usageHours = hours;
        return true;
    }

    // Getters to retrieve the data
    string getName() { return name; }
    double getPowerRating() { return powerRating; }
    double getUsageHours() { return usageHours; }

    // Energy Calculation Method
    double getDailyEnergyKWh() {
        // Formula: (Watts * Hours) / 1000
        return (powerRating * usageHours) / 1000.0;
    }
};

int main() {
    cout << "--- Testing the Appliance Class ---\n";
    
    // Create a test object
    Appliance testFan;
    
    // Let's test the validation (you can change these values to see the errors!)
    testFan.setName("Ceiling Fan");
    testFan.setPowerRating(75.0); // 75 Watts
    testFan.setUsageHours(8.5);   // 8.5 hours a day

    // Print out the results
    cout << "Appliance: " << testFan.getName() << endl;
    cout << "Power Rating: " << testFan.getPowerRating() << " W" << endl;
    cout << "Daily Usage: " << testFan.getUsageHours() << " hours" << endl;
    cout << "Daily Energy Consumption: " << testFan.getDailyEnergyKWh() << " kWh" << endl;

    return 0;
}