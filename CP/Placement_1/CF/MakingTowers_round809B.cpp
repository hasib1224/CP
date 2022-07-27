#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        int arr[100009], k, j;
        int ans[100009];
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }

        for(int i=1;i<=n;i++)
        {
           
            if(arr[i]!=0)
            {
                ans[arr[i]]++; j=i; k=arr[i];
                while(j<=n)
                {
                    if(arr[j+1]==arr[j] && k==arr[j])
                    {
                        ans[k]++; arr[j]=0;
                        if(j+1==n) {arr[j+1]=0;j++;}
                        else j++;
                    }
                    else if(arr[j+3]==arr[j] && k==arr[j])
                    {
                        ans[k]++; arr[j]=0;
                        if( j+3==n) { arr[j+3]=0;j=j+3;}
                        else j=j+3;
                    }
                    
                    else
                    {
                        arr[j]=0;
                        if(k==arr[j+2]) arr[j+2]=0;
                        j=j+4;

                    }    
                }

            }
        }

        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
}