#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        string s="";
        int zero=n, one=m;
        for(ll i=1;i<=m+n;)
        {
            if(n>=m)
            {
                if(zero>0)
                {
                    for(ll p=1; p<=n/m && i<=m+n; p++,i++)
                    {
                        s=to_string(0)+s; zero--;
                    }
                }
                if(i<=m+n && one>0)
                {
                    s=to_string(1)+s;
                    i++; one--;
                }
            }
            else
            {
                if(one>0)
                {
                    for(ll p=1; p<=m/n && i<=m+n; p++,i++)
                    {
                        s=to_string(1)+s; one--;  
                    }
                }
                if(i<=m+n && zero>0)
                {
                    s=to_string(0)+s; zero--;
                    i++;
                }  
            }
        }
        cout<<s<<'\n';
    }
}
