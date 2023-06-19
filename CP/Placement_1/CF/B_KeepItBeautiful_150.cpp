#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t, n,temp,input,f1, im;
    
    cin>>t;

    while (t--)
    {
        cin>>n;
        cin>>input;
        f1=input;
        im=input;
        temp=1;
        
        cout<<"1";
        for(ll i=1;i<n;i++){
            cin>>input;
            if(input>=im && temp!=0) {
                cout<<"1";
                im=input;
            }
            else if(input<im && input<=f1 && temp!=0){
                cout<<"1";
                im=input;
                temp=0;
            }
            else if ((input>=im &&  input<=f1 && temp==0) ){
                cout<<"1";
                im=input;
            }
            else cout << "0";


        }
        cout<<endl;
        
    }
    


}