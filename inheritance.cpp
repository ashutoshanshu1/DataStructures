#include<bits/stdc++.h>
using namespace std;

class Person
{
    int id;
    char name[100];
    public:

    void setP()
    {
        cout<<"Enter ID: ";
        cin>>id;
        cout<<"Enter Name: ";
        cin>>name;  
    }
    void displayP()
    {
        cout<<endl<<"ID: "<<id<<"\nName: "<<name<<endl;
    }
};

class Student:public Person
 Person
{
    char course[50];
    int fee;
    public:
        void set_s()
        {
            setP();
            cout << "Enter the Course Name:";
            cin >> course;
            cout << "Enter the Course Fee:";
            cin >> fee;
        }
 
        void display_s()
        {
            displayP();
            cout <<"Course: "<< course << "\nFee: " << fee << endl;
        }
};

int main()
{
    Student s;
    s.set_s();
    s.displayP();
}