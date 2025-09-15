#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
struct Vector2 {
    ld x, y;
    bool operator==(Vector2& b) {
        return fabsl(x - b.x) <= 1e-7 && fabsl(y - b.y) <= 1e-7;
    }
};
int orientation(Vector2 a, Vector2 b, Vector2 c) {
    double v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(Vector2 a, Vector2 b, Vector2 c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(Vector2 a, Vector2 b, Vector2 c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<Vector2>& a, bool include_collinear = false) {
    Vector2 p0 = *min_element(a.begin(), a.end(), [](Vector2 a, Vector2 b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
        });
    sort(a.begin(), a.end(), [&p0](const Vector2& a, const Vector2& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y)
            < (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);
        return o < 0;
        });
    if (include_collinear) {
        int i = (int)a.size() - 1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin() + i + 1, a.end());
    }

    vector<Vector2> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size() - 2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
}
int main(void){
int tc; cin >> tc;
while (tc--) {
    int n; cin >> n;
    vector<Vector2> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    convex_hull(v);
    n = v.size();
    cout << n << '\n';
    int idx = 0;
    ld minX = INT_MAX, minY = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (v[i].x < minX) {
            minX = v[i].x;
            minY = v[i].y;
            idx = i;
        }
        else if (fabsl(v[i].x - minX) <= 1e-7) {
            if (v[i].y < minY) {
                minX = v[i].x;
                minY = v[i].y;
                idx = i;
            }
        }
    }
    cout << fixed << setprecision(0);
    for (int i = 0; i < n; i++) {
        cout << v[(idx - i + n) % n].x << ' ' << v[(idx - i + n) % n].y << '\n';
    }
}
/*
1
5
1 1
1 -1
0 0
-1 -1
-1 1
*/
}
