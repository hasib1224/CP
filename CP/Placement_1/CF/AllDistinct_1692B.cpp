#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int s,x;
    cin>>n;
    while(n--)
    {  
        cin>>s;
        set <int>arr;
        for(int i=0;i<s;i++)
        {
            cin>>x;
            arr.insert(x);
        }

        if((s-arr.size())%2==0) cout<<arr.size()<<'\n';
        else cout<<arr.size()-1<<'\n';   
    }  
}


