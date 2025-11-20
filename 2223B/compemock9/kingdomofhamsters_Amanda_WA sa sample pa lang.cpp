/*
*OpenKattis
*kingdomofhamsters
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main ()
{
    int N;
    cin >> N;

    vector <pair <double, double>> points;
    //map <pair <double, double>, int> index;
    for (int n = 0; n < N; n++) {
        double x, y;
        cin >> x >> y;
        points.push_back(make_pair(x,y));
        //index[make_pair(x,y)] = n;
    }

    vector <priority_queue <pair <double, int>>> lengths (N); 
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double distance = sqrt((points[j].x - points[i].x)*(points[j].x - points[i].x) + (points[j].y - points[i].y)*(points[j].y - points[i].y));
            //cout << distance << " " << i << " " << j << endl;
            lengths[i].push(make_pair(distance,j));
            lengths[j].push(make_pair(distance,i));
        }
    }
    
    for (int i = 0; i < N; i++) {
        double perimeter = 0;
        int idx = i;
        set <int> taken_points;
        for (int j = 0; j < 6; j++) {
            taken_points.insert(idx);
            vector <pair <double, int>> temp_vec;
            while (taken_points.find(lengths[idx].top().second) != taken_points.end()) {
                pair <double, int> temp = lengths[idx].top();
                lengths[idx].pop();
                temp_vec.push_back(temp);
            }

            perimeter += lengths[idx].top().first;
            //cout << perimeter << endl;

            for (int k = 0; k < (int) temp_vec.size(); k++) {
                pair <double, int> temp = temp_vec[k];
                lengths[idx].push(temp);
            }
        }

        cout << perimeter << endl;
    }
    return 0;
}