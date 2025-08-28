#include "Filemanager.h"
#include<fstream>
#include<string>

using namespace std;


void Filemanager::loadAccount(map<int,Account>&account)
{
    ifstream file("account.txt");  //the file is opening in the hard coded name
    string line;
    while (getline(file,line))    //getline is used to run the loop until reach the null in file
    {
      Account acc;
      acc.loadfile(line);    //send the data to the loadfile to show the output or other works
      account[acc.getaccountnumber()]=acc;   //uesd to get the account number in mapping function
    }
    
}

void Filemanager::saveAccount(const map<int,Account>&account)
{
    ofstream file("account.txt");    //creat a file name as account is inbulit
    for(const auto& pair : account)   //the give data will be stored one by one in the file 
    {
         pair.second.savetofile(file);  //it is store the data using savetofile with "," seperator
    }
}