#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
vector <int> a;
int x, n;

void SelectionSort(vector<int>& values) {
    for (auto i = values.begin(); i != values.end(); ++i) {
        auto j = min_element(i, values.end());
        swap(*i, *j);
    }
}

int main() {
    int n = 100;
    while (n <= 100000)
    {
        for (int j=0; j<n; j++) {
            x = rand();
            a.push_back(x);
        }
        auto start = std::chrono::high_resolution_clock::now();
        SelectionSort(a);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        cout << n <<'\n';
        cout <<  nsec.count()<<'\n';
        if (n<=10000)
            n=n+1000;
        else n=n+15000;}
    return 0;
}
