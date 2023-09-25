#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

struct student
{
    int rollno;
    string name, section;
    float cgpa;
    student(int roll, const string &n, const string &S, float grade)
        : rollno(roll), name(n), section(S), cgpa(grade) {}
};

vector<student> studentrecord;
int getIntInput(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            // Input is an integer, break out of the loop
            break;
        }
        else
        {
            // Input is not an integer, clear the input buffer and try again
            cout << "Invalid input. Please enter an integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}
float getFloatInput(const string &prompt)
{
    float value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            // Input is a float, break out of the loop
            break;
        }
        else
        {
            // Input is not a float, clear the input buffer and try again
            cout << "Invalid input. Please enter a floating-point number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return value;
}
void swapStudents(student &a, student &b)
{
    student temp = a;
    a = b;
    b = temp;
}
void selectionSort()
{
    int n = studentrecord.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (studentrecord[j].rollno < studentrecord[minIndex].rollno)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapStudents(studentrecord[i], studentrecord[minIndex]);
        }
    }
}
void Ranking()
{
    int n = studentrecord.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (studentrecord[j].cgpa > studentrecord[minIndex].cgpa)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapStudents(studentrecord[i], studentrecord[minIndex]);
        }
    }
    cout << left << setw(50) << "STUDENTS RECORDS" << endl
         << endl
         << endl;
    cout << left << setw(15) << "Roll Number"
         << "|" << left << setw(40) << "Name"
         << "|" << left << setw(10) << "Section"
         << "|" << left << setw(5) << "Mark"
         << "|" << endl
         << endl;

    for (int i = 0; i < studentrecord.size(); i++)
    {
        cout << left << setw(15) << studentrecord[i].rollno << "|" << left << setw(40) << studentrecord[i].name << "|" << left << setw(10) << studentrecord[i].section << "|" << left << setw(5) << studentrecord[i].cgpa << "|" << endl;
    }
}
int menu()
{

    int choice;
    cout << endl
         << right << setw(30) << "Main Menu" << endl
         << endl;
    cout << right << setw(25) << "1"
         << " Add a New Student." << endl;
    cout << right << setw(25) << "2"
         << " Delete Student Record." << endl;
    cout << right << setw(25) << "3"
         << " Search Details." << endl;
    cout << right << setw(25) << "4"
         << " Update Student Record." << endl;
    cout << right << setw(25) << "5"
         << " Display Student Record." << endl;
    cout << right << setw(25) << "6"
         << " Ranking." << endl;
    cout << right << setw(25) << "0"
         << " Save Student Record." << endl;
    cout << right << setw(25) << "999"
         << " Exit." << endl;
    cout << endl
         << endl
         << "PLEASE ENTER YOUR CHOICE!!!!" << endl;

    cin >> choice;
    return choice;
}

void Add()
{
    cin.ignore();
    string Name, Section;
    int Rollno;
    float Cgpa;
    cout << "Please Enter The Following Details" << endl;
    cout << "Student name : ";
    getline(cin, Name);
    Rollno = getIntInput("Enter Student roll number: ");
    cin.ignore();
    cout << "\nEnter Student Section : ";
    getline(cin, Section);
    Cgpa = getFloatInput("Enter Student Marks (in CGPA): ");
    cout << "\nPRESS ANY KEY TO RETURN TO THE MAIN MENU!!!" << endl;

    studentrecord.push_back(student(Rollno, Name, Section, Cgpa));
}

void Delete()
{
    int deleteRollNumber;
    cout << "Enter the roll number of the student to delete: ";
    cin >> deleteRollNumber;
    bool deleted = false;

    for (int i = 0; i < studentrecord.size(); i++)
    {
        if (deleteRollNumber == studentrecord[i].rollno)
        {
            studentrecord.erase(studentrecord.begin() + i);
            deleted = true;
            cout << "Student Record Deleted." << endl;
            break;
        }
    }

    if (!deleted)
    {
        cout << "Student with Roll Number " << deleteRollNumber << " not found." << endl;
    }
}

void Search()
{
    int id;
    cout << "Enter the roll number to search for: ";
    cin >> id;
    bool found = false;

    cout << left << setw(15) << "Roll Number"
         << "|" << left << setw(40) << "Name"
         << "|" << left << setw(10) << "Section"
         << "|" << left << setw(5) << "Mark"
         << "|" << endl;
    for (int i = 0; i < studentrecord.size(); i++)
    {
        if (id == studentrecord[i].rollno)
        {
            cout << left << setw(15) << studentrecord[i].rollno << "|" << left << setw(40) << studentrecord[i].name << "|" << left << setw(10) << studentrecord[i].section << "|" << left << setw(5) << studentrecord[i].cgpa << "|" << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with Roll Number " << id << " not found." << endl;
    }
}

void Update()
{
    int updateRollNumber;
    cout << "Enter the roll number of the student to update: ";
    cin >> updateRollNumber;
    cin.ignore();
    bool updated = false;

    for (int i = 0; i < studentrecord.size(); i++)
    {
        if (studentrecord[i].rollno == updateRollNumber)
        {
            cout << "Update Name: ";
            getline(cin, studentrecord[i].name);
            cout << "Update Rollno: ";
            cin >> studentrecord[i].rollno;
            cin.ignore();
            cout << "Update Section: ";
            getline(cin, studentrecord[i].section);
            cout << "Update CGPA: ";
            cin >> studentrecord[i].cgpa;
            updated = true;
            cout << "Student record updated successfully." << endl;
            break;
        }
    }

    if (!updated)
    {
        cout << "Student not found." << endl;
    }
}

void saveRecord()
{
    ofstream myfile("StudentRecord.txt");
    int flag = 0;

    if (myfile.is_open())

    {

        myfile << left << setw(50) << "STUDENTS RECORDS" << endl
               << endl
               << endl;
        myfile << left << setw(15) << "Roll Number"
               << "|" << left << setw(40) << "Name"
               << "|" << left << setw(10) << "Section"
               << "|" << left << setw(5) << "Mark"
               << "|" << endl
               << endl;
        selectionSort();
        for (int i = 0; i < studentrecord.size(); i++)
        {
            myfile << left << setw(15) << studentrecord[i].rollno << "|" << left << setw(40) << studentrecord[i].name << "|" << left << setw(10) << studentrecord[i].section << "|" << left << setw(5) << studentrecord[i].cgpa << "|" << endl;
        }
        myfile.close();
        flag = 1;
    }

    if (flag)
    {
        cout << "Student records saved to file." << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
}
void Display()
{
    cout << left << setw(50) << "STUDENTS RECORDS" << endl
         << endl
         << endl;
    cout << left << setw(15) << "Roll Number"
         << "|" << left << setw(40) << "Name"
         << "|" << left << setw(10) << "Section"
         << "|" << left << setw(5) << "Mark"
         << "|" << endl
         << endl;
    selectionSort();
    for (int i = 0; i < studentrecord.size(); i++)
    {
        cout << left << setw(15) << studentrecord[i].rollno << "|" << left << setw(40) << studentrecord[i].name << "|" << left << setw(10) << studentrecord[i].section << "|" << left << setw(5) << studentrecord[i].cgpa << "|" << endl;
    }
}

int main()
{
    int flag = 1;
    do
    {
        switch (menu())
        {
        case 1:
            Add();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Search();
            break;
        case 4:
            Update();
            break;
        case 5:
            Display();
            break;
        case 6:
            Ranking();
            break;
        case 0:
            saveRecord();
            break;
        case 999:
            flag = 0;
            break;
        default:
            cout << "Invalid choice!!!. Please try again." << endl;
            break;
        }
    } while (flag);
    return 0;
}
