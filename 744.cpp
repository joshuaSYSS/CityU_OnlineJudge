#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vl> vl2;
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
  ll tc; cin >> tc;
while (tc--) {
    ll n; cin >> n;
    vl a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    reverse(a.begin(), a.end());
    ll m; cin >> m;
    while (m--) {
        ll idx = 0;
        stack<ll> s;
        ll okay = 1;
        for (ll i = 0; i < n; i++) {
            ll u; cin >> u;
            if (!s.empty() && s.top() == u) {
                s.pop();
            }
            else {
                ll ok = 0;
                for (ll j = idx; j < n; j++) {
                    if (a[j] == u) {
                        ok = 1;
                        for (ll k = idx; k < j; k++) {
                            s.push(a[k]);
                        }
                        idx = j + 1;
                        break;
                    }
                }
                if (!ok) {
                    okay = 0;
                }
            }
        }
        if (okay) {
            cout << "Aye\n";
        }
        else {
            cout << "Impossible\n";
        }
    }
}
/*
1
5
1 2 3 4 5
3
1 2 3 4 5
1 5 4 2 3
3 2 1 4 5
*/
}
