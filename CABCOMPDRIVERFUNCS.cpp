#ifndef CMDF_H
#define CMDF_H
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
#include "CABCOMPMAINFUNCS.cpp"
#include "CABCOMPFILING.cpp"
#include "CABCOMPCABFUNCS.cpp"
#include "CABCOMPBOOKINGFUNCS.cpp"
#include "Driver.h"
#include "Driver.cpp"

using namespace std;

void CabCompany::DriversManagementMenu(){
	system("cls");
	int Sel;
	cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "\t\t\t\t\t\tDrivers Management."<< endl;
	cout << "\t\t\t1. Add Driver."<<endl;
	cout << "\t\t\t2. View Drivers."<<endl;
	cout << "\t\t\t3. View Free Drivers(Not Driving)."<<endl;
	cout << "\t\t\t4. Remove From Drivers."<<endl;
	cout <<"\t\t\t0. Back"<<endl;
	cout << "\t\t\tPlease Enter Your Choice: ";
	cin >> Sel;
	switch(Sel){
		case 0:
			fflush(stdin);
			MainMenu();
			break;
		case 1:
			fflush(stdin);
			CabCompany::addDriver();
			DriversManagementMenu();
			break;
		case 2:
			fflush(stdin);
			CabCompany::showDrivers();
			DriversManagementMenu();
			break;
		case 3:
			fflush(stdin);
			CabCompany::viewAvailableDrivers();
			DriversManagementMenu();
			break;
		case 4:
			fflush(stdin);
			CabCompany::removeDriver();
			DriversManagementMenu();
			break;
		default:
			DriversManagementMenu();			
	}
}




void CabCompany::addDriver(){
	system("cls");
	Driver* D;
	string EiD,Name,License;
	int Age,workingHours;
	double Pay;
	cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "\t\t\t\t\t\tAdd a Driver."<< endl;
	cout << "\t\t\tDriver's Name: ";
	getline(cin,Name);
	fflush(stdin);
	cout << "\t\t\tDriver's Licencse Registration Number: ";
	getline(cin,License);
	fflush(stdin);
	cout << "\t\t\tDriver's Age: ";
	cin >> Age;
	fflush(stdin);
	cout << "\t\t\tDriver's Employee ID: ";
	getline(cin,EiD);
	fflush(stdin);
	cout << "\t\t\tDriver's Working Hours: ";
	cin >> workingHours;
	fflush(stdin);
	cout << "\t\t\tDriver's Pay: ";
	cin >> Pay;
	fflush(stdin);
	D = new Driver (Name,EiD,Pay,Age,workingHours,License);
	totalDrivers++;
	D->addtoDataBase();
	D->addtoRecords();
	Drivers.push_back(D);
	Sleep(1000);
	cout << "\n\t\t\tDriver Added";
	Sleep(1000);
}

void CabCompany::showDrivers(){
	system("cls");
	cout <<"\t\t\t\t\t\tView Drivers."<< endl;
	int ESC=0;
	while(ESC<totalDrivers){
		if (!Drivers[ESC]==NULL){
			Drivers[ESC]->Print();
		}
		ESC++;
	}
	system("pause");
	
}

void CabCompany::viewAvailableDrivers(){
	system("cls");
	bool EXISTS=false;
	cout <<"\t\t\t\t\t\tAvailable Drivers."<< endl;
	int ESC=0;
	while(ESC<totalDrivers){
		if (!Drivers[ESC]==NULL){
			if (Drivers[ESC]->isAvailable()){
				EXISTS=true;
				Drivers[ESC]->Print();
			}
		}
		ESC++;
	}
	
	try {
		if (!EXISTS){
			throw 5;
		}
	}
	catch (int Er){
		if (Er==5){
			system("cls");
			cout << "Error# "<<Er<< " No Drivers that are not driving.\n";
		}
	}
	system("pause");
}


void CabCompany::removeDriver(){
	fflush(stdin);
	string EmpID;
	bool Exists=false;
	CabCompany::showDrivers();
	cout <<"\t\t\tPlease Enter Employee ID of Driver you want to Remove: "<< endl;
	getline(cin,EmpID);
	fflush(stdin);
	for (int i=0;i<totalCabs;i++){
		if (!Cabs[i]==NULL){
			if (!Cabs[i]->driver==NULL){
				if (Cabs[i]->driver->getemployeeId()==EmpID){
					Exists=true;
					cout << Cabs[i]->getCabId() << "Now Has No Driver. "<<endl;
					Cabs[i]->driver->removeCab();
					Cabs[i]->removeDriver();
				}
			}
		}
	}
	cout << "\t\t\tDriver Data Removed." <<endl;
	for (int i=0;i<totalDrivers;i++){
		if (!Drivers[i]==NULL){
			if (Drivers[i]->getemployeeId()==EmpID){
				Exists=true;
				delete Drivers[i];
				Drivers[i]=0;
				cout << "\t\t\tDriver Data Removed." <<endl;
			}		
		}
	}
	try {
		if (!Exists)
		throw 1;
	}
	catch (int Er){
		cout << "Error#\t" << Er << "\tDriver By Employee ID: "<< EmpID << "\tDoesnt Exist."<<endl;
	}
	Sleep(1000);
	system("pause");
}


#endif
