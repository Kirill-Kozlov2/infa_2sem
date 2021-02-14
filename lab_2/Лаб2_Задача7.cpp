#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b = 1;
    cin >> a;
    for (int k = 2; k <= sqrt(a+2); k++){
        if (a % k == 0){
            b = 0;
        }
    }
    cout << b;
    return 0;
}
