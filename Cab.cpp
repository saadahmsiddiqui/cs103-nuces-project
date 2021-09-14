#include<iostream>
#include "Cab.h"
#include "Driver.h"
#include "CabCompany.h"
#define FUEL_RATE 70
#include<cstring>
#include <string>
using namespace std;

//Constructor
Cab::Cab(double fuelCap , double ttlFuel , string rNum , string _car ) :fuelCapacity(fuelCap) , regNumber(rNum)
{
	ostringstream ss;
    ss << this->NumCabsCreated+2500;
	cabId = ss.str();
	totalFuel=ttlFuel;
	odometer=0;
	timer=0;
	car = _car; 
	status = 1;
	driver = NULL;
	BookingAssignment=false;
	NumCabsCreated++;
}

double Cab::Drive (double Distance,double Charges){
	odometer+=Distance;
	return Distance+Charges;
}

void Cab::removeDriver(){
	driver = NULL;
}

void Cab::setStatus(bool St){
	status=St;
}

void Cab::setOdometer(double _odometer)
{

	odometer = _odometer;
}

void Cab::setTimer(double _timer)
{
	timer = _timer;
}
void Cab::setId(string newId)
{
	cabId=newId;
}


// Getter Functions

void Cab::assignDriver(Driver *driverPtr)
{
	driver = driverPtr;
	status= false;
}


bool Cab::isAvailable() const
{
	return status;
}

string Cab::getCabId(void) const
{
	return cabId;
}

double Cab::getFuelCapacity(void) const
{
	return fuelCapacity;
}

double Cab::getTotalFuel(void) const
{
	return totalFuel;
}
	
string Cab::getRegNumber(void) const
{
	return regNumber;
}

double Cab::getOdometerReading(void) const
{
	return odometer;
}

double Cab::getTimer(void) const
{
	return timer;
}

string Cab::getCarType(void) const
{
	return car;
}


void Cab::Print(){
	cout<<"\nCab Id: "<<cabId<<"\nCab Name: "<<car<<"\nFuel Capacity: "<<fuelCapacity<<"\nTotal Fuel: "<<totalFuel<<"\nRegistration Number: "<<regNumber<<"\nOdometer Reading: "<<odometer<<"\nTimer: "<<timer<<endl;
	if(driver==NULL)
	cout<<"Cab has currently no driver."<<endl;
	else{
		cout<<"Cab is allotted to Driver: "<<driver->getName()<<endl;
		cout<<"Driver's ID: "<<driver->getemployeeId()<<endl;
	}
if (BookingAssignment==true){
		cout << "Booking Status: Booking Assigned."<<endl;
	}
	else{
		cout << "Booking Status: Not Booked."<<endl;
	}
}

//
////Operator Overloading
ostream& operator << (ostream &out , const Cab &obj)
{
	cout<<"\n\t\t\tCab Id: "<<obj.cabId<<"\n\t\t\tCab Name: "<<obj.car<<"\n\t\t\tFuel Capacity: "<<obj.fuelCapacity<<"\n\t\t\tTotal Fuel: "<<obj.totalFuel<<"\n\t\t\tRegistration Number: "<<obj.regNumber<<"\n\t\t\tOdometer Reading: "<<obj.odometer<<"\n\t\t\tTimer: "<<obj.timer<<endl;
	if(obj.driver==NULL)
	out<<"\t\t\tCab has no Driver"<<endl;
	else
	{
		out<<"\t\t\tCab is not available"<<endl;
		out<<"\t\t\tCab is allotted to "<<obj.driver->getName()<<endl;
	}
	if (obj.BookingAssignment==true){
		cout << "\n\t\t\tBooking Assigned."<<endl;
	}
	else{
		cout << "\n\t\t\tNot Booked."<<endl;
	}
}

double operator +(int fuel , Cab &obj)
{
	 return obj.refill(fuel);
}

double operator +(Cab &obj , int fuel )
{
	 return obj.refill(fuel);
}

bool Cab::operator ==(const Cab &obj)
{
	if(obj.cabId==this->cabId)
	return true;
	else 
	return false;
}

bool Cab::operator !=(const Cab &obj)
{
	if(obj.cabId!=this->cabId)
	return true;
	else 
	return false;
}

bool Cab::operator <(const Cab &obj)
{
	if(this->totalFuel<obj.totalFuel)
	return true;
	else return false;
}

bool Cab::operator >(const Cab &obj)
{
	if(this->totalFuel > obj.totalFuel)
	return true;
	else return false;
}

bool Cab::operator >=(const Cab &obj)
{
	if(this->totalFuel >= obj.totalFuel)
	return true;
	else return false;
}

bool Cab::operator <=(const Cab &obj)
{
	if(this->totalFuel <= obj.totalFuel)
	return true;
	else return false;
}


bool Cab::getBookingAssignment(){
	return BookingAssignment;
}

void Cab::setBookingAssigment(bool BookingAssignment){
	this->BookingAssignment=BookingAssignment;
}


//Technical Functions
double Cab::refill(void)
{
	double refillCost;
	if(totalFuel<fuelCapacity)
	{
		refillCost=(fuelCapacity-totalFuel)*FUEL_RATE;
		totalFuel=fuelCapacity;
		return refillCost;
	}
	else return 0;
}

double Cab::refill(double litres)
{
	if(totalFuel+litres<=fuelCapacity)
	{
		totalFuel+=litres;
		return litres*FUEL_RATE;
	}
	return 0;			
}

void Cab::addtoDataBase(){	
	fstream Output;
	Output.open("Cabs.csv",ios::app);
	Output<<cabId<<','<<car<<','<<regNumber<<','<<getFuelCapacity()<<','<<totalFuel<< ',' <<odometer<<','<<timer<<','<<status<<'\n';
	Output.close();
}

void Cab::addtoRecords(){	
	fstream Output;
	Output.open("CabRecords.csv",ios::app);
	Output<<cabId<<','<<car<<','<<regNumber<<','<<getFuelCapacity()<<','<<totalFuel<< ',' <<odometer<<','<<timer<<','<<status<<'\n';
	Output.close();
}

Cab::~Cab()
{
	driver = NULL;
}
char* convert(string ss )
{
	
	int size =ss.size();
	char *arr = new char[size+1];
	for(int i=0; i<size;i++)
	{
		arr[i]=ss[i];
	}
	return arr;
}
