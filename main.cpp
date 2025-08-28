#include<iostream>
#include<fstream>
#include<string>
#include<map>

#include "Filemanager.h"
#include"Account.h"


using namespace std;
void menu(map<int,Account>& accounts)   //here map is using for it is not able to made a copy.the function can modify the original data only
{
     int choice;
   do
   {
     cout<<"---------------Banking system---------------\n";
     cout<<"1.Creat Account\n";
     cout<<"2.Login Account\n";
     cout<<"3.Exit\n";

     cout<<"Enter Your Choice: ";
     cin>>choice;

     if(choice==1)
     {
           Account acc;
           acc.creatacount();   //creat a new account
           accounts[acc.getaccountnumber()]=acc;  //update that in map to easy access
           Filemanager::saveAccount(accounts);      //save that into the file
     }
     else if(choice==2)
     {
            int accno;
            string pass;
            cout<<"Enter the Account Number : ";
            cin>>accno;
             cout<<"Enter the password : ";
             cin.ignore();
             getline(cin,pass);

             if(accounts.count(accno) && accounts[accno].login(accno,pass))
             {
                  int subchoice;
                  do
                  {
                        cout<<"\n-----------------Account Menu-----------------\n";
                        cout<<"1.Deposite\n";
                        cout<<"2.Withdraw\n";
                        cout<<"3.View Details\n";
                        cout<<"4.Logout\n";
                        cout<<"Enter your choice: ";
                        cin>>subchoice;
                            
                         if(subchoice==1)
                         {
                              double amt;
                              cout<<"Enter the amount you want to deposite\n";
                              cin>>amt;
                              accounts[accno].deposit(amt);
                              Filemanager::saveAccount(accounts);
                         }
                         else if(subchoice==2)
                         {
                              double amt;
                              cout<<"Enter the amount you want to withdraw\n";
                              cin>>amt;
                              accounts[accno].withdraw(amt);
                              Filemanager::saveAccount(accounts);
                         }
                         else if(subchoice==3)
                         {
                              accounts[accno].display();
                         }
                  }while(subchoice!=4);
             }
             else
             {
                  cout<<"Invalid Input\n";
             }
            }
     }while(choice!=3);
}


int main()
{
      map<int,Account>accounts;
      Filemanager::loadAccount(accounts);
      menu(accounts);
      Filemanager::saveAccount(accounts);
      return 0;
}
