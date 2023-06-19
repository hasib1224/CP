#include <iostream>
using namespace std;

int main() {
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(y*10<x) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;    
    }
	// your code goes here
	return 0;
}
