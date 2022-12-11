#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, m;
    cin >>n>>m;
    if(n==1) cout<<(m-1);
    else if(m==1) cout<<(n-1);
    else cout<<n*(m-1);
}