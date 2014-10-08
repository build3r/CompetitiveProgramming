#include<iostream>
using namespace std;
class fig
{
    protected:
    float r,l,b,x,y,area;
   public:virtual void cal()=0;
   virtual void cal(float,float)=0;
    virtual void cal(float,float,float)=0;
};

class cir:public fig
{
   public: /*cir(float i)
    {
        r=i;
    }*/
    void cal(float k)
    {
        cout<<"the area of circle is"<<3.142*k*k<<endl;
    }
    void cal(float g,float h)
    {
        cout<<"the area of triangle is"<<g*h<<endl;
    }
    void cal(float d,float e,float f)
    {
        cout<<"the area of trianle is"<<d*e*f<<endl;
    }
};
class rec:public fig
{
  public:  /*rec(double i,double j)
    {
        l=i;
        b=j;
    }*/
    void cal(float k)
    {
        cout<<"the area of circle is"<<3.142*k*k<<endl;
    }
    void cal(float g,float h)
    {
        cout<<"the area of triangle is"<<g*h<<endl;
    }
    void cal(float d,float e,float f)
    {
        cout<<"the area of trianle is"<<d*e*f<<endl;
    }
};

class tri:public fig
{
   public:/* tri(double i,double j)
    {
        x=i;
        y=j;
    }*/
     void cal(float k)
    {
        cout<<"the area of circle is"<<3.142*k*k<<endl;
    }
    void cal(float g,float h)
    {
        cout<<"the area of triangle is"<<g*h<<endl;
    }
    void cal(float d,float e,float f)
    {
        cout<<"the area of trianle is"<<d*e*f<<endl;
    }
};

int main()
{
    fig *p;
    cir ob1;
    rec ob2;
    tri ob3;
    p=&ob1;
    p->cal(10);
    p=&ob2;
    p->cal(8,5);
    p=&ob3;
    p->cal(2,4,6);
    return 0;
}
