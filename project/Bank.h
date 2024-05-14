#pragma once
#include <iostream>
#include <cstdlib>
#include <queue>
#include<cmath> 
using namespace std;
#include "Customer.h"
#include "Teller.h"
#include <list>

class Bank
{
private:
	Teller Tellers[4]; //composition
	queue<Customer> Customers;
	

public :

	Bank()
	{
		int increment = 0;
		for (int i = 0; i < 4; i++)
		{
			Tellers[i] = Teller(++increment, true);
		}
	}

	void Run()
	{
		MainMenu();
	}

	void MainMenu()
	{
		cout << "-------Bank System--------" << endl << endl;
		cout << "1- show the list of customer  " << endl << endl;
		cout << "2- Add Customer " << endl << endl;
		cout << "3- Show Tellers" << endl << endl;
		cout << "4- Show Statistics" << endl << endl;
		int choice;
		cout << "please Enter Your Choice [1-4] : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "---- list of customers ----" << endl << endl;
			showCustomers(); //displaylist();
			break;

		case 2:
			system("cls");
			cout << "---- Add customer ----" << endl << endl;
			AddCustomerQueue();
			break;

		case 3:
			system("cls");
			cout << "---- Tellers Information ----" << endl << endl;
			showTellers();
			break;

		case 4:
			system("cls");
			cout << "---- Statistics ----" << endl << endl;
			statistics();
			break;

		default:
			system("cls");
			MainMenu();
		}


	}
	// add customer in queue
	void AddCustomerQueue()
	{
		//int id;
		int arrivalTime;
		int serviceTime;

			
		cout << "Set Arrival Time : ";
		cin >> arrivalTime;
		cout << endl;
		cout << "Set Service Time : ";
		cin >> serviceTime;
		cout << endl;
		Customer customer(arrivalTime, serviceTime);
		
		int index = freeTellerindex();
		if (index == -1)
		{
			setCustomerToTellerTwo(&customer);
		}
		else
		{
			setCustomerToTellerOne(&customer, index);
		}
		

		 
		Customers.push(customer);
		cout << "----Added Successfully----\n\n" ;
		gobackone();
		

		
	}

	void gobackone()
	{
		char back;
		cout << "Do You want to add new customer ? [y-n] : ";
		cin >> back;

		if (back == 'N' || back == 'n')
		{
			system("cls");
			MainMenu();

		}
		else if (back == 'Y' || back == 'y')
		{
			system("cls");
			AddCustomerQueue();
		}
		else
		{
			gobackone();
		}

	}


	void gobacktwo()
	{
		char back;
		cout << "press any key to return to menu : ";
		cin >> back;
		system("cls");
		MainMenu();
	}



	// if teller is empty (don't have customers)
	void setCustomerToTellerOne(Customer* customer, int index) 
	{
		
		customer->setTellerNumber(Tellers[index].getTellerNumber());
		customer->setWaitingTime(0);
		customer->setLeavingTime(customer->getArrivalTime() + customer->getServiceTime());
		Tellers[index].setLeavingTime(customer->getLeavingTime());
		Tellers[index].setAvailable(false);
		Tellers[index].incrementCustomer();
		Tellers[index].setServiceTellerTime(customer->getServiceTime());
				
	}

	void setCustomerToTellerTwo(Customer* customer)
	{
		int teller_index = 0;
		int minLeavingTime = Tellers[0].getLeavingTime(); // Initialize with the leaving time of the first teller
		for (int i = 1; i < 4; i++)
		{
			if (Tellers[i].getLeavingTime() < minLeavingTime)
			{
				minLeavingTime = Tellers[i].getLeavingTime();
				teller_index = i;
			}
		}
		if (customer->getArrivalTime() > Tellers[teller_index].getLeavingTime())
		{
			customer->setWaitingTime(0);
			customer->setLeavingTime(customer->getArrivalTime() + customer->getServiceTime());
		}
		else
		{
			customer->setWaitingTime(Tellers[teller_index].getLeavingTime() - customer->getArrivalTime());
			customer->setLeavingTime(Tellers[teller_index].getLeavingTime() + customer->getServiceTime());

		}
			

		//customer->setWaitingTime(abs(Tellers[teller_number].getLeavingTime() - customer->getArrivalTime()));
		customer->setTellerNumber(Tellers[teller_index].getTellerNumber());
		Tellers[teller_index].setLeavingTime(customer->getLeavingTime());
		Tellers[teller_index].incrementCustomer();
		Tellers[teller_index].setServiceTellerTime(customer->getServiceTime());
	}


	int freeTellerindex()
	{
		for (int i = 0; i < 4; i++)
		{
			if (Tellers[i].getAvailable())
				return i;
		}
		return -1;
		  // comment
	}
	 


	void showCustomers()
	{
		queue<Customer> temp = Customers;
		while (!temp.empty())
		{
			
			cout << "ID : " << temp.front().getID() << "\t" << "Arrival Time : " << temp.front().getArrivalTime() << "\t" << "Service Time : " << temp.front().getServiceTime() << "\t" << "Waiting Time : " << temp.front().getWaitingTime() << "\t" << "Leaving Time : " << temp.front().getLeavingTime() << "\t" << "Teller Number : " << temp.front().getTellerNumber() <<endl;
			temp.pop();

		}

		gobacktwo();
	}



	// case 3

	void showTellers()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << "Teller Number : " << Tellers[i].getTellerNumber() << "\t" << "service Time : " << Tellers[i].getServiceTellerTime()<< "\t" << "Number of Customers : " << Tellers[i].getCustomersNumber() << endl << endl;

		}
		gobacktwo();
	}


	//start of statistics

	void statistics()
	{
		
		cout << "Average Waiting Time =  " << AverageWaitingTime() << endl << endl;
		cout << "Maximum Waiting Time =  " << MaxWaitingTime() << endl << endl;
		cout << "Average Service Time =  " << AverageServiceTime() << endl << endl;
		cout << "Maximum Service Time =  " << MaxServiceTime() << endl << endl;


	}

	float AverageWaitingTime()
	{
		int count = 0;
		float sum = 0;
		queue<Customer> temp = Customers;
		while (!temp.empty())
		{
			sum += temp.front().getWaitingTime();
			count++;
			temp.pop();
		}
		if (count == 0)
			return 0;

		float average = sum / count;
		return average;
	}





	int MaxWaitingTime()
	{
		queue<Customer> temp = Customers;
		if (temp.empty())
			return 0;

		int maxWaitingTime = temp.front().getWaitingTime();
		temp.pop();
		while (!temp.empty())
		{
			if (temp.front().getWaitingTime() > maxWaitingTime)
				maxWaitingTime = temp.front().getWaitingTime();

			temp.pop();
		}

		return maxWaitingTime;
	}




	float AverageServiceTime()
	{
		int count = 0;
		float sum = 0;
		queue<Customer> temp = Customers;
		while (!temp.empty())
		{
			sum += temp.front().getServiceTime();
			count++;
			temp.pop();
		}
		if (count == 0)
			return 0;

		float average = sum / count;
		return average;
	}


	int MaxServiceTime()
	{
		queue<Customer> temp = Customers;
		if (temp.empty())
			return 0;

		int maxServiceTime = temp.front().getServiceTime();
		temp.pop();
		while (!temp.empty())
		{
			if (temp.front().getServiceTime() > maxServiceTime)
				maxServiceTime = temp.front().getServiceTime();

			temp.pop();
		}

		return maxServiceTime;
	}


	// end of statistics
};


