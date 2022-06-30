#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll t, n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll arr[n+1], longPile=0;
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        if(k==1) cout<<floor((double)((n-1)/2))<<'\n';
        else
        {
            for(ll i=1;i<n-1;i++)
            {
                if(arr[i]>(arr[i-1] + arr[i+1]) )
                {
                    longPile++;
                }
            }
            cout<<longPile<<'\n';
        }  
    }
}