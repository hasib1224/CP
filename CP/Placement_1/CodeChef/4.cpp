#include <iostream>
using namespace std;

int main() {
    int t,n,temp;
    cin>>t;
    while(t--)
    {
        temp=0;
        int a[101]={};
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            a[temp]++;
        }
        
        for(int i=1;i<=100;i++)
        {
            if(a[i]%2) 
            {
                temp=0;
                break;
            }
        }
        if(temp!=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    
	// your code goes here
	return 0;
}
