#ifndef CMCF_H
#define CMCF_H
/*
	Name: CABMANAGEMENTSIMULATION
	Copyright: SAADAHMED
	Author: Saad Ahmed, Osama Arif, Faizan Rasool
	Date: 27/05/16 22:50
	Description: Final Builds
*/
//INCLUDE FILES THAT CONTAIN OTHER FUNCTIONS OF THE CABCOMPANYCLASS
#include <iostream>
#include <windows.h>
#include <vector>
#include <time.h>
#include "CabCompany.h"
#include "Booking.h"
#include "Customer.h"
#include "CabCompany.h"
#include "Cab.cpp"
#include "Cab.h"
#include "CABCOMPMAINFUNCS.cpp"
#include "CABCOMPFILING.cpp"
#include "CABCOMPBOOKINGFUNCS.cpp"
#include "CABCOMPDRIVERFUNCS.cpp"
using namespace std;

//CABSMANAGEMENTMENU GIVES ACCESS TO FUNCTIONS
//THAT ARE MANAGING CABS CONTAINED BY THE COMPANY
void CabCompany::CabsManagementMenu (){
		system("cls");
		int Sel;
		cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "\t\t\t\t\t\tCabs Management."<< endl;
		cout <<endl<<"\t\t\t0. Back";
		cout <<endl<<"\t\t\t1. View all Cabs."<<endl<<"\t\t\t2. Add Cabs."
		<<endl<<"\t\t\t3. Check Available Cabs."
		<<endl<<"\t\t\t4. Search Cab By ID."
		<<endl<<"\t\t\t5. Show Cabs Without Drivers."
		<<endl<<"\t\t\t6. Remove Cab."<<endl;
		cout << "\t\t\tPlease Enter Your Choice: ";
		cin >> Sel;
		switch(Sel){
			case 0:
				fflush(stdin);
				MainMenu();
				break;
			case 1:
				fflush(stdin);
				showCabs();
				CabsManagementMenu();
				break;
			case 2:
				fflush(stdin);				
				addCab();
				CabsManagementMenu();
				break;
			case 3:
				fflush(stdin);
				fflush(stdin);
				showAvailableCabs();
				CabsManagementMenu();
				break;
			case 4:
				fflush(stdin);
				searchCabByID();
				CabsManagementMenu();
				break;
			case 5:
				fflush(stdin);
				CabCompany::showCabsWithoutDrivers();
				CabsManagementMenu();
				break;
			case 6:
				fflush(stdin);
				CabCompany::removeCab();
				CabsManagementMenu();
				break;
			default:
				CabsManagementMenu();	
		}
}

//FUNCTIONS SHOWS AVAILABLE CABS THAT ARE NOT BOOKED
//IS CALLED WHEN USER WANTS TO VIEW ALL AVAILABLE CABS

void CabCompany::showAvailableCabs(){
		system("cls");
			cout <<"\t\t\t\t\t\tAvailable Cabs."<< endl;
			int Loop = 0;
			while (Loop<totalCabs){
				if (!Cabs[Loop]==NULL){
					if (!Cabs[Loop]->getBookingAssignment()){
						Cabs[Loop]->Print();	
						Sleep(500);
					}
				}
				Loop++;
			}
		system("pause");
}


// DYNAMICALLY CREATES A CAB
// PLACES IT INSIDE THE VECTOR OF CAB POINTERS
// DOESNOT RETURN ANYTHING USED IN CABSMANAGEMENTMENU ONLY

void CabCompany::addCab(){
		system("cls");
			Cab* newCab;
			char Type;
			double fuelCap,totalFuel;
			string registNo,modelName;
						
			cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
			<<"\t\t\t\t\t\tEnter a new Cab's Information."<< endl;
			string regID;
			
			
			
			fflush(stdin);
			cout << "\t\t\tModel Name: ";
			getline(cin,modelName);
			fflush(stdin);
			
			cout << "\t\t\tRegistration ID: ";
			getline(cin,registNo);
			fflush(stdin);
			
			
			cout << "\t\t\tFuel Capacity: ";
			cin >> fuelCap;
			
			cout << "\t\t\tTotal Fuel Currently: ";
			cin >> totalFuel;
			
			newCab = new Cab (fuelCap,totalFuel,registNo,modelName);
			newCab->addtoDataBase();
			newCab->addtoRecords();
			Cabs.push_back(newCab);
			totalCabs++;
			newCab=NULL;
			Sleep(1000);
			cout << "\n\t\t\tAdded Information."<<endl;
			Sleep(1000);
}

//FUNCTION JUST USED JO SHOW ALL CABS AS WELL AS THEIR STATUSES
//RESIDING INSIDE THE VECTOR OF CABS
void CabCompany::showCabs(){
		system("cls");
		bool EXISTS=false;
		cout <<"\t\t\t\t\t\tView Cabs."<< endl;
		int Loop = 0;
			while (Loop<=totalCabs){
				if (!Cabs[Loop]==NULL){
					Cabs[Loop]->Print();	
					Sleep(500);
					EXISTS-true;
				}
				Loop++;
		}
		try{
			if (!EXISTS)
			{
				throw 1;
			}
		}
		catch (int Er){
			cout << "Exception #"<<Er<<" Please add Cabs\n";
		}
		system("pause");
}

void CabCompany::searchCabByID(){
	string CABID;
	bool Exists=false;
	cout << "\t\t\tPlease Enter CABID to Search: ";
	fflush(stdin);
	getline(cin,CABID);
	for (int i=0;i<totalCabs;i++){
		if (!Cabs[i]==NULL){
			if (Cabs[i]->getCabId()==CABID){
				Cabs[i]->Print();
				Exists=true;
			}
		}
	}
	try{
		if (!Exists)
		throw 1;
	}
	catch(int Er){
		system("cls");
		cout << "ERROR: #"<<Er<<"\nCab By Id "<<CABID<< " doesnt Exist."<<endl;
	}
	system("pause");
}

void CabCompany::showCabsWithoutDrivers(){
	bool EXISTS=false;
	for (int i=0;i<totalCabs;i++){
		if (!Cabs[i]==NULL){
			if (Cabs[i]->driver==NULL){
				Cabs[i]->Print();
				EXISTS=true;
			}
		}
	}
	try {
		if (!EXISTS){
			throw 3;
		}
	}
	catch (int Er){
		if (Er==3){
			system("cls");
			cout << "Error# "<<Er<< " No Cabs Wihtout Drivers.\n";
		}
	}
	system("pause");
}

void CabCompany::removeCab(){
	string CID;
	bool EXISTS=false;
	bool Booked=false;
	cout << "\t\t\tEnter Cab ID You Want to Delete: ";
	fflush(stdin);
	getline(cin,CID);
	try{
		for (int i=0;i<totalBookings;i++){
			if (!Bookings[i]==NULL){
				if (Bookings[i]->BookingCab!=NULL){
					if (Bookings[i]->BookingCab->getCabId()==CID){
						EXISTS=true;
						throw 1;
					}
				}
			}
		}
		throw 7;
	}
	catch (int Er){
		if (Er==1){
			system("cls");
			cout << "Error# "<<Er<<" First Complete Booking then Delete Cab.\n";
		}
		else {
			
	for (int i=0;i<totalDrivers;i++){
		if (!Drivers[i]==NULL){
			if (Drivers[i]->isDriving!=NULL){
				if (Drivers[i]->isDriving->getCabId()==CID){
					Drivers[i]->removeCab();
					Drivers[i]->Print();
					cout << "Driver Now Available\n";
				}
			}
		}
	}
	for (int i=0;i<totalCabs;i++){
		if (!Cabs[i]==NULL){
			if (Cabs[i]->getCabId()==CID){
				EXISTS=true;
				delete Cabs[i];
				Cabs[i]=0;
				cout << "Deleted Cab\n";
				}
			}
	}
		}
	}
		try{
			if (!EXISTS)	
			throw 10;
		}
		catch(int Er){
			if (Er==10){
				system("cls");
				cout << "Error# "<<"Cab with ID "<<CID<<"doesnt exist.\n";
			}
		}
	system("pause");
	
}
#endif
