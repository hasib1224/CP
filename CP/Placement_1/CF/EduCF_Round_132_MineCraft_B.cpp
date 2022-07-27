#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
   ll n, m, i, s, t, temp;
   vector<ll> x, f, b;
   f.push_back(0);
   b.push_back(0); 

   cin>>n>>m;
   for(i=0;i<n;i++)
   {
        cin>>temp;
        x.push_back(temp);
        if(i>=1)
        {
            if(x[i-1]>=x[i]) 
            {
                temp=x[i-1]-x[i] + f[i-1];
                f.push_back(temp);
                b.push_back(b[i-1]);
            }
            else 
            {
                temp=x[i]-x[i-1] + b[i-1];
                b.push_back(temp);
                f.push_back(f[i-1]);
            }
        } 
   }
   while(m--)
   {
    cin>>s>>t;
    if(s<t) cout<<f[t-1]-f[s-1]<<'\n';
    else cout<<b[s-1]-b[t-1]<<'\n';
   }

}