#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll m, s, t;
    cin>>t;
    while(t--)
    {
        bool n[55]={0};
        int temp, lnum=0;
        ll s2=0;
        cin>>m>>s;
        

        for(ll i=1; i<=m;i++)
        {
            cin>>temp;
            n[temp]=true;
            if(lnum<temp) lnum=temp;
        }
        for(ll i=1; i<=lnum;i++)
        {
            if(!n[i]) s2=s2+i;
        }
     

        if(s2==s) cout<<"yes"<<endl;
        else if(s>s2)
        {
            s2=s-s2;
            while(lnum++)
            {
                s2-=lnum;
                if(s2==0){ cout<<"yes"<<endl; break;}
                else if(s2<0){ cout<<"no"<<endl; break;}
            }

        } 
        else cout<<"no"<<endl;
        
    }
    
}