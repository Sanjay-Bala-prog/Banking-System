                                                            Banking System in C++

A modular, beginner-friendly banking system built in C++ that simulates real-world account management, transaction logging, and 
secure CLI interaction. Designed with clarity, extensibility, and interview-readiness in mind.

 Features:

-  Account creation with password protection
-  Deposit and withdrawal operations
-  View account details with formatted balance
-  Transaction logging with timestamp (DD-MM-YYYY HH:MM:SS)
-  Persistent storage using file I/O (`accounts.txt`, `transactions.txt`)
-  Input validation to prevent crashes and bad data
-  Clean CLI output with receipt-style formatting

Project Structure: 
 
├── main.cpp 
├── Account.h 
├──Account.cpp
├── FileManager.h
├── FileManager.cpp
├── TransactionLogger.h 
├── TransactionLogger.cpp 
├── accounts.txt 
├── transactions.txt

Compile & Run (WSL/Linux):

 g++ *.cpp(to compile)
 ./a.out(to run the program)

Sample CLI Output:

------------------ Account Details ------------------
Account Number : 123456
Name           : Sanjay Bala
Balance        : ₹25000.00


Sample Transaction Log:

[28-08-2025 11:32:00] Acc#123456 | Deposit ₹5000.00 | Balance ₹25000.00
[28-08-2025 11:35:42] Acc#123456 | Withdraw ₹2000.00 | Balance ₹23000.00



