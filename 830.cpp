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
vl2 g;
vl vis;
set<ll> s;
void dfs(ll i) {
    vis[i]++;
    s.insert(i);
    foreach(x, g[i]) {
        if (!s.count(x)) {
            dfs(x);
        }
    }
}
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll k, n, m; cin >> k >> n >> m;
vl pos(k);
for (ll i = 0; i < k; i++) {
    cin >> pos[i];
    pos[i]--;
}
g.resize(n);
for (ll i = 0; i < m; i++) {
    ll u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
}
vis = vl(n, 0);
for (ll i = 0; i < k; i++) {
    s.clear();
    dfs(pos[i]);
}
ll res = 0;
foreach(x, vis) {
    res += x == k;
}
cout << res << '\n';
}
