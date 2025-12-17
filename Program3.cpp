#include <iostream>
using namespace std;

int main()
{
    int choice;
    bool running = true;
    int N = 0;
    int i;
    int sum = 0;
    int evenCount = 0;
    int oddCount = 0;
    double average = 0;

    cout << "========================\n";
    cout << "  LOOP PANEL v1.0\n";
    cout << "========================\n";

    while (running == true)
    {
        cout << "1) Set N\n";
        cout << "2) Print numbers 1..N\n";
        cout << "3) Print a line of N stars\n";
        cout << "4) Compute sum and average of 1..N\n";
        cout << "5) Count evens and odds from 1..N\n";
        cout << "6) Show current stats\n";
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
            cout << "Enter N (1..1000): ";
            cin >> N;
            if (cin.fail())
            {
                cout << "Invalid input. N unchanged.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            if (N > 1000 || N < 1)
            {
                cout << "Out of range. N unchanged.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            break;
        case 2:
            if (N == 0)
            {
                cout << "N is not set.\n";
            }
            else
            {
                for (int i = 1; i <= N; i++)
                {
                    cout << i << "\n";
                }
            }
            break;
        case 3:
            if (N == 0)
            {
                cout << "N is not set.\n";
            }
            else
            {
                for (int i = 1; i <= N; i++)
                {
                    cout << "*";
                }
                cout << "\n";
            }
            break;
        case 4:
            if (N == 0)
            {
                cout << "N is not set.\n";
            }
            else
            {
                sum = 0;
                for (int i = 1; i <= N; i++)
                {
                    sum = sum + i;
                }
                average = (double)sum / N;
                cout << "Sum = " << sum << "\n";
                cout << "Average = " << average << "\n";
            }
            break;
        case 5:
            if (N == 0)
            {
                cout << "N is not set.\n";
            }
            else
            {
                evenCount = 0;
                oddCount = 0;
                for (int i = 1; i <= N; i++)
                {
                    if (i % 2 == 0)
                    {
                        evenCount = evenCount + 1;
                    }
                    else
                    {
                        oddCount = oddCount + 1;
                    }
                }
                cout << "Evens = " << evenCount << "\n";
                cout << "Odds = " << oddCount << "\n";
            }
            break;
        case 6:
            cout << "N = " << N << "\n";
            cout << "sum = " << sum << "\n";
            cout << "average = " << average << "\n";
            cout << "evenCount = " << evenCount << "\n";
            cout << "oddCount = " << oddCount << "\n";
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