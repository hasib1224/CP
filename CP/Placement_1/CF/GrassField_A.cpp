#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int arr[2][2], temp, ans=0;
        for(int i=0;i<4;i++)
        {
            cin>>temp;
            if(temp==1) ans++;  
        }
        if(ans==0) cout<<0<<endl;
        else if(ans==1) cout<<1<<endl;
        else if(ans==2) cout<<1<<endl;
        else if(ans ==3) cout<<1<<endl;
        else if(ans==4) cout<<2<<endl;
    }
}