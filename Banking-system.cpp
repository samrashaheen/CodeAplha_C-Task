#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

const int MAX_TRANS = 50;
const int MAX_ACCOUNTS = 5;

class Transaction{
public:
    string type;
    double amount;
    string details;
    Transaction(){}
    Transaction(string t,double a,string d){
        type=t; amount=a; details=d;
    }
};

class Account{
private:
    int accountNumber;
    double balance;
    Transaction history[MAX_TRANS];
    int transCount;
public:
    Account(){}
    Account(int accNo,double bal=0){
        accountNumber=accNo;
        balance=bal;
        transCount=0;
    }
    int getAccountNumber(){return accountNumber;}
    double getBalance(){return balance;}
    void deposit(double amount){
        balance+=amount;
        if(transCount<MAX_TRANS)history[transCount++]=Transaction("Deposit",amount,"Amount deposited");
    }
    bool withdraw(double amount){
        if(amount>balance)return false;
        balance-=amount;
        if(transCount<MAX_TRANS)history[transCount++]=Transaction("Withdraw",amount,"Amount withdrawn");
        return true;
    }
    bool transfer(Account &to,double amount){
        if(amount>balance)return false;
        balance-=amount;
        to.balance+=amount;
        if(transCount<MAX_TRANS)history[transCount++]=Transaction("Transfer Out",amount,"To account "+to_string(to.accountNumber));
        if(to.transCount<MAX_TRANS)to.history[to.transCount++]=Transaction("Transfer In",amount,"From account "+to_string(accountNumber));
        return true;
    }
    void showTransactions(){
        cout<<"\nTransaction History for Account "<<accountNumber<<":\n";
        for(int i=0;i<transCount;i++){
            cout<<setw(12)<<history[i].type<<" | "<<setw(8)<<history[i].amount<<" | "<<history[i].details<<endl;
        }
    }
};

class Customer{
private:
    string name;
    int customerID;
    Account accounts[MAX_ACCOUNTS];
    int accCount;
public:
    Customer(string n,int id){
        name=n; customerID=id; accCount=0;
    }
    void createAccount(int accNo){
        if(accCount<MAX_ACCOUNTS){
            accounts[accCount++]=Account(accNo);
            cout<<"Account "<<accNo<<" created for "<<name<<endl;
        } else {
            cout<<"Cannot create more accounts!"<<endl;
        }
    }
    Account* getAccount(int accNo){
        for(int i=0;i<accCount;i++){
            if(accounts[i].getAccountNumber()==accNo)return &accounts[i];
        }
        return nullptr;
    }
    void showAccounts(){
        cout<<"\nAccounts of "<<name<<":\n";
        for(int i=0;i<accCount;i++){
            cout<<"Account "<<accounts[i].getAccountNumber()<<" | Balance: "<<accounts[i].getBalance()<<endl;
        }
    }
};

int main(){
    Customer c1("Ali",101);
    c1.createAccount(1001);
    c1.createAccount(1002);

    Account* acc1=c1.getAccount(1001);
    Account* acc2=c1.getAccount(1002);

    if(acc1)acc1->deposit(5000);
    if(acc1)acc1->withdraw(1200);
    if(acc1 && acc2)acc1->transfer(*acc2,2000);

    c1.showAccounts();
    if(acc1)acc1->showTransactions();
    if(acc2)acc2->showTransactions();

    return 0;
}
