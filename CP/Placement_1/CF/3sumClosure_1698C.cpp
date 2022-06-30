#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int check();

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        check();    
    }
}



    int check()
    {
        vector<ll> pos, neg, zer, merg;
        bool ans = true;
        ll n, temp;
        cin>>n;
        for(ll i=0; i<n;i++)
        {
            cin>>temp;
            if(temp>0 )
            {
                pos.push_back(temp);
                if(pos.size()<=2) merg.push_back(temp);

            } 
            else if(temp<0 )
            {
                neg.push_back(temp);
                if(neg.size()<=2) merg.push_back(temp);
            } 
            else if(temp==0 ) 
            {
                zer.push_back(temp);
                if(zer.size()<=2) merg.push_back(temp);
            }
        }

        if(pos.size()>2 || neg.size()>2) cout<<"NO\n";
        else
        {
            for(ll i=0;i<merg.size()-2 ;i++)
            {
                for(ll j=i+1;j<merg.size()-1 ;j++)
                {
                    for(ll k=j+1;k<merg.size() ;k++)
                    {
                        temp=merg[i]+merg[j]+merg[k];
                        bool demo=false;
                        for(ll x=0;x<merg.size();x++)
                        {
                            if(temp==merg[x]) demo =true; 
                        }
                        if(!demo)
                        {
                           cout<<"NO\n";
                           return 0;
                        } 
                    }
                }  
            } 
            cout<<"YES\n"; 
        }
        return 0;
    }