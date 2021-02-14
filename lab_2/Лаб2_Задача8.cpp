#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n != 1) {
        for (int i = 2; i < n + 1; i++) {
            if (n % i == 0) {
                cout << i << endl;
                n = n / i;
            }
        }
    }
    return 0;
}
