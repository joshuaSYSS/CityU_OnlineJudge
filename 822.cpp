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
int head[1000010 << 1], tot;
long long n, sz[1000010], dep[1000010];
long long f[1000010];

struct node {
  int to, next;
} e[1000010 << 1];

void add(int u, int v) {
  e[++tot] = {v, head[u]};
  head[u] = tot;
}

void dfs(int u, int fa) {
  sz[u] = 1;
  dep[u] = dep[fa] + 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v != fa) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

void get_ans(int u, int fa) {
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v != fa) {
      f[v] = f[u] - sz[v] * 2 + n;
      get_ans(v, u);
    }
  }
}
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
cin >> n;
  int u, v;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; i++) f[1] += dep[i];
  get_ans(1, 1);
  long long int ans = INT_MAX;
  int id;
  for (int i = 1; i <= n; i++) {
    if (f[i] < ans) {
      ans = f[i];
      id = i;
    }
  }
  cout << ans << '\n';
}
