//cLASS LINK
//https://www.youtube.com/watch?v=2NaaM_z_Jig

#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string A, vector<string> &B) 
{
    int i,j,len,flag=0;
    int table[A.size()]={};

    for(i=0;i<A.size();i++)
    {
        len=i+1;
        for(j=0; j<=i;j++,len--)
        {
            string s1=A.substr(j,len);

            for(int m=0;m<B.size();m++)
            {
                if(s1==B[m])
                {
                    flag=1;
                    break;
                } 
            }
            if(flag==1)
            {
                if(j!=0)
                {
                    table[i]+=table[j-1];
                    flag=0;
                }
                else
                {
                    table[i]+=1;
                    flag=0;
                }
                
            }   
        }
    }
    cout<<table[A.size()-1]<<endl;
    if(table[A.size()-1]) return true;
    //THE LAST VALUE OF TABLE[] INDICATES THE NUMBER OF WAYS 
}


int main()
{
    vector<string>a={"lrbbmqb", "cd", "r" ,"owkk"};

    string d="lrbbmqbabowkkab";

    if(wordBreak(d,a)) cout<<"yes";
    else cout<<"false";

}


