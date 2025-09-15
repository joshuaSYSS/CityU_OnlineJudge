#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vl> vl2;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<str> vs;
ll solve(ll n, vs& v, ll i, ll j, ll len) {
    ll isSame = 1;
    for (ll a = 0; a < len; a++) {
        for (ll b = 0; b < len; b++) {
            if (v[i + a][j + b] != v[i][j]) {
                isSame = 0;
                break;
            }
        }
        if (!isSame) break;
    }
    if (isSame) {
        return 1;
    }
    len >>= 1ll;
    return solve(n, v, i, j, len) + solve(n, v, i + len, j, len) +
        solve(n, v, i, j + len, len) + solve(n, v, i + len, j + len, len) + 1;
}
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
    ll n;
while (cin >> n) {
    vs v(1ll << n);
    for (ll i = 0; i < (1ll << n); i++) {
        cin >> v[i];
    }
    cout << solve(n, v, 0, 0, 1ll << n) << '\n';
}
/*
2
0011
0001
1111
0111

3 
11111101
01101011 
10000000 
10010111 
00101111 
01011101 
11110100 
11000010
*/
}
