#include<iostream>
#include<fstream>
using namespace std;
class stud
{
    public:
    int rno,per;
    char name[50];
    void add()
    {
        cout<<"enter name rno percentage\n";
        cin>>name;
        cin>>rno>>per;
    }
};


int main()
{
    stud ob;
    int c=0;
    ofstream fp("dat", ios::in | ios::binary);
    if(!fp)
    {
        cout<<"cannot open/create file\n";
        return -1;
    }
    while(c!=-1)
    {
        cout<<"1.add data   2.dis   -1 exit\n";
        cin>>c;
        switch(c)
        {
            case 1:if(fp==NULL)
            {
              ofstream fp("dat", ios::in | ios::binary);
              fp.seekp(0,ios::end);
            if(!fp)
            {
                    cout<<"cannot open/create file\n";
                    return -1;
            }
            }
                    ob.add();
                   fp.write((char *)&ob, sizeof(class stud));
                   break;
            case 2:fp.close();
                   ifstream fp("dat", ios::out | ios::binary);
                   if(!fp)
                    {
                    cout<<"cannot open/create file\n";
                    return -1;
                    }
                    while(fp!=NULL)
                    {
                    fp.read((char *)&ob,sizeof(class stud));
                    cout<<"name="<<ob.name<<endl;
                    cout<<"Roll no="<<ob.rno<<"\npercentage="<<ob.per<<endl;
                    }
                    fp.close();
                    break;
           // default:cout<<"wrong choice\n";

        }
    }
    return 0;
}
