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
str multiply(const str& a, const str& b) {
    ll n = a.size(), m = b.size();
    vl res(n + m, 0);
    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = m - 1; j >= 0; j--) {
            ll mul = (a[i] - '0') * (b[j] - '0');
            ll sum = res[i + j + 1] + mul;
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    str s;
    ll i = 0;
    while (i < res.size() && res[i] == 0) i++;
    for (; i < res.size(); i++) s.push_back(res[i] + '0');
    return s.empty() ? "0" : s;
}
str fastpow(str base, ll exp) {
    str result = "1";
    while (exp > 0) {
        if (exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
str R;
    ll n;
    while (cin >> R >> n) {
        ll dec = 0;
        str digits;
        foreach(c, R) {
            if (c == '.') continue;
            digits.push_back(c);
        }
        auto pos = R.find('.');
        if (pos != string::npos) {
            dec = (ll)R.size() - 1 - pos;
        }

        ll idx = 0;
        while (idx < digits.size() && digits[idx] == '0') idx++;
        if (idx == digits.size()) {
            cout << 0 << '\n';
            continue;
        }
        digits = digits.substr(idx);

        str res = fastpow(digits, n);
        ll totalDec = dec * n;

        if (totalDec > 0) {
            if (res.size() <= totalDec) {
                res = str(totalDec - res.size() + 1, '0') + res;
            }
            res.insert(res.end() - totalDec, '.');
        }

        while (res.size() > 1 && res[0] == '0' && res[1] != '.') res.erase(res.begin());

        if (res.size() > 1 && res[0] == '0' && res[1] == '.') {
            res.erase(res.begin());
        }

        if (res.find('.') != string::npos) {
            while (!res.empty() && res.back() == '0') res.pop_back();
            if (!res.empty() && res.back() == '.') res.pop_back();
        }

        cout << res << '\n';
    }
return 0;
}
