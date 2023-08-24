#include <bits/stdc++.h>
#include <iostream>
using ll = long long;
using namespace std;

struct manacherAlgo {
  // this algo uses the property of palindrome i.e all the left and right would
  // be also a palindrome wrt to the middle one so the idea is to keep a track
  // of large palindrome l and r (l and r exclusive) and by using this build all
  // the small one
  vector<int> p;
  void run_manacher(string s) {
    cout << s;
    int n = s.size();
    p.assign(n, 1);
    int l = 1, r = 1;
    for (int i = 1; i < n; i++) {
      // learn by heart
      p[i] = max(0, min(r - i, p[l + r - i]));
      //   increase the max block
      while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]]) {
        p[i]++;
      }
      //   if we get better then we update
      if (i + p[i] > r) {
        l = i - p[i];
        r = i + p[i];
      }
    }
  }
  void build(string s) {
    string t;
    for (auto e : s) {
      // we add # so that odd palindrome also becomes even when * 2
      t += string("#") + e;
    }
    run_manacher(t + '#');
  }
} m;

int main() {
  string s = "babbabbabc";
  //   how much of the string is same as front and back
  // considering the middle both in front and back
  //   # b # a # b # b #  a  # b # b # a # b # c #
  //   1 2 1 4 1 2 7 2 1 10  1 2 7 2 1 4 1 2 1 2 1
  m.build(s);
  vector<int> v = m.p;
  for (auto e : v) {
    cout << e;
  }
  return 0;
}
