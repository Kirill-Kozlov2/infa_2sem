#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int M = 0, n;
    cin >> n;
    if (n % 2 == 0){
        M = n;
    }
    while (n != 0){
        if (n % 2 == 0 and n > M){
            M = n;
        }
        cin >> n;
    }
    cout << M;
    return 0;
}
