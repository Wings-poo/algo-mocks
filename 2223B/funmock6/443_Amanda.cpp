/*
*OnlineJudge
*443 - Humble Numbers
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

vector <long long> humble_numbers;
set <long long> unique_hn;

void backtracking (long long num)
{
    if (num > 2000000000)
        return;
    
    // kinda like dp since there's "memoization"
    if (unique_hn.find(num) == unique_hn.end()) {
        humble_numbers.push_back(num);
        unique_hn.insert(num);
    } else
        return;
    
    backtracking (num * 2);
    backtracking (num * 3);
    backtracking (num * 5);
    backtracking (num * 7);
}

int main ()
{
    backtracking (1);

    sort(humble_numbers.begin(), humble_numbers.end());
    int idx;
    while (cin >> idx) {
        if (!idx)
            break;

        string th;
        if ((idx%100 >= 11) && (idx%100 <= 13))
            th = "th";
        else if (idx%10 == 1)
            th = "st";
        else if (idx%10 == 2)
            th = "nd";
        else if (idx%10 == 3)
            th = "rd";
        else
            th = "th";
        
        cout << "The " << idx << th << " humble number is " << humble_numbers[idx - 1] << "." << endl;
    }
    return 0;
}