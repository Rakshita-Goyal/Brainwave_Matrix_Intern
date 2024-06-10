#include<iostream>
#include<unordered_map>
#include<vector>
using namespace::std;
class ATM {
private:
struct Account {
        string pin;
        double balance;
    };

    unordered_map<string, Account> accounts;
    string currentAccount;
public:
ATM() {
 accounts["123456"] = {"1234", 5000};
 accounts["567889"] = {"678",6789};
 accounts["278346"] = {"7890",435642};

}

//logout
void logout() {
        currentAccount = "";
    }

//login
bool login(const string& accountNumber, const string& pin) {
        if (accounts.find(accountNumber) != accounts.end() && accounts[accountNumber].pin == pin) {
            currentAccount = accountNumber;
            return true;
        }
        return false;
    }

//deposit
bool deposit(double amount) {
        if (!currentAccount.empty() && amount > 0) {
            accounts[currentAccount].balance += amount;
            return true;
        }
        return false;
    }

//withdraw
 bool withdraw(double amount) {
        if (!currentAccount.empty() && amount > 0 && accounts[currentAccount].balance >= amount) {
            accounts[currentAccount].balance -= amount;
            return true;
        }
        return false;
    }    

//check
double checkBalance() {
        if (!currentAccount.empty()) {
            return accounts[currentAccount].balance;
        }
        return -1;
    }
};
int main(){
    ATM atm;
    string accountNumber, pin;
    int choice;
    double amount;

while (true) {
        cout << "Enter your account number: ";
        cin >> accountNumber;
        cout << "Enter your PIN: ";
        cin >> pin;

        if (atm.login(accountNumber, pin)) {
            cout << "Login successful!" << endl;
            break;
        } else {
            cout << "Invalid account number or PIN. Please try again." << endl;
        }
    }

do {
        cout << "\nATM Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current balance: $" << atm.checkBalance() << endl;
                break;
            case 2:
             cout << "Enter amount to deposit: ";
                cin >> amount;
                if (atm.deposit(amount)) {
                    cout << "Deposit successful!" << endl;
                } else {
                    cout << "Deposit failed." << endl;
                }
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (atm.withdraw(amount)) {
                    cout << "Withdrawal successful" << endl;
                } else {
                    cout << "Insufficient balance" << endl;
                }
                break;
                 case 4:
                atm.logout();
                cout << "Logged out " << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}