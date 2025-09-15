#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vl> vl2;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
#define foreach(a, v) for(auto& a : v)
#define up(initial, n, step) for (ll i = (ll)(initial);i < (ll)(n);i += (ll)(step))
#define up2(initial, n, step) for (ll j = (ll)(initial);j < (ll)(n);j += (ll)(step))

vl2 g;
vl vertices;
vl height;
vl first;

const int tab64[64] = {
    63,  0, 58,  1, 59, 47, 53,  2,
    60, 39, 48, 27, 54, 33, 42,  3,
    61, 51, 37, 40, 49, 18, 28, 20,
    55, 30, 34, 11, 43, 14, 22,  4,
    62, 57, 46, 52, 38, 26, 32, 41,
    50, 36, 17, 19, 29, 10, 13, 21,
    56, 45, 25, 31, 35, 16,  9, 12,
    44, 24, 15,  8, 23,  7,  6,  5 };

ll fast_log2(uint64_t value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value |= value >> 32;
    return tab64[((uint64_t)((value - (value >> 1)) * 0x07EDD5E59A4E28C2)) >> 58];
}

struct stTableLCA {
    ll n;
    vector<vector<pll>> v;
    stTableLCA() {
        n = height.size();
        v = vector<vector<pll>>(n, vpll(fast_log2(n) + 1));
        up(0, n, 1) {
            v[i][0] = { height[i], vertices[i] };
        }
        up(1, fast_log2(n) + 1, 1) {
            up2(0, n, 1) {
                if (j + (1ll << i) - 1 < n) {
                    if (v[j][i - 1].first < v[j + (1ll << (i - 1))][i - 1].first) {
                        v[j][i] = v[j][i - 1];
                    }
                    else {
                        v[j][i] = v[j + (1ll << (i - 1))][i - 1];
                    }
                }
            }
        }
    }
    ll query(ll l, ll r) {
        ll len = r - l + 1;
        ll a = fast_log2(len);
        if (v[l][a].first < v[r - (1ll << a) + 1][a].first) {
            return v[l][a].second;
        }
        return v[r - (1ll << a) + 1][a].second;
    }
};

void builddfsorder(ll i, ll parent, ll dist) {
    first[i] = vertices.size();
    vertices.push_back(i);
    height.push_back(dist);
    foreach(x, g[i]) {
        if (x != parent) {
            builddfsorder(x, i, dist + 1);
            vertices.push_back(i);
            height.push_back(dist);
        }
    }
}
void builddfsorder(ll i) {
    builddfsorder(i, -1, 0);
}
ll lca(ll p, ll q, stTableLCA& st) {
    return st.query(min(first[p], first[q]), max(first[p], first[q]));
}
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
  ll tc; cin >> tc;
while (tc--) {
    ll root; cin >> root;
    --root;
    ll n; cin >> n;
    g = vl2(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    first = vl(n);
    height.clear();
    vertices.clear();
    builddfsorder(root);
    stTableLCA st;
    ll a, b; cin >> a >> b;
    --a, --b;
    ll nodeLCA = lca(a, b, st);
    cout << nodeLCA + 1 << '\n';
}
}
