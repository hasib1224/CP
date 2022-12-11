#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t, n,a, b, c, temp,temp2, ans=1;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        
            temp=a-1;
            if(b<c) temp2=(c-b) + c-1;
            else if(b>c) temp2=b-1;

            if(temp>temp2) cout<<"2\n";
            else if(temp<temp2)  cout<<"1\n";
            else cout<<"3\n";
        
        
    }
}