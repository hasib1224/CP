#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a,b,c,d;
    int count=0;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        if(a>b) count++;
        if(a>c) count++;
        if(a>d) count++;
        cout<<3-count<<'\n';
        count=0;
    }
}



