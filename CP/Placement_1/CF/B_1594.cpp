#include <bits/stdc++.h>
using namespace std;

#define N 1000000007ll

long long findExponen(long long n, int count)
{
    long long res = 1;
    for (int i = 0; i < count; i++)
    {
        res = (res * n) % N;
    }
    return res;
}

int main()
{
    long long int t, n, k, spNum;

    cin >> t; 
    while (t--)
    {
        spNum=0;
        cin>> n >> k;
        int count = -1;
        while (k > 0)
        {
            count++;
            if (k & 1)
            {
                spNum = (spNum + findExponen(n, count)) % N;
            }
            k = k >> 1;
        }
        cout << spNum << endl;
    }
}