#include <bits/stdc++.h>
using namespace std;
int tc, n, m, a, b, i = 1;
constexpr int MAX_N = 30002;
int parent[MAX_N], size_[MAX_N];
int res = 1;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
  cin >> tc;
for (; tc; tc--) {
    cin >> n >> m;
    res = 1;
    for (i = 1; i <= n; ++i) {
        parent[i] = i;
        size_[i] = 1;
    }
    for (i = 0; i < m; ++i) {
        cin >> a >> b;
        a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size_[a] < size_[b])
            swap(a, b);
        parent[b] = a;
        size_[a] += size_[b];
        res = max(res, size_[a]);
    }
    }
    cout << res << '\n';
}
}
