

#include <iostream>
using namespace std;
typedef long long ll;


void algo(ll n) {
    cout << n << " ";
    if (n == 1) return;
    if (n % 2 == 0) algo(n / 2); 
    else algo(3 * n + 1);
}

int main() {
    ll n;
    cin >> n;

    algo(n);

}
