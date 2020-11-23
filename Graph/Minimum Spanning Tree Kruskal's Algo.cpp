/****************************************
**                Ra Sa                **
****************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define fe(i, a, b) for (int i = a; i <= b; i++)
#define fl(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define re(t) \
    int t;    \
    cin >> t;
#define ra(arr, n) \
    int arr[n];    \
    fl(i, 0, n) cin >> arr[i];
#define mod 1000000007
#define el "\n"

class edge
{
public:
    int src;
    int dst;
    int w;
};

class st
{
public:
    int rank;
    int parent;
};

int find(st ur[], int i)
{
    if (ur[i].parent != i)
    {
        ur[i].parent = find(ur, ur[i].parent);
    }
    return ur[i].parent;
}

void un(st ur[], int v1, int v2)
{
    int v1p = find(ur, v1);
    int v2p = find(ur, v2);
    if (ur[v1p].rank < ur[v2p].rank)
    {
        ur[v1p].parent = v2p;
        ur[v2p].rank += ur[v1p].rank;
    }
    else
    {
        ur[v2p].parent = v1p;
        ur[v1p].rank += ur[v2p].rank;
    }
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void kruskal(edge a[], int nv, int e)
{
    sort(a, a + e, cmp);
    edge ans[nv - 1];
    st ur[nv];
    fl(i, 0, nv)
    {
        ur[i].rank = 1;
        ur[i].parent = i;
    }
    int c = 0, i = 0;
    while (c < nv - 1)
    {
        edge ce = a[i];
        int ps = find(ur, ce.src);
        int pd = find(ur, ce.dst);
        if (ps != pd)
        {
            ans[c] = ce;
            un(ur, ps, pd);
            c++;
        }
        i++;
    }
    int weight = 0;
    fl(m, 0, c)
    {
        // cout << ans[m].src << "---" << ans[m].dst << " weight- " << ans[m].w << el;
        weight += ans[m].w;
    }
    cout << weight << el;
}

void solve()
{
    re(nv);
    re(e);
    edge a[e];
    fl(i, 0, e)
    {
        re(s);
        re(d);
        re(w);
        a[i].src = --s;
        a[i].dst = --d;
        a[i].w = w;
    }
    kruskal(a, nv, e);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}