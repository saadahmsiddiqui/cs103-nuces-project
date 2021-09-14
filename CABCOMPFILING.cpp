#ifndef CMF_H
#define CMF_H

/*
	Name: CABMANAGEMENTSIMULATION
	Copyright: SAADAHMED
	Author: Saad Ahmed, Osama Arif, Faizan Rasool
	Date: 27/05/16 22:50
	Description: Final Builds
*/

#include <iostream>
#include <windows.h>
#include <vector>
#include <time.h>
#include "CabCompany.h"
#include "Booking.h"
#include "Customer.h"
#include "Cab.h"
#include "CABCOMPMAINFUNCS.cpp"
#include "CABCOMPCABFUNCS.cpp"
#include "CABCOMPBOOKINGFUNCS.cpp"
#include "CABCOMPDRIVERFUNCS.cpp"
using namespace std;


void CabCompany::WriteCompanyInfo(){
	fstream Out;
	Out.open("CompanyInfo.csv",ios::out);
	Out << "Company Name"<< ',' << CabCompanyName <<'\n'
	<< "Company Account Balance"<< ',' << BankBalance <<'\n'
	<< "Total Bookings " << ',' << totalBookings << '\n'
	<<  "Total Cabs" << ',' << totalCabs <<'\n'
	<< "Total Drivers"	<< ',' << totalDrivers;
	Out.close();
}


void CabCompany::LoadupBookings(){
			fstream Input;
			Input.open("Bookings.csv");
			Booking *B;
			string N,C,P,St,En,Numeric,Bid;
			double Distance,Charges;
			while (Input.good()){
				getline(Input,N,',');
				getline(Input,C,',');
				getline(Input,P,',');
				getline(Input,St,',');
				getline(Input,En,',');
				getline(Input,Numeric,',');
				istringstream DIST (Numeric);
				DIST >> Distance;
				getline(Input,Bid,',');
				getline(Input,Numeric,'\n');
				istringstream CHARGES(Numeric);
				CHARGES >> Charges;
				B = new Booking(N,C,P,Charges,St,En,Bid,Distance,NULL);
				Bookings.push_back(B);
				B=NULL;
				totalBookings++;
			}
		Input.close();
}

void CabCompany::LoadupDrivers(){
	fstream Input;
	string Name,employeeId,licenseNo,NUMERICINPUT;
	double Pay;
	int Age;
	int workingHours;
	Driver* D;
	Input.open("Drivers.csv");
	while(Input.good()){
		getline(Input,employeeId,',');
		getline(Input,Name,',');
		getline(Input,licenseNo,',');
		
		getline(Input,NUMERICINPUT,',');
		istringstream AGEE(NUMERICINPUT);
		AGEE>>Age;
		
		getline(Input,NUMERICINPUT,',');
		istringstream WH(NUMERICINPUT);
		WH>>workingHours;
		
		getline(Input,NUMERICINPUT,'\n');
		istringstream PAYY(NUMERICINPUT);
		PAYY>>Pay;
		D= new Driver(Name,employeeId,Pay,Age,workingHours,licenseNo);
		Drivers.push_back(D);
		totalDrivers++;
		D=NULL;
	}
	Input.close();
}

void CabCompany::LoadupCabs(){
	fstream Input;
	Cab *C;
	string cabId,regNumber,car,NUMERICINP;
	double totalFuel,odometer,timer,fuelCapacity;
	bool status;
	Input.open("Cabs.csv");
	while(Input.good()){
		getline(Input,cabId,',');
		getline(Input,car,',');
		getline(Input,regNumber,',');
		
		
		getline(Input,NUMERICINP,',');
		istringstream FUC(NUMERICINP);
		FUC>>fuelCapacity;
		
		getline(Input,NUMERICINP,',');
		istringstream TOTALCAP(NUMERICINP);
		TOTALCAP>>totalFuel;
		
		getline(Input,NUMERICINP,',');
		istringstream ODO(NUMERICINP);
		ODO>>odometer;
		
		getline(Input,NUMERICINP,',');
		istringstream TIMER(NUMERICINP);
		TIMER>>timer;
		
		getline(Input,NUMERICINP,'\n');
		if (NUMERICINP[0]==0){
			status = false;
		}
		else {
			status = true;
		}
		C = new Cab(fuelCapacity,totalFuel,regNumber,car);
		C->setOdometer(odometer);
		C->setTimer(timer);
		C->setStatus(status);
		C->setId(cabId);		
		Cabs.push_back(C);
		totalCabs++;
		C=NULL;
	}
	Input.close();
}

void CabCompany::WriteCurrentValuestoDataBase(){
	remove ("Cabs.csv");
	remove ("Bookings.csv");
	remove ("Drivers.csv");
	remove ("CompanyInfo.csv");
	CabCompany::WriteCompanyInfo();
	for (int ESC=0;ESC<totalCabs;ESC++){
		if (Cabs[ESC]!=NULL){
			Cabs[ESC]->addtoDataBase();
		}
	}
	for (int ESC=0;ESC<totalDrivers;ESC++){
		if (Drivers[ESC]!=NULL){
			Drivers[ESC]->addtoDataBase();
		}
	}
	for (int ESC=0;ESC<totalBookings;ESC++){
		if (Bookings[ESC]!=NULL){
			Bookings[ESC]->addToDataBase();
		}
	}
	
}
#endif
