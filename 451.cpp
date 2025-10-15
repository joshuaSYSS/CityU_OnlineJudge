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

ll gcd(ll a, ll b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}
ll lcm(ll a, ll b) {
    return abs(a * b) / gcd(a, b);
}
const int tab64[64] = {
    63,  0, 58,  1, 59, 47, 53,  2,
    60, 39, 48, 27, 54, 33, 42,  3,
    61, 51, 37, 40, 49, 18, 28, 20,
    55, 30, 34, 11, 43, 14, 22,  4,
    62, 57, 46, 52, 38, 26, 32, 41,
    50, 36, 17, 19, 29, 10, 13, 21,
    56, 45, 25, 31, 35, 16,  9, 12,
    44, 24, 15,  8, 23,  7,  6,  5 };

ll fast_log2(uint64_t value)
{
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    value |= value >> 32;
    return tab64[((uint64_t)((value - (value >> 1)) * 0x07EDD5E59A4E28C2)) >> 58];
}

struct stTable {
    ll n;
    vl2 v;
    ll op(ll a, ll b) {
        return max(a, b);
    }
    stTable(vl& arr) {
        n = arr.size();
        v = vl2(n, vl(fast_log2(n) + 1));
        up(0, n, 1) {
            v[i][0] = arr[i];
        }
        up(1, fast_log2(n) + 1, 1) {
            up2(0, n, 1) {
                if (j + (1ll << i) - 1 < n) {
                    v[j][i] = op(v[j][i - 1], v[j + (1ll << (i - 1))][i - 1]);
                }
            }
        }
    }

    /// <summary>
    /// Return the range query [l, r]
    /// Note that l and r are 0-indexed.
    /// </summary>
    /// <param name="l">The left boundary</param>
    /// <param name="r">The right boundary</param>
    /// <returns></returns>
    ll query(ll l, ll r) {
        if (l > r) return 0;
        ll len = r - l + 1;
        ll a = fast_log2(len);
        return op(v[l][a], v[r - (1ll << a) + 1][a]);
    }
};
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll n;
while (cin >> n) {
    if (n == 0) break;
    ll q; cin >> q;
    vl v(n);
    up(0, n, 1) {
        cin >> v[i];
    }
    ll L = 0, cnt = 0;
    vpll state(n);
    vl a(n);
    up(0, n, 1) {
        if (v[i] != v[L]) {
            up2(L, i, 1) {
                state[j] = { L, cnt };
                a[j] = cnt;
            }
            cnt = 1;
            L = i;
        }
        else {
            cnt++;
        }
    }
    up2(L, n, 1) {
        state[j] = { L, cnt };
        a[j] = cnt;
    }
    stTable st(a);
    while (q--) {
        ll L, R; cin >> L >> R;
        L--, R--;
        if (v[L] == v[R]) {
            cout << R - L + 1 << '\n';
        }
        else {
            cout << max(state[L].first + state[L].second - L,
                max(R - state[R].first + 1,
                    st.query(state[L].first + state[L].second, state[R].first - 1))) << '\n';
        }
    }
}
return 0;
}
