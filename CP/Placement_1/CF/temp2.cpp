#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define EPS 1e-3

int main()
{
    ll t, temp;
    cin>>t;
    while(t--)
    {
        ll n;
        vector<int> a, coun;
        set<int>b;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            cin>>temp;
            a.push_back(temp);
            b.insert(temp);
        }
        set<int, greater<int> >::iterator itr;
        for(itr = b.begin(); itr != b.end(); itr++)
        {
            temp=0;
            for(ll j=0;j<n;j++)
            {
                if(*itr==a[j] && (itr!=b.begin() ))
                {
                    temp++;
                }
                else if(*itr==a[j] && (itr==b.begin() ))
                {
                    temp++;
                }
            }
            coun.push_back(temp);
        }
        sort(coun.begin(),coun.end());
        cout<<coun[0]<<'\n';
    }
}



























// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define EPS 1e-3

// int main()
// {
//     setprecision(10);
//     int n,k;
//     cin>>n>>k;
//     double  dist, ans;
//     int a,b,c,d;

//     cin>>a>>b;
//     for(int i=1;i<n;i++)
//     {
//         cin>>c>>d;
//         dist = dist + pow( (pow(abs(a-c),2) + pow(abs(b-d),2) ), 0.5) ;
//         a=c;
//         b=d;
//     }
//     ans=(dist/50)*k;

//     printf("%.9lf", ans);
// }





