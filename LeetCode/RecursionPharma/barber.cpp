// Given problem wants to simulate 9 AM to 5 PM
// I could not write all function definitions becasue of lack of time
// This code is NOT complete
// All it does currently is print time, entry of barbers, and entry of customers
// To compile it, you can use g++ like "g++ barber.cpp"

#include <iostream>
#include <stack>

class barber{
private:
	int customer_number;
	std::stack<int> customer_queue;
	int hours;
	int minutes;
public:
	// Default constructor
	barber(){
		hours = 9;
		minutes = 0;
		customer_number = 0;
	}

	// Check time
	bool check_time(){		
		// Question doesn't specify if to measure time in AM or PM
		// Hence, using 24 hours format
		if(hours > 16 && minutes > 0)
			return false;
		else
			return true;
	}

	// Print current time
	std::string get_Time(){
		if(minutes > 59){
			hours += 1;
			minutes = 0;
		}
		std::string str = std::to_string(hours) + ":" + std::to_string(minutes); 
		return str;
	}

	// Barber shop open and close status
	std::string barber_shop_status(){
		std::string str;
		if(hours == 9 && minutes == 0)
			str = "Barber shop opened";
		else if(hours == 17 && minutes == 0)
			str = "Barber shop closed";
		return str;
	}

	// Entry of barbers
	void barber_entry_time(){
		if(hours == 9 && minutes == 0){
			std::cout << get_Time() << " Alto started shift\n";
			std::cout << get_Time() << " Basil started shift\n";
			std::cout << get_Time() << " Camphor started shift\n";
			std::cout << get_Time() << " Diogenes started shift\n";	
		}
		else if(hours == 13 && minutes == 0){
			std::cout << get_Time() << " Eros started shift\n";
			std::cout << get_Time() << " Fatoush started shift\n";
			std::cout << get_Time() << " Glorio started shift\n";
			std::cout << get_Time() << " Heber started shift\n";
		}
	}

	// Entry of a customer
	std::string customer_entry_time(){
		// Average of 10 minutes
		customer_number += 1;
		// Maintain a queue for the entry of customers
		customer_queue.push(customer_number);
		std::string str = get_Time() + " Customer" + std::to_string(customer_number) + " entered";
		minutes = minutes + 10;
		return str;
	}

	// Check if a barber is free
	bool check_barber_status(){

	}

	// Check customers in waiting
	bool check_customer_queue(){
	}

	// Check empty seats in the shop
	bool check_empty_seats(){
	}

	void print_customer_experience(){
	}
};

int main(){
	barber obj1;

	do{
		// Check status of shop - open or close
		std::string barber_shop_status = obj1.barber_shop_status();
		if(barber_shop_status != "")
			std::cout << obj1.get_Time() << " " << obj1.barber_shop_status() << std::endl;
		
		// Check on barbers start time
		obj1.barber_entry_time();

		// Check on the entry of customers
		std::string customer_entry = obj1.customer_entry_time();
		std::cout << customer_entry << std::endl;

	}while(obj1.check_time());

	return 0;
}