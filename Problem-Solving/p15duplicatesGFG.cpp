#include <vector>
#include<iostream>
std::vector<int> duplicates(long long arr[], int n) {
    std::vector<int> result;
    int array[n] = {0};

    for (int i = 0; i < n; i++) {
        array[arr[i] - 1] += 1;
    }

    for (int i = 0; i < n; i++) {
        if (array[i] > 1) {
            result.push_back(i + 1);
        }
    }
    
    if (result.empty()) {
        result.push_back(-1); 
    }
    return result;
}


int main() {
    long long arr1[] = {0, 3, 1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    std::vector<int> result1 = duplicates(arr1, n1);

    long long arr2[] = {2, 3, 1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    std::vector<int> result2 = duplicates(arr2, n2);
    
    long long arr3[] = {0, 5, 4, 2, 0, 3, 0};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    std::vector<int> result3 = duplicates(arr3, n3);

    // Print the results
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
