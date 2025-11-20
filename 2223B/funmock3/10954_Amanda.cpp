/*
*OnlineJudge
*10954 - Add All
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int N;
    while (cin >> N) {
        if (!N)
            break;
        
        priority_queue <int, vector<int>, greater<int>> pq;
        for (int n = 0; n < N; n++) {
            int i;
            cin >> i;
            pq.push(i);
        }
    
        int totalcost = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int c = a + b;
            totalcost += c;
            pq.push(c);
        }

        cout << totalcost << endl;
    }
    return 0;
}