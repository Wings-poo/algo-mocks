/*
*OpenKattis
*increasingsubsequence
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    while (cin >> N) {
        if (!N)
            break;

        int arr[N];
        for (int n = 0; n < N; n++)
            cin >> arr[n];
        
        vector <vector <int>> LIS (N);

        LIS[0].push_back(arr[0]);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if ((arr[i] > arr[j]) && (LIS[i].size() < LIS[j].size() + 1))
                    LIS[i] = LIS[j];
            }
            LIS[i].push_back(arr[i]);
        }

        vector <int> maxLIS = LIS[0];
 
        for (int i = 0; i < (int) LIS.size(); i++) {
            if (LIS[i].size() > maxLIS.size())
                maxLIS = LIS[i];
            else if (LIS[i].size() == maxLIS.size()) {
                bool change = false;
                for (int j = 0; j < (int) maxLIS.size(); j++)
                    if (LIS[i][j] < maxLIS[j])
                        change = true;
                if (change)
                    maxLIS = LIS[i];
            }
        }

        cout << maxLIS.size();
        for (int i = 0; i < (int) maxLIS.size(); i++)
            cout << " " << maxLIS[i];
        cout << endl;
    }    
    
    return 0;
}