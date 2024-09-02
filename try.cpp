#include <iostream>
#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    int x = 0;
    for(int i = 1; i<=1e5;  i++){
        for(int j = 1; j<=1e4; j++){
            for(int k = 1; k<=20; k++){
                x *= 0;
            }
        }
    }
    std::cout<<x;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken: " << elapsed.count() << " seconds\n";

    return 0;
}
