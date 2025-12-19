#include <iostream>
using namespace std;

const int CAPACITY = 10;

void printHeader();
void printMenu();
int readMenuChoice();

int readIntOrFail();

void addValue(int data[], int &count);
void listValues(const int data[], int count);

int sumArray(const int data[], int count);
double averageArray(const int data[], int count);

int minArray(const int data[], int count);
int maxArray(const int data[], int count);

void countEvensOdds(const int data[], int count, int &evens, int &odds);

int findValue(const int data[], int count, int target);

void clearAll(int &count);

int main()
{
    int data[CAPACITY];
    int count = 0;
    bool running = true;
    int choice;

    printHeader();
    while (running == true)
    {
        printMenu();
        choice = readMenuChoice();
        if (choice == -1)
            continue;
        switch (choice)
        {
        case 1:
            addValue(data, count);
            break;
        case 2:
            listValues(data, count);
            break;
        case 3:
        {
            if (count == 0)
            {
                cout << "No values stored.\n";
            }
            else
            {

                int sum = sumArray(data, count);
                double avg = averageArray(data, count);
                cout << "Sum: " << sum << "\n";
                cout << "Average: " << avg << "\n";
            }
            break;
        }
        case 4:
        {
            if (count == 0)
            {
                cout << "No values stored.\n";
            }
            else
            {
                int mn = minArray(data, count);
                int mx = maxArray(data, count);
                cout << "Min: " << mn << "\n";
                cout << "Max: " << mx << "\n";
            }
            break;
        }
        case 5:
        {
            int evens = 0;
            int odds = 0;
            if (count == 0)
            {
                cout << "No values stored.\n";
            }
            else
            {
                countEvensOdds(data, count, evens, odds);
                cout << "Evens: " << evens << "\n";
                cout << "Odds: " << odds << "\n";
            }
            break;
        }
        case 6:
        {
            if (count == 0)
            {
                cout << "No values stored.\n";
            }
            else
            {
                int target = readIntOrFail();
                if (target != 999999999)
                {
                    int index = findValue(data, count, target);
                    if (index == -1)
                    {
                        cout << "Not found.\n";
                    }
                    else
                    {
                        cout << "Found at index: " << index << "\n";
                    }
                }
            }
            break;
        }
        case 7:
            clearAll(count);
            cout << "All values cleared.\n";
            break;
        case 8:
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
    cout << "  ARRAY PANEL v1.0\n";
    cout << "========================\n";
}
void printMenu()
{
    cout << "1) Add a value\n";
    cout << "2) List values\n";
    cout << "3) Show sum and average\n";
    cout << "4) Show min and max\n";
    cout << "5) Count evens and odds\n";
    cout << "6) Find a value\n";
    cout << "7) Clear all values\n";
    cout << "8) Exit\n";
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
int readIntOrFail()
{
    int val;
    cout << "Enter value to find: ";
    cin >> val;
    if (cin.fail())
    {
        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return 999999999;
    }
    return val;
}
void addValue(int data[], int &count)
{
    int num;
    if (count == CAPACITY)
    {
        cout << "Array is full.\n";
    }
    else
    {
        cout << "Enter an integer to add: ";
        cin >> num;
        if (cin.fail())
        {
            cout << "Invalid input. Value not added.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            data[count] = num;
            count++;
        }
    }
}
void listValues(const int data[], int count)
{
    if (count == 0)
    {
        cout << "No values stored.\n";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << "[" << i << "] = " << data[i] << "\n";
        }
    }
}
int sumArray(const int data[], int count)
{
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum = data[i] + sum;
    }
    return sum;
}
double averageArray(const int data[], int count)
{
    double avg = 0;
    double sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum = data[i] + sum;
    }
    avg = sum / count;
    return avg;
}
int minArray(const int data[], int count)
{
    int mn = data[0];
    for (int i = 1; i < count; i++)
    {
        if (mn > data[i])
        {
            mn = data[i];
        }
    }
    return mn;
}
int maxArray(const int data[], int count)
{
    int mx = data[0];
    for (int i = 1; i < count; i++)
    {
        if (mx < data[i])
        {
            mx = data[i];
        }
    }
    return mx;
}
void countEvensOdds(const int data[], int count, int &evens, int &odds)
{
    evens = 0;
    odds = 0;
    for (int i = 0; i < count; i++)
    {
        if (data[i] % 2 == 0)
        {
            evens++;
        }
        else
        {
            odds++;
        }
    }
}
int findValue(const int data[], int count, int target)
{
    for (int i = 0; i < count; i++)
    {
        if (data[i] == target)
        {
            return i;
        }
    }
    return -1;
}
void clearAll(int &count)
{
    count = 0;
}
