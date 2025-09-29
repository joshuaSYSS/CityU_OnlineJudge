/*
TLE. Incorrect solution
*/
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

int main(void){
    std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
    ll n, m, tc = 1;
while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    cout << "Case " << tc++ << ": ";
    vl v(n);
    up(0, n, 1) cin >> v[i];
    vl ls;
    up(0, n, 1) {
        up2(0, n, 1) {
            ls.push_back(v[i] + v[j]);
        }
    }
    sort(all(ls));
    ls.erase(unique(all(ls)), ls.end());
    ll res = 0;
    up(0, n, 1) {
        res = max(res, v[i]);
    }
    res = max(res, ls[ls.size() - 1]);
    up(0, n, 1) {
        auto g = upper_bound(all(ls), m - v[i]);
        if (g != ls.begin()) {
            --g;
            res = max(res, *g + v[i]);
        }
        up2(0, n, 1) {
            auto f = upper_bound(all(ls), m - (v[i] + v[j]));
            if (f == ls.begin()) continue;
            --f;
            res = max(res, *f + v[i] + v[j]);
        }
    }
    cout << res << '\n';
    cout << '\n';
}
    return 0;
}
