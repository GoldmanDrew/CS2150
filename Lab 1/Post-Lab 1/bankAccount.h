/*
Drew Goldman
dag5wd
9/10/2020
bankAccount.h
*/

#include <iostream>
#include <string>
using namespace std;

#ifndef LIFECYCLE_H
#define LIFECYCLE_H

class bankAccount {
 public:
  bankAccount();
  bankAccount(double amount);
  ~bankAccount();
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();
  
 private:
  double balance;
};





#endif
