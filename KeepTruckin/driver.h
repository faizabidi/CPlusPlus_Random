#ifndef driver_h
#define driver_h
using namespace std;

class driver{
private:
    // Id will be incremented as drivers are added
    static int id;
    // Id of the driver
    int id_driver;
    // Name of the driver
    string name;
    // Phone number of the driver
    string phoneNumber;
    // Date of availability
    int year, month, date;
    // Size of the truck
    int length, breadth, height;
    // Rate/mile in dollars
    int rate;
    // Origin and destination city
    string origin, destination;
public:
    // Default constructor
    driver();
    // Set and get the id
    void setId();
    int getId();
    // Set and get the name
    void setName(string name);
    string getName();
    // Set and get the phone number
    void setphoneNumber(string phoneNumber);
    string getphoneNumber();
    // Set and get the year
    void setDate(int year, int month, int date);
    vector<int> getDate();
    // Set and get the dimensions
    void setDimensions(int length, int breadth, int height);
    vector<int> getDimensions();
    // Set and get the rate per mile
    void setRate(int rate);
    int getRate();
    // Set and get the source and destination 
    void setRoute(string origin, string destination);
    vector<string> getRoute();
};

#endif