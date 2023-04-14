#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
    public:
        string name;
        int age;
        int id;
        Student(){}
        Student(string name, int age, int id):name(name),age(age),id(id) {}

        // idup agedown
        static bool compare1(Student o1, Student o2)
        {
            return o1.id != o2.id?(o1.id<o2.id):(o1.age>o2.age);
        }
    private:
};

// idup agedown
bool compare1(Student o1, Student o2)
{
    return o1.id != o2.id?(o1.id<o2.id):(o1.age>o2.age);
};

int main() {
    Student s1("student1", 10, 1);
    Student s2("student2", 20, 2);
    Student s3("student3", 6, 4);
    Student s4("student4", 12, 3);
    Student s5("student5", 66, 4);
    // 

    vector<Student> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);
    v.push_back(s5);

    Student stu;
    sort(v.begin(), v.end(), compare1);
    for (Student ev : v)
    {
        cout<<"I am student "<<ev.name<<" age="<<ev.age<<" id="<<ev.id<<endl;
    }
}