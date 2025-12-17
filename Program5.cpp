#include <iostream>
using namespace std;

void printHeader();
void printMenu();
int readMenuChoice();
void toggleSystemEnabled(bool &systemEnabled);
void setSystemValue(int &systemValue);
void computeSquare(bool systemEnabled, int systemValue, int &lastComputed);
void resetSystemState(int &systemValue, int &lastComputed, bool &systemEnabled);
void showSystemStatus(bool systemEnabled, int systemValue, int lastComputed);

int main()
{
    int systemValue = 0;
    int lastComputed = 0;
    bool systemEnabled = false;
    int choice;
    bool running = true;

    printHeader();
    while (running == true)
    {
        printMenu();
        choice = readMenuChoice();
        if(choice == -1) continue;
        switch (choice)
        {
        case 1:
            toggleSystemEnabled(systemEnabled);
            break;
        case 2:
            setSystemValue(systemValue);
            break;
        case 3:
            computeSquare(systemEnabled, systemValue, lastComputed);
            break;
        case 4:
            resetSystemState(systemValue, lastComputed, systemEnabled);
            break;
        case 5:
            showSystemStatus(systemEnabled, systemValue, lastComputed);
            break;
        case 6:
            cout << "Exiting program.\n";
            running = false;
            break;
        default:
            cout << "Invalid menu option.\n";
            break;
        }
    }
    return 0;
}
void printHeader()
{
    cout << "========================\n";
    cout << "  SCOPE PANEL v2.0\n";
    cout << "========================\n";
}
void printMenu()
{
    cout << "1) Toggle system enabled\n";
    cout << "2) Set system value\n";
    cout << "3) Compute square of system value\n";
    cout << "4) Reset system state\n";
    cout << "5) Show system status\n";
    cout << "6) Exit\n";
    cout << "Enter choice: ";
}
int readMenuChoice()
{
    int choice;
    cin >> choice;
    if (cin.fail())
    {
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    return choice;
}
void toggleSystemEnabled(bool &systemEnabled)
{
    systemEnabled = !systemEnabled;
    if (systemEnabled == true)
    {
        cout << "System enabled: ON\n";
    }
    else
    {
        cout << "System enabled: OFF\n";
    }
}
void setSystemValue(int &systemValue)
{
    int temp;
    cout << "Enter new system value:";
    cin >> temp;
    if (cin.fail())
    {
        cout << "Invalid input. System value unchanged.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else
    {
        systemValue = temp;
    }
}
void computeSquare(bool systemEnabled, int systemValue, int &lastComputed)
{
    if (systemEnabled == false)
    {
        cout << "System is disabled.\n";
    }
    else
    {
        lastComputed = systemValue * systemValue;
        cout << "Computed square: " << lastComputed << "\n";
    }
}
void resetSystemState(int &systemValue, int &lastComputed, bool &systemEnabled)
{
    systemValue = 0;
    lastComputed = 0;
    systemEnabled = false;
    cout << "System reset complete.\n";
}
void showSystemStatus(bool systemEnabled, int systemValue, int lastComputed)
{
    if (systemEnabled == true)
    {
        cout << "System enabled: ON\n";
    }
    else
    {
        cout << "System enabled: OFF\n";
    }
    cout << "System value: " << systemValue << "\n";
    cout << "Last computed: " << lastComputed << "\n";
}