#include <iostream>
#include <vector>
#include "driver.h"
#include "customer.h"
using namespace std;

/****************************************************/
// Driver class functions
int driver::id = 0;
driver::driver(){
    id++;
};
// Set and get driver's id
void driver::setId(){
    id_driver = id;
}
int driver::getId(){
    return id_driver;
}
// Set and get driver's name
void driver::setName(string val){
    name = val;
}
string driver::getName(){
    return name;
}
// Set and get driver's phone number
void driver::setphoneNumber(string val){
    phoneNumber = val;
}
string driver::getphoneNumber(){
    return phoneNumber;
}
// Set and get driver's availability
void driver::setDate(int y, int m, int d){
    year = y;
    month = m;
    date = d;
}
vector<int> driver::getDate(){
    vector<int> dateAvail;
    dateAvail.push_back(year);
    dateAvail.push_back(month);
    dateAvail.push_back(date);
    return dateAvail;
}
// Set and get driver's truck dimensions
void driver::setDimensions(int l, int b, int h){
    length = l;
    breadth = b;
    height = h;
}
vector<int> driver::getDimensions(){
    vector<int> dimensions;
    dimensions.push_back(length);
    dimensions.push_back(breadth);
    dimensions.push_back(height);
    return dimensions;
}
// Set and get driver's rate
void driver::setRate(int val){
    rate = val;
}
int driver::getRate(){
    return rate;
}
// Set and get driver's route
void driver::setRoute(string org, string dest){
    origin = org;
    destination = dest;
}
vector<string> driver::getRoute(){
    vector<string> route;
    route.push_back(origin);
    route.push_back(destination);
    return route;
}
/****************************************************/
// Customer class functions
int customer::id = 0;
customer::customer(){
    id++;
}
// Set and get customer's id
void customer::setId(){
    id_customer = id; 
}
int customer::getId(){
    return id_customer;
}
// Set and get customer's name
void customer::setName(string val){
    name = val;
}
string customer::getName(){
    return name;
}
// Set and get customer's phone number
void customer::setphoneNumber(string val){
    phoneNumber = val;
}
string customer::getphoneNumber(){
    return phoneNumber;
}
// Set and get customer's date requirement
void customer::setDate(int y, int m, int d){
    year = y;
    month = m;
    date = d;
}
vector<int> customer::getDate(){
    vector<int> dateAvail;
    dateAvail.push_back(year);
    dateAvail.push_back(month);
    dateAvail.push_back(date);
    return dateAvail;
}
// Set and get customer's truck dimensions needed
void customer::setDimensions(int l, int b, int h){
    length = l;
    breadth = b;
    height = h;
}
vector<int> customer::getDimensions(){
    vector<int> dimensions;
    dimensions.push_back(length);
    dimensions.push_back(breadth);
    dimensions.push_back(height);
    return dimensions;
}
// Set and get customer's rate needed
void customer::setRate(int val){
    rate = val;
}
int customer::getRate(){
    return rate;
}
void customer::setRoute(string org, string dest){
    origin = org;
    destination = dest;
}
vector<string> customer::getRoute(){
    vector<string> route;
    route.push_back(origin);
    route.push_back(destination);
    return route;
}
/****************************************************/
void getDriverDetails(vector<driver> &allDriverObjects){
    driver d;
    string name, phoneNumber, origin,  destination;
    int year, month, date, length, breadth, height, rate;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your phone number: ";
    cin >> phoneNumber;
    cout << "Enter your availability (year, month, date): ";
    cin >> year >> month >> date;
    cout << "Enter your truck dimensions (length, breadth, height): ";
    cin >> length >> breadth >> height;
    cout << "Enter your rate: ";
    cin >> rate;
    cout << "Enter your route (source, destination): ";
    cin >> origin >> destination;

    d.setId();
    d.setName(name);
    d.setphoneNumber(phoneNumber);
    d.setDate(year, month, date);
    d.setDimensions(length, breadth, height);
    d.setRate(rate);
    d.setRoute(origin, destination);
    allDriverObjects.push_back(d);
}
void showAllDrivers(vector<driver> allDriverObjects){
    int size = allDriverObjects.size();
    cout << "Number of drivers = " << size << endl;
    cout << "Drivers are:\n";
    for(int i = 0; i < size; i++){
        int id = allDriverObjects[i].getId();
        string name = allDriverObjects[i].getName();
        string phoneNumber = allDriverObjects[i].getphoneNumber(); 
        vector<int> date = allDriverObjects[i].getDate(); 
        vector<int> dimensions = allDriverObjects[i].getDimensions();
        int rate = allDriverObjects[i].getRate();
        vector<string> route = allDriverObjects[i].getRoute();
        cout << "**********************\n";
        cout << "Id of driver: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout << "Date available: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
        cout << "Truck dimensions: " << dimensions[0] << ", " << dimensions[1] << ", " << dimensions[2] << endl;
        cout << "Rate: $" << rate << endl;
        cout << "Route: " << route[0] << " to " << route[1] << endl;
        cout << "**********************\n";
    }
}
/****************************************************/
// Add a new customer to the inventory
void getCustomerDetails(vector<customer> &allCustomerObjects){
    customer c;
    string name, phoneNumber, origin,  destination;
    int year, month, date, length, breadth, height, rate;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your phone number: ";
    cin >> phoneNumber;
    cout << "Enter your availability (year, month, date): ";
    cin >> year >> month >> date;
    cout << "Enter your truck dimensions (length, breadth, height): ";
    cin >> length >> breadth >> height;
    cout << "Enter your rate: ";
    cin >> rate;
    cout << "Enter your route (source, destination): ";
    cin >> origin >> destination;

    c.setId();
    c.setName(name);
    c.setphoneNumber(phoneNumber);
    c.setDate(year, month, date);
    c.setDimensions(length, breadth, height);
    c.setRate(rate);
    c.setRoute(origin, destination);
    allCustomerObjects.push_back(c);
}
void showAllCustomers(vector<customer> allCustomerObjects){
    int size = allCustomerObjects.size();
    cout << "Number of customers = " << size << endl;
    cout << "Customers are:\n";
    for(int i = 0; i < size; i++){
        int id = allCustomerObjects[i].getId();
        string name = allCustomerObjects[i].getName();
        string phoneNumber = allCustomerObjects[i].getphoneNumber(); 
        vector<int> date = allCustomerObjects[i].getDate(); 
        vector<int> dimensions = allCustomerObjects[i].getDimensions();
        int rate = allCustomerObjects[i].getRate();
        vector<string> route = allCustomerObjects[i].getRoute();
        cout << "**********************\n";
        cout << "Id of customer: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout << "Dates required: " << date[0] << "/" << date[1] << "/" << date[2] << endl;
        cout << "Truck dimensions: " << dimensions[0] << ", " << dimensions[1] << ", " << dimensions[2] << endl;
        cout << "Rate required: $" << rate << endl;
        cout << "Route required: " << route[0] << " to " << route[1] << endl;
        cout << "**********************\n";
    }
}
/****************************************************/
// Search for customers
vector<customer> findCustomers(vector<customer> allCustomers){
    vector<customer> availableCustomers;
    string origin,  destination;
    int year, month, date, length, breadth, height, rate;

    cout << "**********************\n";
    cout << "Enter the dates you are looking for: ";
    cin >> year >> month >> date;
    vector<int> datesNeeded; 
    datesNeeded.push_back(year); datesNeeded.push_back(month); datesNeeded.push_back(date);
    cout << "Enter the oring and the destination cities: ";
    cin >> origin >> destination;
    vector<string> routeNeeded;
    routeNeeded.push_back(origin); routeNeeded.push_back(destination);
    cout << "Enter your truck dimensions: ";
    cin >> length >> breadth >> height;
    vector<int> dimensionsNeeded;
    dimensionsNeeded.push_back(length); dimensionsNeeded.push_back(breadth); dimensionsNeeded.push_back(height);
    cout << "Enter the minimum rate that you are looking for: ";
    cin >> rate;
    cout << "**********************\n";
    // Search for all such customers
    for(int i = 0; i < allCustomers.size(); i++){
        if(allCustomers[i].getDate() == datesNeeded && 
            allCustomers[i].getRoute() == routeNeeded && 
            allCustomers[i].getDimensions() == dimensionsNeeded &&
            allCustomers[i].getRate() >= rate)
            availableCustomers.push_back(allCustomers[i]);
    }
    return availableCustomers;
}
/****************************************************/
void showMenu(){
    cout << "************* Main menu *************\n";
    cout << "1. I am a new driver. Add my details.\n";
    cout << "2. I am a new customer. Add my details.\n";
    cout << "3. Show all drivers.\n";
    cout << "4. Show all customers.\n";
    cout << "5. I am an existing driver. Search for customers.\n";
    cout << "6. I am an existing customer. Search for drivers.\n";
    cout << "7. Exit.\n";
}

int main(){
    vector<driver> allDriverObjects;
    vector<customer> allCustomerObjects;
    while(true){
        showMenu();
        int value;
        cin >> value;
        if(value == 1)
            getDriverDetails(allDriverObjects);
        else if(value == 2)
            getCustomerDetails(allCustomerObjects);
        else if(value == 3)
            showAllDrivers(allDriverObjects);
        else if(value == 4)
            showAllCustomers(allCustomerObjects);
        else if(value == 5){
            vector<customer> availableCustomers = findCustomers(allCustomerObjects);
            cout << "Based on your requirements, below are available customers.\n";
            showAllCustomers(availableCustomers);
        }
        // TODO: Add search driver feature
        else if(value == 6)
            continue;
        else if(value == 7)
            break;
    }
    return 0;
}
