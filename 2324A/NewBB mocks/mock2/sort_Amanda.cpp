/*
*OpenKattis
*sort
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

bool sorter (tuple <long long, int, int> A, tuple <long long, int, int> B)
{
    if (get <2> (A) == get <2> (B))
        return get <1> (A) < get <1> (B);

    return get <2> (A) > get <2> (B);
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long N, C;
    cin >> N >> C;

    vector <tuple <long long, int, int>> order_freq;
    for (int n = 0; n < N; n++) {
        long long i;
        cin >> i;

        bool found = false;
        for (int j = 0; j < (int) order_freq.size(); j++)
            if (get <0> (order_freq[j]) == i) {
                order_freq[j] = make_tuple(get <0> (order_freq[j]), get <1> (order_freq[j]), get <2> (order_freq[j]) + 1);
                found = true;
            }
        
        if (!found)
            order_freq.push_back(make_tuple(i, order_freq.size(), 1));
    }

    sort(order_freq.begin(), order_freq.end(), sorter);

    for (int i = 0; i < (int) order_freq.size(); i++)
        for (int j = 0; j < get <2> (order_freq[i]); j++)
            cout << get <0> (order_freq[i]) << " ";

    return 0;
}