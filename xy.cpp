#include<iostream>
#include <iomanip>
using namespace std;
class OCTAL
{
        int n;
        public: OCTAL(int m)
                        {
                                n=m;
                        }
                        friend int operator+(OCTAL n1,OCTAL n2);
                        friend ostream & operator<<(ostream &p,OCTAL o);
};
int operator+(OCTAL n1,OCTAL n2)
  {
   return(n1.n+n2.n);
  }
 ostream & operator<<(ostream & p,OCTAL o)
  {
    p<<setbase(8)<<o.n<<endl;;
    return p;
  }
  int main()
  {
   int x,k,y;
   cout<<"enter the decimal no\n";
   cin>>x;
   OCTAL h=x;
   cout<<"the convert 1sr OCTAL num is\n"<<h;
   cout<<"enter the 2nd decimal num\n";
   cin>>k;
   y=h+k;
   cout<<"addition of two octal nos is\n"<<y;
   return 1;
  }
