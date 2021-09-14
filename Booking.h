/* 
	Name: CABMANAGEMENTSIMULATION
	Copyright: SAADAHMED
	Author: Saad Ahmed, Osama Arif, Faizan Rasool
	Date: 27/05/16 22:50
	Description: Final Builds
*/
#ifndef BOOKING_H
#define BOOKING_H
#include "Cab.h"
#include "Customer.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class Booking{
	friend class CabCompany;
	protected:
		Cab* BookingCab;
		Customer Booker;
		string Start;
		string End;
		double Charges;
		double Distance;
		string BookingID;
		bool BookingDone;
	public:
		
		string getBookingID(){
			return BookingID;
		}
		
		void setCab(Cab* toSet){
			BookingCab=toSet;
		}
		void removeCab(){
			
			BookingCab=NULL;
		}
		
		Booking (string Name,string CNIC,string PhoneNo,double Charges,string Start,string End,string BookingID,double Distance,Cab* toBooK=NULL){
			this->Start = Start;
			this->End = End;
			this->BookingID=BookingID;
			this->Distance = Distance;
			this->Charges=Charges;
			this->Booker.setCNIC(CNIC);
			this->Booker.setName(Name);
			this->Booker.setPhoneNo(PhoneNo);
			this->BookingDone=false;
			this->BookingCab = toBooK;
		}
		
		friend ostream& operator << (ostream&Out,Booking&Obj){
			Out <<endl<<"\t\t\tBooking ID: "<<Obj.BookingID<<endl<< "\t\t\tFrom: "<<Obj.Start<<endl
			<<"\t\t\tTo: "<<Obj.End<<endl<<
			"\t\t\tDistance : "<<Obj.Distance<<endl;
			return Out;
		}
		
		
		void PrintCustomerInfo(){
			cout <<endl<< Booker;
		}
		void PrintCabInfo(){
			cout <<endl<< *BookingCab;
		}
		
		double getDistance(){
			return this->Distance;
		}

		void addToDataBase(){
			fstream Out;
			Out.open("Bookings.csv",ios::app);
			Out << Booker.getName() <<','
			<< Booker.getCNIC() << ','
			<< Booker.getPhoneNo() << ','
			<< Start << ','
			<< End <<','
			<< Distance <<','
			<< BookingID << ','
			<< Charges << '\n';
		}

		void addToRecords(){
			fstream Out;
			Out.open("BookingRecords.csv",ios::app);
			Out << Booker.getName() <<','
			<< Booker.getCNIC() << ','
			<< Booker.getPhoneNo() << ','
			<< Start << ','
			<< End <<','
			<< Distance <<','
			<< BookingID << ','
			<< Charges << '\n';
		}

		bool operator == (Booking &Obj){
			if (
			this->Start==Obj.Start 
			&& this->End == Obj.End 
			&& this->BookingID==Obj.BookingID
			&& this->Booker==Obj.Booker
			){
				return true;
			}
			else {
				return false;
			}
		}
		bool CabGiven(){
			if (BookingCab==NULL){
				return false;
			}
			else return true;
		}
		double getCharges(){
			return this->Charges;
		}
		~Booking(){
			BookingCab=NULL;
		}
};
#endif
