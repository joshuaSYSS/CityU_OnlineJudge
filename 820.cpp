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
map<vl, vl> mp;
set<vl> cut, nocut;
pll dfs(vl i) { //{val, has nocut}
    if (cut.count(i)) {
        return { 1, 0 };
    }
    else if (nocut.count(i)) {
        return { 0, 1 };
    }
    pll res = { 0, 0 };
    foreach(x, mp[i]) {
        vl a = i;
        a.push_back(x);
        pll b = dfs(a);
        res.second |= b.second;
        res.first += b.first;
    }
    if (!res.second) {
        res.first = 1;
    }
    return res;
}
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
tcin{
    ll n, m; cin >> n >> m;
mp.clear();
cut.clear();
nocut.clear();
up(0, n, 1) {
    vl v;
    ll u;
    while (cin >> u) {
        if (u == -1) break;
        ll has = 0;
        foreach(x, mp[v]) {
            if (x == u) has = 1;
        }
        if(!has) mp[v].push_back(u);
        v.push_back(u);
    }
    cut.insert(v);
}
up(0, m, 1) {
    vl v;
    ll u;
    while (cin >> u) {
        if (u == -1) break;
        ll has = 0;
        foreach(x, mp[v]) {
            if (x == u) has = 1;
        }
        if(!has) mp[v].push_back(u);
        v.push_back(u);
    }
    nocut.insert(v);
}
ll cnt = 0;
foreach(x, mp[{}]) {
    pll u = dfs({ x });
    cnt += u.first;
}
cout << cnt << '\n';
}
return 0;
}
