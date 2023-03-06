#include <iostream>
#define MARKS 40

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int deg_per_mark = 360/MARKS;
    int start, first, second, third;
    std::cin >> start >> first >> second >> third;
    while(start || first || second || third) {
        int total = 360 * 3;
        if(start >= first) 
            total += deg_per_mark * (start - first);
        else 
            total += deg_per_mark * (start + MARKS - first);
        if(second >= first)
            total += deg_per_mark * (second - first);
        else
            total += deg_per_mark * (MARKS - first + second);
        if(second >= third)
            total += deg_per_mark * (second - third);
        else
            total += deg_per_mark * (second + MARKS - third);
        std::cout << total << "\n";
        std::cin >> start >> first >> second >> third;
    }
    return 0;
}
