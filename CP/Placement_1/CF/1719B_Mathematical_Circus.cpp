#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t, n, k, l;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        l=0;
        if(k==0 || k%4==0) cout <<"NO\n";
        else 
        {
            cout<<"YES\n";
            while(++l<n)
            {
                if(( (l+k)* (++l) )%4 ==0) cout<<l-1<<" "<<l<<'\n';
                else cout<<l<<" "<<l-1<<'\n';
            }

        }
    }
    
}