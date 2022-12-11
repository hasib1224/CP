#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t, n, temp, ans=1;
   
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll htem[2]={0}, ltem[2];
        ltem[0]=99999999999;
        for(int i=1; i<=n;i++)
        {
            cin>>temp;
            if(htem[0]<temp)
            {
                htem[1]=htem[0];
                htem[0]=temp;    
            }
            else if(htem[1]<temp) htem[1]=temp;
            if(ltem[0]>temp)
            {
                ltem[1]=ltem[0];
                ltem[0]=temp;   
            }
            else if(ltem[1]>temp) ltem[1]=temp;

        }

        cout<<htem[0]+htem[1]-ltem[0]-ltem[1]<<'\n';

    }
}