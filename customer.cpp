#include "customer.h"
#include <iostream>
#include<string>
using namespace std;


customer::customer() : mechanicId(0), appointment({ 0, 0 }) {} // default constructor definition

customer::customer(string name, int id, int age, int mechanicId, const Appointment& appointment) : //parametrized constructore definition
	person(name, id, age), mechanicId(mechanicId), appointment(appointment) {}

void customer::setMechanicID(int mechanicId) {
	this->mechanicId = mechanicId;
}

void customer::setAppointment(const Appointment& appointment) {
	this->appointment = appointment;
}

int customer::getMechanicID() {
	return mechanicId;
}

Appointment customer::getAppointment() const {
	return appointment;
}

void customer::printInfo() const {
	cout << "Name: " << getName() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Mechanic ID: " << mechanicId << endl;
	cout << "Appointment Time: " << appointment.hours << ":" << appointment.mins << endl;
}

bool customer::operator<(const customer& other) const {
	if (appointment.hours < other.appointment.hours) {
		return true;
	}
	else if (appointment.hours == other.appointment.hours) { // if hours are the same then compare minutes
		if (appointment.mins < other.appointment.mins)
		{
			return true;
		}
		else
			false;
	}
	return false;
}

bool customer::operator>(const customer& other) const {
	if (appointment.hours > other.appointment.hours) {
		return true;
	}
	else if (appointment.hours == other.appointment.hours) { // if hours are the same then compare minutes
		if (appointment.mins > other.appointment.mins)
		{
			return true;
		}
		else
			false;
	}
	return false;
}

bool customer::operator==(const customer& other) const {
	return appointment.hours == other.appointment.hours && appointment.mins == other.appointment.mins;
}