#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Struct to hold each transaction
struct Transaction
{
    string type;        // Income or Expense
    string description; // What it was for
    double amount;      // Amount of money
};

// Function prototypes
void showMenu();
void addTransaction(vector<Transaction>& list, string type);
void printSummary(vector<Transaction>& list);
double getTotal(vector<Transaction>& list, string type);

int main()
{
    vector<Transaction> transactions;
    int choice = 0;

    // Main loop
    while (choice != 4) 
    {
        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            addTransaction(transactions, "Income");
        }
        else if (choice == 2) 
        {
            addTransaction(transactions, "Expense");
        }
        else if (choice == 3)
        {
            printSummary(transactions);
        }
        else if (choice == 4)
        {
            cout << "Goodbye!\n";
        }
        else
        {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}

// Displays menu
void showMenu()
{
    cout << "\n==== Budget Tracker ====\n";
    cout << "1. Add Income\n";
    cout << "2. Add Expense\n";
    cout << "3. View Summary\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

// Adds either income or expense
void addTransaction(vector<Transaction>& list, string type)
{
    Transaction t;
    t.type = type;

    cin.ignore(); // clears input buffer

    cout << "Enter description: ";
    getline(cin, t.description);

    cout << "Enter amount: ";
    cin >> t.amount;

    list.push_back(t);

    cout << type << " added.\n";
}

// Calculates total for income or expense
double getTotal(vector<Transaction>& list, string type) 
{
    double total = 0;

    for (int i = 0; i < list.size(); i++) 
    {
        if (list[i].type == type)
        {
            total += list[i].amount;
        }
    }

    return total;
}

// Prints summary of finances
void printSummary(vector<Transaction>& list) 
{
    double income = getTotal(list, "Income");
    double expense = getTotal(list, "Expense");
    double balance = income - expense;

    cout << fixed << setprecision(2);

    cout << "\n==== Summary ====\n";
    cout << "Total Income: $" << income << endl;
    cout << "Total Expenses: $" << expense << endl;
    cout << "Balance: $" << balance << endl;

    cout << "\nTransactions:\n";

    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i].type << " | "
            << list[i].description << " | $"
            << list[i].amount << endl;
    }
}