//class link
//https://www.youtube.com/watch?v=JbRsM2X2_pg

#include<bits/stdc++.h>
using namespace std;

int countWays(int N, string S)
{
    int strLen ,i=0, j=0, k,m ;
    //if(S.size()%2) strLen = (S.size()/2)+1;
    //else strLen = S.size()/2;
    strLen = ceil((float)N/2);

    long long int t_table [N] [N]={} ;
    long long int f_table [N] [N]={} ;
    char string[N];
    char oper[N];
    
    for(i=0;i<N;i=i+2)
    {
        string[j++]=S[i];
    } 

    j=0;
    for(i=1;i<N;i=i+2)
    {
        oper[j++]=S[i];
    } 

    

    //cout<<t_table[0][N-1]; 

    for(i=0;i<strLen;i++)
    {
        for(j=i,k=0;j<strLen;j++,k++)
        {
            if(i==0)
            {
                if(string[k]=='T')
                {
                    t_table [k] [j] = 1;
                    f_table [k] [j] = 0;
                }
                else if(string[k]=='F')
                {
                    t_table [k] [j] = 0;
                    f_table [k] [j] = 1;
                } 
            }
            else
            {
                for(m=k; m<j; m++)
                {
                    int lt= t_table[k][m];
                    int rt=t_table[m+1][j];
                    int lf=f_table[k][m];
                    int rf=f_table[m+1][j];

                    if(oper[m]=='&')
                    {
                        t_table[k][j]+=lt*rt;
                        f_table[k][j]+=lf*rt + lt*rf + lf*rf ;
                    }
                    else if(oper[m]=='|')
                    {
                        t_table[k][j] += lt*rt + rt*lf + lt*rf ;
                        f_table[k][j] += lf*rf ;
                        
                    }
                    else if(oper[m]=='^') //xor
                    {
                        t_table[k][j]+= lt*rf + lf*rt ;
                        f_table[k][j] += lt*rt + lf*rf; 
                    }

                    //see the qn .....result should be in modulo of 1003
                    t_table[k][j]=t_table[k][j]%1003;
                    f_table[k][j]=f_table[k][j]%1003;

                }

            }
        }

    }

    //Extra t_table showing ......
    for(i=0;i<strLen;i++){
        for(j=0;j<strLen;j++){
            cout<<t_table[i][j]<<" ";

        }cout<<endl;
    }

    //see the qn .....result should be in modulo of 1003
    return t_table[0][strLen-1]%1003;

}



int main(){

    string s;
    int l=s.size();
    cin>>s;
    cout<<countWays(l,s);
}







