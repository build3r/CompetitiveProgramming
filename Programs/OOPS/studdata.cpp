#include<iostream>
#include<fstream>
using namespace std;
class stud
{
    public:
    int rno;
    char n[20];
    float per;
    void read()
    {
        cin>>rno>>n>>per;
    }
};
int main()
{
    stud s[5];
    ofstream da("C:\stud",ios::binary);
    if(!da)
    {
        cout<<"can't open file \n";
        return 1;
    }
    cout<<"Enter 5 studs dat\n";
    for(int i=0;i<5;i++)
    {
        //cin>>s.rno>>s.n>>s.per;
        s[i].read();
        da.write((char *)&(s[i]),sizeof(s[i]));
    }
    da.close();
    ifstream dat("C:\stud",ios::binary);
    if(!dat)
    {
        cout<<"can't open file \n";
        return 1;
    }
    for(int i=0;i<5;i++)
    {
        dat.read((char *)&s[i],sizeof(s));
        cout<<"\nroll np="<<s[i].rno<<"\nName="<<s[i].n<<"\n percentage="<<s[i].per<<endl;
    }
    dat.seekg(3*sizeof(s[3]),ios::beg);
    dat.read((char *)&s[3],sizeof(s[0]));
    cout<<"\n\n4th student\n";
    cout<<"\nroll np="<<s[3].rno<<"\nName="<<s[3].n<<"\n percentage="<<s[3].per<<endl;
    dat.close();
    return 0;
}
