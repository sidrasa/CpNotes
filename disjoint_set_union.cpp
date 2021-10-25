struct DSU {
	vector<int> e;
	void init (int n) { e = vector<int> (n, -1); }
	int get (int x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
	bool sameSet (int x, int y) { return get(x) == get(y); }
	int size (int x) { return -e[get(x)]; }
	bool unite (int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};
