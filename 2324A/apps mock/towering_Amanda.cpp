/*
*OpenKattis
*towering
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> boxes (6);
    int towerA, towerB;
    for (int i = 0; i < 6; i++)
        cin >> boxes[i];
    cin >> towerA >> towerB;

    sort(boxes.begin(), boxes.end(), greater <int> ());

    // brute-force since there's only 6, lol
    bool done = false;
    for (int i = 0; (i < 6) && !done; i++)
        for (int j = i+1; (j < 6) && !done; j++)
            for (int k = j+1; (k < 6) && !done; k++) {
                vector <int> tower1 = {i,j,k};
                int sum = boxes[i] + boxes[j] + boxes[k];

                vector <int> tower2;
                int othersum = 0;
                for (int l = 0; l < 6; l++)
                    if ((l != i) && (l != j) && (l != k)) {
                        othersum += boxes[l];
                        tower2.push_back(l);
                    }

                if ((sum == towerA) && (othersum == towerB)) {
                    cout << boxes[tower1[0]] << " " << boxes[tower1[1]] << " " << boxes[tower1[2]] << " " << boxes[tower2[0]] << " " << boxes[tower2[1]] << " " << boxes[tower2[2]] << endl;
                    done = true;
                }

                else if ((sum == towerB) && (othersum == towerA)) {
                    cout << boxes[tower2[0]] << " " << boxes[tower2[1]] << " " << boxes[tower2[2]] << " " << boxes[tower1[0]] << " " << boxes[tower1[1]] << " " << boxes[tower1[2]] << endl;
                    done = true;
                }
            }
    return 0;
}