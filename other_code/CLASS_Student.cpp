#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
class Student
{
private:
    float gpa;
    string firstname, lastname;
    char sex;
    int grade;
    int Study_time;

public:
    Student(string &fn, string &ln, char &s)
    {
        sex = s;
        firstname = fn;
        lastname = ln;
        gpa = 0.0f;
        grade = 1;
        Study_time = 0;
    }
    ~Student() {}
    void show_myself()
    {
        cout << firstname << "'s gpa is " << gpa << endl;
    }
    int study_time(int n)
    {
        Study_time += n;
        gpa = log(Study_time) > 4.0f ? 4.0f : gpa + log(Study_time);
    }
    int upgrade(int grade)
    {
        int tmp = this->grade;
        this->grade = grade;
        return tmp;
    }
};

int main()
{
    vector<Student> student_list;

    return 0;
}