#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort()
using namespace std;

class Person {
    public:
        string name;
        int d, m, y;
        
        Person(string &name, int &d, int &m, int &y) {
            this->name = name;
            this->d = d;
            this->m = m;
            this->y = y;
        }
};

bool cmp(Person &a, Person &b) {
    if(a.y != b.y)
        return (a.y < b.y);
    if(a.m != b.m)
        return (a.m < b.m);
    return a.d < b.d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<Person> list;
    int n;
    cin >> n;
    while(n--) {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        list.push_back(Person(name, d, m, y));
    }
    sort(list.begin(), list.end(), cmp);
    cout << list.back().name << "\n";
    cout << list.front().name << "\n";
}
