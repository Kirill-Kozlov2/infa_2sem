#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;
vector <int> a;
int x;

void BubbleSort(vector<int>& a) {
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        for (size_t j = 0; j + 1 < a.size() - i; ++j) {
            if (a[j + 1] < a[j]) {
                swap(a[j], a[j + 1]);
            }
        }
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
        BubbleSort(a);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        cout << n <<'\n';
        cout <<  nsec.count()<<'\n';
        if (n<=10000)
        n=n+1000;
    else n=n+15000;}
    return 0;
}
