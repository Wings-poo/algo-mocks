/*
*OpenKattis
*mazeman
*Code by: Amanda Lim
*/

#include <bits/stdc++.h>
using namespace std;

int find (int parent[], int A) {
    if (parent[A] == A)
        return A;
    return find(parent, parent[A]);
}

void union_ (int parent[], int size[], int A, int B) {
    int X = find(parent, B);
    int Y = find(parent, A);
    if (X != Y) {
        parent[Y] = X;
        size[X] += size[Y];
    }
    return;
}

int main ()
{
    int N, M;
    cin >> N >> M;
    getchar();

    char maze[N][M];
    int dots = 0;
    vector <int> entrance;

    int index = 0;
    map <pair <int, int>, int> idx;
    
    int parent[N*M];
    int size[N*M];
    
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            maze[n][m] = getchar();

            parent[index] = index;
            if (maze[n][m] == '.')
                size[index] = 1;
            else
                size[index] = 0;

            if (maze[n][m] == '.')
                dots++;
            
            if (isalpha(maze[n][m]) && (maze[n][m] != 'X'))
                entrance.push_back(index);

            idx[make_pair(n,m)] = index;
            index++;         
        }
        getchar();
    }
            
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (maze[n][m] != 'X') {
                int A = idx[make_pair(n,m)];

                if (n != 0) {
                    if (((maze[n][m] == '.') || (maze[n][m] == ' ')) && (maze[n-1][m] != 'X')) {
                        int B = idx[make_pair(n-1,m)];
                        union_(parent,size,A,B);
                    }
                    if (isalpha(maze[n][m]) && (maze[n][m] != 'X') && ((maze[n-1][m] == '.') || (maze[n-1][m] == ' '))) {
                        int B = idx[make_pair(n-1,m)];
                        union_(parent,size,A,B);
                    }
                }

                if (m != 0) {
                    if (((maze[n][m] == '.') || (maze[n][m] == ' ')) && (maze[n][m-1] != 'X')) {
                        int B = idx[make_pair(n,m-1)];
                        union_(parent,size,A,B);
                    }
                    if (isalpha(maze[n][m]) && (maze[n][m] != 'X') && ((maze[n][m-1] == '.') || (maze[n][m-1] == ' '))) {
                        int B = idx[make_pair(n,m-1)];
                        union_(parent,size,A,B);
                    }
                }

                if (n != N - 1) {
                    if (((maze[n][m] == '.') || (maze[n][m] == ' ')) && (maze[n+1][m] != 'X')) {
                        int B = idx[make_pair(n+1,m)];
                        union_(parent,size,A,B);
                    }
                    if (isalpha(maze[n][m]) && (maze[n][m] != 'X') && ((maze[n+1][m] == '.') || (maze[n+1][m] == ' '))) {
                        int B = idx[make_pair(n+1,m)];
                        union_(parent,size,A,B);
                    }
                }

                if (n != M - 1) {
                    if (((maze[n][m] == '.') || (maze[n][m] == ' ')) && (maze[n][m+1] != 'X')) {
                        int B = idx[make_pair(n,m+1)];
                        union_(parent,size,A,B);
                    }
                    if (isalpha(maze[n][m]) && (maze[n][m] != 'X') && ((maze[n][m+1] == '.') || (maze[n][m+1] == ' '))) {
                        int B = idx[make_pair(n,m+1)];
                        union_(parent,size,A,B);
                    }
                }
            }
        }
    }

    map <int,int> necessary_entrance;
    for (int i = 0; i < (int) entrance.size(); i++) {
        int X = find(parent,entrance[i]);
        if ((necessary_entrance.find(X) == necessary_entrance.end()) && (size[X]))
            necessary_entrance[X] = 1;
        else if (size[X] > 1)
            necessary_entrance[X]++;
    }

    int reachable_dots = 0;
    for (auto it : necessary_entrance) {
        reachable_dots += size[it.first];
    }

    cout << necessary_entrance.size() << " " << dots - reachable_dots << endl;

    return 0;
}