
//https://www.youtube.com/watch?v=UvksR0hR9nA

#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k) 
    {
        int table[n+1][k+1]={};
        //initializing my table with the base cases
        for(int i=0;i<=n;i++) table[i][0]=0;
        for(int i=0;i<=k;i++) table[0][i]=123456;
        for(int i=0;i<=k;i++) table[1][i]=i;

        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                int temp=123456;
                for(int x=1;x<=j;x++)
                {
                    if( (max( table[i-1][x-1], table[i][j-x]) ) <temp )
                    {
                        temp = max( table[i-1][x-1],table[i][j-x] ) +1;
                    } 
                }
                table[i][j]=temp;
            }
        }

        //print table
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                cout<<table[i][j]<<" ";

            }cout<<endl;
        }
        return table[n][k];
    }




    int main(){
        cout<<eggDrop(2,5);
    }

