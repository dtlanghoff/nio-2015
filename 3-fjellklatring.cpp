#include <cstdlib>
#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

class Compare {
public:
  bool operator() (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

vector<int> neighbours(int u, int n, int m) {
  vector<int> nb;
  if (u >= m)
    nb.push_back(u-m);
  if (u+m < n*m)
    nb.push_back(u+m);
  if (u%m > 0)
    nb.push_back(u-1);
  if (u%m < (m-1))
    nb.push_back(u+1);

  return nb;
}

int main() {
  int n, m;
  int src = -1;
  cin >> n >> m;

  vector<int> dest;
  vector<int> difficulty(n*m, numeric_limits<int>::max());
  vector<int> height(n*m);
  vector<bool> visited(n*m, false);
  priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;

  for (int i = 0; i < n*m; i++)
    cin >> height[i];

  for (int i = 0; i < n*m; i++) {
    bool p;
    cin >> p;
    if (p) {
      if (src == -1)
        src = i;
      else
        dest.push_back(i);
    }
  }

  difficulty[src] = 0;
  for (int i = 0; i < n*m ; i++)
    pq.push(make_pair(i, difficulty[i]));

  while (!pq.empty()) {
    pair<int, int> u = pq.top();
    pq.pop();
    if (!visited[u.first]) {
      visited[u.first] = true;
      vector<int> nb = neighbours(u.first, n, m);
      for (int i = 0; i < nb.size(); i++) {
        int v = nb[i];
        if (!visited[v]) {
          int alt = max(difficulty[u.first], abs(height[u.first]-height[v]));
          if (alt < difficulty[v]) {
            difficulty[v] = alt;
            pq.push(make_pair(v, alt));
          }
        }
      }
    }
  }
  int r = 0;
  for (int i = 0; i < dest.size(); i++)
    r = max(r, difficulty[dest[i]]);

  cout << r << endl;
}
