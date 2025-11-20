/*
*OnlineJudge
*484 - The Department of Redundancy Department
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    vector <int> order;
    map <int, int> ctr;
    int i;
    while (cin >> i) {
        if (ctr.find(i) == ctr.end()) {
            order.push_back(i);
            ctr[i] = 1;
        } else
            ctr[i]++;
    }

    for (int i = 0; i < (int) order.size(); i++)
        cout << order[i] << " " << ctr[order[i]] << endl;

    return 0;
}