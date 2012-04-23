#include <iostream>
using namespace std;

class Box
{
int x,y,z;
public:
Box()
{
cout<<"Zero arg constructor"<<endl;
}
Box(int a,int b, int c)
{
x=a;y=b;z=c;
cout<<"Three arg constructor"<<endl;
}
~Box()
{
cout<<"Destructor called"<<endl;
}
int getvolume()
{
return x*y*z;
}
int set_data(int a, int b, int c)
{
x=a;y=b;z=c;
cout<<"Set data"<<endl;
}
};


main()
{
Box b;
Box c(1,3,5);
cout<<"Volume="<<c.getvolume()<<endl;
cout<<"Volume="<<b.getvolume()<<endl;
Box *x;
x=new Box;
x->set_data(4,5,6);


cout<<"Volume="<<x->getvolume()<<endl;
Box *y;
y=new Box(7,8,9);
cout<<"Volume="<<y->getvolume()<<endl;


Box *z=new Box[10];
//Box *a=new (Box(2,3,4))[5];
delete x;
delete y;
return 0;
}
