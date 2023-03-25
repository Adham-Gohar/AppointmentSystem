#include <iostream>
#include <fstream>
#include "person.h"
#include "customer.h"
#include "mechanic.h"
#include "Queue.h"

using namespace std;

int main()
{
	// read mechanics' data from the file and assign it to the an array of mechanics
	ifstream mechanicsFile("mechanicsData.txt"); // opning the file
	int numMechanics;
	int numAppointments;
	mechanicsFile >> numMechanics; // cin from the file
	mechanic* mechanics = new mechanic[numMechanics]; // creating an a dynamic array of mechanics
	for (int i = 0; i < numMechanics; i++) { // fill the data for each mechanic
		string name;
		int age, id;
		mechanicsFile >> name >> id >> age >> numAppointments;
		mechanics[i] = mechanic(name, id, age);
		for (int j = 0; j < numAppointments; j++) {
			int hours, mins;
			mechanicsFile >> hours >> mins;
			mechanics[i].addAppointment(Appointment(hours, mins));

		}
	}
	mechanicsFile.close();


	// read customers' data from the file and assign it to the an array of customers
	ifstream customersFile("customersData.txt"); // opning the file
	int numCustomers;
	customersFile >> numCustomers; // creating an a dynamic array of mechanics
	customer* customers = new customer[numCustomers]; // creating an a dynamic array of mechanics
	for (int i = 0; i < numCustomers; i++) { // fill the data for each mechanic
		string name;
		int age, id, hours, mins;
		customersFile >> name >> id >> age >> hours >> mins;
		customers[i] = customer(name, id, age, -1, Appointment(hours, mins));// initialize mechanicId to -1
	}
	customersFile.close();


	// assign each customers to a mechanics and insert them into queue
	Queue<customer> customerQueue(numCustomers); // creat a queue of customers
	int x = 0;
	for (int i = 0; i < numCustomers; i++) {
		bool assigned = false;
		int mechanicIndex;
		for (int j = 0; j < numMechanics && !assigned && customers[i].getMechanicID() == -1; j++) { // loops over each custemer that is not assigned to a mechanic
			if (mechanics[j].isAvailable(customers[i].getAppointment())) { // checks if mechanic is available at the customer requested time
				int mechanicIndex = i % numMechanics; // index of mechanics, as we need to loop over them to check if they have extra apointments
				mechanics[mechanicIndex].addAppointment(customers[i].getAppointment()); // add customer's appointment to mechanic's schedule(array)
				customers[i].setMechanicID(mechanicIndex);  // assign each customer to a mechanic in the correct order
				assigned = true;
			}
		}
		if (!assigned) { // if we can't find a matching appontment for the customer 
			cout << "No mechanics available for customer " << customers[i].getID() << endl;
		}
	}


	// print customers in order of appointments and their assigned mechanics by arranging the array according to the apointments time
	// using the overloaded operators
	for (int k = 0; k < numCustomers; k++)
	{
		for (int l = k; l < numCustomers; l++)
		{
			if (customers[k] > customers[l])
			{
				customer c = customers[k];
				customers[k] = customers[l];
				customers[l] = c;
			}
		}
	}
	for (int m = 0; m < numCustomers; m++) // push them into a queue of customers after arranging
	{
		customerQueue.push(customers[m]);
	}


	for (int i = 0; i < numCustomers; i++) { // shows the final schudual of the customers and thier assigned mechanics
		int mechanicIndex = i % numMechanics;
		cout << "Mr./Mrs." << customerQueue.peek().getName() << " has an appointment at "
			<< customerQueue.peek().getAppointment().hours << ":" << customerQueue.peek().getAppointment().mins
			<< " with " << mechanics[mechanicIndex].getName() << "." << endl;
		customerQueue.pop();
	}

	// Free up memory allocated for arrays
	delete[] mechanics;
	delete[] customers;

	return 0;
}
