/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 321653
 * Submitted at:  2025-09-15 01:58:29
 *
 * User ID:       2811
 * Username:      59270829
 * Problem ID:    98
 * Problem Name:  Trees
 */

#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, i, res, p1, p2, tc = 1;
constexpr int MAX_N = 502;
int parent[MAX_N];
int size_[MAX_N];
int isTree[MAX_N];
void make_set(int v) {
    parent[v] = v;
    size_[v] = 1;
    isTree[v] = 1;
}
int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
int union_sets(int x, int y) {
    if (size_[x] < size_[y]) swap(x, y);
    parent[y] = x;
    size_[x] += size_[y];
    return x;
}
int main(void){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    for (;; ++tc) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        res = n;
        for (i = 1; i <= n; ++i) make_set(i);
        for (i = 0; i < m; ++i) {
            cin >> a >> b;
            p1 = find_set(a); p2 = find_set(b);
            if (p1 == p2) {
                if (isTree[p1]) { --res; isTree[p1] = 0; }
            } else {
                int t1 = isTree[p1], t2 = isTree[p2];
                int newRoot = union_sets(p1, p2);
                int newIsTree = t1 & t2;
                isTree[newRoot] = newIsTree;
                res -= (t1 + t2 - newIsTree);
            }
        }
        cout << "Case " << tc << ": ";
        if (res == 1) { cout << "There is one tree.\n"; }
        else if (res == 0) { cout << "No trees.\n"; }
        else { cout << "A forest of " << res << " trees.\n"; }
    }
}
