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

int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll n;
while (cin >> n) {
    set<str> st;
    up(0, n, 1) {
        str s; cin >> s;
        st.insert(s);
    }
    ll m; cin >> m;
    vs v(m);
    unordered_set<str> st2;
    map<str, ll> mp;
    queue<ll> q;
    pqls lazy;
    up(0, m, 1) {
        cin >> v[i];
        if (st.count(v[i])) {
            st2.insert(v[i]);
            mp[v[i]] = -1;
        }
    }
    foreach(x, st2) {
        q.push(-1);
    }
    cout << st2.size() << '\n';
    ll res = INT_MAX;
    up(0, m, 1) {
        if (st2.count(v[i])) {
            if (q.front() == mp[v[i]]) {
                q.pop();
            }
            else {
                lazy.push(mp[v[i]]);
            }
            mp[v[i]] = i;
            q.push(i);
            while (!lazy.empty() && q.front() == lazy.top()) q.pop(), lazy.pop();
            if (q.front() != -1) {
                res = min(res, i - q.front() + 1);
            }
        }
    }
    if (res == INT_MAX) res = 0;
    cout << res << '\n';
}

/*
3
analyze
initiates
split
14
when
a
nuclear
reaction
initiates
the
old
uranium
nucleus
will
split
into
two
nuclei
3
analyze
initiates
split
6
i
do
not
love
university
english
*/
return 0;
}
