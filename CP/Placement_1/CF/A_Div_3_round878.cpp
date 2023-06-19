#include <iostream>
#include <string>
using namespace std;

#define ll long long int

int main()
{
    ll t,n;
    string s="";
    char temp;

    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        temp=s[0];

        for(int i=1; i<n;i++)
        {
            
            if(temp==s[i] ){
                cout<<s[i];
                temp=s[++i];
            }

        }cout<<endl;

    }

}