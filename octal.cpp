#include<iostream>
#include<iomanip>
using namespace std;
class octal
{
    int n;
    public:
    octal(int m)
    {
        n=m;
    }
    friend int operator+(octal n1,octal n2);
    friend ostream &operator<<(ostream &out,octal o);
};
int operator+(octal n1,octal n2)
{
    return(n1.n+n2.n);
}
ostream &operator<<(ostream &out,octal o)
{
    out<<setbase(8)<<o.n<<endl;
    return out;
}
int main()
{
    int x,k,y;
    cout<<"Enter the deciaml no. : ";
    cin>>x;
    octal h=x;
    cout<<"Octal conversion of "<<x<<" is: "<<h;
    cout<<"enter 2nd decimal no. : ";
    cin>>k;
    y=h+k;
    cout<<"Addition of 2 decimal nos is "<<y;
    return 1;
}

