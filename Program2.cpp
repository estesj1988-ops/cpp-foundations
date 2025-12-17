#include <iostream>
using namespace std;

int main()
{
    int choice;
    bool running = true;

    double a = 0;
    double b = 0;
    double result = 0;

    int intA = 0;
    int intB = 0;
    int intResult = 0;

    cout << "========================\n";
    cout << "  CALC PANEL v1.0\n";
    cout << "========================\n";

    while (running == true)
    {
        cout << "1) Set two doubles (a and b)\n";
        cout << "2) Add (double)\n";
        cout << "3) Divide (double)\n";
        cout << "4) Set two ints (intA and intB)\n";
        cout << "5) Divide (int)\n";
        cout << "6) Show all current values\n";
        cout << "7) Exit\n";
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
            cout << "Enter a: ";
            cin >> a;
            if (cin.fail())
            {
                cout << "Invalid input. a unchanged.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "Enter b: ";
            cin >> b;
            if (cin.fail())
            {
                cout << "Invalid input. b unchanged.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            break;
        case 2:
            result = a + b;
            cout << "Result (double): " << result << '\n';
            break;
        case 3:
            if (b == 0)
            {
                cout << "Error: division by zero.\n";
            }
            else
            {
                result = a / b;
                cout << "Result (double): " << result << '\n';
            }
            break;
        case 4:
            cout << "Enter intA: ";
            cin >> intA;
            if (cin.fail())
            {
                cout << "Invalid input. intA unchanged.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cout << "Enter intB: ";
            cin >> intB;
            if (cin.fail())
            {
                cout << "Invalid input. intB unchanged.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            break;
        case 5:
            if (intB == 0)
            {
                cout << "Error: division by zero.\n";
            }
            else
            {
                intResult = intA / intB;
                cout << "Result (int): " << intResult << '\n';
            }
            break;
        case 6:
            cout << "a = " << a << '\n';
            cout << "b = " << b << '\n';
            cout << "result = " << result << '\n';
            cout << "intA = " << intA << '\n';
            cout << "intB = " << intB << '\n';
            cout << "intResult = " << intResult << '\n';
            break;
        case 7:
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