#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int input[1005]={}, input2[1005]={}, result[1005]={}, len;

        cin>>len; 
        for(int i=0;i<len;i++)
        {
           cin>>input[i];
           input2[i] = input[i];
        }

        if(len==1)
        {
            cout<<-1<<endl;
            continue;;
        }

        sort(input2, input2+len);

        for(int i=0;i<len;i++)
        {
            int temp;
            for(int j=i;j<len;j++)
            {
                if(input[i]!=input2[j])
                {
                    temp=input2[i];
                    input2[i]=input2[j];
                    input2[j]=temp;
                    break;
                }
                else if(i==len-1)
                {
                    temp=input2[len-1];
                    input2[len-1]=input2[len-2];
                    input2[len-2]=temp;

                }
            }
        }

        for(int i=0;i<len;i++)
        {
           cout<<input2[i]<<" ";
        } cout<<endl;

    }
  
}





