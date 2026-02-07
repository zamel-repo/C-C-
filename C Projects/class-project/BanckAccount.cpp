#include "BankAccount.h"

BankAccount::BankAccount(double b) : balance(b) {}

void BankAccount::deposit(double amount) {
    balance += amount;
}

double BankAccount::getBalance() const {
    return balance;
}
