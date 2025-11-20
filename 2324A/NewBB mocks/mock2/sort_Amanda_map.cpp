/*
*OpenKattis
*sort
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

map <long long, pair<int, int>> freq;
bool sorter (long long A, long long B)
{
    if (freq[A].second == freq[B].second)
        return freq[A].first < freq[B].first;

    return freq[A].second > freq[B].second;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N, C;
    cin >> N >> C;

    vector <long long> seq (N);
    for (int n = 0; n < N; n++) {
        cin >> seq[n];
        if (freq.find(seq[n]) == freq.end()) {
            freq[seq[n]].first = freq.size();
            freq[seq[n]].second = 1;
        } else
            freq[seq[n]].second++;
    }

    sort(seq.begin(), seq.end(), sorter);

    for (int n = 0; n < N; n++)
        cout << seq[n] << " ";

    return 0;
}