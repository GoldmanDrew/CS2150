/*
Drew Goldman
dag5wd
9/10/2020
bankAccount.cpp
*/

#include "bankAccount.h"
#include <iostream>
#include <string>
using namespace std;

bankAccount::bankAccount() {
  balance = 0.00;
}
bankAccount::bankAccount(double amount) {
  balance = amount;
}
bankAccount::~bankAccount() {
}
double bankAccount::withdraw(double amount) {
  if(amount > balance) return balance;
  else {
    balance -= amount;
    return balance;
  }
}
double bankAccount::deposit(double amount) {
  balance += amount;
  return balance;
}
double bankAccount::getBalance() {
  return balance;
}
 
