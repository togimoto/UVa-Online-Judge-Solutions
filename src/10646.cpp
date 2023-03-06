#include <iostream>
#include <string>
using namespace std;

class Card {
    public:
        string name;
        int next;

        int getValue(void) {
            if('2' <= name[1] && name[1] <= '9')
                return name[1] - '0';
            return 10;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Card deck[52];
    int N;
    cin >> N;
    for(int j = 1; j <= N; j++) {
        for(int i = 0; i < 52; i++) {
            cin >> deck[i].name;
            deck[i].next = i + 1;
        }
        int top = 52 - 25 - 1, Y = 0;
        for(int i = 0; i < 3; i++) {
            int value = deck[top--].getValue();
            Y += value;
            top -= (10 - value);
            deck[top].next = 52 - 25;
        }
        int target = 0;
        for(int i = 1; i < Y; i++)
            target = deck[target].next;
        cout << "Case " << j << ": " << deck[target].name << '\n';
    }
    return 0;
}
