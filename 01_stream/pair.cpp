#include<iostream>

using namespace std;

pair<int, int> findPriceRange(int dist) {
    int min = dist * 0.3;
    int max = dist * 3;
    return make_pair(min, max);
}

int main() {
    int dist = 78;
    
    auto [min, max] = findPriceRange(dist);
    cout << "min = " << min << "max = " << max << endl;
    return 0;
}