#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef string str;
typedef vector<ll> vl;
typedef vector<vl> vl2;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
int main(void){
  std::ios::sync_with_stdio(EXIT_SUCCESS); std::cin.tie(EXIT_SUCCESS); std::cout.tie(EXIT_SUCCESS);
    
  int n; 
  while(cin >> n){
    priority_queue<ll> pq;
    int sum = 0;
    for(int i = 0; i < n;i++){
        char op; cin >> op;
        if(op == 'a'){
            int val; cin >> val;
            pq.push(val);
            sum += val;
        }
        else if(op == 'p'){
            sum -= pq.top();
            pq.pop();
        }
        else{
            cout << sum << '\n';
        }
    }
}
}
