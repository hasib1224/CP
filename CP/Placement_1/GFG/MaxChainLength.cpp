
#include<bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;

};
int maxChainLen(struct val p[],int n)
{
    int f_sort[n];
    int s_sort[n];
    for(int i=0;i<n;i++) 
    {
        f_sort[i]=p[i].first;
        s_sort[i]=p[i].second;    
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int temp;
            if(f_sort[i]>f_sort[i+1])
            {
                temp=f_sort[i+1];
                f_sort[i+1]=f_sort[i];
                f_sort[i]=temp;
            }
            if(s_sort[i]>s_sort[i+1])
            {
                temp=s_sort[i+1];
                s_sort[i+1]=s_sort[i];
                s_sort[i]=temp;
            }

        }
    }

    int table[n+1][n+1]={};
    for(int i=0;i<=n;i++) table[i][0]=0;
    for(int i=0;i<=n;i++) table[0][i]=1;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s_sort[i]<f_sort[j]) table[i][j]=table[i-1][j]+1;
            else table[i][j]=table[i-1][j];
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<table[i][j]<<" ";

        }cout<<endl;
    }

    return table[n][n];



}

int main()
{
    struct val p[]= { {5,24} , {39,60} , {15,28} , {27,40} ,{50,90} };
    cout<<maxChainLen(p,5);
}








