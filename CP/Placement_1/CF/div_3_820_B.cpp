#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    ll t, n,a, b, c, temp[55], ans=1;
    
    cin>>t;
    // temp2=97+1;
    // cout<<temp2;
    while(t--)
    {
        string s1,s, temp2;
        
        cin>>n;
        
        cin>>s1; 
        
          
       
        for(int i=n-1;i>=0;i--)
        {
            int t;
            if(s1[i]!='0')
            {
                temp2= ((int)(s1[i])-48) + 96;
                //cout<<temp2;
                s =s + temp2;
            }
            if(s1[i]=='0')
            {
                // temp2=int(s1[i]) -48 + 96;
                // s =s + temp2;
                t=(int)(s1[--i]) + (int) (s1[--i]) *10;
                temp2=t -48 + 96;
                s =s + temp2;
                // temp2=int(s1[i-1]) -48 + 96;
                // s =s + temp2;

            }
        }
        for(int i=0;i<=s.size();i++){
            if(s[i]>=65&&s[i]<=90)
            s[i]=s[i]+32;
        }    
        reverse(s.begin(), s.end());
        cout<<s<<'\n'; 

    }

}


