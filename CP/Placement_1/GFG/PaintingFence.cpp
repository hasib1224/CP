
//https://www.youtube.com/watch?v=ju8vrEAsa3Q

#include<bits/stdc++.h>
using namespace std;

long long countWays(int n, int k)
{
    if(k==1 && n<=2) return k;
    else
    {
        long long int lastTwoSameMust[n+1];
        long long int lastTwoDiffMust[n+1];
        long long int total[n+1];

        lastTwoDiffMust[1]=k;
        lastTwoSameMust[1]=0;
        total[1]=k;


        for(int i=2;i<=n;i++)
        {
            lastTwoSameMust[i]=lastTwoDiffMust[i-1];
            lastTwoDiffMust[i]=(total[i-1]*(k-1))%1000000007;
            total[i]=(lastTwoSameMust[i] + lastTwoDiffMust[i])%1000000007;
        }
        return total[n];
    }
             
}
int main()
{
    int n=40;
    int k=79;
    cout<<countWays(n, k);
}


