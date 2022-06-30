//class link
//https://www.youtube.com/watch?v=dJmyfFC3-3A


#include<bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[])
    {
        int i,j;
        int temp = sizeof(arr)/sizeof(arr[0]);
        sort(arr,arr+temp);

        vector< vector<int> > table;

        int sum=0;

        for( i=0;i<N; i++)
        {
            sum = sum + arr[i];
        }
     

        if(sum%2)   return 0;
        else 
        {
            for( i=0;i<=N;i++)
            {
                vector<int>temp1;

                for( j=0;j<=(sum/2); j++)
                {
                    if(i==0||j==0)
                    {
                        if(j==0) temp1.push_back(1);
                        else if(i==0) temp1.push_back(0);
                    }
                    else 
                    {
                        if(j==arr[i-1]) temp1.push_back(1);
                        else if(j>arr[i-1])
                        {
                            if(table[i-1][j]==1) temp1.push_back(table[i-1][j]); 
                            else temp1.push_back(table[i-1][j-arr[i-1]]);
                        }
                        
                        else temp1.push_back(table[i-1][j]);
                    }
                }
                table.push_back(temp1);
            }
            

            for (i = 0; i < table.size(); i++)
    	    {
        	    for ( j = 0; j < table[i].size(); j++)
        	    {
            	    cout << table[i][j] << " ";
        	    }    
        	    cout << endl;
    	    }

            return table[N][sum/2];
        }
    
    }


    int main()
    {
        int arr1[9]={2,3,7,5,11};
        int n=5;
        if(equalPartition( n, arr1)) cout<<"YES";
        else cout<<"NO";
    }







