#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;
vector <int> a;
int x;

void MergeSort1(vector <int>& a, vector<int>& b, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort1(a, b, l, m);
        MergeSort1(a, b, m + 1, r);

        int k = l;
        for (int i = l, j = m + 1; i <= m || j <= r; ) {
            if (j > r || (i <= m && a[i] < a[j])) {
                b[k] = a[i];
                ++i;
            } else {
                b[k] = a[j];
                ++j;
            }
            ++k;
        }
        for (int i = l; i <= r; ++i) {
            a[i] = b[i];
        }
    }
}

void MergeSort(vector<int>& a) {
    if (!a.empty()) {
        vector<int> b(a.size());
        MergeSort1(a, b, 0, a.size() - 1);
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
        MergeSort(a);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        cout << n <<'\n';
        cout <<  nsec.count()<<'\n';
        if (n<=10000)
            n=n+1000;
        else n=n+15000;}
    return 0;
}
