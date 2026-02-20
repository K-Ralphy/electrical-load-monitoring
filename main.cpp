#include <iostream>
#include <string>

using namespace std;


class Appliance {
private:
    string name;
    double powerRating; 
    double usageHours;  

public:
    
    Appliance() {
        name = "Unknown";
        powerRating = 0.0;
        usageHours = 0.0;
    }

   
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

    
    string getName() { return name; }
    double getPowerRating() { return powerRating; }
    double getUsageHours() { return usageHours; }

    
    double getDailyEnergyKWh() {
        
        return (powerRating * usageHours) / 1000.0;
    }
};

int main() {
    
    const int MAX_APPLIANCES = 100;
    Appliance appliances[MAX_APPLIANCES];
    
    int applianceCount = 0; 
    int choice;            

    
    while (true) {
       
        cout << "\n=========================================\n";
        cout << "  Electrical Load Monitoring System\n";
        cout << "=========================================\n";
        cout << "1. Register an Appliance\n";
        cout << "2. View All Registered Appliances\n";
        cout << "3. Search Appliance by Name\n"; 
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        
     
        if (!(cin >> choice)) { 
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();               
            cin.ignore(10000, '\n');   
            continue;                  
        }

       
        if (choice == 0) {
            cout << "Exiting system. Goodbye!\n";
            break; 
        } 
        
        else if (choice == 1) {
         
            if (applianceCount >= MAX_APPLIANCES) {
                cout << "Error: Maximum appliance limit reached.\n";
                continue; 
            }

          
            Appliance newAppliance;
            string tempName;
            double tempPower, tempHours;

            cout << "\n--- Register New Appliance ---\n";
            cin.ignore(); 
            
            
            do {
                cout << "Enter Appliance Name: ";
                getline(cin, tempName);
            } while (!newAppliance.setName(tempName));

           
            do {
                cout << "Enter Power Rating (Watts): ";
                cin >> tempPower;
            } while (!newAppliance.setPowerRating(tempPower));

            
            do {
                cout << "Enter Daily Usage (Hours): ";
                cin >> tempHours;
            } while (!newAppliance.setUsageHours(tempHours));

            
            appliances[applianceCount] = newAppliance;
            applianceCount++;
            
            cout << "Appliance successfully registered!\n";
        } 
        
        else if (choice == 2) {
            cout << "\n--- Registered Appliances ---\n";
            
           
            if (applianceCount == 0) {
                cout << "No appliances registered yet.\n";
            } else {
                
                for (int i = 0; i < applianceCount; i++) {   
                    cout << i + 1 << ". " << appliances[i].getName() 
                         << " | Power: " << appliances[i].getPowerRating() << " W"
                         << " | Usage: " << appliances[i].getUsageHours() << " hrs"
                         << " | Energy: " << appliances[i].getDailyEnergyKWh() << " kWh/day\n";
                }
            }
        } 
           
        else if (choice == 3) {
            
            if (applianceCount == 0) {
                cout << "The shelf is empty. No appliances registered yet to search.\n";
                continue; 
            }

            string targetName;
            cout << "\n--- Search Appliance ---\n";
            cout << "Enter the exact name of the appliance to find: ";
            cin.ignore(); 
            getline(cin, targetName);

            
            bool found = false;
            int matchCount = 0;
          
            for (int i = 0; i < applianceCount; i++) {
                
                
                if (appliances[i].getName() == targetName) {

                    matchCount++;
                   
                    cout << "\n[Match Found!]\n";
                    cout << "Name:   " << appliances[i].getName() << "\n";
                    cout << "Power:  " << appliances[i].getPowerRating() << " W\n";
                    cout << "Usage:  " << appliances[i].getUsageHours() << " hours/day\n";
                    cout << "Energy: " << appliances[i].getDailyEnergyKWh() << " kWh/day\n";
                    
                    
                    found = true;
                    
        
                }
            }

            
            if (found == false) {
                cout << "Sorry, no appliance named '" << targetName << "' was found on the system.\n";
            }
        
        else {
           
           cout << "\nTotal '" << targetName << "' appliances found: " << matchCount << "\n";
        }
     }
    

     
}
return 0;
}