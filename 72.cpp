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
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const ld INF = 1e18;
bool isClose(ld a, ld b, ld eps = EPS) {
    return fabsl(a - b) <= eps;
}

struct circle {
    ld x, y, r;
};
struct pt {
    ld x, y;
};

struct Info {
    ll node_id;
    ld sum_dist;
    bool operator<(const Info& arg) const {
        return sum_dist > arg.sum_dist;
    }
};

pair<pt, pt> solve(circle ca, circle cb) {
    ld h1 = ca.x, k1 = ca.y, r1 = ca.r;
    ld h2 = cb.x, k2 = cb.y, r2 = cb.r;
    ld dx = h2 - h1;
    ld dy = k2 - k1;
    ld dd = sqrtl(dx * dx + dy * dy);
    if (dd > r1 + r2 + EPS || fabsl(r1 - r2) > dd + EPS) {
        return {{INF, INF}, {INF, INF}};
    }
    if (isClose(dd, 0) && isClose(r1, r2)) {
        return {{INF, INF}, {INF, INF}};
    }
    ld a = (r1 * r1 - r2 * r2 + dd * dd) / (2 * dd);
    ld hh = sqrtl(r1 * r1 - a * a);
    if (isnan(hh)) hh = 0;
    ld px = h1 + a * (dx / dd);
    ld py = k1 + a * (dy / dd);
    pt p1 = {px + hh * (-dy / dd), py + hh * (dx / dd)};
    pt p2 = {px - hh * (-dy / dd), py - hh * (dx / dd)};
    return {p1, p2};
}
ld dist(pt a, pt b) {
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ll ccw(pt a, pt b, pt c) {
    ld gaiseki = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
    if (gaiseki > EPS) return 1;
    if (gaiseki < -EPS) return -1;
    ld naiseki = (c.x - a.x) * (b.x - a.x) + (c.y - a.y) * (b.y - a.y);
    if (naiseki < -EPS) return 2;
    ld norm1 = dist(a, b);
    ld norm2 = dist(a, c);
    if (norm1 + EPS < norm2) return -2;
    return 0;
}

int main(void) {
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    ll n;
    while (cin >> n) {
        if (n == 0) break;
        vector<circle> v(n);
        up(0, n, 1) {
            cin >> v[i].x >> v[i].y >> v[i].r;
        }
        vector<pt> points;
        points.push_back({v[0].x, v[0].y});
        up(0, n - 1, 1) {
            pair<pt, pt> res = solve(v[i], v[i + 1]);
            points.push_back(res.first);
            points.push_back(res.second);
            points.push_back({v[i + 1].x, v[i + 1].y});
        }
        ll num = points.size();
        ll start = 0;
        ll goal = num - 1;
        vector<vl> G(num);
        vector<vd> Dist(num, vd(num));
        up(0, num, 1) {
            up2(0, num, 1) {
                Dist[i][j] = dist(points[i], points[j]);
            }
        }
        bool FLG;
        ll first_up, last_up;
        up(0, num - 1, 1) {
            switch (i % 3) {
            case 0:
                first_up = i + 1;
                break;
            case 1:
                first_up = i + 3;
                break;
            case 2:
                first_up = i + 2;
                break;
            }
            up2(i + 1, num, 1) {
                FLG = true;
                switch (j % 3) {
                case 0:
                    last_up = j - 2;
                    break;
                case 1:
                    last_up = j - 3;
                    break;
                case 2:
                    last_up = j - 4;
                    break;
                }
                if (last_up < first_up) {
                    G[i].push_back(j);
                    continue;
                }
                up3(first_up, last_up + 1, 3) {
                    ll prod1 = ccw(points[i], points[j], points[k]) * ccw(points[i], points[j], points[k + 1]);
                    ll prod2 = ccw(points[k], points[k + 1], points[i]) * ccw(points[k], points[k + 1], points[j]);
                    if (prod1 > 0 || prod2 > 0) {
                        FLG = false;
                        break;
                    }
                }
                if (FLG) {
                    G[i].push_back(j);
                }
            }
        }
        vd min_dist(num, INF);
        priority_queue<Info> Q;
        min_dist[start] = 0;
        Q.push({start, 0});
        while (!Q.empty()) {
            Info cur = Q.top();
            if (cur.sum_dist > min_dist[cur.node_id]) {
                Q.pop();
                continue;
            }
            Q.pop();
            if (cur.node_id == goal) {
                cout << fixed << setprecision(6) << cur.sum_dist << '\n';
                break;
            }
            foreach(to, G[cur.node_id]) {
                ld nextd = cur.sum_dist + Dist[cur.node_id][to];
                if (nextd < min_dist[to]) {
                    min_dist[to] = nextd;
                    Q.push({to, nextd});
                }
            }
        }
    }
    return 0;
}