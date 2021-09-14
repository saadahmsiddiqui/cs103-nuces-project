#ifndef DRIVERIMP_H
#define DRIVERIMP_H
#include<iostream>
#include "Driver.h"
#include "Cab.h"
using namespace std;

Driver::~Driver()
{
	isDriving = NULL;
}

//ostream& operator <<(ostream &out , const Driver &obj)
//{
//	out << endl;
//	out<<"\t\t\tName:"<<obj.Name<<endl;
//	out<<"\t\t\tPay:"<<obj.Pay<<endl;
//	out<<"\t\t\tEmployeeId: "<<obj.employeeId<<endl;
//	out<<"\t\t\tAge: "<<obj.Age<<endl;
//	out<<"\t\t\tWorking Hours: "<<obj.workingHours<<endl;
//	if(obj.isAvailable())
//	out<<"\t\t\tDriver Status: Available"<<endl;	
//	else
//	{
//		out<<"\t\t\tDriver Status: Not Available"<<endl;
////	out<<"\t\t\tDriving Cab: "<<obj.isDriving->getCabId()<<endl;
//	}
//}

bool Driver::isAvailable () const
{
	if (isDriving==NULL){
		return true;
	}
	else {
		return false;
	}
}

Driver::Driver(string _name , string _empId , double _pay , int _age , int _workingHrs , string _license ):
Employee(_name , _empId , _pay , _age , _workingHrs){
			license = _license;
			this->isDriving= NULL;
}

string Driver::getLicense()
{
	return license;
}

void Driver::setCab(Cab* toSet)
{
	isDriving = toSet;
}

void Driver::removeCab()
{
	if (isDriving!=NULL){
		isDriving=NULL;
	}
}

void Driver::addtoDataBase(){
		fstream Out;
		Out.open("Drivers.csv",ios::app);
		Out << employeeId << ','
		<< Name << ','
		<< license << ','
		<< Age << ','
		<< workingHours << ','
		<< Pay << '\n';
		Out.close();
}


void Driver::addtoRecords(){
		fstream Out;
		Out.open("DriverRecords.csv",ios::app);
		Out << employeeId << ','
		<< Name << ','
		<< license << ','
		<< Age << ','
		<< workingHours << ','
		<< Pay << '\n';
		Out.close();
}

void Driver::Print(){
	cout << endl;
	cout<<"\t\t\tName:"<<Name<<endl;
	cout<<"\t\t\tPay:"<<Pay<<endl;
	cout<<"\t\t\tEmployeeId: "<<employeeId<<endl;
	cout<<"\t\t\tAge: "<<Age<<endl;
	cout<<"\t\t\tWorking Hours: "<<workingHours<<endl;
	if(isAvailable())
	cout<<"\t\t\tDriver Status: Available"<<endl;	
	else
	{
		cout<<"\t\t\tDriver Status: Driving"<<endl<<"\t\t\tCab No : "<<isDriving->getCabId()<<endl<<endl;
	}
}


#endif
