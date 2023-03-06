#include <iostream>
#include <cmath>
#include <vector>
using std::cin;
using std::cout;
using std::ios_base;
using std::vector;

class TrafficLight {
    public:
        int green;
        int cycle;
        int total;

        TrafficLight(int cycle) {
            green = cycle - 5;
            this->cycle = cycle;
            total = 0;
        }

        void add() {
            total += 2 * cycle;
            return;
        }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cycle;
    cin >> cycle;
    while(cycle != 0) {
        vector<TrafficLight> lights;
        int max = 100;
        do {
            TrafficLight light(cycle);
            max = std::min(max, 2 * light.cycle); //must take the minimum first, otherwise may skip the solution
            lights.push_back(light);
            cin >> cycle;
        } while(cycle != 0);
        int i, size = lights.size(), five_hours = 5 * 60 * 60;
        for(i = 0; i < size && max <= five_hours; i++) {
            while(lights[i].total + lights[i].green <= max)
                lights[i].add();
            if(lights[i].total > max) {
                max = lights[i].total;
                i = -1;
            }
        }
        if(max > five_hours)
            cout << "Signals fail to synchronise in 5 hours\n";
        else {
            int hr = max / (60 * 60);
            max %= (60 * 60);
            int min = max / 60;
            max %= 60;
            int sec = max;
            cout << '0' << hr << ':' << (min < 10 ? "0" : "") << min << ':' << (sec < 10 ? "0" : "") << sec << '\n';
        }
        cin >> cycle;
    }
    return 0;
}
