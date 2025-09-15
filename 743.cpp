#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
str s;
while (getline(cin, s)) {
    stack<pair<char, ll>> st;
    ll firstidx = -1;
    map<char, char> p = { {'}', '{'}, {')', '('}, {']', '['} };
    for (ll i = 0; i < s.length(); ++i) {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push({ s[i], i });
        }
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
            if (st.empty()) {
                firstidx = i + 1;
                break;
            }
            if (st.top().first != p[s[i]]) {
                firstidx = i + 1;
                break;
            }
            st.pop();
        }
    }
    if (firstidx == -1) {
        while (!st.empty()) {
            firstidx = st.top().second + 1;
            st.pop();
        }
    }
    if (firstidx == -1) {
        cout << "Success\n";
    }
    else {
        cout << firstidx << '\n';
    }
}
/*
{[()]()}[]
{}([[]
{}([[]}]
{}{(]}
{}{](}
( [43]( i++ ; ) ) {   lol  = 3 ; }
*/
}
