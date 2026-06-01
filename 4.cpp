/*Given that an EMPLOYEE class contains following members:
data members: Employee number, Employee name, Basic, DA, IT, Net Salary
and print data members. Write a C++ program to read the data of N employee
and compute Net salary of each employee (DA=52% of Basic and Income Tax
(IT) =30% of the gross salary) .*/

#include<iostream>
using namespace std;
class EMPLOYEE{
	int emp_no;
	float basic_salary,DA,IT,Gross_salary,Net_salary;
	char name[50];
	public:
		void getinfo()
		{
			cout<<"enter name , number and basic salary of an employee : ";
			cin>> name >> emp_no >> basic_salary ;
		}
		void calculate()
		{
			DA = 0.52 * basic_salary;
   			Gross_salary = basic_salary + DA;
    		IT = 0.30 * Gross_salary;
    		Net_salary = Gross_salary - IT;
    
		}
		void showdata()
		{
			cout<<"the name , id , basic salary , net salary of an employee is given as:"<<endl;
			cout<< name <<" "<<emp_no<<" "<<basic_salary<<" "<<Net_salary<<endl;
		}
};

int main()
{
	EMPLOYEE EMP[100];
	int i,n;
	cout<<"enter how many records you want to store:";
	cin>> n ;
	for(i=0;i<n;i++)
	{
		EMP[i].getinfo();
	}
	for(i=0;i<n;i++)
	{
		EMP[i].calculate();
	}
	for(i=0;i<n;i++)
	{
		EMP[i].showdata();
	}
	return 0;
}