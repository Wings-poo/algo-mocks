/*
*OpenKattis
*pizzahawaii
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// first attempt at solving the problem

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        map <string, vector <string>> possible_translations;
        vector <pair <set <string>, vector <string>>> pizza_ingredients;
        set <string> allchingchong;
        for (int n = 0; n < N; n++) {
            string pizza;
            cin >> pizza;

            int A;
            cin >> A;
            set <string> chingchong;
            for (int a = 0; a < A; a++) {
                string ingredient;
                cin >> ingredient;
                chingchong.insert(ingredient);
                allchingchong.insert(ingredient);
            }

            int B;
            cin >> B;
            vector <string> english (B);
            for (int b = 0; b < B; b++) {
                string ingredient;
                cin >> ingredient;
                english[b] = ingredient;
            }
            sort(english.begin(), english.end());

            for (auto i : chingchong)
                possible_translations[i] = english;

            pizza_ingredients.push_back(make_pair(chingchong, english));
        }

        // brute-force, too lazy to think
        for (auto i : allchingchong) {
            for (int j = 0; j < (int) pizza_ingredients.size(); j++) {
                if (pizza_ingredients[j].first.find(i) != pizza_ingredients[j].first.end()) {
                    vector <string> intersection (min(possible_translations[i].size(), pizza_ingredients[j].second.size()));
                    auto it = set_intersection(possible_translations[i].begin(), possible_translations[i].end(), pizza_ingredients[j].second.begin(), pizza_ingredients[j].second.end(), intersection.begin());
                    intersection.resize(it-intersection.begin());

                    possible_translations[i] = intersection;
                } else {
                    if (possible_translations[i].empty())
                        continue;
                    else {
                        vector <string> intersection (min(possible_translations[i].size(), pizza_ingredients[j].second.size()));
                        auto it = set_intersection(possible_translations[i].begin(), possible_translations[i].end(), pizza_ingredients[j].second.begin(), pizza_ingredients[j].second.end(), intersection.begin());
                        intersection.resize(it-intersection.begin());

                        set <string> intersectionset; // idk, less hassle?
                        for (int k = 0; k < (int) intersection.size(); k++)
                            intersectionset.insert(intersection[k]);

                        vector <string> newvec;
                        for (int k = 0; k < (int) possible_translations[i].size(); k++)
                            if (intersectionset.find(possible_translations[i][k]) == intersectionset.end())
                                newvec.push_back(possible_translations[i][k]);
                        
                        possible_translations[i] = newvec;
                    }
                }
            }
        }

        for (auto i : possible_translations) {
            if (i.second.empty())
                continue;
            for (int j = 0; j < (int) i.second.size(); j++)
                cout << '(' << i.first << ", " << i.second[j] << ")\n"; 
        }

        cout << endl;
    }
    return 0;
}