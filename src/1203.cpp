#include <bits/stdc++.h>
using namespace std;

class Query {
    public:
        int id;
        int p;
        int t;

        Query(int id, int p) {
            this->id = id;
            this->p = p;
            this->t = p;
        }
};

class Compare {
    public:
        bool operator()(const Query &a, const Query &b) {
            if(a.t != b.t)
                return a.t > b.t;
            return a.id > b.id;
        }
};

string instruction;
int K, id, period;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<Query, vector<Query>, Compare> q;
    cin >> instruction;
    while(instruction != "#") {
        cin >> id >> period;
        q.push(Query(id, period));
        cin >> instruction;
    }
    cin >> K;
    while(K--) {
        Query curr = q.top();
        q.pop();
        cout << curr.id << "\n";
        curr.t += curr.p;
        q.push(curr);
    }
}
