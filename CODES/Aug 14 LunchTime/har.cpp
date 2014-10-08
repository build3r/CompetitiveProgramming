#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    string s;
    cin >> T;
    while(T--)
    {
        cin >> s;
        string s2="";
        int len=s.length();
            int f=1,j=len-1;
            for(int i=0;i<len/2;i++)
            {
                if(s[i]!=s[j--])
                {
                    f=0;
                    break;
                }
            }
            if(f)
        cout << 1 << endl;
        else
        {
                cout<<2<<endl;;

        }
    }
    return 0;
}
