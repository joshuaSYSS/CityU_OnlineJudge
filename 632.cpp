/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 321644
 * Submitted at:  2025-09-15 01:03:08
 *
 * User ID:       2811
 * Username:      59270829
 * Problem ID:    632
 * Problem Name:  Stranger Investigation
 */

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
int tc; cin >> tc;
vector<int> v(1000);
while (tc--) {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.begin() + n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (k - v[i] < 0) {
            break;
        }
        k -= v[i];
        res++;
    }
    cout << res << '\n';
}
}
