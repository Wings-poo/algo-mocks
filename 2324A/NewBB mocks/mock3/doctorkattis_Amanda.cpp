/*
*OpenKattis
*doctorkattis
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
    cin >> N;
    map <string, pair <int, int>> clinic; // or unordered_map for speed
    map <pair <int, int>, string> priority; // needs to be ordered
    for (int n = 0; n < N; n++) {
        int cmd;
        string catName;
        int infectionLevel, increaseInfection;

        cin >> cmd;
        switch (cmd) {
            case 0:
                cin >> catName >> infectionLevel;
                clinic[catName] = {infectionLevel, -1*n};
                priority[clinic[catName]] = catName;
                break;
            case 1:
                cin >> catName >> increaseInfection;
                priority.erase(priority.find(clinic[catName]));
                clinic[catName].first += increaseInfection;
                priority[clinic[catName]] = catName;
                break;
            case 2:
                cin >> catName;
                priority.erase(priority.find(clinic[catName]));
                clinic.erase(clinic.find(catName));
                break;
            case 3:
                if (priority.empty())
                    cout << "The clinic is empty" << endl;
                else
                    cout << (*priority.rbegin()).second << endl;
                break;
        }
    }
    return 0;
}