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
int clz32(unsigned int x) {
    if (x == 0) return 32;
    int n = 0;
    if ((x >> 16) == 0) { n += 16; x <<= 16; }
    if ((x >> 24) == 0) { n += 8;  x <<= 8; }
    if ((x >> 28) == 0) { n += 4;  x <<= 4; }
    if ((x >> 30) == 0) { n += 2;  x <<= 2; }
    if ((x >> 31) == 0) { n += 1; }
    return n;
}
struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    int findKth(int k) {
        int idx = 0, mask = 1 << (31 - clz32(n));
        for (; mask; mask >>= 1) {
            int next = idx + mask;
            if (next <= n && bit[next] < k) {
                k -= bit[next];
                idx = next;
            }
        }
        return idx + 1;
    }
};
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
int n, m; cin >> n >> m;
Fenwick f(n);
for (int i = 1; i <= n; i++) f.update(i, 1);
vector<int> order;
int alive = n;
int pos = 0;

while (alive > 0) {
    pos = (pos + m - 1) % alive;
    if (pos == 0) pos = alive;
    int person = f.findKth(pos);
    order.push_back(person);
    f.update(person, -1);
    alive--;
}

for (int i = 0; i < order.size(); i++) {
    cout << (order[i] + 1 > n?1:order[i] + 1) << " \n"[i == order.size() - 1];
}
return 0;
}
