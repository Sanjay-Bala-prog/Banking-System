#include"Transacationlog.h"
#include<fstream>
#include<ctime>

void translog::log(int accountnum,const string type,double amount,double balance)
{
    ofstream log("transaction.txt",ios::app);  //file open in "read and write" mode.so ,we using append
    time_t now=time(0);    //calculating the currnent time
    string dt=ctime(&now);  //it is used to show the current time using address of the now varaible
     dt.pop_back();  //delete the newline in the last
     log << dt << " | Acc#" << accountnum << " | " << type << " ₹" << amount << " | Balance ₹" << balance << "\n";
}