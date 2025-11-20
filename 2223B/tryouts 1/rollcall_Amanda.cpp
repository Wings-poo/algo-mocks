/*
*OpenKattis
*rollcall
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    vector <pair <string, string>> name;
    map <string, int> repeats;
    string first_name, last_name;
    while (cin >> first_name >> last_name) {
        if (repeats.find(first_name) == repeats.end())
            repeats[first_name] = 1;
        else
            repeats[first_name]++;
        
        name.push_back(make_pair(last_name, first_name));
    }

    sort(name.begin(), name.end());

    for (int i = 0; i < (int) name.size(); i++) {

        if (repeats[name[i].second] > 1)
            cout << name[i].second << " " << name[i].first << endl;
        else
            cout << name[i].second << endl;

    }
    return 0;
}