
#include <iostream>
typedef long long ll;

int main(void) {
    ll n;
    std::cin >> n;
    int officers = 0;
    int untreated = 0;
    
    for(ll i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if(a == -1 && officers != 0) {
            officers--;
        }
        else if(a == -1 && officers == 0) {
            untreated++;
        }
        else if(a != -1) {
            officers += a;
        }
    }

    std::cout << untreated << "\n";

}