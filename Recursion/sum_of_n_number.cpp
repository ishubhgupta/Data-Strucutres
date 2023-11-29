#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Recursion
int sum(int n) {
    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}

// Loop
int sumUsingLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int num = 10000;
    
    // Measure time for recursion
    auto start_time_recursion = high_resolution_clock::now();
    cout << "Sum using recursion: " << sum(num) << endl;
    auto end_time_recursion = high_resolution_clock::now();
    auto duration_recursion = duration_cast<microseconds>(end_time_recursion - start_time_recursion);
    cout << "Time taken by recursion: " << duration_recursion.count() << " microseconds" << endl;

    // Measure time for loop
    auto start_time_loop = high_resolution_clock::now();
    cout << "Sum using loop: " << sumUsingLoop(num) << endl;
    auto end_time_loop = high_resolution_clock::now();
    auto duration_loop = duration_cast<microseconds>(end_time_loop - start_time_loop);
    cout << "Time taken by loop: " << duration_loop.count() << " microseconds" << endl;

    return 0;
}
