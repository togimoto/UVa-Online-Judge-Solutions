#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++) {
        unsigned long long a, b;
        std::cin >> a >> b;
        if(a > b)
            std::cout << ">\n";
        else if(a == b)
            std::cout << "=\n";
        else
            std::cout << "<\n";
    }
    return 0;
}
