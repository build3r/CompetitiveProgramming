    #include<stdio.h>
    #include<iostream>
    #include<string>
    #include<stdlib.h>
    #include<list>
    #include<limits.h>
    #define ll long long
    using namespace std;
    int main()
    {
    int n;
    scanf("%d",&n);
    ll p,j,s1=0,s2=0,sum=0,s=0,mid;
    list<ll> ls;
    for(j=0;j<n/2;j++)
    {scanf("%lld",&p);s1+=p;ls.push_back(p);}
    //scanf("%lld",&p);s1+=p;ls.push_back(p);mid=p;
    for(j=n/2;j<n;j++)
    {scanf("%lld",&p);s2+=p;ls.push_back(p);}
    sum=s1-s2;
    s=abs(sum);
    int c=0,f,ct=0;
    string ans,ans1;
    list<ll>::iterator i;
    while(ct<2)
    {ct++;
    //cout<<sum<<endl;
    if(sum<0)
    f=1;
    else if(sum>0)f=0;
    else break;
    for(i=ls.begin(),j=0;j<n/2;j++,i++);
    mid=*i;
    //cout<<mid;
    if(f==0)
    {
    for(i=ls.begin(),j=0;j<n/2;j++,i++)
    {
    if(*i>mid)break;
    }

    if(j==n/2&&(s>abs(sum+2*mid-2*ls.front())))
    {
    i=ls.begin();
    if(s>abs(sum+2*mid-2*(*i)))
    {c++;ans+="1 ";ans+=n;ans+="\n";
    ll value=*i;
    sum=sum+2*mid-2*(*i);
    s=abs(sum);
    ls.erase(i);
    ls.push_back(value);
    }

    }

    else
    { if(c<2&&(s>abs(sum+2*mid-2*(*i))))
    {c++;//cout<<"here";
    ans+=(j+1);ans+=" ";ans+=(n);ans+="\n";
    ll value=*i;
    sum=sum+2*mid-2*(*i);
    s=abs(sum);
    ls.erase(i);
    ls.push_back(value);

    }
    }
    }

    else
    {
    for(i=ls.begin(),j=0;j<n/2;j++,i++)
    {
    if(*i<mid)break;
    }

    if(j==n/2&&(s>abs(sum+2*mid-2*ls.front())))
    {
    i=ls.begin();
    if(s>abs(sum+2*mid-2*(*i)))
    {ans+="1 ";ans+=(n);ans+="\n";c++;ll value=*i;
    sum=sum+2*mid-2*(*i);
    s=abs(sum);
    ls.erase(i);
    ls.push_back(value);
    }
    }

    else
    { if(c<2&&(s>abs(sum+2*mid-2*(*i))))
    {c++;
    ans+=(j+1);ans+=" ";ans+=(n);ans+="\n";
    ll value=*i;
    sum=sum+2*mid-2*(*i);
    s=abs(sum);
    ls.erase(i);
    ls.push_back(value);
    }}}}
    //cout<<c;
    if(c!=0||sum==0){//cout<<"here";
    ans1+=(c);ans1+="\n";
    ans1+=ans;
    cout<<ans1;}
    else if(c==0&&sum!=0)
    { //cout<<mid;
    ll t=0,min=INT_MAX,max=0;
    for(j=1,i=ls.begin();j<n/2;j++,i++);
    list<ll>::iterator k;
    list<ll>::iterator z;
    //cout<<(*i);
    if(f==0)
    {
    for(k=i,j=n/2;j>0;k--,j--)
    {
    if(*k>mid&&(s>abs(sum+2*mid-2*(*k))))
    {
    t=j;
    break;
    }}

    }


    else
    {
    for(k=i,j=n/2;j>0;k--,j--)
    {
    if(*k<mid&&(s>abs(sum+2*mid-2*(*k))))
    {
    t=j;break;
    }}
    }

    string st;
    if(t!=0){
    st="1\n";
    st+=(j);st+=" ";st+=(n/2+1);}
    else
    {
    st="0";

    }
    cout<<st;

    }
    return 0;}
