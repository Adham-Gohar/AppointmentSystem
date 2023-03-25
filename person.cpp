#include "person.h"
#include<iostream>
#include<string>
using namespace std;

person::person() { // the defualt constructor
	name = "";
	age = 0;
	id = 0;
};

person::person(string name, int id, int age) // the parametiazed constructore
{
	this->name = name;
	this->age = age;
	this->id = id;
}

void person::setName(string name) { //setters definition
	this->name = name;
};

void person::setAge(int age) { 
	this->age = age;
};

void person::setID(int id) {
	this->id = id;
};

string person::getName()const { // getters definition
	return name;
};

int person::getAge()const {
	return age;
};

int person::getID()const {
	return id;
};

void person::printInfo()const { // definition for printInfo class 
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Age: " << age << endl;
};