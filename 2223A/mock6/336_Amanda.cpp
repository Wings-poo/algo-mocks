#include <bits/stdc++.h>

using namespace std;

int sz = 8; //size of graph

void add_edge(vector<int>neighbors[], int x, int y){
  neighbors[x].push_back(y);
  neighbors[y].push_back(x);
  return;
}

int bfs(vector<int>neighbors[], int source){
  vector <int> distance(sz, INT_MAX);
  queue <int> q;

  distance[source] = 0;
  q.push(source);

  int cur, next;
  while(!q.empty()){
    cur = q.front();
    q.pop();

    cout << cur << " ";

    for(int i = 0; i < (int)neighbors[cur].size(); i++){
      next = neighbors[cur][i];
      if(distance[next] == INT_MAX){
        distance[next] = distance[cur] + 1;
        q.push(next);
      }
    }
  }

  return;
}

int main(void){
  int N;
  while (cin >> N) {
    vector <int> neighbors[2*N]; //max graph size
    map <int, int> node;

    int A, B;
    for (int n = 0; n < N; n++) {
        cin >> A >> B;
        if (node.find(A) == node.end())
            node[A] = node.size();
        if (node.find(B) == node.end())
            node[B] = node.size();
        add_edge(neighbors, node[A], node[B]);
    }

    bfs(neighbors, 0);
    while (cin >> A >> B) {
      if (!A && !B)
        break;
      
      if ((node.find(A) == node.end()) || (node.find(B) == node.end()))
            not existing node lol
    }
  }

  return 0;
}
