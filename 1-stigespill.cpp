#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> stige(101);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    stige[a] = b;
  }

  int martin = 1;
  int lise = 1;

  for (int i = 0; i < m; i++) {
    int terning;
    cin >> terning;

    bool mt = i % 2 == 0;

    int felt = (mt ? martin : lise) + terning;
    if (felt < 100 && stige[felt] != 0)
      felt = stige[felt];

    if (felt >= 100) {
      cout << (mt ? "Martin " : "Lise ") << i/2+1 << " " << (mt ? lise : martin) << endl;
      return 0;
    }
    
    if (mt)
      martin = felt;
    else
      lise = felt;
  }

  cout << martin << " " << lise << endl;
  return 0;
}
