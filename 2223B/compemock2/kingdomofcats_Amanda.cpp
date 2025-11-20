/*
*OpenKattis
*kingdomofcats
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

#define pt pair<long long, long long>
#define vec pair<long long, long long>
#define x first
#define y second

long long CCW (pt A, pt B, pt C)
{
    vec AB = make_pair(B.first-A.first, B.second-A.second);
    vec AC = make_pair(C.first-A.first, C.second-A.second);
    return ((AB.first*AC.second - AB.second*AC.first));
}

/*
bool polygon (vector <pt> P)
{
    int k = 0, n = 4;
    vector<pt> H(2*n);
    //vector <pt> lower;
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && CCW(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
    }

    //vector <pt> upper;
	for (int i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && CCW(H[k-2], H[k-1], P[i-1]) <= 0) k--;
		H[k++] = P[i-1];
	}

    if (k - 1 == 4)
        return true;
    else 
        return false;
}
*/
/*
bool polygon (vector <pt> P)
{
    int sz = P.size();

    sort(P.begin(), P.end());
    pt a = P.front(), b = P.back();

    deque<pt> upper, lower;
    upper.push_back(a);
    lower.push_back(a);

    for(int i = 1; i < sz; ++i){
        if(i == sz - 1 || CCW(a, P[i], b) < 0){
            while(upper.size() >= 2 && CCW(upper[upper.size() - 2], upper[upper.size() - 1], P[i]) >= 0)
                upper.pop_back();
            upper.push_back(P[i]);
        }

        if(i == sz - 1 || CCW(a, P[i], b) > 0){
            while(lower.size() >= 2 && CCW(lower[lower.size() - 2], lower[lower.size() - 1], P[i]) <= 0)
                lower.pop_back();
            lower.push_back(P[i]);
        }
    }

    return ((lower.size() + upper.size() - 2) == 4);
}*/

bool polygon (vector <pt> P)
{
    int sz = P.size();
    vector <pt> upper, lower;

    for(int i = 0; i < sz; i++){
        while(lower.size() >= 2 && CCW(lower[lower.size() - 2], lower[lower.size() - 1], P[i]) <= 0)
            lower.pop_back();
        lower.push_back(P[i]);
    }

    for(int i = sz-1; i >= 0; i--){
        while(upper.size() >= 2 && CCW(upper[upper.size() - 2], upper[upper.size() - 1], P[i]) <= 0)
            upper.pop_back();
        upper.push_back(P[i]);
    }

    return ((lower.size() + upper.size() - 2) == 4);
}

int main ()
{
    int N;
    while (cin >> N) {
        if (!N)
            break;
        
        // get input
        vector <pt> points;
        for (int n = 0; n < N; n++) {
            int x, y;
            cin >> x >> y;
            points.push_back(make_pair(x,y));
        }

        sort(points.begin(), points.end());

        int ans = 0;

        // select 4 points and check if it makes a polygon
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = j+1; k < N; k++) {
                    for (int l = k+1; l < N; l++) {
                        
                        // selected 4 points
                        vector <pt> input;
                        input.push_back(points[i]);
                        input.push_back(points[j]);
                        input.push_back(points[k]);
                        input.push_back(points[l]);

                        if (polygon(input)) {
                            ans++;
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}