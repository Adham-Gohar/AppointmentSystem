#pragma once

#include<iostream>
#include<string>
using namespace std;

struct Appointment { //creating a struct to create appointments
	int hours;
	int mins;

	Appointment() // the defualt constructor of apointments that will be used late on  in the program and i also used it wwhile testing
	{
		hours = 0;
		mins = 0;
	}

	Appointment(int h, int m) // a prametarized to easily access the appoitment created and change its data members
	{
		hours = h;
		mins = m;
	}
	
	void Print() { // I used this member function in testing if the appointments are all created in the right way
		cout << hours << "   " << mins << "\n";
	}
};

class person // defining class person
{
protected: // i created data members as protected to make them ready for inharitance and easy access
	string name;
	int id; 
	int age;

public:
	person(); // defualt constructor
	person(string name, int id, int age); // prametarized constructor 
	void setName(string name); //setters
	void setAge(int age);
	void setID(int id);
	string getName()const; //getters
	int getAge()const;
	int getID()const;
	virtual void printInfo()const; // a virtual function, that is ready to be inhereted and changed by any other class
};