#include <iostream>
using namespace std;

int main() {
    int t,n,max,temp;
    cin>>t;
    while(t--)
    {
        temp=0;
        max=0;
        cin>>n;
        int a[n+1], b[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=0 && b[i]!=0) 
            {
                temp++;
                if(temp>max) max=temp;
            }
            else temp=0;
        }

        cout<<max<<endl;
        
        
    }
	// your code goes here
	return 0;
}