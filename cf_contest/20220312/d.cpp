#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000010;

int is_prime(int x) {
    if (x < 2) return 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}


int vp(int X, int prime) {
    int ans = 0;
    while (X % prime == 0) {
        ans += 1;
        X /= prime;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int x, d; cin >> x >> d;
        if (is_prime(d)) {
            int cnt = 0;
            int x1 = x;
            while (x1 % d == 0) {
                x1 /= d;
                cnt++;
            }
            if (is_prime(x1) || cnt < 2) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            int cnt = 0;
            int x1 = x;
            while (x1 % d == 0) {
                x1 /= d;
                cnt++;
            }
            if (cnt < 2) {
                cout << "NO\n";
                continue;
            }
            vector<int> prime_factors;
            // find all prime factors of d
            int d1 = d;
            for (int i = 2; i * i <= d1; i++) {
                if (d1 % i == 0) {
                    prime_factors.push_back(i);
                    while (d1 % i == 0) {
                        d1 /= i;
                    }
                }
            }
            if (d1 > 1) {
                prime_factors.push_back(d1);
            }

            if (cnt == 2) {
                if (prime_factors.size() > 1) {
                    if (is_prime(x1)) {
                        cout << "YES\n";
                    }
                    else {
                        cout << "NO\n";
                    }
                }
                else {
                    int prime = prime_factors[0];
                    int r = vp(x1, prime);
                    int k = vp(d, prime);
                    int res = x1;
                    while (res % prime == 0) {
                        res /= prime;
                    }

                    if ((r < 2 * k && res > 1) || (r < 2 * k - 1)) {
                        cout << "YES\n";
                    }
                    else {
                        cout << "NO\n";
                    }
                }
            }
            else {
                if (prime_factors.size() > 1) {
                    cout << "YES\n";
                }
                else {
                    int prime = prime_factors[0];
                    int r = vp(x1, prime);
                    int k = vp(d, prime);
                    int res = x1;
                    while (res % prime == 0) {
                        res /= prime;
                    }
                    if (r < k && res > 1) {
                        cout << "YES\n";
                    }
                    else {
                        cout << "NO\n";
                    }
                }
            }







            // if (is_prime(x1) && cnt < 3) {
            //     cout << "NO\n";
            // }
            // else {

            //     vector<int> prime_factors;
            //     // find all prime factors of d
            //     int d1 = d;
            //     for (int i = 2; i * i <= d1; i++) {
            //         if (d1 % i == 0) {
            //             prime_factors.push_back(i);
            //             while (d1 % i == 0) {
            //                 d1 /= i;
            //             }
            //         }
            //     }
            //     if (d1 > 1) {
            //         prime_factors.push_back(d1);
            //     }
            //     if (prime_factors.size() > 1) {
            //         cout << "YES\n";
            //     }
            //     else {
            //         int p = prime_factors[0];
            //         if (vp(d, p) == 2 && vp(x1, p) == 1) {
            //             cout << "NO\n";
            //         }
            //         else {
            //             cout << "YES\n";
            //         }
            //     }
            // }

        }
    }
}