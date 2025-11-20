#include <bits/stdc++.h>

using namespace std;

int sz = 8; //size of graph

void add_edge(vector<int>neighbors[], int x, int y){
  neighbors[x].push_back(y);
  neighbors[y].push_back(x);
  return;
}

void bfs(vector<int>neighbors[], int source){
  vector<int> distance(sz, INT_MAX);
  queue<int> q;

  distance[source] = 0;
  q.push(source);

  int cur, next;
  while(!q.empty()){
    cur = q.front();
    q.pop();

    for(int i = 0; i < (int)neighbors[cur].size(); i++){
      next = neighbors[cur][i];
      if(distance[next] == INT_MAX){
        distance[next] = distance[cur] + 1;
        q.push(next);
      }
    }
  }

  for (int i = 1; i < sz; i++)
    cout << distance[i] << endl;

  return;
}

int main(void){
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    if (t > 0)
        cout << endl;
        
    int P, D;
    cin >> P >> D;
    vector<int> neighbors[P]; //the graph
    sz = P;

    for (int d = 0; d < D; d++) {
      int A, B;
      cin >> A >> B;

      add_edge(neighbors, A, B);
    }

    bfs(neighbors, 0);
  }

  return 0;
}
