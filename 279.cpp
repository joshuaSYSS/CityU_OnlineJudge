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
const ld EPS = 1e-8;
const ld PI = 2 * acos(0.0);

ll gcd(ll a, ll b) {
    while (b)
        b ^= a ^= b ^= a %= b;
    return a;
}
ll lcm(ll a, ll b) {
    return abs(a * b) / gcd(a, b);
}
map<str, ll> tz = {
    {"UTC",0},{"GMT",0},
    {"BST",60},{"IST",60},{"WET",0},{"WEST",60},
    {"CET",60},{"CEST",120},{"EET",120},{"EEST",180},
    {"MSK",180},{"MSD",240},
    {"AST",-240},{"ADT",-180},
    {"NST",-210},{"NDT",-150},
    {"EST",-300},{"EDT",-240},
    {"CST",-360},{"CDT",-300},
    {"MST",-420},{"MDT",-360},
    {"PST",-480},{"PDT",-420},
    {"HST",-600},
    {"AKST",-540},{"AKDT",-480},
    {"AEST",600},{"AEDT",660},
    {"ACST",570},{"ACDT",630},
    {"AWST",480}
};

ll parseTime(const vs& tokens, ll& idx) {
    str t = tokens[idx];
    if (t == "noon") { idx++; return 12 * 60; }
    if (t == "midnight") { idx++; return 0; }

    ll hh, mm;
    char colon;
    stringstream ss(t);
    ss >> hh >> colon >> mm;
    idx++;

    str ampm = tokens[idx]; idx++;
    ll isPM = ampm == "p.m.";
    ll isAM = ampm == "a.m.";

    if (hh == 12) hh = 0;
    if (isPM) hh += 12;

    return hh * 60 + mm;
}

str formatTime(int minutes) {
    minutes = (minutes % (24 * 60) + 24 * 60) % (24 * 60); 
    if (minutes == 0) return "midnight";
    if (minutes == 12 * 60) return "noon";

    int hh = minutes / 60;
    int mm = minutes % 60;
    str ampm = hh >= 12 ? "p.m." : "a.m.";
    hh %= 12;
    if (hh == 0) hh = 12;

    stringstream ss;
    ss << hh << ':' << setw(2) << setfill('0') << mm << ' ' << ampm;
    return ss.str();
}
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll tc; cin >> tc; cin.ignore();
while (tc--) {
    str line; getline(cin, line);
    stringstream ss(line);
    vs tokens; str tok;
    while (ss >> tok) tokens.push_back(tok);

    ll idx = 0;
    ll minutes = parseTime(tokens, idx);
    str fromTZ = tokens[idx++];
    str toTZ = tokens[idx++];

    minutes -= tz[fromTZ];
    minutes += tz[toTZ];

    cout << formatTime(minutes) << '\n';
}
return 0;
}
