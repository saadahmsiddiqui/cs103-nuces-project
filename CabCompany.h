/*
	Name: CABMANAGEMENTSIMULATION
	Copyright: SAADAHMED
	Author: Saad Ahmed, Osama Arif, Faizan Rasool
	Date: 27/05/16 22:50
	Description: Final Builds
*/

#ifndef CABCOM_H
#define CABCOM_H
#include <iostream>
#include <windows.h>
#include <vector>
#include <time.h>
#include "Booking.h"
#include "Customer.h"
using namespace std;


class CabCompany {
	protected:
		string CabCompanyName;
		vector <Booking*> Bookings;
		vector <Cab*> Cabs;
		vector <Driver*>Drivers;
		
		double BankBalance;
		int totalBookings;
		int totalCabs;
		int totalDrivers;
		
		void CabandDriverAssignment ();
		void CabandDriverRemoval ();
		
		void WriteCompanyInfo();
		void LoadupBookings();
		void LoadupDrivers();
		void LoadupCabs();
		void WriteCurrentValuestoDataBase();		
		
		
		void MainMenu();
		void CabsManagementMenu ();
		void DriversManagementMenu();
		void BookingsManagementMenu();
		
		
		void addCab();
		void showCabs();
		void showAvailableCabs();
		void searchCabByID();
		void showCabsWithoutDrivers();
		void removeCab();
		
		void addDriver();
		void showDrivers();
		void viewAvailableDrivers();
		void removeDriver();
		
		void addBooking();
		void searchBookingByID(string);
		void showBookings(int);
		void removeBooking();
		void AssignCab();
		void showInfo();
		
		
	public:
	CabCompany(string,double);
	CabCompany(string);
	void StartupScreen();
	~CabCompany();
};

#endif
