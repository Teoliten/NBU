#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person();
    void setFirstName(const string &);
    string getFirstName() const;

private:
    string first_name;
    string surname;
    int cit_numb;
};

Person::Person(const string &frist_name, const string &surname, int cit_number)
{
    this->first_name = first_name;
    this->surname = surname;
    this->cit_numb = cit_numb;
}

class Student : public Person //denotes inheritance
{
public:
    void setFirstName(const string &);
    string getFirstName() const;
    void setFNumber(const string &);
    int getFNumber() const;
private:
    int f_number;
};

Student::Student(const string &first_name, const string &surname, int cit_number) 
: Person(first_name, surname, cit_numb)
{
    this->f_numb = f_numb;
}

int main()
{
    /*Object-Oriented Programming: data abstraction, encapsulation, inheritance, polymorphism
    
    */
    return 0;
}//main