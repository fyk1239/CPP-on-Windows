#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name, sex;
    int age;

public:
    Person() {}
    void Person_show()
    {
        cout << "Name:" << name << " Sex:" << sex << " Age:" << age << endl;
    }
};
class Teacher : public Person
{
private:
    string title;

public:
    Teacher() {}
    void Teacher_show()
    {
        cout << "Title:" << title << endl;
    }
};

class Cadre:public Teacher
{
private:
    string post;
public:
    Cadre(){}
    void Cadre_show()
    {
        cout << "Post:" << post << endl;
    }
};

class TeacherCadre:public Teacher,public Cadre
{
private:
    int wage;
public:
    
};

int main()
{

    system("pause");
    return 0;
}