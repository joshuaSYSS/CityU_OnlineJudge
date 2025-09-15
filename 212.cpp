#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vl> vl2;
ll fastPowMod(ll b, ll power, ll mod = 0) {
    ll result = 1;
    if (mod) {
        b %= mod;
        while (power > 0) {
            if (power & 1) result = (result * b) % mod;
            b = (b * b) % mod;
            power >>= 1ll;
        }
    }
    else {
        while (power > 0) {
            if (power & 1) result = result * b;
            b = (b * b);
            power >>= 1ll;
        }
    }
    return result;
}
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
    ll b, p, m;
while (cin >> b >> p >> m) {
    cout << fastPowMod(b, p, m) << '\n';
}
}
