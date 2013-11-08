#include<iostream>
#include<string.h>
using namespace std;

class string
{
    char *a;
    int len;
    public:
    string()
    {
        a=NULL;
        len=0;

    }
    string(const char *x)
    {
        len=strlen(x);
        a=new char[len+1];
        strcpy(a,x);

    }
    string(string &x)
    {

        len=x.len;
        a=new char[len+1];
        strcpy(a,x.a);
    }
    string operator+(string &x)
    {

        string z;
        int l=len+x.len;
        z.len=l+1;
        z.a=new char[l+1];
        strcpy(z.a,a);
        strcat(z.a,x.a);
        return z;
    }
    friend ostream &operator<<(ostream &o,string &x);
};
ostream &operator<<(ostream &o,string &x)
{
    o<<"string is "<<x.a<<endl;
    return o;
}
void main()
{
    clrscr();
    string s1="vtu ",s2="belgaum";
    string s3=s1+s2;
    cout<<"string 1 : "<<s1<<endl;
    cout<<"string 2 : "<<s2<<endl;
    cout<<"string 3 : "<<s3<<endl;
    getch();
}
