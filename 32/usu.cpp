#include <iostream>

using namespace std;
using LL = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    LL a, b;
    cin >> a >> b;

    LL n = b - a + 1;
    LL n_even = (a % 2 == 0) ? (b - a) / 2 + 1 : (b - a + 1) / 2;
    LL n_odd = n - n_even;
    LL max_removed = 2 * min(n_even, n_odd);
    if (n % 2 == 0 && (b + (a + b) / 2) % 2 != 0)
        max_removed -= 2;

    cout << max_removed;

    return 0;
}
