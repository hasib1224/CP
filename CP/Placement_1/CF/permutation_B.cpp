#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[200009], i, j, k=1;
        bool arr2[200009];
       
        for(i=1;i<=n;i++)
        {
            arr2[i]=true;   
        }

        for(i=1;i<=n;i++)
        {
            if(arr2[i])
            {
                j=i;
                while(j<=n)
                {
                    arr[k++]=j;
                    arr2[j]=false;
                    j*=2;
                }
            }  
        }
        cout<<2<<'\n';
        
        for(ll i=1;i<=n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
}