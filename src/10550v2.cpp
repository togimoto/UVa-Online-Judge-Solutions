/*
 * Reference:
 * User dsferreira on Virtual Judge
 * (https://vjudge.net/solution/40907201)
 */
#include <iostream>
#define MARKS 40

//clockwise from start to dest
inline int cnt_marks(int start, int dest) {
    return (dest - start < 0) ? (MARKS + dest - start) : (dest - start);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int deg_per_mark = 360/MARKS;
    int start, first, second, third;
    std::cin >> start >> first >> second >> third;
    while(start || first || second || third) {
        int total_marks = cnt_marks(first, start) + cnt_marks(first, second) + cnt_marks(third, second);
        std::cout << (total_marks * deg_per_mark + 360 * 3) << "\n";
        std::cin >> start >> first >> second >> third;
    }
    return 0;
}
