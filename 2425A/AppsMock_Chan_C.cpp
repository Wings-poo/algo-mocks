/*
*OpenKattis
*musicalscales
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string code, guess;
    cin >> n >> code >> guess;  
    
    int r,s = 0;
    string code_copy = code;
    string guess_copy = guess;

    for(int i = 0; i<n; i++){
        if(code_copy[i]==guess_copy[i]){
            code_copy[i]='0';
            guess_copy[i]='0';
            r++;
        }
    }
    
    for(int i = 0; i<n; i++){
        if(code_copy[i]!=guess_copy[i]){
            for(int j = 0; j<n; j++){
                if(code_copy[i]==guess_copy[j]){
                    guess_copy[j]='0';
                    s++;
                    break;
                }
            }
        }
    }
    cout << r << " " << s;
    return 0;
}