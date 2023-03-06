#include <iostream>
#include <string>
using namespace std;

inline int getValue(string &name) {
    if('2' <= name[1] && name[1] <= '9')
        return name[1] - '0';
    return 10;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string deck[52];
    int N;
    cin >> N;
    for(int case_no = 1; case_no <= N; case_no++) {
        for(int i = 0; i < 52; i++)
            cin >> deck[i];
        int top = 52 - 25 - 1, Y = 0;
        for(int i = 0; i < 3; i++) {
            int value = getValue(deck[top--]);
            Y += value;
            top -= (10 - value);
        }
        int target;
        if(Y <= top + 1)
            target = Y - 1;
        else
            target = 52 - 25 - 1 + Y - (top + 1);
        cout << "Case " << case_no << ": " << deck[target] << '\n';
    }
    return 0;
}
