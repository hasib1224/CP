#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long int n,m;
        cin>>n>>m;
        long long int sum = (m*(m+1))/2;
        sum=sum+ (float)(n-1)/2 *( (2*(m*2)) + ((n-2)*m) );
        cout<<sum<<endl;
    }

}





