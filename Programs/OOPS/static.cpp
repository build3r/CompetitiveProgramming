#include<iostream>
using namespace std;
class test
{
    static int count;
    int code;
    public:
    test(int x)
    {
        code=x;
        count++;
    }
    void static showc();
    void show()
    {
        showc();
        cout<<"  Code is:"<<code<<endl;
    }
    ~test()
    {
        count--;
        cout<<"There are "<<count<<" Objects remaining\n";
    }
};
void test::showc()
{
    cout<<"No of Object are: "<<count;
}
int test::count=0;
int main()
{
    test ob1(10);
    test ob2(20);
    test ob3(30);
    ob1.show();
    ob2.show();
    ob3.show();

}
