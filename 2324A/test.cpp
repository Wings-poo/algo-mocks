#include <bits/stdc++.h>
using namespace std;

void constructLIS(int arr[], int n)
{
    // L[i] - The longest increasing sub-sequence ending with arr[i]
    vector <vector<int>> L(n);
    L[0].push_back(arr[0]);
 
    // common LIS with a twist
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((arr[i] > arr[j]) && (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }
        // L[i] ends with arr[i]
        L[i].push_back(arr[i]);
    }

    vector <int> max = L[0];
 
    for (int i = 0; i < (int) L.size(); i++)
        if (L[i].size() > max.size())
            max = L[i];
 
    // max will contain LIS
    cout << max.size() << endl;
    for (int i = 0; i < (int) max.size(); i++)
        cout << max[i] << endl;
}

void LISNlgNsize (int arr, int N)
{
    vector <int> maxLIS;
    maxLIS.push_back(arr[0]);
    for (int i = 0; i < N; i++) {
        if (arr[i] > maxLIS.back())
            maxLIS.push_back(arr[i]);
        else {
            int low = lower_bound(maxLIS.begin(), maxLIS.end(), arr[i]) - maxLIS.begin();
            maxLIS[low] = arr[i];
        }
    }

    cout << maxLIS.size() << endl;
    
    return;
}

int main()
{
    int arr[] = {100, 1, 5, 6, 2, 3, 4};
    int N = 7; // size of arr[]
    int lis[N] = {0};
    lis[0] = 1; // first digit
    int ans = 0;

    for (int i = 1; i < N; i++) {
        lis[i] = 1; // base case is 1 per digit
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])
                lis[i] = max(lis[i], lis[j] + 1);
        }
        ans = max(ans, lis[i]);
    }

    cout << ans << endl;

    constructLIS(arr, N);

    return 0;
}