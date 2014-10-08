#include<bits/stdc++.h>
using namespace std;
string s,sb;
int i,ct=0,tt=0;
int main()
{

    cin>>s;
    sb='a';

  while(s.find(sb)!=string::npos)
  {
      sb+='a';
  }
//    freopen("lex.txt","w",stdout);
//    while(tt++ < 100000)//s.find(sb)!=string::npos)
//    {
//
//        cout<<"sb = "<<sb<<endl;
//        ct++;
//        if(ct>25)
//         {
//    for(i=sb.length()-1;i>=0;i--)
//        {
//            if(sb[i]>='z')
//            {
//                if(sb[0]>='z')
//                {
//                    int k=sb.length();
//                sb.clear();
//
//                for(int j=0;j<k+1;j++)
//                    sb+='a';
//                }
//
//                sb[i-1]++;
//                sb[i]='a';
//
//            }
//        }
//        ct=0;
//         }
//        else
//            sb[sb.length()-1]++;
//    }
    cout<<sb<<endl;
    return 0;
}
