#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){  
    ll a[3],n,val;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>val;
        if(val%2020<=val/2020) cout<<"YES\n";
        else cout<<"NO\n";
    }   
}

//EI methgod e korle tle khay & most importantly eta onk comlicated way te 
//think kora hoise
//think simplyy.....

/*
bool NewYears(int n)
{
 
   int a[2]={2021,2020};
   vector<vector<int>>table;

    if(n%a[0]==0|| n%a[1]==0) return true;
    else
    {
        for(int i=0;i<=2;i++){
            vector<int>temp;

            for(int j=0;j<=n;j++){
                if(j==0) temp.push_back(1);
                else if(i==0) temp.push_back(0);
                else{
                    if(a[i-1]==j)
                    {
                        temp.push_back(max(temp[j-a[i-1]],table [i-1][j]));
                    }
                    else if(a[i-1]<j)
                    {
                        if(temp[j-a[i-1]]!=0)
                        {
                            temp.push_back( max( temp[j-a[i-1]] +1 , table[i-1][j] ) );
                        }

                        else if( temp[j-a[i-1]==0] ) temp.push_back( table[i-1][j] );
                    }
                        else temp.push_back( table[i-1] [j] );
                }
            }
            table.push_back(temp);
        }

        //........print Value........
        // for (int i = 0; i < table.size(); i++)
        // {
        //     for (int j = 0; j < table[i].size(); j++)
        //     {
        //         cout << table[i][j] << " ";
        //     }    
        //     cout << endl;
        // }
    }

    if(table[2][n]!=0) return true;
    else return false; 
}
*/





