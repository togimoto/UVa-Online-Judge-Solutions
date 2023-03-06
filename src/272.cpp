#include <iostream>

int main(void) {
    char c, left_single = '`', right_single = '\'';
    bool left_double = true;
    while((c = getchar_unlocked()) != EOF) {
        if(c == '\"') {
            if(left_double) {
                putchar_unlocked(left_single);
                putchar_unlocked(left_single);
                left_double = !left_double;
            } else {
                putchar_unlocked(right_single);
                putchar_unlocked(right_single);
                left_double = !left_double;
            }
        } else {
            putchar_unlocked(c);
        }
    }
    return 0;
}
