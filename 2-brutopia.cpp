#include <cstdio>
#include <functional>
#include <queue>

using namespace std;

int main() {
  int k, n;
  scanf("%d%d", &k, &n);

  priority_queue<int, vector<int>, greater<int> > board;
  priority_queue<int, vector<int>, greater<int> > disembark;

  int tickets = 0;
  int passengers = 0;
  int sum = 0;

  int a, b;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    board.push(a);
    disembark.push(b);
  }

  while (board.size() > 0) {
    if (board.top() < disembark.top()) {
      passengers++;
      if (passengers > tickets) {
        tickets++;
        sum++;
      }
      board.pop();
    }
    else if (board.top() == disembark.top()) {
      board.pop();
      disembark.pop();
    }
    else {
      passengers--;
      if (passengers == 0)
        tickets = 0;
      disembark.pop();
    }
  }

  printf("%d\n", sum);
  return 0;
}
