/****************************************
**                Ra Sa                **
****************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define mp make_pair
#define fe(i, a, b) for (int i = a; i <= b; i++)
#define fl(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define ee(t) \
    int t;    \
    cin >> t;
#define aa(arr, n) \
    int arr[n];    \
    fl(i, 0, n) cin >> arr[i];
#define sz size()
#define mod 1000000007
#define el "\n"
#define ff first
#define ss second

class graph
{
public:
    int v;
    list<pair<int, int>> *al;
    graph(int v)
    {
        this->v = v;
        al = new list<pair<int, int>>[v];
    }
    void ae(int s, int d, int w)
    {
        al[s].pb(mp(d, w));
        al[d].pb(mp(s, w));
    }
    int fmv(bool vis[], int w[], int v)
    {
        int ind = -1;
        int mn = INT_MAX;
        fl(i, 0, v)
        {
            if (vis[i] == false && w[i] < mn)
            {
                mn = w[i];
                ind = i;
            }
        }
        return ind;
    }
    void prims()
    {
        bool vis[v];
        int par[v];
        int w[v];
        fl(i, 0, v)
        {
            vis[i] = false;
            w[i] = INT_MAX;
        }
        par[0] = -1;
        w[0] = 0;
        fl(i, 0, v)
        {
            int mv = fmv(vis, w, v);
            vis[mv] = true;
            for (auto child : al[mv])
            {
                if (!vis[child.ff])
                {
                    if (w[child.ff] > child.ss)
                    {
                        par[child.ff] = mv;
                        w[child.ff] = child.ss;
                    }
                }
            }
        }
        fl(i, 1, v)
        {
            cout << i << "--" << par[i] << " - " << w[i] << el;
        }
    }
};

void solve()
{
    ee(n);
    ee(e);
    graph g(n);
    fl(i, 0, e)
    {
        ee(u);
        ee(v);
        ee(w);
        g.ae(u, v, w);
    }
    g.prims();
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}