#include "Person.h"
#include <iostream> 
# include <fstream>
#include <string>
#include <vector>
using namespace std;
//void readFile(Person empl[], int &N);
//void writeData(Person empl[], int N);
void readFile(vector <Person> &empl,int &N)
{
	string lastName;
	string firstName;
	float  payRate = 0;
	float  hoursWorked = 0;
	int i = 0;
	ifstream Personfile;
	Personfile.open("input.txt");
	while (Personfile >> firstName >> lastName >> payRate >> hoursWorked)
	{
		//Personfile >> firstName;
		//Personfile >> lastName;
		//Personfile >> hoursWorked;
		//Personfile >> payRate;
		empl.emplace_back(lastName, lastName, payRate, hoursWorked);
		cout << firstName << " " << lastName << " " << payRate << " " << hoursWorked << "" << endl;

		//empl[i].setFirstName(firstName);
		//cout << empl[i].getFirstName();
		//empl[i].setLastName(lastName);
		//cout << empl[i].getLastName();
		//empl[i].setHoursWorked(hoursWorked);
		//cout << empl[i].getHoursWorked();
		//empl[i].setPayRate(payRate);
		//cout << empl[i].getPayRate();
		i++;
	}
	Personfile.close();
	empl.pop_back();
	
}
void writeData(vector<Person> &empl, int N) {
	int i = 0;
	ofstream Personfile_;
	Personfile_.open("output.txt");
	for (int i = 0; i < N; i++)
	{
		Personfile_ << empl[i].fullName() << " " << empl[i].totalPay() << endl;
	}
	Personfile_.close();
}
int main() {
	string lastName;
	string firstName;
	float  payRate = 0;
	float  hoursWorked = 0;
	
	int N;
	vector<Person> empl;

	readFile(empl, N);
	writeData(empl, N);
	system("pause");
	return 0;
}
