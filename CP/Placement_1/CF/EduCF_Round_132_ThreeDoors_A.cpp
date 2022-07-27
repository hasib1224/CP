#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, k, arr1[4];
    arr1[0]=0;
    cin>>t;
    while(t--)
    {
        bool arr2[4];
        cin>>k;
        for(int i=1;i<=3;i++)
        {
            cin>>arr1[i];
            arr2[i] =true;
        }
        
        for(int i=1;i<=3;i++)
        {
            arr2[k]=false;
            k=arr1[k];
        }

        if(arr2[1]||arr2[2]||arr2[3]) cout<<"NO\n";
        else cout<<"YES\n";
        
    }
}