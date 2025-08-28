#pragma once
#include <string>
#include<iostream>
using namespace std;

class translog
{
     public:
         static void log(int accountnum,const string type,double amount,double balance);   //prototype for transacation.cpp
};