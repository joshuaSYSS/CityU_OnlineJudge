#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
int main(void){
ll n; cin >> n;
vl v(n);
for (ll i = 0; i < n; i++) {
    cin >> v[i];
}
ll q; cin >> q;
while (q--) {
    ll op; cin >> op;
    if (op == 1) {
        ll i, val; cin >> i >> val;
        --i;
        v.insert(v.begin() + i, val);
    }
    else if (op == 2) {
        ll i; cin >> i;
        --i;
        v.erase(v.begin() + i);
    }
    else if (op == 3) {
        ll i, j; cin >> i >> j;
        --i;
        reverse(v.begin() + i, v.begin() + j);
    }
    else {
        ll i; cin >> i;
        --i;
        cout << v[i] << '\n';
    }
}
}
