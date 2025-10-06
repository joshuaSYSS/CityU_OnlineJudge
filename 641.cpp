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
struct State {
    int link, len;
    int first_pos;
    int minpos, maxpos;
    int next[26];
    bool accept;
    bool reject;
    State() {
        link = -1; len = 0; first_pos = -1;
        minpos = INT_MAX; maxpos = INT_MIN;
        accept = false;
        reject = false;
        for (int i = 0; i < 26; ++i) {
            next[i] = 6;
        }
    }
};
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
vector<State> st(7);
st[0].next[0] = 1;
for (char c = 'B'; c <= 'F'; c++) {
    st[0].next[c - 'A'] = 2;
}
st[1].next[0] = 1;
st[1].next[5] = 3;
st[2].next[0] = 1;
st[3].next[5] = 3;
st[3].next[2] = 4;
for (char c = 'A'; c <= 'F'; c++) {
    st[4].next[c - 'A'] = 5;
}
st[4].next[4] = 4;
st[4].accept = true;
st[5].accept = true;
st[6].reject = true;

tcin{
    str s; cin >> s;
int cur = 0;
for (ll i = 0; i < s.length(); i++) {
    cur = st[cur].next[s[i] - 'A'];
}
if (st[cur].accept) {
    cout << "Infected!\n";
}
else {
    cout << "Good\n";
}
}
return 0;
}
