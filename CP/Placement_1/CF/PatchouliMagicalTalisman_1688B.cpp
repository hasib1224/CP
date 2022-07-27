#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t, temp, n;
    cin>>t;
    while(t--)
    {
        vector<ll>even, odd, ans;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>temp;
            if(temp%2==0) even.push_back(temp);
            else odd.push_back(temp);
        }
        if(odd.size()!=0) cout<<even.size()<<'\n';
        else
        {
            for(ll i=0;i<n;i++)
            {
                ll x=0;
                temp=even[i];
                while(temp%2!=1)
                {
                    temp=temp/2;
                    x++;
                }
                ans.push_back(x);
            }
            sort(ans.begin(),ans.end());
            
            cout<<ans[0]+(ans.size()-1)<<'\n';
        }
    }
}
