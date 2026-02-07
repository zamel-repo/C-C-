#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
private:
    double balance;
public:
    BankAccount(double b);
    void deposit(double amount);
    double getBalance() const;
};

#endif
