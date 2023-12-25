#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int t,x,y,k;

    cin>>t;
    while(t--){
        cin>>x>>y>>k;
        if(y<=x) cout<<x<<endl;
        else{
            if(abs(x-y)<=k) cout<<y<<endl;
            else cout<<x+k+2*abs(x+k-y)<<endl;
        }
    }
}