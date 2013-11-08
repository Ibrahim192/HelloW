#include<iostream>
using namespace std;
int days_in_mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class date
{
    int dd,mm,yy;
    long int no_of_days;
    public:
    date()
    {
        dd=mm=yy=no_of_days=0;

    }
    int leap(int n)
    {

        return ((n%4==0&&n%100!=0)||n%400==0);
    }
    void convert()
    {

        int i;
        long int sum=0;
        for(i=1900;i<yy;i++)
            sum+=(365+leap(i));
        for(i=1;i<mm;i++)
{



            if(i==2&&leap(yy))
                sum+=29;
            else
                sum+=days_in_mon[i];
        }
        sum+=dd;
        cout<<"no of days: "<<sum<<endl;
        no_of_days=sum;
    }
    int operator>=(date &d)
    {
            return (no_of_days>=d.no_of_days?1:0);
    }
    int operator-(date &d)
    {
        return (no_of_days-d.no_of_days);
    }
    int validate()
    {

        if(mm<=12)
        {


            if((mm==2)&&leap(yy)&&(dd<=days_in_mon[mm]
                                   +1))
               return 1;
            if(mm!=2&&dd<=(days_in_mon[mm]))
                return 1;
            else
                return 0;
        }
    }
    date operator+(int x)
    {




        int i;
        long int sum=no_of_days+x;

        date t;
        t.no_of_days=sum;
        for(i=1900;sum>366;i++)
            sum-=365+leap(i);
        t.yy=i;
        for(i=1;sum>days_in_mon[i]+1;i++)
        {

            if((i==2)&&(leap(yy)))


                sum-=29;
            else
                sum-=days_in_mon[i];

        }
        t.mm=i;
        t.dd=sum;
        return t;

    }
friend ostream &operator<<(ostream &out,date &d1);
friend istream &operator>>(istream &in,date &d1);

};
ostream &operator<<(ostream &out,date &d1)
{

    out<<d1.dd<<"-"<<d1.mm<<"-"<<d1.yy<<endl;
    return out;
}
istream &operator>>(istream &in,date &d1)
{

    while(1)
    {
        cout<<"enter the date: ";
        in>>d1.dd>>d1.mm>>d1.yy;
        if(d1.validate())
            break;
        else
            cout<<"\n in valid";

    }
    d1.convert();
    return in;
}
int main()
{

    date d1,d2,d3;
    cout<<"enter d1 and d2: ";
    cin>>d1;
    cout<<"enter d1 and d2: ";
    cin>>d2;
    if(d2>=d1)
        cout<<d2<<" "<<d1<<" "<<d2-d1<<endl;
    else
        cout<<"not possible";
    int s;
    cout<<"enter the value of s: ";
    cin>>s;
    d3=d1+s;
    cout<<"result date : "<<d3<<endl;
    return 1;

}

