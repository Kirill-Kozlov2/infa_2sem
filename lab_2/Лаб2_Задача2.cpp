#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N,a,b,c;
    cin >> N;
    a = N % 4;
    b = N % 400;
    c = N % 100;
    if ( a == 0, c != 0) {
        cout << "YES";
    }
        else if (b == 0) {
        cout << "YES";
    }
        else {
        cout << "NO";
    }
    return 0;
}
