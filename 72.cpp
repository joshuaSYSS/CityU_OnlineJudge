/*
INCORRECT.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double;
using ull = unsigned long long; using str = string;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef set<ll> sl;
typedef vector<vector<ll>> vl2;
typedef vector<str> vs;
typedef map<ll, ll> mll;
typedef map<str, ll> msl;
typedef queue<ll> ql;
typedef priority_queue<ll> pqlg;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqls;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef queue<pair<ll, ll>> qpll;

#define up(initial, n, step) for (ll i = (ll)(initial);i < (ll)(n);i += (ll)(step))
#define up2(initial, n, step) for (ll j = (ll)(initial);j < (ll)(n);j += (ll)(step))
#define up3(initial, n, step) for (ll k = (ll)(initial);k < (ll)(n);k += (ll)(step))
#define down(initial, n, step) for (ll i = (ll)(initial) - 1;i >= (ll)(n);i -= (ll)(step))
#define down2(initial, n, step) for (ll j = (ll)(initial) - 1;j >= (ll)(n);j -= (ll)(step))
#define down3(initial, n, step) for (ll k = (ll)(initial) - 1;k >= (ll)(n);k -= (ll)(step))

#define all(x) (x).begin(), (x).end()
#define YES(a) ((a)?"YES":"NO")
#define Yes(a) ((a)?"Yes":"No")
#define yes(a) ((a)?"yes":"no")
#define rev(s) reverse((s).begin(), (s).end());
#define toStr(s) to_string((s))
#define throwErr(s) throw invalid_argument(s)
#define nextPerm next_permutation
#define foreach(a, v) for(auto& a : v)
#define tcin \
  ll testcase; cin >> testcase;\
  while (testcase--)

#define LL_MAX 9223372036854775807
#define LL_MIN (LL_MAX + 1)
const ld PHI = (1 + sqrt(5)) / 2;
const ll Mod = 998244353ll;
const ll Mod2 = 1000000007ll; //10^9 + 7
const ld EPS = 1e-5;
const ld PI = 2 * acos(0.0);
bool isClose(ld a, ld b, ld eps = EPS) {
    return fabsl(a - b) <= eps;
}

struct circle {
    ld x, y, r;
};
struct pt {
    ld x, y;
};
pair<pt, pt> solve(circle ca, circle cb) {
    ld a = -2 * ca.x;
    ld b = -2 * ca.y;
    ld c = ca.r * ca.r - ca.y * ca.y - ca.x * ca.x;

    ld p = -2 * ca.x + 2 * cb.x;
    ld q = -2 * ca.y + 2 * cb.y;
    ld s = ca.r * ca.r - cb.r * cb.r - ca.x * ca.x + cb.x * cb.x - ca.y * ca.y + cb.y * cb.y;

    pair<pt, pt> ppt;
    if (q == 0) {
        //x = s / p
        ld A = 1;
        ld B = b;
        ld C = (s / p) * (s / p) + a * (s / p) - c;

        ld D = B * B - 4 * A * C;
        if (D < 0) {
            ppt = { {INT_MAX, INT_MAX}, {INT_MAX, INT_MAX} };
        }
        else {
            ld y1 = (-B + sqrtl(D)) / (2 * A);
            ld y2 = (-B - sqrtl(D)) / (2 * A);
            ppt = { {s / p, y1}, {s / p, y2}};
        }
    }
    else {
        ld A = (p / q) * (p / q) + 1;
        ld B = a - 2 * (p / q) * (s / q) - (b * p / q);
        ld C = (s / q) * (s / q) + b * s / q - c;

        ld D = B * B - 4 * A * C;
        if (D < 0) {
            ppt = { {INT_MAX, INT_MAX}, {INT_MAX, INT_MAX} };
        }
        else {
            ld x1 = (-B + sqrtl(D)) / (2 * A);
            ld y1 = (-p / q) * x1 + s / q;
            ld x2 = (-B - sqrtl(D)) / (2 * A);
            ld y2 = (-p / q) * x2 + s / q;
            ppt = { {x1, y1}, {x2, y2} };
        }
    }
    return ppt;
}
ld dist(pt a, pt b) {
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll n; 
while (cin >> n) {
    if (n == 0) break;
    vector<circle> v(n);
    up(0, n, 1) {
        cin >> v[i].x >> v[i].y >> v[i].r;
    }
    vector<vector<ld>> dp(n - 1, vector<ld>(2, INT_MAX));
    pair<pt, pt> ppt = solve(v[0], v[1]);
    //cout << ppt.first.x << ' ' << ppt.first.y << '\n';
    dp[0][0] = dist({ v[0].x, v[0].y }, ppt.first);
    dp[0][1] = dist({ v[0].x, v[0].y }, ppt.second);
    up(1, n - 1, 1) {
        ppt = solve(v[i], v[i + 1]);

        //Consider first point

        //Start center
        if (isClose(ppt.first.x, v[0].x)) {
            //Vertical line
            //x = ppt.first.x
            ll ok = 1;
            up3(0, i, 1) {
                pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                if (isClose(ppt2.first.x, ppt2.second.x)) {
                    //Vertical line
                    //x = ppt2.first.x
                    if (isClose(ppt.first.x, ppt2.first.x)) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                    ld c = ppt2.first.y - m * ppt2.first.x;
                    ld y = m * ppt.first.x + c;
                    if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                        y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                dp[i][0] = min(dp[i][0], dist(ppt.first, { v[0].x, v[0].y }));
            }
        }
        else {
            ld m = (ppt.first.y - v[0].y) / (ppt.first.x - v[0].x);
            ld c = ppt.first.y - m * ppt.first.x;
            ll ok = 1;
            up3(0, i, 1) {
                pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                if (isClose(ppt2.first.x, ppt2.second.x)) {
                    //Vertical line
                    //x = ppt2.first.x
                    ld y = m * ppt2.first.x + c;
                    if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                        y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                    ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                    //y = mx + c
                    //y = m2x + c2
                    //mx + c = m2x + c2
                    //(m - m2)x = c2 - c
                    if (isClose(m, m2)) {
                        continue;
                    }
                    else {
                        ld x = (c2 - c) / (m - m2);
                        if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                            x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                dp[i][0] = min(dp[i][0], dist(ppt.first, { v[0].x, v[0].y }));
            }
        }

        //Start with other points
        up2(0, i, 1) {
            pair<pt, pt> ppt3 = solve(v[j], v[j + 1]);
            //Consider first point
            if (isClose(ppt.first.x, ppt3.first.x)) {
                //Vertical line
                //x = ppt.first.x
                ll ok = 1;
                up3(j, i, 1) {
                    pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                    if (isClose(ppt2.first.x, ppt2.second.x)) {
                        //Vertical line
                        //x = ppt2.first.x
                        if (isClose(ppt.first.x, ppt2.first.x)) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                    else {
                        ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                        ld c = ppt2.first.y - m * ppt2.first.x;
                        ld y = m * ppt.first.x + c;
                        if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                            y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) {
                    dp[i][0] = min(dp[i][0], dp[j][0] + dist(ppt.first, ppt3.first));
                }
            }
            else {
                ld m = (ppt.first.y - ppt3.first.y) / (ppt.first.x - ppt3.first.x);
                ld c = ppt.first.y - m * ppt.first.x;
                ll ok = 1;
                up3(j, i, 1) {
                    pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                    if (isClose(ppt2.first.x, ppt2.second.x)) {
                        //Vertical line
                        //x = ppt2.first.x
                        ld y = m * ppt2.first.x + c;
                        if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                            y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                    else {
                        ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                        ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                        //y = mx + c
                        //y = m2x + c2
                        //mx + c = m2x + c2
                        //(m - m2)x = c2 - c
                        if (isClose(m, m2)) {
                            continue;
                        }
                        else {
                            ld x = (c2 - c) / (m - m2);
                            if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                                x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                                continue;
                            }
                            else {
                                ok = 0;
                                break;
                            }
                        }
                    }
                }
                if (ok) {
                    dp[i][0] = min(dp[i][0], dp[j][0] + dist(ppt.first, ppt3.first));
                }
            }

            //Consider second point
            if (isClose(ppt.first.x, ppt3.second.x)) {
                //Vertical line
                //x = ppt.first.x
                ll ok = 1;
                up3(j, i, 1) {
                    pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                    if (isClose(ppt2.first.x, ppt2.second.x)) {
                        //Vertical line
                        //x = ppt2.first.x
                        if (isClose(ppt.first.x, ppt2.first.x)) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                    else {
                        ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                        ld c = ppt2.first.y - m * ppt2.first.x;
                        ld y = m * ppt.first.x + c;
                        if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                            y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) {
                    dp[i][0] = min(dp[i][0], dp[j][1] + dist(ppt.first, ppt3.second));
                }
            }
            else {
                ld m = (ppt.first.y - ppt3.second.y) / (ppt.first.x - ppt3.second.x);
                ld c = ppt.first.y - m * ppt.first.x;
                ll ok = 1;
                up3(j, i, 1) {
                    pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                    if (isClose(ppt2.first.x, ppt2.second.x)) {
                        //Vertical line
                        //x = ppt2.first.x
                        ld y = m * ppt2.first.x + c;
                        if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                            y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                    else {
                        ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                        ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                        //y = mx + c
                        //y = m2x + c2
                        //mx + c = m2x + c2
                        //(m - m2)x = c2 - c
                        if (isClose(m, m2)) {
                            continue;
                        }
                        else {
                            ld x = (c2 - c) / (m - m2);
                            if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                                x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                                continue;
                            }
                            else {
                                ok = 0;
                                break;
                            }
                        }
                    }
                }
                if (ok) {
                    dp[i][0] = min(dp[i][0], dp[j][1] + dist(ppt.first, ppt3.second));
                }
            }
        }

        //Consider second point
        swap(ppt.first, ppt.second);

        //Start center
        if (isClose(ppt.first.x, v[0].x)) {
            //Vertical line
            //x = ppt.first.x
            ll ok = 1;
            up3(0, i, 1) {
                pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                if (isClose(ppt2.first.x, ppt2.second.x)) {
                    //Vertical line
                    //x = ppt2.first.x
                    if (isClose(ppt.first.x, ppt2.first.x)) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                    ld c = ppt2.first.y - m * ppt2.first.x;
                    ld y = m * ppt.first.x + c;
                    if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                        y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                dp[i][1] = min(dp[i][1], dist(ppt.first, { v[0].x, v[0].y }));
            }
        }
        else {
            ld m = (ppt.first.y - v[0].y) / (ppt.first.x - v[0].x);
            ld c = ppt.first.y - m * ppt.first.x;
            ll ok = 1;
            up3(0, i, 1) {
                pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                if (isClose(ppt2.first.x, ppt2.second.x)) {
                    //Vertical line
                    //x = ppt2.first.x
                    ld y = m * ppt2.first.x + c;
                    if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                        y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                    ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                    //y = mx + c
                    //y = m2x + c2
                    //mx + c = m2x + c2
                    //(m - m2)x = c2 - c
                    if (isClose(m, m2)) {
                        continue;
                    }
                    else {
                        ld x = (c2 - c) / (m - m2);
                        if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                            x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                dp[i][1] = min(dp[i][1], dist(ppt.first, { v[0].x, v[0].y }));
            }
        }

        //Start with other points
        up2(0, i, 1) {
            pair<pt, pt> ppt3 = solve(v[j], v[j + 1]);
            //Consider first point
            if (isClose(ppt.first.x, ppt3.first.x)) {
                //Vertical line
                //x = ppt.first.x
                ll ok = 1;
                up3(j, i, 1) {
                    pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                    if (isClose(ppt2.first.x, ppt2.second.x)) {
                        //Vertical line
                        //x = ppt2.first.x
                        if (isClose(ppt.first.x, ppt2.first.x)) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                    else {
                        ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                        ld c = ppt2.first.y - m * ppt2.first.x;
                        ld y = m * ppt.first.x + c;
                        if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                            y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) {
                    dp[i][1] = min(dp[i][1], dp[j][0] + dist(ppt.first, ppt3.first));
                }
            }
            else {
                ld m = (ppt.first.y - ppt3.first.y) / (ppt.first.x - ppt3.first.x);
                ld c = ppt.first.y - m * ppt.first.x;
                ll ok = 1;
                up3(j, i, 1) {
                    pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                    if (isClose(ppt2.first.x, ppt2.second.x)) {
                        //Vertical line
                        //x = ppt2.first.x
                        ld y = m * ppt2.first.x + c;
                        if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                            y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                    else {
                        ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                        ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                        //y = mx + c
                        //y = m2x + c2
                        //mx + c = m2x + c2
                        //(m - m2)x = c2 - c
                        if (isClose(m, m2)) {
                            continue;
                        }
                        else {
                            ld x = (c2 - c) / (m - m2);
                            if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                                x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                                continue;
                            }
                            else {
                                ok = 0;
                                break;
                            }
                        }
                    }
                }
                if (ok) {
                    dp[i][1] = min(dp[i][1], dp[j][0] + dist(ppt.first, ppt3.first));
                }
            }

            //Consider second point
            if (isClose(ppt.first.x, ppt3.second.x)) {
                //Vertical line
                //x = ppt.first.x
                ll ok = 1;
                up3(j, i, 1) {
                    pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                    if (isClose(ppt2.first.x, ppt2.second.x)) {
                        //Vertical line
                        //x = ppt2.first.x
                        if (isClose(ppt.first.x, ppt2.first.x)) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                    else {
                        ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                        ld c = ppt2.first.y - m * ppt2.first.x;
                        ld y = m * ppt.first.x + c;
                        if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                            y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) {
                    dp[i][1] = min(dp[i][1], dp[j][1] + dist(ppt.first, ppt3.second));
                }
            }
            else {
                ld m = (ppt.first.y - ppt3.second.y) / (ppt.first.x - ppt3.second.x);
                ld c = ppt.first.y - m * ppt.first.x;
                ll ok = 1;
                up3(j, i, 1) {
                    pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                    if (isClose(ppt2.first.x, ppt2.second.x)) {
                        //Vertical line
                        //x = ppt2.first.x
                        ld y = m * ppt2.first.x + c;
                        if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                            y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                    else {
                        ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                        ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                        //y = mx + c
                        //y = m2x + c2
                        //mx + c = m2x + c2
                        //(m - m2)x = c2 - c
                        if (isClose(m, m2)) {
                            continue;
                        }
                        else {
                            ld x = (c2 - c) / (m - m2);
                            if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                                x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                                continue;
                            }
                            else {
                                ok = 0;
                                break;
                            }
                        }
                    }
                }
                if (ok) {
                    dp[i][1] = min(dp[i][1], dp[j][1] + dist(ppt.first, ppt3.second));
                }
            }
        }
    }

    ld res = INT_MAX;
    ppt.first = { v[n - 1].x, v[n - 1].y };

    //Consider first point center
    if (isClose(ppt.first.x, v[0].x)) {
        //Vertical line
        //x = ppt.first.x
        ll ok = 1;
        up3(0, n - 1, 1) {
            pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
            if (isClose(ppt2.first.x, ppt2.second.x)) {
                //Vertical line
                //x = ppt2.first.x
                if (isClose(ppt.first.x, ppt2.first.x)) {
                    continue;
                }
                else {
                    ok = 0;
                    break;
                }
            }
            else {
                ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                ld c = ppt2.first.y - m * ppt2.first.x;
                ld y = m * ppt.first.x + c;
                if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                    y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                    continue;
                }
                else {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) {
            res = min(res, dist(ppt.first, { v[0].x, v[0].y }));
        }
    }
    else {
        ld m = (ppt.first.y - v[0].y) / (ppt.first.x - v[0].x);
        ld c = ppt.first.y - m * ppt.first.x;
        ll ok = 1;
        up3(0, n - 1, 1) {
            pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
            if (isClose(ppt2.first.x, ppt2.second.x)) {
                //Vertical line
                //x = ppt2.first.x
                ld y = m * ppt2.first.x + c;
                if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                    y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                    continue;
                }
                else {
                    ok = 0;
                    break;
                }
            }
            else {
                ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                //y = mx + c
                //y = m2x + c2
                //mx + c = m2x + c2
                //(m - m2)x = c2 - c
                if (isClose(m, m2)) {
                    continue;
                }
                else {
                    ld x = (c2 - c) / (m - m2);
                    if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                        x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
            }
        }
        if (ok) {
            res = min(res, dist(ppt.first, { v[0].x, v[0].y }));
        }
    }

    //Start with other points
    up2(0, n - 1, 1) {
        pair<pt, pt> ppt3 = solve(v[j], v[j + 1]);
        //Consider first point
        if (isClose(ppt.first.x, ppt3.first.x)) {
            //Vertical line
            //x = ppt.first.x
            ll ok = 1;
            up3(j, n - 1, 1) {
                pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                if (isClose(ppt2.first.x, ppt2.second.x)) {
                    //Vertical line
                    //x = ppt2.first.x
                    if (isClose(ppt.first.x, ppt2.first.x)) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                    ld c = ppt2.first.y - m * ppt2.first.x;
                    ld y = m * ppt.first.x + c;
                    if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                        y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                res = min(res, dp[j][0] + dist(ppt.first, ppt3.first));
            }
        }
        else {
            ld m = (ppt.first.y - ppt3.first.y) / (ppt.first.x - ppt3.first.x);
            ld c = ppt.first.y - m * ppt.first.x;
            ll ok = 1;
            up3(j, n - 1, 1) {
                pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                if (isClose(ppt2.first.x, ppt2.second.x)) {
                    //Vertical line
                    //x = ppt2.first.x
                    ld y = m * ppt2.first.x + c;
                    if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                        y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                    ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                    //y = mx + c
                    //y = m2x + c2
                    //mx + c = m2x + c2
                    //(m - m2)x = c2 - c
                    if (isClose(m, m2)) {
                        continue;
                    }
                    else {
                        ld x = (c2 - c) / (m - m2);
                        if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                            x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                            continue;
                        }
                        else {
                            //cout << j << ' ' << x << '\n';
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                res = min(res, dp[j][0] + dist(ppt.first, ppt3.first));
            }
        }

        //Consider second point
        if (isClose(ppt.first.x, ppt3.second.x)) {
            //Vertical line
            //x = ppt.first.x
            ll ok = 1;
            up3(j, n - 1, 1) {
                pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                if (isClose(ppt2.first.x, ppt2.second.x)) {
                    //Vertical line
                    //x = ppt2.first.x
                    if (isClose(ppt.first.x, ppt2.first.x)) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ld m = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                    ld c = ppt2.first.y - m * ppt2.first.x;
                    ld y = m * ppt.first.x + c;
                    if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                        y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                res = min(res, dp[j][1] + dist(ppt.first, ppt3.second));
            }
        }
        else {
            ld m = (ppt.first.y - ppt3.second.y) / (ppt.first.x - ppt3.second.x);
            ld c = ppt.first.y - m * ppt.first.x;
            ll ok = 1;
            up3(j, n - 1, 1) {
                pair<pt, pt> ppt2 = solve(v[k], v[k + 1]);
                if (isClose(ppt2.first.x, ppt2.second.x)) {
                    //Vertical line
                    //x = ppt2.first.x
                    ld y = m * ppt2.first.x + c;
                    if (min(ppt2.first.y, ppt2.second.y) - EPS <= y &&
                        y <= max(ppt2.first.y, ppt2.second.y) + EPS) {
                        continue;
                    }
                    else {
                        ok = 0;
                        break;
                    }
                }
                else {
                    ld m2 = (ppt2.first.y - ppt2.second.y) / (ppt2.first.x - ppt2.second.x);
                    ld c2 = ppt2.first.y - m2 * ppt2.first.x;
                    //y = mx + c
                    //y = m2x + c2
                    //mx + c = m2x + c2
                    //(m - m2)x = c2 - c
                    if (isClose(m, m2)) {
                        continue;
                    }
                    else {
                        ld x = (c2 - c) / (m - m2);
                        if (min(ppt2.first.x, ppt2.second.x) - EPS <= x &&
                            x <= max(ppt2.first.x, ppt2.second.x) + EPS) {
                            continue;
                        }
                        else {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
            if (ok) {
                res = min(res, dp[j][1] + dist(ppt.first, ppt3.second));
            }
        }
    }
    /*cout << ":";
    foreach(x, dp) {
        cout << x[0] << ' ' << x[1] << '\n';
    }*/
    cout << fixed << setprecision(6);
    cout << res << '\n';
}
return 0;
}
