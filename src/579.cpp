#include <iostream>
#include <iomanip>
using namespace std;

inline double get_angle(double h, double m) {
    if(m > h) {
        double temp = m;
        m = h;
        h = temp;
    }
    double angle = (h-m)*6;
    return (angle <= 180) ? angle : 360-angle;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout << setprecision(3);
    double h, m;
    char c;
    while(true) {
        cin >> h >> c >> m;
        if(!(h || m))
            break;
        h = h * 5 + m/12;
        cout << get_angle(h,m) << '\n';
    }
}
