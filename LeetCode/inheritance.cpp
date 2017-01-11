// https://www.hackerrank.com/challenges/30-inheritance

#include <iostream>
#include <vector>

class Person{
	protected:
		std::string firstName;
		std::string lastName;
		int id;
	public:
		Person(std::string firstName, std::string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			std::cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
};

class Student : public Person{
	private:
		std::vector<int> testScores;  
	public:
  		Student(std::string fname, std::string lname, int id, std::vector<int> testScores) \
  				: Person(fname, lname, id){
  			this->testScores = testScores;
        }
  		
    	char calculate(){
            int sum = 0;
            char grade;
            for(int i = 0; i < testScores.size(); i++)
                sum = sum + testScores[i];
            int avg = sum / testScores.size();
            if(avg <= 100 && avg >= 90)
                grade = 'O';
            else if (avg < 90 && avg >=80)
                grade = 'E';
            else if (avg < 80 && avg >=70)
                grade = 'A';
            else if (avg < 70 && avg >=55)
                grade = 'P';
            else if (avg < 55 && avg >=40)
                grade = 'D';
            else
                grade = 'T';
            return grade;
        }
};

int main() {
	std::string firstName;
  	std::string lastName;
	int id;
  	int numScores;
  	std::vector<int> scores;

	std::cin >> firstName >> lastName >> id >> numScores;
  	
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	std::cin >> tmpScore;
		scores.push_back(tmpScore);
	}

	Student* s = new Student(firstName, lastName, id, scores);

	s->printPerson();

	std::cout << "Grade: " << s->calculate() << "\n";
	
	return 0;
}