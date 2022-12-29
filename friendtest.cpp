#include <iostream>
using namespace std;

class Line{
    public:
        Line() {}
        Line(int para);

        friend int geta(Line line);

        virtual ~Line()
        {
            cout<<"Line is end!"<<endl;
        }

    private:
        int a;
};

Line::Line(int para):a(para)
{
    //a=para;
    cout<<"Line is initialed!"<<endl;
}

int geta(Line line)
{         
    cout<<"a="<<line.a<<endl;
}

class Rectan: public Line
{
    public:
        Rectan() //: Line(6)
        {
            cout<<"Rectan is initialed!"<<endl;
            ptr = new int;
        }

        ~Rectan()
        {
            cout<<"Rectan is end!"<<endl;
            delete ptr;
        }
    private:
        int *ptr;

};

int main() {
    // Line line(6);
    // cout<<"geta="<<geta(line)<<endl;

    Rectan rec;

}