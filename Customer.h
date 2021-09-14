#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;

class Customer {
	protected:
		string Name,CNIC,PhoneNo;
	public :
		Customer (){	
			this->Name = "";
			this->CNIC = "";
			this->PhoneNo = "";
		}
		
		void setName(string Name){
			this->Name=Name;	
		}
		string getName(){
			return Name;
		}
		string getCNIC(){
			return CNIC;
		}
		string getPhoneNo(){
			return PhoneNo;
		}
		void setCNIC(string CNIC){
			this->CNIC=CNIC;
		}
		
		void setPhoneNo(string PhoneNo){
			this->PhoneNo = PhoneNo;
		}		
		friend ostream& operator << (ostream&Out,Customer&Obj){
			cout<<endl<<endl
			<<"\t\t\tCustomer Name: "<<Obj.Name
			<<endl<<"\t\t\tCustomer CNIC: "<<Obj.CNIC
			<<endl<<"\t\t\tCustomer Phone Number: "<<Obj.PhoneNo<<endl;
			return Out;
		}
		bool operator == (Customer &Obj){
			if (this->Name==Obj.Name
			&& this->CNIC==Obj.CNIC
			&& this->PhoneNo==Obj.PhoneNo){
				return true;
			}
			else {
				return false;
			}
		}
};
#endif

