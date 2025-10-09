#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double;
using ull = unsigned long long; using str = string;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef set<ll> sl;
typedef vector<vector<ll>> vl2;
typedef vector<str> vs;
typedef map<ll, ll> mll;
typedef map<str, ll> msl;
typedef queue<ll> ql;
typedef priority_queue<ll> pqlg;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqls;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef queue<pair<ll, ll>> qpll;

#define up(initial, n, step) for (ll i = (ll)(initial);i < (ll)(n);i += (ll)(step))
#define up2(initial, n, step) for (ll j = (ll)(initial);j < (ll)(n);j += (ll)(step))
#define up3(initial, n, step) for (ll k = (ll)(initial);k < (ll)(n);k += (ll)(step))
#define down(initial, n, step) for (ll i = (ll)(initial) - 1;i >= (ll)(n);i -= (ll)(step))
#define down2(initial, n, step) for (ll j = (ll)(initial) - 1;j >= (ll)(n);j -= (ll)(step))
#define down3(initial, n, step) for (ll k = (ll)(initial) - 1;k >= (ll)(n);k -= (ll)(step))

#define all(x) (x).begin(), (x).end()
#define YES(a) ((a)?"YES":"NO")
#define Yes(a) ((a)?"Yes":"No")
#define yes(a) ((a)?"yes":"no")
#define rev(s) reverse((s).begin(), (s).end());
#define toStr(s) to_string((s))
#define throwErr(s) throw invalid_argument(s)
#define nextPerm next_permutation
#define foreach(a, v) for(auto& a : v)
#define tcin \
  ll testcase; cin >> testcase;\
  while (testcase--)

#define LL_MAX 9223372036854775807
#define LL_MIN (LL_MAX + 1)
const ld PHI = (1 + sqrt(5)) / 2;
const ll Mod = 998244353ll;
const ll Mod2 = 1000000007ll; //10^9 + 7
const ld EPS = 1e-8;
const ld PI = 2 * acos(0.0);
struct node {
    ll to, w;
};
vector<vector<node>> g;
ll res = 0;
pll dfs(ll i, ll p) {
    pll ans = { 0, 0 };
    foreach(x, g[i]) {
        if (x.to != p) {
            pll u = dfs(x.to, i);
            ll val = max(u.first, u.second) + x.w;
            if (val >= ans.first) {
                ans.second = ans.first;
                ans.first = val;
            }
            else if (val >= ans.second) {
                ans.second = val;
            }
        }
    }
    res = max(res, ans.first + ans.second);
    return ans;
}
int main(void){
    std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
    ll n; cin >> n;
    g.resize(n);
    up(0, n - 1, 1) {
        ll u, v; cin >> u >> v;
        u--, v--;
        ll w; cin >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    dfs(0, -1);
    cout << res << '\n';
    return 0;
}
