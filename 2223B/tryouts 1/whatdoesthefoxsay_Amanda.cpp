/*
*OpenKattis
*whatdoesthefoxsay
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T;
    cin >> T;
    getchar();

    for (int t = 0; t < T; t++) {
        string in;
        getline(cin, in);
        
        vector <string> sounds;
        stringstream ss(in);
        string sound;
        while (ss >> sound)
            sounds.push_back(sound);
        
        set <string> not_fox;
        while (1) {
            getline(cin, in);
            if (in == "what does the fox say?")
                break;
            
            stringstream ss2(in);
            ss2 >> sound >> sound >> sound;
            not_fox.insert(sound);
        }

        for (int i = 0; i < (int) sounds.size(); i++) {
            if (not_fox.find(sounds[i]) == not_fox.end())
                cout << sounds[i] << " ";
        }
        cout << endl;
    }

    return 0;
}