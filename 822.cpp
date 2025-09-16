#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vl> vl2;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
#define up(initial, n, step) for (ll i = (ll)(initial);i < (ll)(n);i += (ll)(step))
#define foreach(a, v) for(auto& a : v)
ll n, sum = 0;
vl2 g;
vl s;
vl cnt;
vl depth;
void dfs(ll i, ll p) {
    foreach(x, g[i]) {
        if (x != p) {
            depth[x] = depth[i] + 1;
            dfs(x, i);
            s[i] += s[x];
        }
    }
    s[i] += cnt[i];
}
vl dp;
void dfs2(ll i, ll p) {
    dp[i] = dp[p] + sum - 2 * s[i];
    foreach(x, g[i]) {
        if (x != p) {
            dfs2(x, i);
        }
    }
}
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
cin >> n;
g.resize(n);
cnt.resize(n);
up(0, n, 1) {
    ll l, r; cin >> cnt[i] >> l >> r;
    sum += cnt[i];
    --l, --r;
    if (l != -1) g[i].push_back(l), g[l].push_back(i);
    if (r != -1) g[i].push_back(r), g[r].push_back(i);
}
s = vl(n, 0);
depth = vl(n, 0);
dfs(0, -1);
dp = vl(n);
dp[0] = 0;
up(0, n, 1) {
    dp[0] += depth[i] * cnt[i];
}
foreach(x, g[0]) {
    dfs2(x, 0);
}
ll res = LLONG_MAX;
foreach(x, dp) {
    res = min(res, x);
}
cout << res << '\n';
}