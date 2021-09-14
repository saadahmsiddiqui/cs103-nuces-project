#ifndef Cab_H
#define Cab_H
#include<iostream>
#include<fstream>
#include "Driver.h"
using namespace std;
class Driver;

class Cab
{
	friend class CabCompany;
	protected:
		static int NumCabsCreated;
		string cabId,regNumber,car;
		const double fuelCapacity;
		double totalFuel,odometer,timer;
		bool status;
		Driver *driver;
		bool BookingAssignment;
	public:
		void setStatus(bool);
		Cab(double fuelCap , double ttlFuel, string rNum , string _car ); 
		Cab();
		~Cab();
		bool getBookingAssignment();
		void setBookingAssigment(bool);
//		virtual void drive(void)=0;
		void assignDriver(Driver *driverPtr);
		void removeDriver();
		bool isAvailable(void) const;
		double refill(void);
		void addtoRecords();
		double refill(double litres);
		string getCabId(void) const;
		void setId(string newId);
		double getFuelCapacity(void) const;
		double getTotalFuel(void) const;
		string getRegNumber(void) const;
		double getOdometerReading(void) const;
		double getTimer(void) const;
		string getCarType(void) const;
		void addtoDataBase();
		void setOdometer(double);
		void setTimer(double);
		void Print();
		double Drive(double,double);
		bool operator >(const Cab &obj); //Will compare the total fuel of both the cabs
		bool operator <(const Cab &obj); //Will compare the total fuel of both the cabs
		bool operator >=(const Cab &obj); //Will compare the total fuel of both the cabs
		bool operator <=(const Cab &obj);
		
		bool operator ==(const Cab &obj); //Will compare cab ID
		bool operator !=(const Cab &obj); //Will compare the total fuel of both the cabs
		
		friend double operator +(int fuel , Cab &obj); //Will add 'fuel' amount of fuel in the cab
		friend double operator +(Cab &obj , int fuel );
		friend ostream& operator << (ostream &out , const Cab &obj); //Will display all the characterstics of cab
		void storeCab();
		friend void search();
		void incrementOdometer(double);
};

int Cab::NumCabsCreated=0;
char* convert(string ss );
#endif
