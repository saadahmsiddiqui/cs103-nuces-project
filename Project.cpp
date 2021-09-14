/*
	Name: CABMANAGEMENTSIMULATION
	Copyright: SAADAHMED
	Author: Saad Ahmed, Osama Arif, Faizan Rasool
	Date: 27/05/16 22:50
	Description: Final Builds
*/
#include <iostream>
#include "CabCompany.h"
#include "CABCOMPMAINFUNCS.cpp"
#include "CABCOMPFILING.cpp"
#include "CABCOMPCABFUNCS.cpp"
#include "CABCOMPBOOKINGFUNCS.cpp"
#include "CABCOMPDRIVERFUNCS.cpp"

using namespace std;

int main(){
	CabCompany SaadCabs("ViceCab",150000);
	SaadCabs.StartupScreen();
}
