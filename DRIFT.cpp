#include <bits/stdc++.h>
using namespace std;

int Akm(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return Akm(m - 1, 1);
    else
        return Akm(m - 1, Akm(m, n - 1));
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    if (x < y){
        if (z < x){
            cout << z << " " << x << " " << y << endl;
        }
        else if (z < y){
            cout << x << " " << z << " " << y << endl;
        }
        else{
            cout << x << " " << y << " " << z << endl;
        }
    }
    else{
        if (z < y){
            cout << z << " " << y << " " << x << endl;
        }
        else if (z < x){
            cout << y << " " << z << " " << x << endl;
        }
        else{
            cout << y << " " << x << " " << z << endl;
        }
    }
}