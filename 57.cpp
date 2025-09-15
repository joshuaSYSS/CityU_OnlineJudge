#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vl> vl2;


vector<ll> prefix_function(string& s) {
    ll n = (ll)s.length();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++) {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<ll> kmp(string& text, string& pattern) {
    if (pattern.empty()) return {};
    string cur = pattern + "#" + text;
    ll sz1 = (ll)text.size(), sz2 = (ll)pattern.size();
    vector<ll> lps = prefix_function(cur);
    vector<ll> starts;
    for (ll i = sz2 + 1; i < (ll)cur.size(); i++) {
        if (lps[i] == sz2) {
            ll start = i - 2 * sz2;
            if (0 <= start && start + sz2 <= sz1) starts.push_back(start);
        }
    }
    return starts;
}

bool better_tiebreak(vector<ll>& cand, vector<ll>& best) {
    size_t L = min(cand.size(), best.size());
    for (size_t k = 0; k < L; k++) {
        if (cand[k] != best[k]) return cand[k] < best[k];
    }
    if (cand.size() != best.size()) return cand.size() > best.size();
    return false;
}

ll main(void){
    std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);

    ll testcase; cin >> testcase;
    for (ll tc = 1; tc <= testcase; tc++) {
        cout << "Inscription #" << tc << ":\n";

        str s; cin >> s;
        ll n = (ll)s.length();

        ll c; cin >> c;
        vector<pair<str, ll>> v(c);
        for (ll i = 0; i < c; i++) cin >> v[i].first >> v[i].second;

        vector<vector<pair<ll,ll>>> nxt(n + 1);
        for (ll i = 0; i < c; i++) {
            str& w = v[i].first;
            ll val = v[i].second;
            vector<ll> occ = kmp(s, w);
            ll len = (ll)w.size();
            for (ll st : occ) {
                ll en = st + len;
                nxt[st].push_back({en, (ll)val});
            }
        }

        vl dp(n + 1, -1);
        vector<vector<ll>> spaces(n + 1); 
        dp[0] = 0;

        for (ll pos = 0; pos <= n; pos++) {
            if (dp[pos] == -1) continue;
            for (auto &e : nxt[pos]) {
                ll en = e.first, val = e.second;
                ll cand = dp[pos] + val;
                if (cand > dp[en]) {
                    dp[en] = cand;
                    spaces[en] = spaces[pos];
                    if (en < n) spaces[en].push_back(en);
                } else if (cand == dp[en]) {
                    auto candSpaces = spaces[pos];
                    if (en < n) candSpaces.push_back(en);
                    if (better_tiebreak(candSpaces, spaces[en])) {
                        spaces[en] = std::move(candSpaces);
                    }
                }
            }
        }

        cout << dp[n] << '\n';

        ll last = 0;
        for (ll i = 0; i < (ll)spaces[n].size(); i++) {
            ll cut = spaces[n][i];
            cout << s.substr(last, cut - last) << ' ';
            last = cut;
        }
        cout << s.substr(last) << "\n\n";
    }

    return 0;
}