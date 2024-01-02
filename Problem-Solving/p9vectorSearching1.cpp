// Problem Statement 9: Vector Searching
// You are given a list of integers sorted in ascending order. Implement a program in C++ that searches for a given element in the list using vectors.

// Input:

// The first line contains an integer 'n', the size of the list.
// The second line contains 'n' space-separated integers representing the elements of the sorted list.
// The third line contains an integer 'x', the element to be searched.
// Output:

// Print "Found" if the element is present in the list, otherwise print "Not Found".
// Example:
// Input:

// Copy code
// 5
// 1 2 3 4 5
// 3
// Output:

// Copy code
// Found

#include<iostream>
#include<vector>

using namespace std;

void binarySearch(vector<int>& vec1, int l, int r, int key) {
    if (l > r) {
        cout << "not found";
        return;
    }

    int mid = l + (r - l) / 2;

    if (vec1[mid] == key) {
        cout << "found";
    }
    else if (key > vec1[mid]) {
        binarySearch(vec1, mid + 1, r, key);
    }
    else{
        binarySearch(vec1, l, mid - 1, key);
    }
}

int main() {
    vector<int> vec1;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        vec1.push_back(num);
    }

    // sort(vec1.begin(), vec1.end());

    binarySearch(vec1, 0, vec1.size() - 1, 4);

    return 0;
}
