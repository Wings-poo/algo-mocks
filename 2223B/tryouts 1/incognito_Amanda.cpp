/*
*OpenKattis
*incognito
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        string attribute, category;
        map <string, int> attr_per_cat;
        for (int n = 0; n < N; n++) {
            cin >> attribute >> category;
            if (attr_per_cat.find(category) == attr_per_cat.end())
                attr_per_cat[category] = 1;
            else
                attr_per_cat[category]++;
        }

        int ans = 1;
        for (auto it : attr_per_cat)
            ans *= (it.second + 1);
        
        ans--;

        cout << ans << endl;
    }
    return 0;
}