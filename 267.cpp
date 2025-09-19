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
vector<vector<pll>> head(101, vpll(101));
vector<vector<ll>> size_(101, vl(101));
pll find_set(pll v) {
    if (v == head[v.first][v.second]) {
        return v;
    }
    return head[v.first][v.second] = find_set(head[v.first][v.second]);
}
void union_sets(pll a, pll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size_[a.first][a.second] < size_[b.first][b.second]) {
            swap(a, b);
        }
        head[b.first][b.second] = head[a.first][a.second];
        size_[a.first][a.second] += size_[b.first][b.second];
    }
}

int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll n, m, k; 
while (cin >> n >> m >> k) {
    up(0, n, 1) {
        up2(0, m, 1) {
            head[i][j] = { i, j };
            size_[i][j] = 1;
        }
    }
    vl2 v(n, vl(m, 0));
    while (k--) {
        ll a, b; cin >> a >> b;
        --a, --b;
        v[a][b] = 1;
    }
    up(0, n, 1) {
        up2(0, m, 1) {
            if (v[i][j]) {
                pll u = find_set(head[i][j]);
                if (i > 0 && v[i - 1][j] == 1) {
                    union_sets(u, head[i - 1][j]);
                }
                if (j > 0 && v[i][j - 1] == 1) {
                    union_sets(u, head[i][j - 1]);
                }
            }
        }
    }
    ll res = 0;
    up(0, n, 1) {
        up2(0, m, 1) {
            if (v[i][j]) {
                pll u = find_set(head[i][j]);
                //cout << i << ", " << j << ": " << u.first << ' ' << u.second << '\n';
                res = max(res, size_[u.first][u.second]);
            }
        }
    }
    cout << res << '\n';
}
/*
oxxx
xoox
ooxx
*/
return 0;
}
