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
struct State {
    int link, len;
    int first_pos;
    int minpos, maxpos;
    int next[26];
    State() {
        link = -1; len = 0; first_pos = -1;
        minpos = INT_MAX; maxpos = INT_MIN;
        for(int i = 0; i < 26;++i){
            next[i] = -1;
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
        int letter = c - 'A';
        for (; p != -1 && st[p].next[letter] == -1; p = st[p].link)
            st[p].next[letter] = cur;

        if (p == -1) {
            st[cur].link = 0;
        }
        else {
            int q = st[p].next[letter];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            }
            else {
                int clone = (int)st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;
                for (; p != -1 && st[p].next[letter] == q; p = st[p].link)
                    st[p].next[letter] = clone;
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
};
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
str s;
while (cin >> s) {
    ll n = s.length();
    SuffixAutomaton sam(n);
    for (int i = 0; i < n; i++) {
        sam.extend(s[i], i);
    }

    vector<int> order(sam.st.size());
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), 
        [&](int a, int b) {
        return sam.st[a].len > sam.st[b].len;
        });

    foreach(v, order) {
        if (sam.st[v].link != -1) {
            sam.st[sam.st[v].link].minpos = min(sam.st[sam.st[v].link].minpos, sam.st[v].minpos);
            sam.st[sam.st[v].link].maxpos = max(sam.st[sam.st[v].link].maxpos, sam.st[v].maxpos);
        }
    }

    int res = 0;
    str ans = "";
    for (int v = 1; v < sam.st.size(); v++) {
        if (sam.st[v].maxpos - sam.st[v].minpos >= sam.st[v].len) {
            if (sam.st[v].len > res) {
                res = max(res, sam.st[v].len);
                ans = s.substr(sam.st[v].maxpos - sam.st[v].len + 1, sam.st[v].len);
            }
            else if (sam.st[v].len == res &&
                s.substr(sam.st[v].maxpos - sam.st[v].len + 1, sam.st[v].len) < ans) {
                ans = s.substr(sam.st[v].maxpos - sam.st[v].len + 1, sam.st[v].len);
            }
        }
    }
    if (res == 0) {
        cout << "No LRS is found.\n";
    }
    else {
        cout << ans << '\n';
    }
}
return 0;
}
