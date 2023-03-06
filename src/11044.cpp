#include <iostream>

inline int ceil_div(int dividend, int divisor) {
    return (dividend % divisor > 0) ? (dividend / divisor + 1) : (dividend / divisor);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // ignore border cells
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;
        std::cout << ceil_div(n-2, 3) * ceil_div(m-2, 3) << "\n";
    }
    return 0;
}
