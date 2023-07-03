const int N = 1e6 + 3;
vector<int> p;
void prime() {
  p.resize(N, 1);
  p[0] = p[1] = 0;
  for (int i = 2; i * i < N; i++) {
    if (p[i]) {
      for (int j = i * i; j < N; j += i)
        p[j] = 0;
    }
  }
}
