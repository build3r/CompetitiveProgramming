#include <iostream>
#include <math.h>
using namespace std;
int getGCD(int a, int b)
{
     if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main()

{
    int x, y;
    cout << "Please enter two integers x and y, for GCD calculation" << endl;
    cin >> x >> y;
    cout << "The GCD of " << x << "and " << y << " is" << getGCD(x, y) << endl;
    return 0;
}
