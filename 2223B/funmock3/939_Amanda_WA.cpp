/*
*OnlineJudge
*939 - Genes
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

map <string, string> genes;
map <string, pair <string, string>> parents;

int main ()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; n++) {
        string a, b;
        cin >> a >> b;
        if ((b == "non-existent") || (b == "recessive") || (b == "dominant"))
            genes[a] = b;
        else {
            if (parents.find(b) == parents.end()) {
                parents[b] = make_pair(a, "");
            } else {
                parents[b] = make_pair(parents[b].first, a);
            }
        }
    }
    
    // problem is if parent doesn't exist in genes yet
    for (auto it: parents) {

        if (genes[it.second.first] == "dominant") {
            if (genes[it.second.second] != "non-existent")
                genes[it.first] = "dominant";
            else
                genes[it.first] = "recessive";
        } else if (genes[it.second.second] == "dominant") {
            if (genes[it.second.first] != "non-existent")
                genes[it.first] = "dominant";
            else
                genes[it.first] = "recessive";
        } else if (genes[it.second.first] == "recessive") {
            if (genes[it.second.second] != "non-existent")
                genes[it.first] = "recessive";
            else
                genes[it.first] = "non-existent";
        } else if (genes[it.second.second] == "recessive") {
            if (genes[it.second.first] != "non-existent")
                genes[it.first] = "recessive";
            else
                genes[it.first] = "non-existent";
        } else
            genes[it.first] = "non-existent";
    }

    for (auto it: genes)
        cout << it.first << " " << it.second << endl;
    return 0;
}