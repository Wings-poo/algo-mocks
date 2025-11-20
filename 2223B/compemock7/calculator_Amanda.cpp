/*
*OpenKattis
*calculator
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string exp;
    while (getline(cin, exp)) {
        char c;
        double i;
        bool prev_is_num = false;
        bool neg = false;
        stack <char> ope;
        vector <pair <int, double>> postfix;
        for (int idx = 0; idx < (int) exp.size(); idx++) {
            c = exp[idx];
            if (c == ' ')
                continue;

            if (isdigit(c)) {
                i = 0;
                while (isdigit(c)) {
                    i *= 10;
                    i += (c - '0');
                    idx++;
                    if (idx < (int) exp.size())
                        c = exp[idx];
                    else
                        c = EOF;
                }
                idx--;

                if (neg) 
                    postfix.push_back(make_pair(0,-i));
                else
                    postfix.push_back(make_pair(0,i));
                
                neg = false;
                prev_is_num = true;
            } else {
                if ((c == '-') && !prev_is_num) {
                    neg = !neg;
                    continue;
                }

                if (c == ')')
                    prev_is_num = true;
                else
                    prev_is_num  = false;
                
                if (((ope.empty()) || (ope.top() == '(')) && (c != ')'))
                    ope.push(c);
                else if (c == '(')
                    ope.push(c);
                else if (c == ')') {
                    while ((!ope.empty()) && (ope.top() != '(')) {
                        c = ope.top();
                        ope.pop();

                        if (c == '+')
                            postfix.push_back(make_pair(1,0));
                        if (c == '-')
                            postfix.push_back(make_pair(1,1));
                        if (c == '*')
                            postfix.push_back(make_pair(1,2));
                        if (c == '/')
                            postfix.push_back(make_pair(1,3));
                    }
                    if ((!ope.empty()) && (ope.top() == '('))
                        ope.pop();
                } else if (c == '*') {
                    if ((ope.top() == '+') || (ope.top() == '-'))
                        ope.push(c);
                    else {
                        char d = c;
                        while ((!ope.empty()) && (ope.top() != '(') && (ope.top() != '+') && (ope.top() != '-')) {
                            c = ope.top();
                            ope.pop();

                            if (c == '*')
                                postfix.push_back(make_pair(1,2));
                            if (c == '/')
                                postfix.push_back(make_pair(1,3));
                        }

                        ope.push(d);
                    }
                } else if (c == '/') {
                    if ((ope.top() == '+') || (ope.top() == '-'))
                        ope.push(c);
                    else {
                        char d = c;
                        while ((!ope.empty()) && (ope.top() != '(') && (ope.top() != '+') && (ope.top() != '-')) {
                            c = ope.top();
                            ope.pop();

                            if (c == '*')
                                postfix.push_back(make_pair(1,2));
                            if (c == '/')
                                postfix.push_back(make_pair(1,3));
                        }

                        ope.push(d);
                    }
                } else if (c == '+') {
                    char d = c;
                    while ((!ope.empty()) && (ope.top() != '(')) {
                        c = ope.top();
                        ope.pop();

                        if (c == '+')
                            postfix.push_back(make_pair(1,0));
                        if (c == '-')
                            postfix.push_back(make_pair(1,1));
                        if (c == '*')
                            postfix.push_back(make_pair(1,2));
                        if (c == '/')
                            postfix.push_back(make_pair(1,3));
                    }

                    ope.push(d);
                } else {
                    char d = c;
                    while ((!ope.empty()) && (ope.top() != '(')) {
                        c = ope.top();
                        ope.pop();

                        if (c == '+')
                            postfix.push_back(make_pair(1,0));
                        if (c == '-')
                            postfix.push_back(make_pair(1,1));
                        if (c == '*')
                            postfix.push_back(make_pair(1,2));
                        if (c == '/')
                            postfix.push_back(make_pair(1,3));
                    }

                    ope.push(d);
                }
            }
        }

        while (!ope.empty()) {
            c = ope.top();
            ope.pop();

            if (c == '+')
                postfix.push_back(make_pair(1,0));
            if (c == '-')
                postfix.push_back(make_pair(1,1));
            if (c == '*')
                postfix.push_back(make_pair(1,2));
            if (c == '/')
                postfix.push_back(make_pair(1,3));
        }

        stack <double> solve_postfix;
        for (int k = 0; k < (int) postfix.size(); k++) {
            pair <int, double> n = postfix[k];
            if (n.first == 0)
                solve_postfix.push(n.second);
            else {
                double a = solve_postfix.top();
                solve_postfix.pop();
                double b = solve_postfix.top();
                solve_postfix.pop();

                if (n.second == 0)
                    solve_postfix.push(b+a);
                if (n.second == 1)
                    solve_postfix.push(b-a);
                if (n.second == 2)
                    solve_postfix.push(b*a);
                if (n.second == 3)
                    solve_postfix.push(b/a);
            }
        }

        cout << setprecision(2) << fixed << solve_postfix.top() << endl;
    }
    return 0;
}