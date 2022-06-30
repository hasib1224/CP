#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, soln;
        string s;
        cin>>n>>s;
        soln=n;

        for(ll i=1;i<n;i++)
        {
            if(s[i]!=s[i-1]) soln+=i;
        }
        cout<<soln<<'\n';
    }

}