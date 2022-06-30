
//https://www.youtube.com/watch?v=3YILP-PdEJA

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int K, int N, int A[]) 
{
    int table[K+1][N]={};
    for(int i=0;i<N;i++) table[0][i]=0;
     for(int i=0;i<=K;i++) table[i][0]=0;


    for(int i=1;i<=K;i++)
    {
        for(int j=1;j<N;j++)
        {
            int temp=table[i][j-1];

            for(int x=0;x<j;x++)
            {  
               temp=max(temp,A[j]-A[x]+table[i-1][x]);
            }
            table[i][j]=temp;
        }
    }
  
    for(int i=0;i<=K;i++){
        for(int j=0;j<N;j++){
            cout<<table[i][j]<<" ";

        }cout<<endl;
    }
    return table[K][N-1];   
}

int main()
{
    int k=3;
    int n=6;
    int a[]={9,6,7,6,3,8};

    // int k=2;
    // int n=6;
    // int a[6]={10, 22 ,5 ,75 ,65, 80};

    cout<<maxProfit(k, n, a);
}






