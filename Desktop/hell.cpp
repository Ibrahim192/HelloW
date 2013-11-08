#include<iostream>
using namespace std;
class base
{
    public:
    virtual void disp()=0;//    {
//        cout<<"This is base";
//    }
};
class der1:public base
{
    public:
    void disp()
    {

        cout<<"D1!!!";
    }
};
class der2:public der1
{

    public:
    void disp()
    {
        cout<<"D2TOO";
    }
};
void f(der1 &r)
{

    r.disp();
}
int main()
{

    der1 d;
    der2 c;

    f(d);
    f(c);
    return 0;
}
