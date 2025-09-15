#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll tc; cin >> tc;
while (tc--) {
    str s; cin >> s;
    ll n = s.length();
    ll res = n - 1;
    if (s[0] == 'A') {
        ll front = 0;
        ll back = 0;
        for (ll i = 0; i < n; i++) {
            if (s[i] == 'A') front++;
            else break;
        }
        for (ll i = n - 1; i >= 0; i--) {
            if (s[i] == 'A') back++;
            else break;
        }
        res = max(0ll, min(n - front, n - back - 1));
    }
    ll acc = 0;

    for (ll i = 0; i < n; i++) {
        if (s[i] == 'A') {
            acc++;
        }
        else {
            if (acc) {
                ll L = i - acc;
                ll R = n - i;
                res = max(0ll, min(res,
                    min(max(0ll, L * 2 - 2) + R, 
                        max(0ll, R * 2 - 1) + L)));
            }
            acc = 0;
        }
    }
    if (acc) {
        res = max(0ll, min(res, n - acc - 1));
    }
    for (ll i = 0; i < n; i++) {
        res += min('Z' - s[i] + 1, s[i] - 'A');
    }
    cout << res << '\n';
}
/*
1
ZZAAAAZAAAZZ

1
ZZZAAAAAAAAZZ

1
ZZZZAAAAAAA

1
AAZZZ

1
AAAAZZA

1
A

1
B

1
AAA
*/
}
