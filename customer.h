#pragma once

#include "person.h"
#include<iostream>
#include<string>
using namespace std;

class customer : public person // class customer that inherts publicly from person
{
private: // a customer has a mechanic assigned using the id, and an apointment when they need to fix thier car
	int mechanicId; 
	Appointment appointment;

public:
	customer(); // defualt constructor
	customer(string name, int id, int age, int mechanicId, const Appointment& appointment);//parametarized constructor
	void setMechanicID(int mechanicId); //setters
	void setAppointment(const Appointment& appointment); 
	int getMechanicID();// getters
	Appointment getAppointment() const;
	void printInfo() const override; //redefinition of printInfo for the customer class
	bool operator<(const customer& other) const; // operators overloading that will be used in arranging the appointemnts
	bool operator>(const customer& other) const;
	bool operator==(const customer& other) const;
};