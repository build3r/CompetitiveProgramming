#include<iostream>
using namespace std;
class b
{
public:
	virtual void fn()=0;
	/*{
	    cout<<"call from b\n";
	}*/
};
class d1:public b
{
public:
	void fn()
	{
		cout<<"call from d1\n";
	}
};
class d2:public b
{
public:
	void fn()
	{
		cout<<"Call from d2\n";
	}
};
int main()
{
	b *p;
	d1 ob1;
	d2 ob2;
	//ob1.fn();
	//ob2.fn();
	//p=&f;
	//p->fn();
	p=&ob1;
	p->fn();
	p=&ob2;
    p->fn();
	return 0;
}
