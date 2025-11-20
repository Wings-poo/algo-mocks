/*
*OpenKattis
*knapsack
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    vector <vector <int>> K(n + 1, vector<int>(W + 1)); 
    vector <vector <int>> constructedK(n + 1);
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) {
                if (val[i - 1] + K[i - 1][w - wt[i - 1]] > K[i - 1][w]) {
                    K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                    constructedK[i].push_back(i - 1);
                } else {
                    K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
                    constructedK[i] = constructedK[i - 1];
                }
            } else
                K[i][w] = K[i - 1][w]; 
        }
        //if (wt[i] < W)
        //    constructedK[i].push_back(i); 
    }
    
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j <= W; j++)
            cout << K[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < constructedK[i].size(); j++)
            cout << constructedK[i][j] << " ";
        cout << endl;
    }
    return K[n][W]; 
} 

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int C, N;
    while (cin >> C >> N) {
        int profit[N], weight[N];
        for (int n = 0; n < N; n++) {
            int p, w;
            cin >> p >> w;
            profit[n] = p;
            weight[n] = w;
        }

        cout << knapSack(C, weight, profit, N) << endl; 
    }
    
    return 0;
}