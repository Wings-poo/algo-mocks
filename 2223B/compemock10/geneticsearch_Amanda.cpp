/*
*OpenKattis
*geneticsearch
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string S, L;
    while (cin >> S >> L) {
        int type1 = 0, type2 = 0, type3 = 0;

        vector <string> genes = {"A", "G", "C", "T"};

        set <string> past_s;
        string s = S;
        for (int i = 0; i <= (int) L.size() - s.size() ; i++) {
            if (L.substr(i, s.size()) == s)
                type1++;
        }
        past_s.insert(s);

        for (int j = 0; j < (int) S.size(); j++) {
            if (j == 0)
                s = S.substr(j + 1, S.size());
            else if (j < S.size() - 1)
                s = S.substr(0, j) + S.substr(j + 1, S.size() - j);
            else
                s = S.substr(0, j);
            
            if (past_s.find(s) == past_s.end()) {

            //cout << j << " " << s << endl;
            for (int i = 0; i <= (int) L.size() - (int) s.size() ; i++) {
                //cout << L.substr(i, s.size()) << endl;
                if (L.substr(i, s.size()) == s)
                    type2++;
            }

            past_s.insert(s);
            }
        }

        for (int j = 0; j <= (int) S.size(); j++) {
            for (int k = 0; k < 4; k++) {
                s = S.substr(0, j) + genes[k] + S.substr(j, S.size());
                /*if (j == 0)
                    s = genes[k] + S.substr(0, S.size()) ;
                else if (j < S.size() - 1)
                    s = S.substr(0, j) + genes[k] + S.substr(j, S.size() - j);
                else
                    s = S.substr(0, S.size()) + genes[k];*/

                if (past_s.find(s) == past_s.end()) {
                    
                
                //cout << j << " " << s <<  endl;
                //cout << (int) L.size() - (int) s.size() << endl;
                for (int i = 0; i <= (int) L.size() - (int) s.size() ; i++) {
                   // cout << L.substr(i, s.size()) << endl;
                    if (L.substr(i, s.size()) == s)
                        type3++;
                }

                past_s.insert(s);
                }
            }
        }

        cout << type1 << " " << type2 << " " << type3 << endl;
    }
    return 0;
}