
#include <iostream>
#include <string>
# include <fstream>
#include "Person.cpp"
using namespace std;

void readFile(Person empl[], int &N)
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
  cout << firstName << " " << lastName << " " << payRate << " " << hoursWorked << "" << endl;
  empl[i].setFirstName(firstName);
  empl[i].setLastName(lastName);
  empl[i].setHoursWorked(hoursWorked);
  empl[i].setPayRate(payRate);
  i++;
 }
 Personfile.close();
}
void writeData(Person empl[], int N) {
 int i = 0;
 float totalPay=0;
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
 Person empl[20];

 readFile(empl, N);
 writeData(empl, N);

 return 0;
}
