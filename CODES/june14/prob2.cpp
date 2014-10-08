    #include<iostream>
    #include<map>
    #include<string>
    using namespace std;
    int main()
    {
    map<char, char> mymap;
    string s;
    int i,j,k,n,t,f,lpos,rpos;
    char x,y;
    cin>>t;
    while(t--)
    {
    f=0;
    mymap.clear();
    s.clear();
    cin>>n;
    for(i=0;i<n;i++)
    {
    cin>>x>>y;
    mymap[x]=y;
    }
    cin>>s;
    int len=s.length();
    for(i=0;i<len;i++)
    {

    if(mymap.find(s[i])!=mymap.end())
    {

    s[i]=mymap[s[i]];

    }
             if(s[i]=='.')
            f=1;
    }
    lpos=0;
    rpos=len-1;
    for(i=0;i<len;i++)
    {
    if(s[i]=='0')
    {lpos++;
    }
    else
    break;
    }
    if(f)
    for(i=len-1;i>=0;i--)
    {
    if(s[i]=='0')
    {rpos--;
    }
    else if(s[i]=='.')

    {
    rpos--;
    break;
    }
    else
    break;
    }
    if(rpos<lpos)
    cout<<"0";
    else
   {rpos-=lpos;
   cout<<s.substr(lpos,rpos+1);}
    cout<<endl;

    }
    return 0;
    }
