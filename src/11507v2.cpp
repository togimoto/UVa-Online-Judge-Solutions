/*
 * Reference:
 * User imtyaz17 on Virtual Judge
 * (https://vjudge.net/solution/39407369)
 */
#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int L;
    cin >> L;
    while(L != 0) {
        string curr_dir = "+x";
        for(int i = 1; i < L; i++) {
            string dir;
            cin >> dir;
            if(dir == "No")
                continue;
            if(curr_dir[1] == 'x') {
                if(curr_dir[0] == '-') 
                    dir[0] = (dir[0] == '+') ? '-' : '+';
                curr_dir = dir;
            } else if(dir[1] == curr_dir[1])
                curr_dir = (dir[0] == curr_dir[0]) ? "-x" : "+x";
        }
        cout << curr_dir << "\n";
        cin >> L;
    }
    return 0;
}
