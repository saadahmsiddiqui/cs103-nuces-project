#ifndef CMBF_H
#define CMBF_H
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
#include <string>
#include <vector>
#include <time.h>
#include "CabCompany.h"
#include "Booking.h"
#include "Customer.h"
#include "CabCompany.h"
#include "CABCOMPMAINFUNCS.cpp"
#include "CABCOMPFILING.cpp"
#include "CABCOMPCABFUNCS.cpp"
#include "CABCOMPDRIVERFUNCS.cpp"
#include "CABCOMPBOOKINGFUNCS.cpp"
using namespace std;



//BOOKINGSMANAGEMENTMENU GIVES ACCESS TO FUNCTIONS
//THAT ARE MANAGING BOOKINGS OF CUSTOMERS
void CabCompany::BookingsManagementMenu(){
		int Sel;
		string BID;
		system("cls");
		cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<< "\t\t\t\t\t\tBookings Management."<< endl;
		cout <<"\t\t\t0. Back"<<endl;
		cout <<"\t\t\t1. Add Booking"<<endl;
		cout <<"\t\t\t2. View Booking"<<endl;
		cout <<"\t\t\t3. Remove Booking"<<endl;
		cout <<"\t\t\t4. Search Booking By ID"<<endl;
		cout <<"\t\t\t5. Assign Cab to Booking By ID"<<endl;
		cout << "\t\t\tPlease Enter Your Choice: ";
		cin >> Sel;
		switch(Sel){
			case 0:
				fflush(stdin);
				MainMenu();
				break;
			case 1:
				fflush(stdin);
				addBooking();
				BookingsManagementMenu();
				break;
			case 2:	
				fflush(stdin);
				system("cls");
				int CHECK;
				cout <<endl<<endl<<endl<<endl
				<<endl<<endl<<endl<<endl
				<<endl<<endl<< "\t\t\t\t\t\tView Bookings.\n\t\t\t1.With Customer Info.\n\t\t\t2.Without Customer Info\n\t\t\t3.With Customer and Cab Info\n\t\t\tPlease Enter Your Choice. . ."; 
				cin>> CHECK;
				showBookings(CHECK);
				fflush(stdin);
				BookingsManagementMenu();			
				break;
			case 3:
				fflush(stdin);
				removeBooking();
				fflush(stdin);
				BookingsManagementMenu();
				break;
			case 4:
				fflush(stdin);
				cout << "\t\t\tEnter Booking ID To Search: ";
				getline(cin,BID);
				searchBookingByID(BID);
				fflush(stdin);
				BookingsManagementMenu();
				break;
			case 5:
				AssignCab ();
				BookingsManagementMenu();
				break;
			default:
				BookingsManagementMenu();
		}
}

// DYNAMICALLY CREATES A BOOKING
// PLACES IT INSIDE THE VECTOR OF BOOKING POINTERS
// DOESNOT RETURN ANYTHING USED IN BOOKINGSMANAGEMENTMENU ONLY
void CabCompany::addBooking(){
			Booking *B;
			string Name,Phno,CNIC,Start,End,BookingID;
			double Charges,Dist;
			int cabtoAppoint;
			bool CabAvailable=false;			
			fflush(stdin);
			system("cls");
			cout <<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl
			<<"\t\t\tEnter Customer's Name: ";
			getline(cin,Name);
			fflush(stdin);
			cout <<"\t\t\tEnter Customer's CNIC : ";
			getline(cin,CNIC);
			fflush(stdin);
			cout <<"\t\t\tEnter Customer's Phone Number : ";
			getline(cin,Phno);
			fflush(stdin);
			cout <<"\t\t\tEnter Customer's Starting Point : ";
			getline(cin,Start);
			fflush(stdin);
			cout <<"\t\t\tEnter Customer's Arrival Point : ";
			getline(cin,End);
			fflush(stdin);
			cout <<"\t\t\tEnter Booking's ID: ";
			cin>> BookingID;
			fflush(stdin);
			cout <<"\t\t\tEnter Route's Distance: ";
			cin>> Dist;
			fflush(stdin);
			cout <<"\t\t\tEnter Route's Fare Charge: ";
			cin>> Charges;
			fflush(stdin);
			Sleep(1000);
			
			for (int ESC =0;ESC<totalCabs;ESC++){
				if(!Cabs[ESC]==NULL){
					if(Cabs[ESC]->isAvailable()){
						cabtoAppoint=ESC;
						ESC=totalCabs+5;		
						CabAvailable=true;
					}
				}
			}
			try {
				if (!CabAvailable){
					throw 5;
				
				}
				else{
					B = new Booking(Name,CNIC,Phno,Charges,Start,End,BookingID,Dist,Cabs[cabtoAppoint]);
					Bookings.push_back(B);
					B->addToDataBase();
					B->addToRecords();
					B=NULL;
					totalBookings++;
					cout <<"\t\t\tBooking Added."<<endl;
					Sleep(1000);		
				}
			}
			catch (int Er){
				if (Er==5){
					cout << "Exception #"<<Er<<endl;
					cout << "Cab is Not Available.\nPlease Complete Current Bookings and Try Again.\n";
					system("cls");
					Sleep(1000);
				}
			}
}


//SHOWS ALL THE BOOKINGS CURRENTLY AVAILABLE 
//WHICH ARE NOT REMOVED
//PARAMETERS DECIDE WHETHER TO SHOW ONLY BOOKING DATA OR CUSTOMER DATA
// 1 = SHOW WITH CUSTOMER DATA
// 2 = SHOW WITHOUT CUSTOMER DATA AND CAB DATA
// 3 = SHOW WITH CUSTOMER DATA AND CAB DATA
void CabCompany::showBookings(int CHECK){
		
		try{
			if (CHECK>3||CHECK<1)
			throw 2;
		}			
		catch(int Er){
			if (Er==2)
			cout << "Exception #" <<Er<<" Invalid Parameter passed.\n";
		}
		system("cls");
		int Esc=0;
		while(Esc<totalBookings){
				if (!Bookings[Esc]==NULL){
					if (CHECK==2){
						cout << *Bookings[Esc];					
					}
					else if (CHECK==1){
						Bookings[Esc]->PrintCustomerInfo();
						cout << *Bookings[Esc];
					}
					else if (CHECK==3){
						Bookings[Esc]->PrintCustomerInfo();
						cout << *Bookings[Esc];
						if (Bookings[Esc]->CabGiven()){
							Bookings[Esc]->PrintCabInfo();
						}
						else {
							cout << "\t\t\tCab Not Given."<<endl;
						}
					}
				}
				Esc++;
		}
		system("PAUSE");
}


//FOR REMOVING A BOOKING FROM THE CAB CLASS USING ITS ID AND SETTING THE POINTER INSIDE THE VECTOR EQUALS TO NULL
//DYNAMICALLY DELETING MEMORY (DYNAMICALLY ALLOCATED MEMORY)
void CabCompany::removeBooking(){
			
			system("cls");
			bool Exists=false;
			string ID;
			showBookings(1);
			fflush(stdin);
			cout << "\t\t\tPlease Enter Desired Booking ID to Remove: ";
			getline(cin,ID);
			Sleep(2500);
			int Loop=0;
			while(Loop<totalBookings){
				if (!Bookings[Loop]==NULL){
					if (Bookings[Loop]->getBookingID()==ID){
						Exists=true;
						if (!Bookings[Loop]->BookingCab==NULL){
									Bookings[Loop]->BookingCab->setBookingAssigment(0);
									BankBalance+=Bookings[Loop]->BookingCab->Drive(Bookings[Loop]->Distance,Bookings[Loop]->Charges);
									Bookings[Loop]->removeCab();
									delete Bookings[Loop];
									Bookings[Loop]=NULL;
									cout << "\t\t\tCab Now Available\n\t\t\tBooking Removed.\n";	
						}
					}
				}
				Loop++;
			}
			try{	
				if (!Exists)
				throw 1;
			}
			catch(int Er){
			cout << "ERROR: #"<<Er<<"\nBooking Can not be assigned\nBooking By Id "<<ID<< " doesnt Exist."<<endl;
			}
		system("pause");
}


//SEARCHES FOR A PERTICULAR BOOKINGS USING BOOKINGS ID
// OUTPUTS ALL POSSIBILITIES
void CabCompany::searchBookingByID(string BookingID){
	bool Exists=false;
	int ESC=0;
	while (ESC<totalBookings){
		if (Bookings[ESC]->getBookingID()==BookingID){
			cout <<*Bookings[ESC];
			Exists=true;
		}
		ESC++;
	}
	try{
		if (!Exists)
		throw 1;
	}
	catch(int Er){
		cout << "ERROR: #"<<Er<<"\nBooking Can not be assigned\nBooking By Id "<<BookingID<< " doesnt Exist."<<endl;
	}
	system("pause");
}



void CabCompany::AssignCab(){
	bool Exists=false;
	int ESC=0;
	string BookingID;
	
	fflush(stdin);
	cout << "\t\t\tEnter Booking ID To Assign a Cab: ";
	getline(cin,BookingID);
	while(ESC<totalBookings){
		if (!Bookings[ESC]==NULL){
			if (Bookings[ESC]->getBookingID()==BookingID){
				Exists=true;
				if (!Bookings[ESC]->CabGiven()){
					int ESCI=0;
					while(ESCI<totalCabs){
						if (!Cabs[ESCI]==NULL){
							if (!Cabs[ESCI]->getBookingAssignment()){
								Cabs[ESCI]->setBookingAssigment(true);
								Bookings[ESC]->setCab(Cabs[ESCI]);
								cout << "\t\t\tBooked.";
								ESCI+=totalCabs;
							}
						}
						ESCI++;
					}
				}
				Exists=true;
			}
		}
		ESC++;
	}
	try{
		if (!Exists)
		throw 1;
	}
	catch(int Er){
		cout << "ERROR: #"<<Er<<"\nBooking Can not be assigned\nBooking By Id "<<BookingID<< " doesnt Exist."<<endl;
	}
	fflush(stdin);
	system("pause");
}
	
#endif
