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

bool cmp(const vl& a, const vl& b) {
    return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
}
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
str s;
while (getline(cin, s)) {
    ll n = s.length();
    ll a = 0, b = 0, c = 0;
    up(0, n, 1) {
        if (s[i] == 'A') a++;
        else if (s[i] == 'B') b++;
        else c++;
    }
    ll res = 0;
    vector<vector<vector<tuple<ll, ll, ll>>>> dp;
    vl2 q;
    up(0, a + 1, 1) {
        up2(0, b + 1, 1) {
            up3(0, c + 1, 1) {
                if (i + j + k > 1) {
                    q.push_back({ i, j, k });
                }
            }
        }
    }
    sort(all(q), cmp);
    if (a) {
        dp = vector<vector<vector<tuple<ll, ll, ll>>>>(a + 1, vector<vector<tuple<ll, ll, ll>>>(b + 1, vector<tuple<ll, ll, ll>>(c + 1, tuple<ll,ll,ll>(0, 0, 0))));
        dp[1][0][0] = tuple<ll,ll,ll>(1, 0, 0);
        foreach(x, q) {
            ll i = x[0], j = x[1], k = x[2];
            if (i > 0) {
                get<0>(dp[i][j][k]) = (get<1>(dp[i - 1][j][k]) + get<2>(dp[i - 1][j][k])) % Mod2;
            }
            if (j > 0) {
                get<1>(dp[i][j][k]) = (get<0>(dp[i][j - 1][k]) + get<2>(dp[i][j - 1][k])) % Mod2;
            }
            if (k > 0) {
                get<2>(dp[i][j][k]) = (get<0>(dp[i][j][k - 1]) + get<1>(dp[i][j][k - 1])) % Mod2;
            }
            //cout << i << ' ' << j << ' ' << k << ":\n";
            /*for (ll p1 = 0; p1 <= i; p1++) {
                for (ll p2 = 0; p2 <= j; p2++) {
                    for (ll p3 = 0; p3 <= k; p3++) {
                        if (p1 + p2 + p3 + 1 == i + j + k) {
                            if (p1 + 1 == i) {
                                get<0>(dp[i][j][k]) = (get<1>(dp[p1][p2][p3]) + get<2>(dp[p1][p2][p3])) % Mod2;
                            }
                            if (p2 + 1 == j) {
                                get<1>(dp[i][j][k]) = (get<0>(dp[p1][p2][p3]) + get<2>(dp[p1][p2][p3])) % Mod2;
                            }
                            if (p3 + 1 == k) {
                                get<2>(dp[i][j][k]) = (get<0>(dp[p1][p2][p3]) + get<1>(dp[p1][p2][p3])) % Mod2;
                            }
                        }
                    }
                }
            }*/
        }
        /*up(0, a + 1, 1) {
            cout << i << ":\n";
            up2(0, b + 1, 1) {
                up3(0, c + 1, 1) {
                    cout << get<0>(dp[i][j][k]) << ',' << get<1>(dp[i][j][k]) << ',' << get<2>(dp[i][j][k]) << ' ';
                }
                cout << '\n';
            }
            cout << '\n';
        }*/
        res = (res + get<1>(dp[a][b][c])) % Mod2;
        res = (res + get<2>(dp[a][b][c])) % Mod2;
        //cout << res << '\n';
    }

    if (b) {
        dp = vector<vector<vector<tuple<ll, ll, ll>>>>(a + 1, vector<vector<tuple<ll, ll, ll>>>(b + 1, vector<tuple<ll, ll, ll>>(c + 1, tuple<ll,ll,ll>(0, 0, 0))));
        dp[0][1][0] = tuple<ll,ll,ll>(0, 1, 0);
        foreach(x, q) {
            ll i = x[0], j = x[1], k = x[2];
            if (i > 0) {
                get<0>(dp[i][j][k]) = (get<1>(dp[i - 1][j][k]) + get<2>(dp[i - 1][j][k])) % Mod2;
            }
            if (j > 0) {
                get<1>(dp[i][j][k]) = (get<0>(dp[i][j - 1][k]) + get<2>(dp[i][j - 1][k])) % Mod2;
            }
            if (k > 0) {
                get<2>(dp[i][j][k]) = (get<0>(dp[i][j][k - 1]) + get<1>(dp[i][j][k - 1])) % Mod2;
            }
        }
        res = (res + get<0>(dp[a][b][c])) % Mod2;
        res = (res + get<2>(dp[a][b][c])) % Mod2;
    }

    if (c) {
        dp = vector<vector<vector<tuple<ll, ll, ll>>>>(a + 1, vector<vector<tuple<ll, ll, ll>>>(b + 1, vector<tuple<ll, ll, ll>>(c + 1, tuple<ll,ll,ll>(0, 0, 0))));
        dp[0][0][1] = tuple<ll,ll,ll>(0, 0, 1);
        foreach(x, q) {
            ll i = x[0], j = x[1], k = x[2];
            if (i > 0) {
                get<0>(dp[i][j][k]) = (get<1>(dp[i - 1][j][k]) + get<2>(dp[i - 1][j][k])) % Mod2;
            }
            if (j > 0) {
                get<1>(dp[i][j][k]) = (get<0>(dp[i][j - 1][k]) + get<2>(dp[i][j - 1][k])) % Mod2;
            }
            if (k > 0) {
                get<2>(dp[i][j][k]) = (get<0>(dp[i][j][k - 1]) + get<1>(dp[i][j][k - 1])) % Mod2;
            }
        }
        res = (res + get<0>(dp[a][b][c])) % Mod2;
        res = (res + get<1>(dp[a][b][c])) % Mod2;
    }

    cout << res << '\n';
}
return 0;
}
