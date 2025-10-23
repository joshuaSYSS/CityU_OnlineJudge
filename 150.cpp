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
template <typename T>
class SegmentTree {
    vector<T> tree, lazy;
    vector<T>* arr;
    vector<bool> ifLazy;
    int n, root, n4, end;

    T segtreeop(T a, T b) {
        return max(a, b);
    }

    void maintain(int cl, int cr, int p) {
        int cm = cl + (cr - cl) / 2;
        if (cl != cr && ifLazy[p]) {
            lazy[p * 2] = lazy[p], ifLazy[p * 2] = 1;
            lazy[p * 2 + 1] = lazy[p], ifLazy[p * 2 + 1] = 1;
            tree[p * 2] = lazy[p] * (cm - cl + 1);
            tree[p * 2 + 1] = lazy[p] * (cr - cm);
            lazy[p] = 0;
            ifLazy[p] = 0;
        }
    }

    T range_sum(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) return tree[p];
        int m = cl + (cr - cl) / 2;
        T sum = 0;
        maintain(cl, cr, p);
        if (l <= m) sum = segtreeop(sum, range_sum(l, r, cl, m, p * 2));
        if (r > m) sum = segtreeop(sum, range_sum(l, r, m + 1, cr, p * 2 + 1));
        return sum;
    }

    void range_set(int l, int r, T val, int cl, int cr, int p) {
        if (l <= cl && cr <= r) {
            lazy[p] = val;
            ifLazy[p] = 1;
            tree[p] = (cr - cl + 1) * val;
            return;
        }
        int m = cl + (cr - cl) / 2;
        maintain(cl, cr, p);
        if (l <= m) range_set(l, r, val, cl, m, p * 2);
        if (r > m) range_set(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p] = segtreeop(tree[p * 2], tree[p * 2 + 1]);
    }

    void build(int s, int t, int p) {
        if (s == t) {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p] = segtreeop(tree[p * 2], tree[p * 2 + 1]);
    }

public:
    SegmentTree() {}
    explicit SegmentTree<T>(vector<T> v) {
        n = v.size();
        n4 = n * 4;
        tree = vector<T>(n4, 0);
        lazy = vector<T>(n4, 0);
        ifLazy = vector<bool>(n4, 0);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr;
    }

    T query(int l, int r) { return range_sum(l, r, 0, end, root); }

    void update(int l, int r, T val) { range_set(l, r, val, 0, end, root); }

};
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
tcin{
    ll n; cin >> n;
vl v(n);
up(0, n, 1) cin >> v[i];
vl arr(n + 1, 0);
SegmentTree<ll> sg1(arr); //as min
SegmentTree<ll> sg2(arr); //as max
ll res = 1;
sg2.update(v[0], v[0], 1);
up(1, n, 1) {
    ll x = sg1.query(1, v[i]);
    ll y = sg2.query(v[i], n);
    if (x) {
        sg2.update(v[i], v[i], x + 1);
        res = max(res, x + 1);
    }
    else {
        sg2.update(v[i], v[i], 1);
    }
    if (y) {
        sg1.update(v[i], v[i], y + 1);
        res = max(res, y + 1);
    }
}
cout << res << '\n';
}
return 0;
}
