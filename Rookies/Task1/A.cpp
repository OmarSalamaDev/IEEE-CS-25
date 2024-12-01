
#include <iostream>


int main(void) {
    int n;
    std::cin >> n;
    int a[n];
    int max_index = n - 1, max = 1;
    int min_index = 0, min = 100;

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        if(a[i] > max) {
            max = a[i];
            max_index = i;
        }
        if(a[i] <= min) {
            min = a[i];
            min_index = i;
        }
    }

    if(max_index == min_index) std::cout << 0 << "\n";
    else if(max_index > min_index) std::cout << max_index + n - 2 - min_index << "\n";
    else std::cout << max_index + n - 1 - min_index << "\n";

}