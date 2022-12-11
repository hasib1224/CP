#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(m==1 && n==1) cout<<0<<'\n';
        else if(m<=n) cout<<(m+m+n-2)<<'\n';
        else cout<<(n+m-2+n)<<'\n';
        

    }
}