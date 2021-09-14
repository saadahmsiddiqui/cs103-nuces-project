#ifndef DRIVER_H
#define DRIVER_H	
#include<iostream>
#include "Employee.h"
#include "cab.h"
using namespace std;
class Cab;

class Driver:public Employee{
	
	friend class CabCompany;
	protected:
		Cab* isDriving;
		string license;
	public:
		bool isAvailable() const;
		Driver(string _name , string _empId , double _pay , int _age , int _workingHrs , string _license );
		string getLicense();
		void setCab(Cab* toSet);
		void removeCab();
		virtual void Print();
		void addtoDataBase();
		void addtoRecords();
		~Driver();
		string getEmpID();
		friend ostream& operator << (ostream &out , const Driver &obj); //Will display all the characterstics of cab
};

#endif
