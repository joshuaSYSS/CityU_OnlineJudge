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
bool MST_SORT(vl& a, vl& b) {
    return a[2] < b[2];
}
ll cost = 0;
void MST(ll n, vl2& edges) { //edges is a tuple storing 3 items {u, v, w}
    vl tree_id(n);
    up(0, n, 1) {
        tree_id[i] = i;
    }
    cost = 0; //Get cost if you need.
    sort(all(edges), MST_SORT);
    foreach(e, edges) {
        ll u = e[0], v = e[1], w = e[2];
        if (tree_id[u] != tree_id[v]) {
            cost += w;
            ll old_id = tree_id[u], new_id = tree_id[v];
            up(0, n, 1) {
                if (tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }
    }
}

int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll p, r;
while (cin >> p) {
    if (p == 0) break;
    cin >> r;
    vl2 edge(r, vl(3));
    up(0, r, 1) {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
        --edge[i][0];
        --edge[i][1];
    }
    MST(p, edge);
    cout << cost << '\n';
}
return 0;
}
