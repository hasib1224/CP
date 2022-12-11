#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t, n, k, c, r;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>r>>c;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((i+j)%k==(c+r)%k) cout<<'X';
                else cout<<'.';
            }
            cout<<'\n';
        }
    }
}
