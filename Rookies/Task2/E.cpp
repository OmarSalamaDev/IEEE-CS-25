#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>


using namespace std;
typedef long long ll;
ll getMaxLines(ll v, ll k);



int main() {

    ll n, k;
    cin >> n >> k;

    ll b = 0, e = n, v = n;
    
    while(b <= e) {
        ll c = (b + e) / 2;
        ll lines = getMaxLines(c, k);
        if(lines >= n) {
            v = c;
            e = c - 1;
        } 
        else b = c + 1;
    }

    cout << v << "\n";

}

ll getMaxLines(ll v, ll k) {
    ll lines = 0;
    for(ll i = 0; i < 100; i++) {
        ll calc = v / pow(k, i);
        if(calc == 0) break;
        lines += calc;
    }
    return lines;
}

