#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, lis[100], a[100], i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        lis[i] = 1;
    }
    for (i = 1; i < n; i++)
    {
        if(a[i]>a[i-1])
        lis[i] = max(lis[i], lis[i - 1]+1);
    }
    int max = lis[0];
    for (i = 0; i < n; i++)
    {
        if (lis[i] > max)
            max = lis[i];
    }
    cout << max << endl;
}