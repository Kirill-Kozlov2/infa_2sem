#include <iostream>

using namespace std;

int main()
{
    int a = 0, n, m;
    cin >> n;
    int *array = new int [n];

    for (int i=0; i<n; ++i){
        cin >> array[i];
    }
    for (int i=0; i<n; i++){
        a += array[i];
    }
    m = a / n;
    a = 0;
    for (int i=0; i<n; i++){
        if (array[i] > m){
            a += array[i];
        }
    }
    cout << a;
    delete [] array;
    return 0;
}
