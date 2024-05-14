#pragma once
#include <iostream>
using namespace std;

class Teller
{
private:
	int Number;
	bool available;
	int leavingTime; // leaving time current customer
	int CustomersNumber;
	int TellerTime;

public :
	Teller(int Number, bool available)
	{
		this->Number = Number;
		this->available = available;
	}

	Teller()
	{

	}

	void setAvailable(bool available)
	{
		this->available = available;
	}

	bool getAvailable()
	{
		return this->available;
	}


	void setLeavingTime(int time)
	{
		this->leavingTime = time;
	}

	int getLeavingTime()
	{
		return this->leavingTime;
	}

	int getTellerNumber()
	{
		return this->Number;
	}

	void incrementCustomer()
	{
		this->CustomersNumber++;
	}

	int getCustomersNumber()
	{
		return this->CustomersNumber;
	}

	void setServiceTellerTime(int CustomerService)
	{
		this->TellerTime += CustomerService;
	}

	int getServiceTellerTime()
	{
		return this->TellerTime;
	}


};

