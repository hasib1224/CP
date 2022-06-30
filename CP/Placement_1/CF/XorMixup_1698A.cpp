#include <bits/stdc++.h>
using namespace std;
 
int XOR(int x, int y) { return (x + y - (2 * (x & y))); }
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        int result;
        for(int i=0;i<n;i++)
        {
            result=arr[0];
            for (int j = 1; j <n; j++)
            {
                result = XOR(result,arr[j]);
            }
            if(arr[i]==XOR(arr[i], result) && result!=0) break;
            else if(result==0) result=arr[n-1];
        }
        cout<<result<<endl;
    }
}


