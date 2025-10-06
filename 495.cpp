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
int charIndex(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}
struct State {
    int link, len;
    int first_pos;
    int minpos, maxpos;
    int next[52];
    State() {
        link = -1; len = 0; first_pos = -1;
        minpos = INT_MAX; maxpos = INT_MIN;
        for (char c = 'a'; c <= 'z'; c++) {
            next[charIndex(c)] = -1;
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            next[charIndex(c)] = -1;
        }
    }
};

struct SuffixAutomaton {
    vector<State> st;
    int last;

    SuffixAutomaton(int n) {
        st.reserve(2 * n);
        st.push_back(State());
        last = 0;
    }

    void extend(char c, int pos) {
        int cur = (int)st.size();
        st.push_back(State());
        st[cur].len = st[last].len + 1;
        st[cur].first_pos = pos;
        st[cur].minpos = st[cur].maxpos = pos;

        int p = last;
        for (; p != -1 && st[p].next[charIndex(c)] == -1; p = st[p].link)
            st[p].next[charIndex(c)] = cur;

        if (p == -1) {
            st[cur].link = 0;
        }
        else {
            int q = st[p].next[charIndex(c)];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            }
            else {
                int clone = (int)st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                for (; p != -1 && st[p].next[charIndex(c)] == q; p = st[p].link)
                    st[p].next[charIndex(c)] = clone;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
};
int main(void){
    std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
    tcin{
    str s; cin >> s;
ll n = s.length();
SuffixAutomaton sam(n);
for (int i = 0; i < n; i++) {
    sam.extend(s[i], i);
}
ll q; cin >> q;
while (q--) {
    str p; cin >> p;
    ll cur = 0;
    for (ll i = 0; i < p.length(); i++) {
        if (sam.st[cur].next[charIndex(p[i])] == -1) {
            cur = -1;
            break;
        }
        cur = sam.st[cur].next[charIndex(p[i])];
    }
    if (cur == -1) {
        cout << 'n' << '\n';
    }
    else {
        cout << 'y' << '\n';
    }
}
}
    return 0;
}
