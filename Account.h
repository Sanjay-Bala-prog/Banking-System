#pragma once
#include <string>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;
class Account
{
    int accnumber;
    string name;
    string password;
    double balance;

    public:
         Account();     //it is constructore of the class  //it is used to set the private varaible is 0 and it is used in STL(like: map in this project)
         void creatacount();  //creating a new account
         bool login(int accno,const string& pass);   //Login the new or previous account
         void deposit(double amount);   //Depostit the amount in the account
         void withdraw(double amount); //withdraw the amount in the account
          void display() const;  //used to display the account details
          void savetofile(ofstream &out)const;  //save the data in file
          void loadfile(const string line);//load a data from the file using a "," seprator.
          int getaccountnumber()const; //it is used to get the account number
};
