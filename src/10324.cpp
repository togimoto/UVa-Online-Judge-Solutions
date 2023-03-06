#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

#define MAX 1000000

inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

int main(void) {
    int *arr = (int *)malloc(sizeof(int) * MAX);
    assert(arr != nullptr);
    for(int case_no = 1; ; case_no++) {
        int length = 0;
        char c, prev = '2';
        while((c = getchar_unlocked()) != '\n' && c != EOF) {
            if(c == prev)
                arr[length] = arr[length-1] + 1;
            else {
                prev = c;
                arr[length] = 1;
            }
            length++;
        }
        if(length == 0)
            break;
        cout << "Case " << case_no << ":\n";
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            if(l > r)
                swap(l, r);
            if(arr[r] >= (r - l + 1))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        getchar_unlocked();
    }
    return 0;
}
