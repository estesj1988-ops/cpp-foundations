#include <iostream>
using namespace std;

int main()
{
    int systemValue = 0;
    int lastComputed = 0;
    bool systemEnabled = false;
    int choice;
    bool running = true;

    cout << "========================\n";
    cout << "  SCOPE PANEL v1.0\n";
    cout << "========================\n";

    while (running == true)
    {
        cout << "1) Toggle system enabled\n";
        cout << "2) Set system value\n";
        cout << "3) Compute square of system value\n";
        cout << "4) Reset system state\n";
        cout << "5) Show system status\n";
        cout << "6) Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            if (systemEnabled == true)
            {
                systemEnabled = false;
                cout << "System enabled: OFF\n";
            }
            else if (systemEnabled == false)
            {
                systemEnabled = true;
                cout << "System enabled: ON\n";
            }

            break;
        case 2:
        {
            int temp;
            cout << "Enter new system value: ";
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
            break;
        }
        case 3:
            if (systemEnabled == false)
            {
                cout << "System is disabled.\n";
            }
            else
            {
                lastComputed = systemValue * systemValue;
                cout << "Computed square: " << lastComputed << "\n";
            }
            break;
        case 4:
            systemValue = 0;
            lastComputed = 0;
            systemEnabled = false;
            cout << "System reset complete.\n";
            break;
        case 5:
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