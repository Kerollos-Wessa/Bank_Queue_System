#pragma once
#include <iostream>
using namespace std;

class Customer
{
private:
	static int ID;
    int id;
	int arrivalTime;
	int serviceTime;
	int waitingTime;
	int tellerNumber;
	int leavingTime;

public :


	Customer(int arrivalTime, int serviceTime)
	{
		this->id = ++ID;
		this->arrivalTime = arrivalTime;
		this->serviceTime = serviceTime;
	}

	Customer()
	{
		this->id = ++ID;
	}
	

	/*
	void AddCustomer(int id, int arrivalTime, int serviceTime)
	{
		this->id = id;
		this->arrivalTime = arrivalTime;
		this->serviceTime = serviceTime;
	}
	*/

	void Display()
	{
		cout << "ID : " << id << "\tarrival Time : " << arrivalTime << "\tservice Time : " << serviceTime << endl;
	}

	int getID()
	{
		return this->id;
	}

	void setTellerNumber(int number)
	{
		this->tellerNumber = number;
	}

	int getTellerNumber()
	{
		return this->tellerNumber;
	}

	void setArrivalTime(int time)
	{
		this->arrivalTime = time;
	}

	int getArrivalTime()
	{
		return this->arrivalTime;
	}

	void setServiceTime(int time)
	{
		this->serviceTime = time;
	}

	int getServiceTime()
	{
		return this->serviceTime;
	}

	void setLeavingTime(int time)
	{
		this->leavingTime = time;
	}

	int getLeavingTime()
	{
		return this->leavingTime;
	}

	void setWaitingTime(int time)
	{
		this->waitingTime = time;
	}

	int getWaitingTime()
	{
		return this->waitingTime;
	}

	

};

