#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n, m;
set<string> used;
string last = "*";
char b = '*', e = '*';
bool found;
bool saved;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  for (auto i = 0; i < n; ++i) {
    string x;
    cin >> x;
    if ("?" != x) {
      used.insert(x);
      if (!found) {
        last = x;
      } else {
        if (!saved) {
          e = x.front();
          saved = true;
        }
      }
    } else {
      b = last.back();
      found = true;
    }
  }

  cin >> m;
  for (auto i = 0; i < m; ++i) {
    string x;
    cin >> x;
    if (('*' == b || x.front() == b) && ('*' == e || x.back() == e)) {
      if (used.find(x) == used.end()) {
        cout << x;
        return 0;
      }
    }
  }

  return 0;
}