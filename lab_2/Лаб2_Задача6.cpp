#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, maxn, maxnumber = 1;
    cin >> n;
    maxn = n;
    while (n != 0){
        cin >> n;
        if (n == maxn){
            maxnumber++;
        }
        else if (n > maxn){
            maxn = n;
            maxnumber = 1;
        }
    }
    cout << maxnumber;
    return 0;
}
