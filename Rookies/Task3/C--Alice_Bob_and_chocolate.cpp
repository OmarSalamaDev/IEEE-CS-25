#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
typedef long long ll;



int main() {

    ll n, a = 0, b = 0;
    cin >> n;
    vector<ll> t(n);
    for(ll i = 0; i < n; i++) cin >> t[i];

    ll alice = 0, bob = n - 1, aliceTime = 0, bobTime = 0;
    while(alice <= bob) {

        if(aliceTime > bobTime) {
            bobTime += t[bob];
            bob--;
            b++;
        }
        else if(bobTime >= aliceTime) {
            aliceTime += t[alice];
            alice++;
            a++;
        }
    }

    cout << a << " " << b << endl;


}

