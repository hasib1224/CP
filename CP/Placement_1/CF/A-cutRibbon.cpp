#include<bits/stdc++.h>
using namespace std;

int cutRibbon(int n,int a[])
{
    int cut [n+1] [n+1]={};

   for(int i=0;i<4;i++) cut[i][0]=1;

    for(int i=1;i<=3;i++){
       for(int j=1;j<=n;j++){
           if(a[i-1]==j)
           {
               cut[i][j] = max( cut[i][j-a[i-1]] , cut[i-1][j] );

           }

           else if(a[i-1]<j)
           {
               if(cut[i][j-a[i-1]]!=0)
               {
                   cut[i][j] = max( cut[i][j-a[i-1]]+1 , cut[i-1][j] );
               }

            else if( cut[i] [j-a[i-1]==0] ) cut[i][j] = cut[i-1][j];
           }
            else cut[i][j]=cut[i-1][j];
 
        }
    }

    //........print Value........
    for (int i = 0; i <4; i++)
    	{
        	for (int j = 0; j <=n; j++)
        	{
            	cout << cut[i][j] << " ";
        	}    
        	cout << endl;
    	}

    return cut[3][n];
}


int main(){
    int a[3],n;
    cin>>n;
    cin>>a[0]>>a[1]>>a[2];
 
    cout<<cutRibbon(n,a);
 
  
}