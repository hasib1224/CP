#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n, m, needEnerg=0;
        cin>>n>>m;
        int dist[n+1];

        for(ll i=0;i<n;i++)
        {
            cin>>dist[i];
            if(dist[i]<=m)
            {
                m=m-dist[i];
            }
            else
            {
                needEnerg=needEnerg+ dist[i]-m;
                m=0;
            } 
        }
        cout<<needEnerg<<'\n';
    }
}

