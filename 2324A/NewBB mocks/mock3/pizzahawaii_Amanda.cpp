/*
*OpenKattis
*pizzahawaii
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

// second attempt at solving the problem
// tried a different approach by using maps

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        map <int, vector <string>> ingredient_per_pizza;
        map <string, vector <vector <string>>> possible_translations;
        vector <vector <string>> placeholder (N, vector <string> ());
        vector <string> all_ingredients;
        for (int n = 0; n < N; n++) {
            string pizza;
            cin >> pizza;

            int M;
            
            cin >> M;
            vector <string> foreign (M);
            for (int m = 0; m < M; m++) {
                string ingredient;
                cin >> ingredient;
                if (possible_translations.find(ingredient) == possible_translations.end()) {
                    possible_translations[ingredient] = placeholder;
                    all_ingredients.push_back(ingredient);
                }
                foreign[m] = ingredient;
            }
            sort(foreign.begin(), foreign.end());

            cin >> M;
            vector <string> local (M);
            for (int m = 0; m < M; m++) {
                string ingredient;
                cin >> ingredient;
                local[m] = ingredient;
            }
            sort(local.begin(), local.end());

            for (int m = 0; m < (int) foreign.size(); m++)
                possible_translations[foreign[m]][n] = local;

            ingredient_per_pizza[n] = foreign;
        }

        sort(all_ingredients.begin(), all_ingredients.end());

        map <string, vector <string>> translations;
        for (auto x : possible_translations) {
            int idx = 0;
            while ((idx < (int) x.second.size()) && x.second[idx].empty())
                idx++;
            
            vector <string> trimmed = x.second[idx];
            for (int i = idx + 1; i < (int) x.second.size(); i++) {
                if (x.second[i].empty())
                    continue;

                vector <string> intersection (20);
                auto it = set_intersection(x.second[i].begin(), x.second[i].end(), trimmed.begin(), trimmed.end(), intersection.begin());
                intersection.resize(it-intersection.begin());
                trimmed = intersection;

                if (trimmed.empty())
                    break;
            }
            translations[x.first] = trimmed;
        }

        for (int i = 0; i < (int) all_ingredients.size(); i++) {
            string ingredient = all_ingredients[i];
            for (int j = 0; j < N; j++) {
                if (possible_translations[ingredient][j].empty()) {
                    for (int k = 0; k < (int) ingredient_per_pizza[j].size(); k++) {
                        string otheringredient = ingredient_per_pizza[j][k];
                        for (int l = 0; l < (int) possible_translations[otheringredient].size(); l++) {
                            if (!possible_translations[ingredient][l].empty())
                                continue;

                            set <string> setint (possible_translations[otheringredient][l].begin(), possible_translations[otheringredient][l].end()); 
                            
                            vector <string> newvec;
                            for (int m = 0; m < (int) translations[ingredient].size(); m++) {
                                if (setint.find(translations[ingredient][m]) == setint.end())
                                    newvec.push_back(translations[ingredient][m]);
                            }

                            translations[ingredient] = newvec;
                        }
                    }
                }
            }
        }

        for (auto x: translations) {
            for (int i = 0; i < (int) x.second.size(); i++)
                cout << "(" << x.first << ", " << x.second[i] << ")\n"; 
        }

        cout << endl;
    }
    return 0;
}