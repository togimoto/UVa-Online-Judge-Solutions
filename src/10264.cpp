#include <iostream>
#include <vector>
using namespace std;

class Corner {
    public:
        int w;
        int p;
        
        Corner(int weight) {
            this->w = weight;
            this->p = 0;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int dim;
    while(cin >> dim) {
        int last_index = 0;
        for(int i = 0; i < dim; i++)
            last_index = (last_index << 1) | 1;
        vector<Corner> weights;
        vector<bool> visited;
        for(int i = 0; i <= last_index; i++) {
            int weight;
            cin >> weight;
            weights.push_back(Corner(weight));
            visited.push_back(false);
        }
        for(int index = 0; index <= last_index; index++)
            for(int i = 1; i < last_index; i = i << 1)
                weights[index].p += weights[index ^ i].w;
        int max_sum = 0;
        for(int index = 0; index <= last_index; index++) {
            for(int i = 1; i < last_index; i = i << 1) {
                if(visited[index ^ i])
                    continue;
                if(weights[index].p + weights[index ^ i].p > max_sum)
                    max_sum = weights[index].p + weights[index ^ i].p;
            }
            visited[index] = true;
        }
        cout << max_sum << "\n";
    }
}
