#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  vector< vector<int> > edgelist(n);
  vector<int> degree(n);
  vector<int> ndegree(n);

  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    edgelist[a].push_back(b);
    edgelist[b].push_back(a);
    degree[a]++;
    degree[b]++;
  }

  ndegree = degree;

  while (true) {
    for (int i = 0; i < n; i++) {
      if (degree[i] == 1) {
        ndegree[i] = -1;
        for (int j = 0; j < edgelist[i].size(); j++)
          ndegree[edgelist[i][j]]--;
      }
      else if (degree[i] == 0) {
        cout << i << endl;
        return 0;
      }
    }
    degree = ndegree;
  }
}
