#include"Account.h"
#include"Transacationlog.h"

using namespace std;

Account ::Account() : accnumber(0),balance(0.0)   //using the private arguments in another file using scope resolution operator
{}

void Account::creatacount()  //It is used to creat the new Account 
{
    cout<<"Enter Your Account Number\n";
    cin>>accnumber;
    cout<<"Enter Your Name\n";
    cin.ignore();       //It is used to avoid the newline and avoid space in the name
    getline(cin,name);  //getline is used to gather the input from hole line include the new line
    cout<<"Set the Password\n";
    // cin.ignore();
    getline(cin,password);   //Simlier in password also
    balance=0.0;    //In intialie Balance will be set as 0.
    cout<<"Account Created Successfully\n";
}

bool Account::login(int accno,const string& pass)  //if the given input and already eixisting details will be fetched with the help of login
{
      return (accnumber==accno && password==pass);  //when the give data and eixisting data is matched means retun 1 otherwsie return 0.
}

void Account::deposit(double amount)
{
     balance=balance+amount;    //here add the amount in back account
     translog::log(accnumber,"Deposite",amount,balance);    //we need to store in file.so,we need to update that in file
     cout<<"Deposite Amount "<<amount<<" Successfully\n";     
}

void Account::withdraw(double amount)
{
    if(amount > balance)   //here withdraw the ammount.if the amount is greater then the balances means show the warrning message
    {
        cout<<"Insufficent Balances\n";
        return ;
    }
    balance=balance-amount;  //withdraw the amount 
    translog::log(accnumber,"Withdraw",amount,balance);  //update the amount details in file
    cout<<"Withdraw Amount "<<amount<<" Successfully\n";  //then print it
}


void Account::display()const  //here const is used for(only for show not modifie any content in that object)
{
    cout<<"------------------Account Details-----------------\n";
    cout<<"Account Number : "<<accnumber<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"Balances : "<<fixed<<setprecision(2)<<balance<<endl;  //here fixed is (fixed-point notation) and setprecision is (after . how many value need to print.like(.23))
}

void Account::savetofile(ofstream &out)const
{
    out<<accnumber<<","<<name<<","<<password<<","<<balance<<endl;
}

void Account::loadfile(const string line)
{
    size_t pos1=line.find(',');     //finding the first "," to account number
    size_t pos2=line.find(',',pos1+1);   //similer this is used  to find the name in the file
    size_t pos3=line.find(',',pos2+1);    //it used to find the balances of the account

    accnumber=stoi(line.substr(0,pos1));   //used to convet the string to integer 
    name=line.substr(pos1+1,pos2-pos1-1);   //the name will be fetched using substr and finding the position in that line
    password=line.substr(pos2+1,pos3-pos2-1);  //similer like this also used to find the password
    balance=stod(line.substr(pos3+1));  //the stod is a "string to double" it is covert the string to the double. 
}

int Account::getaccountnumber()const
{
     return accnumber;
}
