#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
using namespace std;
class Employee{
	protected:
		string Name,employeeId;
		double Pay;
		int Age;
		int workingHours;
	public:
	
	Employee(string tName,string temployeeId,double tPay,int tAge,int tworkingHours);
	
	virtual void Print()=0;
	
	virtual string getName(){
	   	return Name;
	}
	
	virtual string getemployeeId(){
	   	return employeeId;
	}
	
	virtual double getPay(){
	   	return Pay;
	}
	
	virtual int getAge(){
	   	return Age;
   }

	virtual int getworkingHours(){
	   	return workingHours;
	}
};

Employee::Employee(string tName,string temployeeId,double tPay,int tAge,int tworkingHours)
{
	Name=tName;
	employeeId=temployeeId;
	Pay=tPay;
	Age=tAge;
	workingHours=tworkingHours;
}
void Employee::Print()
{
	cout<<Name<<endl<<employeeId<<endl<<Pay<<endl<<Age<<endl<<workingHours;
}


#endif
