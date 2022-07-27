#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int arr1[n+1];
        bool arr2[m+1];
        for(int i=1;i<=m;i++)
        {
            arr2[i]=true;
        }

        for(int i=1;i<=n;i++)
        {
            cin>>arr1[i];
            if(arr1[i]>=(m+1-arr1[i]) && arr2[m+1-arr1[i]]==true)
            {
                arr2[m+1-arr1[i]]=false;
            }
            else if(arr2[arr1[i]])  arr2[arr1[i]]=false;
            else if(arr2[m+1-arr1[i]]) arr2[m+1-arr1[i]]=false;
            
        }

        for(int i=1;i<=m;i++)
        {
            if(arr2[i]) cout<<'B';
            else cout<<'A';   
        }cout<<'\n';

        

    }
}