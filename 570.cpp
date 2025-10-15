#include <bits/stdc++.h>
using namespace std;
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
    int tc; cin >> tc;
    while (tc--) {
        string s; cin >> s;
        int n = s.length();
        int res = n - 1;
        if (s[0] == 'A') {
            int front = 0;
            int back = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'A') front++;
                else break;
            }
            for (int i = n - 1; i >= 0; --i) {
                if (s[i] == 'A') back++;
                else break;
            }
            res = max(0, min(n - front, n - back - 1));
        }
        int acc = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                acc++;
            }
            else {
                if (acc) {
                    int L = i - acc;
                    int R = n - i;
                    res = max(0, min(res,
                        min(max(0, L * 2 - 2) + R, 
                            max(0, R * 2 - 1) + L)));
                }
                acc = 0;
            }
        }
        if (acc) {
            res = max(0, min(res, n - acc - 1));
        }
        for (int i = 0; i < n; ++i) {
            res += min('Z' - s[i] + 1, s[i] - 'A');
        }
        cout << res << '\n';
    }
}