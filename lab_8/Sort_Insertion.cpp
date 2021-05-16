#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;
vector <int> a;
int x, n;

void InsertionSort(vector<int>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        int x = a[i];
        size_t j = i;
        while (j > 0 && a[j - 1] > x) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = x;
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
        InsertionSort(a);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        cout << n <<'\n';
        cout <<  nsec.count()<<'\n';
        if (n<=10000)
        n=n+1000;
    else n=n+15000;}
    return 0;
}
