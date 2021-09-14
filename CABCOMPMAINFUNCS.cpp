#ifndef CMMF_H
#define CMMF_H
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
#include "CABCOMPFILING.cpp"
#include "CABCOMPCABFUNCS.cpp"
#include "CABCOMPBOOKINGFUNCS.cpp"
#include "CABCOMPDRIVERFUNCS.cpp"
using namespace std;


CabCompany::CabCompany(string CompanyName,double Balance){
			this->totalBookings=0;
			this->totalCabs=0;
			this->totalDrivers=0;
			this->CabCompanyName=CompanyName;
			BankBalance = Balance;
}

CabCompany::CabCompany(string CompanyName){
			this->totalBookings=0;
			this->totalCabs=0;
			this->totalDrivers=0;
			this->CabCompanyName=CompanyName;
			BankBalance = 0;
}


void CabCompany::StartupScreen(){
	char CH;
	cout << "Load Previous Data? Y/N ";
	cin >> CH;
	try{		
		if (CH=='y'||CH=='Y'){
		LoadupBookings();
		LoadupDrivers();
		LoadupCabs();
		
		if (!totalBookings==0){
			delete Bookings[totalBookings-1];
			Bookings[totalBookings-1]=0;
			totalBookings--;	
		}
		if (!totalCabs==0){
			delete Cabs[totalCabs-1];
			Cabs[totalCabs-1]=0;
			totalCabs--;
		}
		if (!totalDrivers==0){
			delete Drivers[totalDrivers-1];
			Drivers[totalDrivers-1]=0;
			totalDrivers--;
		}
		CabandDriverAssignment();
		cout << "Please Wait Loading. . . ";
		Sleep(5550);
		fflush(stdin);
		MainMenu();
		}
		else {
			throw 2;
		}
	}
	catch (int Ex){
		remove("Bookings.csv");
		remove("Cabs.csv");
		remove("Driver.csv");
		remove("CompanyInfo.csv");
		cout << "Resetting and Starting Again. . . ";
		Sleep(5000);
		MainMenu();
	}
}
void CabCompany::MainMenu(){
		//8B//7C//FC
		system("Color E0");
		string Option_Select;
		system("cls");
		cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<
		"\t\t\t\t\t\t"<<this->CabCompanyName<<" CabCompany."<< endl<<
		"\t\t\t1. Manage Cabs"<<endl<<
		"\t\t\t2. Manage Drivers."<<endl<<"\t\t\t3. Manage Bookings."<<endl<<
		"\t\t\t4. Check Company Info"<<endl<<"\t\t\t5. Exit"<<endl;
		cout << "\t\t\tPlease Enter Your Choice: ";
		int Sel;
		cin >> Sel;
		switch(Sel){
			case 1:
				system("cls");
				fflush(stdin);
				CabsManagementMenu();
				break;
			case 2:
				system("cls");
				fflush(stdin);
				DriversManagementMenu();
				break;
			case 3:
				system("cls");
				fflush(stdin);
				BookingsManagementMenu();
				break;
			case 4:
				system("cls");
				fflush(stdin);
				showInfo();
				MainMenu();	
				break;
			case 5:
				system("cls");
				Sleep(1000);
				cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "\t\t\t\t\tProject By: Saad Ahmed, Osama Arif And Faizan Rasool."<<endl;
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				Sleep(2000);
				break;
			default:
				MainMenu();
		}
}

void CabCompany::showInfo(){
		cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "\t\t\tCompany Name: "<<CabCompanyName<<endl<<
		"\t\t\tTotal Drivers: "<<totalDrivers<<endl<<"\t\t\tTotal Cabs: "<<totalCabs<<endl<<
		"\t\t\tTotal Number of Bookings: "<<totalBookings<<endl
		<<"\t\t\tAccount Balance: "<<BankBalance<<endl<<"\t\t\t";
		system("pause");
}

CabCompany::~CabCompany(){
		int Esc = 0;
		CabCompany::CabandDriverRemoval();
		CabCompany::WriteCurrentValuestoDataBase();
		for (int ESC=0;ESC<totalBookings&&totalBookings>0;ESC++){
			if (Bookings[ESC]!=NULL){
				delete Bookings[ESC];
				Bookings[ESC]=0;
			}
		}
		for (int ESC=0;ESC<totalCabs&totalCabs>0;ESC++){
			if (Cabs[ESC]!=NULL){
				delete Cabs[ESC];
				Cabs[ESC]=0;
			}
		}
		for (int ESC=0;ESC<totalDrivers&totalCabs>0;ESC++){
			if (Drivers[ESC]!=NULL){
				delete Drivers[ESC];
				Cabs[ESC]=0;
			}
		}
}

void CabCompany::CabandDriverAssignment(){
	int Loop=0;
	if (totalCabs!=0&&totalDrivers!=0){
		if (totalCabs==totalDrivers && Loop==0){
			while(Loop<totalCabs){
				if (!Cabs[Loop]==NULL&& !Drivers[Loop]==NULL){
					Cabs[Loop]->assignDriver(Drivers[Loop]);
					Drivers[Loop]->setCab(Cabs[Loop]);
				}				
				Loop++;
			}
		}
		if (totalCabs<totalDrivers&&Loop==0){
				while(Loop<totalCabs){
					if (!Cabs[Loop]==NULL&&!Drivers[Loop]==NULL){
					Cabs[Loop]->assignDriver(Drivers[Loop]);
					Drivers[Loop]->setCab(Cabs[Loop]);
					}
					Loop++;
				}
		}
		if (totalDrivers<totalCabs &&Loop==0){
			while(Loop<totalDrivers){
				if (!Cabs[Loop]==NULL&&!Drivers[Loop]==NULL){
					Cabs[Loop]->assignDriver(Drivers[Loop]);
					Drivers[Loop]->setCab(Cabs[Loop]);
				}
				Loop++;	
			}
		}
	}
}


void CabCompany::CabandDriverRemoval(){
	int Loop=0;
	if (totalCabs!=0&&totalDrivers!=0){
		if (totalCabs==totalDrivers && Loop==0){
			while(Loop<totalCabs){
				if (!Cabs[Loop]==NULL&& !Drivers[Loop]==NULL){
					Cabs[Loop]->removeDriver();
					Drivers[Loop]->removeCab();
				}				
				Loop++;
			}
		}
		if (totalCabs<totalDrivers&&Loop==0){
				while(Loop<totalCabs){
					if (!Cabs[Loop]==NULL&&!Drivers[Loop]==NULL){
					Cabs[Loop]->removeDriver();
					Drivers[Loop]->removeCab();
					}
					Loop++;
				}
		}
		if (totalDrivers<totalCabs &&Loop==0){
			while(Loop<totalDrivers){
				if (!Cabs[Loop]==NULL&&!Drivers[Loop]==NULL){
					Cabs[Loop]->removeDriver();
					Drivers[Loop]->removeCab();
				}
				Loop++;	
			}
		}
	}
	try {
		if (totalCabs<totalDrivers){
			throw 1;
		}
		if (totalCabs>totalDrivers){
			throw 2;
		}
	}
	catch(int Er){
		if (Er==1){
			cout << "Warning. No of Drivers Exceed No of Cabs\nSome Drivers are not assigned Cabs";
			Sleep(2000);
			system("pause");
		}
		if (Er==2){
			cout << "Warning. No of Cabs Exceed No of Drivers\nSome Cabs are not assigned Drivers.";
			Sleep(2000);
			system("pause");
		}
	}
}

#endif
