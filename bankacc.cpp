#include <iostream>
using namespace std;

class Bank
{
private:
    int total;
    int accnumber;
    struct person
    {
        string name;
        int accno;
        float balance = 10000;
    } person[100];

public:
    Bank()
    {
        total = 0;
    }
    void choice();
    void createAcc();
    void display();
    void search();
    void deposit();
    void withdraw();
};

void Bank::choice()
{
    while (1)
    {
        char ch;
        cout << "\n Bank Managament System " << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. View Customers list" << endl;
        cout << "3. Check the details of an existing account" << endl;
        cout << "4. Deposit" << endl;
        cout << "5. Withdraw" << endl;
        cout << " Select an option from above: ";
        ch = getchar();
        switch (ch)
        {
        case '1':
            Bank::createAcc();
            break;
        case '2':
            Bank::display();
            break;
        case '3':
            Bank::search();
            break;
        case '4':
            Bank::deposit();
            break;
        case '5':
            Bank::withdraw();
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
}

void Bank::createAcc()
{
    cout << "Enter data of person " << total + 1 << endl;
    cout << "Enter account no. ";
    cin >> person[total].accno;
    cout << "Enter name: ";
    cin >> person[total].name;
    total++;
    cout << "Account created successfully!\n";
}

void Bank::display()
{
    for (int i = 0; i < total; i++)
    {
        cout << "Data of customer " << i + 1 << endl;
        cout << "Account no. " << person[i].accno << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "Balance: " << person[i].balance << endl;
    }
}

void Bank::search()
{
    cout << "Enter your account number: ";
    cin >> accnumber;
    for (int i = 0; i < total; i++)
    {
        if (accnumber == person[i].accno)
        {
            cout << "Account no. " << person[i].accno << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "Balance: " << person[i].balance << endl;
        }
        else
            cout << "Sorry! No account found!";
        break;
    }
}

void Bank::deposit()
{
    int amount;
    cout << "Enter your account number: ";
    cin >> accnumber;
    for (int i = 0; i < total; i++)
    {
        if (accnumber == person[i].accno)
        {
            cout << "Account no. " << person[i].accno << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "Existing Balance: " << person[i].balance << endl;
            cout << "\nEnter amount to be deposited: ";
            cin >> amount;
            person[i].balance += amount;
            cout << "\nRs. " << amount << " has been successfully deposited into your account number " << person[i].accno;
            cout << "\nYour updated balance is " << person[i].balance << endl;
        }
        break;
    }
}

void Bank::withdraw()
{
    int amount;
    cout << "Enter your account number: ";
    cin >> accnumber;
    for (int i = 0; i < total; i++)
    {
        if (accnumber == person[i].accno)
        {
            cout << "Account no. " << person[i].accno << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "Existing Balance: " << person[i].balance << endl;
        back:
            cout << "\nEnter amount to be withdrawn: ";
            cin >> amount;
            if (amount > person[i].balance)
            {
                cout << "Sorry! Your bank balance is less than the requested amount.";
                goto back;
            }
            person[i].balance -= amount;
            cout << "\nRs. " << amount << " has been successfully withdrawn from your account number " << person[i].accno;
            cout << "\nYour updated balance is " << person[i].balance << endl;
        }
        break;
    }
}
int main()
{
    Bank a;
    a.choice();
    return 0;
}
