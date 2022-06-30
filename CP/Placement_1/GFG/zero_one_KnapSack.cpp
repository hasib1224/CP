
//class link
//https://www.youtube.com/watch?v=nLmhmB6NzcM&t=681s

#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
    { 
        //NO-NEEDD_TO_SORT_BECAUSE_QN_ER_ARRAY_TE_SORT

        //int temp = sizeof(wt) / sizeof(wt[0]);
        //sort(wt, wt + temp);
        
       // temp=sizeof(val) / sizeof(val[0]);
       // sort(val, val + temp);
        
        vector<vector<int>> table;
        
        
        for(int i=0;i<=n;i++)
        {
            vector<int>temp;
            for(int j=0;j<=W;j++)
            {
                if(i==0||j==0)
				{
                	temp.push_back(0);
				}

                else
                {
					if(wt[i-1]>j)
					{
						temp.push_back(table[i-1][j]);
					}
					else temp.push_back(max(table[i-1][j],table[i-1][j-wt[i-1]]+val[i-1]));
                        
                }
            }
			table.push_back(temp);
       
    	}

        //table_output
        for (int i = 0; i < table.size(); i++)
    	{
        	for (int j = 0; j < table[i].size(); j++)
        	{
            	cout << table[i][j] << " ";
        	}    
        	cout << endl;
    	}
		return table[n][W];

    }




