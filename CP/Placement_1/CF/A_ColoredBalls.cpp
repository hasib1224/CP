#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t, n, temp=0, ans=1;
    cin>>t;
    while(t--)
    {
        ans=1;
        temp=0;
        cin>>n;
        ll b[n];
        b[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            if(temp<b[i])
            {
                temp=b[i];
               // cout<<temp<<endl;
                ans=i;
                //cout<<ans<<endl;
            }
        }
        cout<<ans<<'\n';
    }
}