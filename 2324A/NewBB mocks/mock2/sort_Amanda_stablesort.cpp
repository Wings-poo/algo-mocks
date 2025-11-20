/*
*OpenKattis
*sort
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

bool sorter (pair <long long, int> A, pair <long long, int> B)
{
    return A.second > B.second;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N, C;
    cin >> N >> C;

    vector <pair <long long, int>> order_freq;
    for (int n = 0; n < N; n++) {
        long long i;
        cin >> i;

        bool found = false;
        for (int j = 0; j < (int) order_freq.size(); j++)
            if (order_freq[j].first == i) {
                order_freq[j].second++;
                found = true;
            }
        
        if (!found)
            order_freq.push_back(make_pair(i, 1));
    }

    stable_sort(order_freq.begin(), order_freq.end(), sorter);

    for (int i = 0; i < (int) order_freq.size(); i++)
        for (int j = 0; j < order_freq[i].second; j++)
            cout << order_freq[i].first << " ";

    return 0;
}