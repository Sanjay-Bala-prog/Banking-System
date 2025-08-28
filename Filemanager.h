#pragma once
#include "Account.h"
#include<map>
using namespace std;

class Filemanager
{
    public:   
       static void loadAccount(map<int,Account>&account);  //load a data into the file
       static void saveAccount(const map<int,Account>&account);   //it ia save the data compiler to file
};