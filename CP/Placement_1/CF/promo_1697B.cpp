#include<bits/stdc++.h>
using namespace std;
#define ll long long  
int main()
{
    ll n, q, x, y, temp;
    cin>>n>>q;
    vector<ll> price, cumPric;
    cumPric.push_back(0);
    price.push_back(0);

    for(ll i=1;i<=n;i++)
    {
        cin>>temp;
        price.push_back(temp);
    }
    sort(price.begin(), price.end());
    for(ll i=1;i<=n;i++)
    {
        temp=cumPric[i-1] + price[i];
        cumPric.push_back(temp);
    }
    while(q--)
    {
        cin>>x>>y;
        cout<<cumPric[n-x+y]-cumPric[n-x]<<'\n';
    }

}