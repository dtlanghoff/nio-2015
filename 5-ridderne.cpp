#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

bool step(vector<map<int, int> >& comb, vector<map<int, int> >& lcomb, vector<int>& armour, vector<int>& larmour,
           vector<int>& tot, vector<int>& ltot, vector<int>& first_armour) {
  for (int i = 0; i < comb.size(); i++)
    comb[i].clear();
  fill(tot.begin(), tot.end(), 0);

  int n;
  scanf("%d", &n); // dette er ikkje ei tevling i funksjonell programmering
  armour.resize(n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &armour[i]);
    for (int j = 0; j < first_armour.size(); j++) {
      comb[first_armour[j]][armour[i]] = (ltot[first_armour[j]] - lcomb[first_armour[j]][armour[i]]) % 1000003;
      tot[first_armour[j]] += comb[first_armour[j]][armour[i]];
    }
  }

  if (n == 1 && larmour.size() == 1 && armour[0] == larmour[0])
    return false;

  return true;
}

int main() {
  int nknights;
  scanf("%d", &nknights);

  vector<int> last_armour;
  vector<int> armour;

  int n;

  scanf("%d", &n);
  vector<map<int, int> > last_comb(n+1);
  vector<map<int, int> > comb(n+1);
  vector<int> ltot(n+1);
  vector<int> tot(n+1);
  vector<int> first_armour(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &first_armour[i]);

  scanf("%d", &n);
  last_armour.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &last_armour[i]);
    for (int j = 0; j < first_armour.size(); j++)
      if (first_armour[j] != last_armour[i]) {
        last_comb[first_armour[j]][last_armour[i]] = 1;
        ltot[first_armour[j]]++;
      }
  }

  for (int t = 2; t < nknights; t++) {
    bool r;
    if (t % 2 == 0)
      r = step(comb, last_comb, armour, last_armour, tot, ltot, first_armour);
    else
      r = step(last_comb, comb, last_armour, armour, ltot, tot, first_armour);
    if (!r) {
      printf("0\n");
      return 0;
    }
  }

  if (nknights % 2 == 0)
    comb = last_comb;
  else
    last_armour = armour;

  int sum = 0;

  for (int i = 0; i < first_armour.size(); i++)
    for (int j = 0; j < last_armour.size(); j++) {
      if (first_armour[i] != last_armour[j])
        sum += comb[first_armour[i]][last_armour[j]];
      sum %= 1000003;
    }

  printf("%d\n", sum);
  return 0;
}
