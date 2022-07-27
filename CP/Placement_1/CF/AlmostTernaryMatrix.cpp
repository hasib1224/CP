#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t, n, m;
    cin>>t;
    char s1[4]={'1','0','0','1'};
    char s2[4]={'0','1','1','0'};
    while(t--)
    {
        cin>>n>>m;
        char arr[n+1][m+1];
        string ans;

        for(int i=0;i<n;i++)
        {
            //ans="";
            
            if(i%4==0 || i%4==3)
            {
                for(int k=0;k<m;k++)
                {
                    arr[i][k]=s1[k%4];  
                }
                
            }
    
            else if(i%4==1 || i%4==2)
            {
                for(int k=0;k<m;k++)
                {
                    arr[i][k]=s2[k%4];
                }
                
            }
            
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<arr[i][j]<<" ";
            }cout<<'\n';
        }cout<<'\n';
    }
}