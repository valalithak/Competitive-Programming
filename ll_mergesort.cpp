#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long int a[10000007];

void merge(long long int arr[10000007], long long int l, long long int m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 = r - m;

    /* create temp arrays */
    ll L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
	are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
	are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(ll arr[10000007], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ll m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    long int i, j, n, m, t, index, min;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        mergeSort(a, 0, n - 1);
        for (i = m - 1; i < n; i++)
        {
            if ((a[i] - a[i - m + 1]) < min)
            {
                min = a[i] - a[i - m + 1];
                index = i;
            }
        }
        cout << min << endl;
        t--;
    }
}