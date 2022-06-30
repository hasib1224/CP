#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,c="";
    int t,n,m,k,ind1=0,ind2=0, i;
    int marker1=0,marker2=0,flag=0;
    cin>>t;
    while(t--)
    {   marker1=0,marker2=0,ind1=0,ind2=0,i=0;
        cin>>n>>m>>k;
        cin>>a>>b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        //token1 = given_str.substr(0, pos);
        
        i=0;
        while(n>ind1&&m>ind2)
        {
            if((a[ind1]<b[ind2] && marker1<k) ||marker2==k)
            {
                c=c+a[ind1];
                marker1++;ind1++;
                marker2=0;
                i++;
            }
            else 
            {
                c=c+b[ind2];
                marker2++;ind2++;
                marker1=0;
                i++;
            }
            
            
        }
        cout<<c<<endl;
        c="";
    }
   
}




