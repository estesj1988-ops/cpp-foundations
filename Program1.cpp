#include <iostream>
using namespace std;

int main()
{

    int choice;
    int targetValue = 0;
    bool running = true;

    cout << "========================\n";
    cout << "  CONTROL PANEL v1.0\n";
    cout << "========================\n";

    while (running == true)
    {
        cout << "1) Print system status\n";
        cout << "2) Set target value\n";
        cout << "3) Show current target\n";
        cout << "4) Exit\n";
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
            cout << "System running normally.\n";
            break;
        case 2:
            cout << "Enter new target value: ";
            cin >> targetValue;
            if (cin.fail())
            {
                cout << "Invalid input. Target value unchanged.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            break;
        case 3:
            cout << "Current target value: " << targetValue << "\n";
            break;
        case 4:
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