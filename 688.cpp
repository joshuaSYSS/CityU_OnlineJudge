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
class cmp {
public:
    bool operator()(vl& a, vl& b) {
        return a[2] > b[2];
    }
};
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll tc; cin >> tc;
for(ll p = 1; p <= tc;p++){
    cout << "Case " << p << ": ";
    ll n = 8;
vs v(n);
up(0, n, 1) cin >> v[i];
vl2 dist(n, vl(n, INT_MAX));
priority_queue<vl, vl2, cmp> pq;
ll ok = 0;
up(0, n, 1) {
    up2(0, n, 1) {
        if (v[i][j] == '#') {
            pq.push({ i, j });
            ok = 1;
            dist[i][j] = 0;
            break;
        }
    }
    if (ok) break;
}
while (!pq.empty()) {
    vl u = pq.top();
    pq.pop();
    ll i = u[0], j = u[1];
    if (i - 1 >= 0 && j - 2 >= 0 && v[i - 1][j - 2] != '*' && dist[i - 1][j - 2] > dist[i][j] + 1) {
        dist[i - 1][j - 2] = dist[i][j] + 1;
        pq.push({ i - 1, j - 2, dist[i - 1][j - 2] });
    }
    if (i - 2 >= 0 && j - 1 >= 0 && v[i - 2][j - 1] != '*' && dist[i - 2][j - 1] > dist[i][j] + 1) {
        dist[i - 2][j - 1] = dist[i][j] + 1;
        pq.push({ i - 2, j - 1, dist[i - 2][j - 1] });
    }
    if (i - 2 >= 0 && j + 1 < n && v[i - 2][j + 1] != '*' && dist[i - 2][j + 1] > dist[i][j] + 1) {
        dist[i - 2][j + 1] = dist[i][j] + 1;
        pq.push({ i - 2, j + 1, dist[i - 2][j + 1] });
    }
    if (i - 1 >= 0 && j + 2 < n && v[i - 1][j + 2] != '*' && dist[i - 1][j + 2] > dist[i][j] + 1) {
        dist[i - 1][j + 2] = dist[i][j] + 1;
        pq.push({ i - 1, j + 2, dist[i - 1][j + 2] });
    }

    if (i + 1 < n && j - 2 >= 0 && v[i + 1][j - 2] != '*' && dist[i + 1][j - 2] > dist[i][j] + 1) {
        dist[i + 1][j - 2] = dist[i][j] + 1;
        pq.push({ i + 1, j - 2, dist[i + 1][j - 2] });
    }
    if (i + 2 < n && j - 1 >= 0 && v[i + 2][j - 1] != '*' && dist[i + 2][j - 1] > dist[i][j] + 1) {
        dist[i + 2][j - 1] = dist[i][j] + 1;
        pq.push({ i + 2, j - 1, dist[i + 2][j - 1] });
    }
    if (i + 2 < n && j + 1 < n && v[i + 2][j + 1] != '*' && dist[i + 2][j + 1] > dist[i][j] + 1) {
        dist[i + 2][j + 1] = dist[i][j] + 1;
        pq.push({ i + 2, j + 1, dist[i + 2][j + 1] });
    }
    if (i + 1 < n && j + 2 < n && v[i + 1][j + 2] != '*' && dist[i + 1][j + 2] > dist[i][j] + 1) {
        dist[i + 1][j + 2] = dist[i][j] + 1;
        pq.push({ i + 1, j + 2, dist[i + 1][j + 2] });
    }
}
ok = 0;
ll res = 0;
up(0, n, 1) {
    up2(0, n, 1) {
        if (v[i][j] == '@') {
            res = dist[i][j];
            ok = 1;
            break;
        }
    }
    if (ok) break;
}
if (res == INT_MAX) {
    cout << "IMPOSSIBLE\n";
}
else {
    cout << res << '\n';
}
}
/*
2 
#----*-- 
---*---- 
----*--- 
------*- 
--@----- 
-------- 
---*--*- 
-----*-- 

#----*-- 
--**---- 
-*--*---
------*-
--@-----
--------
---*--*-
-----*--
*/
return 0;
}
