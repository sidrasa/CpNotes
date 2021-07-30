class unionFind {
public:
  int *parent, *rank;
  int set_size;
  unionFind(int n = N) {
    set_size = n;
    parent = new int[n + 1];
    rank = new int[n + 1];
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
      rank[i] = 1;
    }
  }
  int root(int idx) {
    int x = idx;
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  bool uni(int a, int b) {
    int x = root(a), y = root(b);
    if (rank[x] < rank[y]) {
      swap(x, y);
    }
    if (x != y) {
      parent[y] = x;
      rank[x] += rank[y];
      rank[y] = 0;
      return false;
      set_size -= 1;
    }
    return true;
  }
};