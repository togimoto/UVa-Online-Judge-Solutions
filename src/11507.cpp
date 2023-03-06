#include <iostream>
using namespace std;

string new_directions[4] = {"+y", "-y", "+z", "-z"};
string directions[6] = {"+x", "-x", "+y", "-y", "+z", "-z"};
string final_directions[6][4] = {
    {"+y", "-y", "+z", "-z"},
    {"-y", "+y", "-z", "+z"},
    {"-x", "+x", "+y", "+y"},
    {"+x", "-x", "-y", "-y"},
    {"+z", "+z", "-x", "+x"},
    {"-z", "-z", "+x", "-x"},
 };

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
            int index1 = 0;
            while(dir != new_directions[index1])
                index1++;
            int index2 = 0;
            while(curr_dir != directions[index2])
                index2++;
            curr_dir = final_directions[index2][index1];
        }
        cout << curr_dir << "\n";
        cin >> L;
    }
    return 0;
}
