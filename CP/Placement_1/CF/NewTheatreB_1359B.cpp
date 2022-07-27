    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int

    int main()
    {
        int t, n, m, x, y;
        cin>>t;
        while(t--)
        {
            cin>>n>>m>>x>>y;
            string s;
            int star=0, dot=0, xtile=0, ytile=0;
            if( (2*x)>y)
            {
                for(int i=0;i<n;i++)
                {
                    cin>>s;
                    for(int j=0;j<m;j++)
                    {
                        if(s[j]=='.' && s[j+1]=='.')
                        {
                            ytile++;
                            j++;
                        }
                        else if(s[j]=='.')
                        {
                            xtile++;
                        }
                    }
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    cin>>s;
                    for(int j=0;j<m;j++)
                    {
                        if(s[j]=='.')
                        {
                            xtile++;
                        }
                    }
                }

            }

            cout<<xtile*x+ytile*y<<'\n';
        }
    }