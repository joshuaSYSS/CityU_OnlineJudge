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
    ld a;
const ld PI = acos(0) * 2;
while (cin >> a) {
    ld sq = a * a;
    ld b = PI * a * a / 4.0;
    ld c = b + b - sq;
    ld y = a / 2.0;
    ld x = sqrtl(a * a - y * y);
    ld alpha = 60.0 / 360.0 * 2 * PI;
    ld section = PI * a * a * alpha / (2 * PI);
    ld area = section * 2 - (1.0 / 2.0) * sin(alpha) * a * a;
    //cout << area << ' ' << 0.003 + 0.005 / 2.0 + 0.002 / 4 << '\n';
    ld black = (area - c) * 4;
    ld d = sq - b - black / 2.0;
    ld e = c - d - d;

    //x^2 + y^2 = a^2
    //when y = a / 2
    //x^2 = a^2 - (a/2)^2
    //tan(alpha) = y / x
    //area = section * 2 - (1/2)sin(alpha)*a*a
    //(area - c) * 4 = black
    cout << fixed << setprecision(3);
    cout << e << ' ' <<
        d * 4 << ' ' <<
        black << '\n';
}
    return 0;
}
