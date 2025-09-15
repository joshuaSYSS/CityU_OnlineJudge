#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vl> vl2;
typedef pair<ll, ll> pll;
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
   ll tc; cin >> tc;
while (tc--) {
    ll n, k; cin >> n >> k;
    queue<pll> q;
    for (ll i = 0; i < n; i++) {
        ll u; cin >> u;
        q.push({ u, i + 1 });
    }
    while (!q.empty()) {
        queue<pll> a;
        pll res = { LLONG_MIN, -1 };
        pll b;
        for (ll i = 0; i < k && !q.empty(); i++) {
            a.push(q.front());
            if (q.front().first > res.first) {
                res = { q.front().first, i };
                b = q.front();
            }
            q.pop();
        }
        cout << b.second;
        while (!a.empty()) {
            if (a.front() != b) {
                q.push({a.front().first - 1, a.front().second});
            }
            a.pop();
        }
        if(q.empty()){
            cout << '\n';
        }
        else{
            cout << ' ';
        }
    }
}
/*
1
5 3
5 3 2 4 10

{5[1], 3[2], 2[3]}
4 10 2 1

{4[4], 10[5], 2[2]}
1 3 1

{1[3], 3[4], 1[2]}
0 0

{1[2], 1[3]}
*/
}
