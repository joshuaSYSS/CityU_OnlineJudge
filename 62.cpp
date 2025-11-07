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
struct Pizza {
    str name;
    ll E, S;
    bool operator<(const Pizza& o) const {
        return name < o.name;
    }
};

ll compute(const vector<Pizza>& order, ll D) {
    ll P = order.size();
    ll total = 0;
    for (ll d = 1; d <= D; d++) {
        vector<ld> weights;
        foreach(p, order) {
            ll eaten = 1LL * d * p.E;
            ll mod = eaten % p.S;
            ll rem = (mod == 0 ? 0 : p.S - mod);
            if (rem > 0) {
                weights.push_back((ld)rem / (ld)p.S);
            }
        }
        up(0, weights.size() - 1, 1) {
            if (weights[i] > weights[i + 1]) ++total;
        }
    }
    return total;
}
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll n; cin >> n;
up(1, n + 1, 1) {
    ll P, D; cin >> P >> D;
    vector<Pizza> pizzas(P);
    up(0, P, 1) {
        cin >> pizzas[i].name >> pizzas[i].E >> pizzas[i].S;
    }
    vector<Pizza> perm = pizzas;
    sort(all(perm));
    ll min_viol = -1;
    vector<Pizza> best;
    do {
        ll viol = compute(perm, D);
        if (min_viol == -1 || viol < min_viol) {
            min_viol = viol;
            best = perm;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << "Leftover Pizza Stacking Order for Semester " << i << ":\n";
    foreach(p, best) {
        cout << p.name << '\n';
    }
    cout << '\n';
}
return 0;
}
