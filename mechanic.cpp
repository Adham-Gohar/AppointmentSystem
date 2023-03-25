#include "mechanic.h"

mechanic::mechanic() : person(), counter(0) { // mechanic defualt constructor definition
	for (int i = 0; i < 10; i++) {
		appointments[i].hours = 0;
		appointments[i].mins = 0;
	}
}

mechanic::mechanic(string name, int id, int age) : person(name, id, age) // mechanic parametrized constructor definition
{
	this->counter = 0;
	for (int i = 0; i < 10; i++) {
		appointments[i].hours = 0;
		appointments[i].mins = 0;
	}

}

int mechanic::getCounter() const { //getter definition
	return counter;
}

void mechanic::setCounter(int count) { // setter definition
	this->counter = count;
}

bool mechanic::isAvailable(Appointment appt) const {
	for (int i = 0; i < counter; i++) {
		if (appointments[i].hours == appt.hours && appointments[i].mins == appt.mins) {
			return false; // because the mechanic will be booked at this time
		}
	}
	return true; // mechanic will be available at this time
}

void mechanic::addAppointment(Appointment appt) { // adds and appointment to the array and increments the counter
	appointments[counter++] = appt;
}

Appointment mechanic::getApp(int i) { // returns an apointment using the array index
	return appointments[i];
}