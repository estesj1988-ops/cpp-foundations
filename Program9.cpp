#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// fixed array size
const int CAPACITY = 10;
// function prototypes
void printHeader();
void printMenu();
int readMenuChoice();
void addRecord(int values[], string labels[], int &count);
void listRecord(const int values[], const string labels[], int count);
void editRecord(int values[], string labels[], int count);
void deleteRecord(int values[], string labels[], int &count);
int findLabel(const string labels[], int count, const string &target);
string readString();
void sortbyValue(int values[], string labels[], int count);
void clearAll(int &count);
void savetoFile(const int values[], const string labels[], int count);
void loadtoFile(int values[], string labels[], int &count);

int main() // main program
{
    // intilizing variables
    int values[CAPACITY];
    string labels[CAPACITY];
    bool running = true;
    int choice;
    int count = 0;

    printHeader();          // print header
    while (running == true) // loop menu
    {
        printMenu();               // print menu options
        choice = readMenuChoice(); // read menu choice
        if (choice == -1)
            continue;
        switch (choice) // each menus choice case
        {
        case 1: // add new record
            addRecord(values, labels, count);
            break;
        case 2: // output all records
            listRecord(values, labels, count);
            break;
        case 3: // edit an exsisting record
            if (count == 0)
            {
                cout << "No values stored.\n";
            }
            else
            {
                editRecord(values, labels, count);
            }
            break;
        case 4: // delete an exsisting record
            if (count == 0)
            {
                cout << "No values stored.\n";
            }
            else
            {
                deleteRecord(values, labels, count);
            }
            break;
        case 5: // find a record by the label
        {
            if (count == 0)
            {
                cout << "No values stored.\n";
            }
            else
            {
                string target = readString();

                int index = findLabel(labels, count, target);
                if (index == -1)
                {
                    cout << "Not found.\n";
                }
                else
                {
                    cout << "Found at index: " << index << "\n";
                }
            }
            break;
        }
        case 6: // sort records by values
            if (count == 0)
            {
                cout << "No values stored.\n";
            }
            else
            {
                sortbyValue(values, labels, count);
                cout << "Values sorted using Selection Sort.\n";
            }
            break;
        case 7: // save records to file
            savetoFile(values, labels, count);
            break;
        case 8: // load records from file
            loadtoFile(values, labels, count);
            break;
        case 9: // clear all records
            clearAll(count);
            cout << "All records cleared.\n";
            break;
        case 10: // exit program
            cout << "Exiting program.\n";
            running = false;
            break;
        default: // error handling for switch case
            cout << "Invalid menu option.\n";
            break;
        }
    }
    return 0;
}
void printHeader() // header function
{

    cout << "==============================\n";
    cout << "   RECORD MANAGEMENT PANEL\n";
    cout << "==============================\n";
}
void printMenu() // menu function
{
    cout << "1) Add a record\n";
    cout << "2) List records\n";
    cout << "3) Edit a record\n";
    cout << "4) Delete a record\n";
    cout << "5) Find by label\n";
    cout << "6) Sort by value\n";
    cout << "7) Save to file\n";
    cout << "8) Load from file\n";
    cout << "9) Clear all records\n";
    cout << "10) Exit\n";
    cout << "Enter choice: ";
}
int readMenuChoice() // menu choice function
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
void addRecord(int values[], string labels[], int &count) // add new record function
{
    int num;
    string lab;

    if (count == CAPACITY)
    {
        cout << "Array is full.\n";
    }
    else
    {
        cout << "Enter a label to add: ";
        cin >> lab;
        cout << "Enter an integer to add: ";
        cin >> num;
        if (cin.fail())
        {
            cout << "Invalid input. Record not added.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        else
        {
            values[count] = num;
            labels[count] = lab;
            count++;
        }
    }
}
void listRecord(const int values[], const string labels[], int count) // list all record function
{
    if (count == 0)
    {
        cout << "No records stored.\n";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << "[" << i << "] = " << labels[i] << " " << values[i] << "\n";
        }
    }
}
void editRecord(int values[], string labels[], int count)
{
    int index;
    int num;
    string lab;
    cout << "Which index would you like to modify? ";
    cin >> index;
    if (cin.fail() || index < 0 || index >= count)
    {
        cout << "Invalid index.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    cout << "Enter new label: ";
    cin >> lab;
    cout << "Enter new value: ";
    cin >> num;
    if (cin.fail())
    {
        cout << "Invalid input. Record not modified.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    values[index] = num;
    labels[index] = lab;
}
void deleteRecord(int values[], string labels[], int &count)
{
    int index;
    cout << "Enter index to delete: ";
    cin >> index;
    if (cin.fail() || index < 0 || index >= count)
    {
        cout << "Invalid index.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    for (int i = index; i < count - 1; i++)
    {
        values[i] = values[i + 1];
        labels[i] = labels[i + 1];
    }
    count--;
}
string readString()
{
    string lab;
    cout << "Enter label to find: ";
    cin >> lab;
    return lab;
}
int findLabel(const string labels[], int count, const string &target)
{
    for (int i = 0; i < count; i++)
    {
        if (labels[i] == target)
        {
            return i;
        }
    }
    return -1;
}
void sortbyValue(int values[], string labels[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        int minI = i;
        for (int j = i + 1; j < count; j++)
        {
            if (values[j] < values[minI])
            {
                minI = j;
            }
        }
        if (minI != i)
        {
            int tmp = values[i];
            values[i] = values[minI];
            values[minI] = tmp;

            string labtmp = labels[i];
            labels[i] = labels[minI];
            labels[minI] = labtmp;
        }
    }
}
void savetoFile(const int values[], const string labels[], int count)
{
    ofstream out("records.txt");

    if (out.fail())
    {
        cout << "Error opening file.\n";
        return;
    }
    out << count << "\n";
    for (int i = 0; i < count; i++)
    {
        out << labels[i] << " " << values[i] << "\n";
    }
    out.close();
    cout << "Records saved.\n";
}
void loadtoFile(int values[], string labels[], int &count)
{
    ifstream fin("records.txt");
    if (fin.fail())
    {
        cout << "Error opening file.\n";
        return;
    }

    int newCount = 0;
    fin >> newCount;

    if (fin.fail())
    {
        cout << "File is corrupt or empty.\n";
        return;
    }

    if (newCount < 0) newCount = 0;
    if (newCount > CAPACITY) newCount = CAPACITY;

    for (int i = 0; i < newCount; i++)
    {
        fin >> labels[i] >> values[i];   // ✅ label then value (matches save)
        if (fin.fail())
        {
            cout << "Error reading record " << i << ".\n";
            count = i; // keep what we successfully loaded
            return;
        }
    }

    count = newCount;
    cout << "Loaded " << count << " record(s).\n";
}
void clearAll(int &count)
{
    count = 0;
}