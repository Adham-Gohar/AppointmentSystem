#pragma once

#include "person.h"
#include<iostream>
#include<string>
using namespace std;

class mechanic : public person // class mechanic inherts publicly from class person 
{
private:
	int counter; // counter to keep the number of appointments the mechanic has
	Appointment appointments[15]; // an array of appoits where appoinments of mechanic is saved and i assumed that its size will be 15
public:
	mechanic(); //defualt constructor
	mechanic(string name, int id, int age); // parametriazed constructor
	bool isAvailable(Appointment appt) const; // function isAvailable to check the availability of a mechanic at a certain time
	void addAppointment(Appointment appt); // function that will add an apointment to the array of appointments and increment the counter for easily accessing the array 
	void setCounter(int count); // setter for counter
	int getCounter() const; // getter for counter
	Appointment getApp(int i); // getter for apointment info using the array, i used it mostly in testing
};