#include <iostream>
#include <string>
using namespace std;

inline string checkBlank(int pagenum) {
    if(pagenum)
        return to_string(pagenum);
    return "Blank";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n != 0) {
        int sheets = n / 4 + (n % 4 ? 1 : 0);
        int left[sheets * 2], right[sheets * 2];
        int j = 1;
        for(int i = 0; i < sheets * 2; i++)
            right[i] = (j <= n) ? j++ : 0;
        for(int i = sheets * 2 - 1; i >= 0; i--)
            left[i] = (j <= n) ? j++ : 0;
        cout << "Printing order for " << n << " pages:\n";
        for(int i = 0; i < sheets; i++) {
            int index = i * 2;
            string first = checkBlank(left[index]), second = checkBlank(right[index]);
            if(first != "Blank" || second != "Blank")
                cout << "Sheet " << i + 1 << ", front: " << first << ", " << second << '\n';
            index++;
            first = checkBlank(right[index]);
            second = checkBlank(left[index]);
            if(first != "Blank" || second != "Blank")
                cout << "Sheet " << i + 1 << ", back : " << first << ", " << second << '\n';
        }
        cin >> n;
    }
    return 0;
}
