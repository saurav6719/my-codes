#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

void find_divisors(long long num, std::vector<long long>& divisors) {
    if (num <= 0) return;
    long long limit = sqrt(num);
    for (long long i = 1; i <= limit; ++i) {
        if (num % i == 0) {
            divisors.push_back(i);
            if (i * i != num) {
                divisors.push_back(num / i);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, x;
    std::cin >> n >> x;

    long long valid_k_count = 0;

    long long diff = n - x;
    std::vector<long long> divisors1;
    find_divisors(diff, divisors1);

    for (long long d : divisors1) {
        if (d % 2 == 0) {
            if (d >= 2 * x - 2) {
                valid_k_count++;
            }
        }
    }

    if (x > 1) {
        long long sum = n + x - 2;
        std::vector<long long> divisors2;
        find_divisors(sum, divisors2);

        for (long long d : divisors2) {
            if (d % 2 == 0) {
                if (d > 2 * x - 2) {
                    valid_k_count++;
                }
            }
        }
    }

    std::cout << valid_k_count << std::endl;

    return 0;
}