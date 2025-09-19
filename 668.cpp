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
ll n, m;
while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    vs v(n + 2, str(m + 2, '.'));
    up(1, n + 1, 1) {
        up2(1, m + 1, 1) {
            cin >> v[i][j];
        }
    }
    vl2 marked(n + 2, vl(m + 2, 0));
    queue<pll> q;
    q.push({ 0, 0 });
    set<pll> visited;
    while (!q.empty()) {
        pll u = q.front();
        q.pop();
        ll i = u.first, j = u.second;
        if (visited.count({i, j})) continue;
        visited.insert({ i, j });
        if (i > 0) {
            if (v[i - 1][j] == '.') {
                q.push({ i - 1, j });
            }
            else {
                marked[i - 1][j] = 1;
            }
        }
        if (j > 0) {
            if (v[i][j - 1] == '.') {
                q.push({ i, j - 1 });
            }
            else {
                marked[i][j - 1] = 1;
            }
        }
        if (i + 1 < n + 2) {
            if (v[i + 1][j] == '.') {
                q.push({ i + 1, j });
            }
            else {
                marked[i + 1][j] = 1;
            }
        }
        if (j + 1 < m + 2) {
            if (v[i][j + 1] == '.') {
                q.push({ i, j + 1 });
            }
            else {
                marked[i][j + 1] = 1;
            }
        }
    }
    up(1, n + 1, 1) {
        up2(1, m + 1, 1) {
            if (v[i][j] == '*') {
                if (marked[i][j]) {
                    if (visited.count({i - 1, j}) &&
                        visited.count({i, j - 1}) &&
                        visited.count({i + 1, j}) &&
                        visited.count({i, j + 1})) {
                        marked[i][j] = 3;
                    }
                }
                else {
                    marked[i][j] = 2;
                }
            }
        }
    }
    up(1, n + 1, 1) {
        up2(1, m + 1, 1) {
            if (marked[i][j] == 0) {
                cout << '.';
            }
            else if (marked[i][j] == 1) {
                cout << 'A';
            }
            else if (marked[i][j] == 2) {
                cout << 'S';
            }
            else {
                cout << 'W';
            }
        }
        cout << '\n';
    }
}
return 0;
}
