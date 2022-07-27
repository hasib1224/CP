#include<bits/stdc++.h>
using namespace std;
#define ll long long int


bool solve(int n, float arr[],float sum)
{
    float temp;
    bool ans=false;
    for(int i=0;i<n;i++)
    {
        temp=(sum-arr[i])/(n-1);
        if(temp==arr[i]) 
        {
            ans= true;
            return ans;
        }    
    }
    return ans;  
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        float arr[70], sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum=sum+arr[i];
        }
        if(solve(n,arr,sum)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}