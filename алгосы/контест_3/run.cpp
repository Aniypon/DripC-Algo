#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <iomanip>

bool bad_comparator(int a, int b) {
    return (a % 2) < (b % 2);
}

int main() {
    const int n = 32768;
    std::vector<int> arr(n);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    
    for (int i = 0; i < n; ++i) {
        arr[i] = dis(gen);
    }

    std::ofstream outFile("array_data.txt", std::ios::binary);
    
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(arr.begin(), arr.end(), bad_comparator);
    auto end = std::chrono::high_resolution_clock::now();
    
    // Записываем элементы в одну строку через пробел
    for (int i = 0; i < n; ++i) {
        outFile << arr[i];
        if (i < n - 1) outFile << ' ';
    }
    
    outFile.close();

    std::chrono::duration<double> duration = end - start;
    std::cout << std::fixed << std::setprecision(10) << duration.count() << " seconds\n";
    
    return 0;
}