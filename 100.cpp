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
struct Treatment {
    ll priority, duration;
};

struct Patient {
    ll arrival;
    vector<Treatment> treatments;
    ll idx = 0;
    ll releaseTime = -1;
};

struct WaitingCmp {
    bool operator()(const Patient* a, const Patient* b) const {
        ll pa = a->treatments[a->idx].priority;
        ll pb = b->treatments[b->idx].priority;
        if (pa != pb) return pa < pb;
        return a->arrival > b->arrival; 
    }
};

struct DoctorEvent {
    ll finish;
    Patient* patient;
    bool operator>(const DoctorEvent& other) const {
        if (finish != other.finish) return finish > other.finish;
        return patient->arrival > other.patient->arrival;
    }
};
int main(void){
std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
ll doctors, startTime;
ll caseNo = 1;
while (cin >> doctors >> startTime) {
    if (doctors == 0 && startTime == 0) break;

    vector<Patient> patients;
    while (1) {
        int arr; cin >> arr;
        if (arr == -1) break;
        if (arr == 0) {
            return 0;
        }
        Patient p;
        p.arrival = arr;
        while (1) {
            ll pr, dur; cin >> pr >> dur;
            if (pr == 0 && dur == 0) break;
            p.treatments.push_back({ pr, dur });
        }
        patients.push_back(p);
    }

    priority_queue<Patient*, vector<Patient*>, WaitingCmp> waiting;
    priority_queue<DoctorEvent, vector<DoctorEvent>, greater<DoctorEvent>> busy;

    ll time = startTime;
    ll nextPatientIdx = 0;
    ll n = patients.size();

    vpll releases;

    while ((ll)releases.size() < n) {
        while (nextPatientIdx < n && patients[nextPatientIdx].arrival <= time) {
            waiting.push(&patients[nextPatientIdx]);
            nextPatientIdx++;
        }

        ll freeDocs = doctors - (ll)busy.size();
        while (freeDocs > 0 && !waiting.empty()) {
            Patient* p = waiting.top(); waiting.pop();
            Treatment& t = p->treatments[p->idx];
            busy.push({ time + t.duration, p });
            freeDocs--;
        }

        if (busy.empty()) {
            if (nextPatientIdx < n)
                time = max(time, patients[nextPatientIdx].arrival);
            else
                break;
        }
        else {
            DoctorEvent ev = busy.top(); busy.pop();
            time = ev.finish;
            Patient* p = ev.patient;
            p->idx++;
            if (p->idx < (ll)p->treatments.size()) {
                waiting.push(p);
            }
            else {
                // finished
                p->releaseTime = time;
                releases.push_back({ time, p->arrival });
            }
        }
    }

    sort(all(releases));

    cout << "Case " << caseNo++ << ":\n";
    foreach(r, releases) {
        cout << "Patient " << r.second << " released at clock = " << r.first << '\n';
    }
}
return 0;
}
