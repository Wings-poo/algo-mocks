/*
*OpenKattis
*stockprices
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        priority_queue <pair <int, int>> buy; // maxheap
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> sell; // minheap

        int N; 
        cin >> N;
        int sold_price = -1;
        for (int n = 0; n < N; n++) {
            string order_type, tapon;
            int shares, price;
            cin >> order_type >> shares >> tapon >> tapon >> price;

            if (order_type == "buy")
                buy.push({price, shares});
            else
                sell.push({price, shares});

            while ((!buy.empty()) && (!sell.empty())) {
                if (buy.top().first < sell.top().first)
                    break;

                pair <int, int> to_buy = buy.top();
                buy.pop();
                pair <int, int> to_sell = sell.top();
                sell.pop();

                sold_price = to_sell.first;

                int sold = min(to_buy.second, to_sell.second);
                to_buy.second = to_buy.second - sold;
                to_sell.second = to_sell.second - sold;

                if (to_buy.second)
                    buy.push(to_buy);
                if (to_sell.second)
                    sell.push(to_sell);
            }
            
            // printing of output
            if (!sell.empty())
                cout << sell.top().first;
            else
                cout << "-";
            
            if (!buy.empty())
                cout << " " << buy.top().first;
            else
                cout << " -";
            
            if (sold_price != -1)
                cout << " " << sold_price << endl;  
            else
                cout << " -\n";
        }
    }
    return 0;
}