#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    char c;
    while((c = getchar_unlocked()) != EOF)
        putchar_unlocked(c);
    return 0;
}
