#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t, n, temp=0, ans=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%3==0)
        {
            cout<<n-2<<" "<<n-1<<" ";
            for(int i=1;i<n-2;i++)
            {
                cout<<i<<" ";
            }cout<<n;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                cout<<i<<" ";
            }

        }
        cout<<"\n";
    }
}