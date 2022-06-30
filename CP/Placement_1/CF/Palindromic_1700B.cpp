#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;

    while(t--)
    {
        long long int len;
        string input, output;

        cin>>len;
        cin>>input;
        if((int)(input[0]-'0')==9)
        {
            int carry=0;
            for(long long int i=len-1;i>=0;i--)
            {
                if((int)(input[i]-'0')+carry<=1)
                {
                    int x=1-(int)(input[i]-'0')-carry; carry=0;
                    output=to_string(x)+output;
                }
                else 
                {
                    int x=11-(int)(input[i]-'0')-carry;
                    output=to_string(x)+output;
                    carry=1;
                }
            }
            cout<<output<<endl;
        }

        else
        {
            for(long long int i=len-1;i>=0;i--)
            {
                int x=9-(int)(input[i]-'0');
                output=to_string(x)+output;
            }
            cout<<output<<endl;   
        }
           
    }
}










// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin>>t;

//     while(t--)
//     {
//         long long int len, n;
//         cin>>len>>n;
//         long long int temp1, temp2 ,r,sum, palin;
//         temp2= pow(10,len-1) + n;
        
//         while(1)
//         {
//             temp1=temp2;
//             sum=0,r=0;
//             while(temp1>0)
//             {
//                 r=temp1%10;
//                 sum=sum*10 + r;
//                 temp1=temp1/10;
//             }
//             if(temp2==sum)
//             {
//                 palin=temp2;
//                 break;
//             }
//             temp2++;

//         }
//         cout<<palin-n<<'\n';    
//     }
// }



