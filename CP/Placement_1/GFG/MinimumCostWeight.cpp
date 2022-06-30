
#include<bits/stdc++.h>
using namespace std;

int minimumCost(int cost[], int N, int W) 
{   
        int weight[N]={};
        int cost2[N]={};
        int count=0;

        for(int i=0;i<N;i++) 
        {
           if(cost[i]!=-1){ 
             weight[count] = i+1;
             cost2[count++]=cost[i];
           }
            
        }
        // for(int i=0;i<=count;i++) 
        // { 
        //     cout<<weight[i]<<" ";
        //     cout<<cost2[i]<<" ";
        //     cout<<endl;    
        // }
        

        vector<vector<int>>table;

        for(int i=0;i<=count; i++)
        {
            vector<int> temp;

            for(int j=0;j<=W;j++)
            {
                if(j==0) temp.push_back(0);
                else if(i==0) temp.push_back(INT_MAX);

                else
                {
                    if( weight[i-1]<=j && temp[j-weight[i-1]]!=INT_MAX) temp.push_back( min( temp[j-weight[i-1]] + cost2[i-1] , table[i-1][j] ) );
                    else  temp.push_back( table[i-1][j] ); 
                }
            }
            table.push_back(temp);
        }

        for (int i = 0; i < table.size(); i++)
    	{
        	for (int j = 0; j < table[i].size(); j++)
        	{
            	cout << table[i][j] << " ";
        	}    
        	cout << endl;
    	}

        if(table[count][W]>0)  return table[count][W];
        return -1;
        

} 


int main(){
    // int arr[] = { 2, 10, 40, 7, 6,-1};

    // int arr[] = { -1 ,25 ,78, 40, 77, 66, 13, 96, 76, 92, 11, 67, 11, 94};
    // int N = 14;
    // int W = 29;

        int W = 8;
        int N = 6;
       int arr[] = { -1, 10, 40, 7, 6,-1};

    // int arr[] = { -1, 10, 4, 7, 6};
    // int W = 10;
    // int N = 6;

    // int arr[]={40, 28, 7, 21, 59, 48, 74, 15, 63, 24, 81, 14, 31, 7 ,35, -1, 13};
    // int W = 138;
    // int N = 17;



    // int arr[]={40, 28, 7, 21, 59, 48, 74, 15, 63, 24, 81, 14, 31, 7 ,35, -1, 13};
    // int W = 138;
    // int N = 17;
    cout<<minimumCost( arr ,N ,W);
}

//35, 43, 40 ,18,80 ,64 ,63 ,99 ,50 ,51 ,36 ,31

// 14 29
// -1 25 78 40 77 66 13 96 76 92 11 67 11 94