#include <bits/stdc++.h>
#include <iostream>
using ll = long long;
using namespace std;

struct manacherAlgo {
  vector<int> p;
  void run_manacher(string s) {
    int n = s.size();
    p.assign(n, 1);
    int l = 1, r = 1;
    for (int i = 1; i < n; i++) {
      p[i] = max(0, min(r - i, p[l + r - i]));
      while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) {
        p[i]++;
      }
      if (i + p[i] > r) {
        l = i - p[i];
        r = i + p[i];
      }
    }
  }
  void build(string s) {
    string t;
    for (auto e : s) {
      t += string("#") + e;
    }
    run_manacher(t + '#');
  }
} m;

int main() {
  string s = "babbabbabc"; // 1 2 1 4 1 2 7 2 1 10 1 2 7 2 1 4 1 2 1 2 1
  m.build(s);
  vector<int> v = m.p;
  for (auto e : v) {
    cout << e << " ";
  }
  return 0;
}
