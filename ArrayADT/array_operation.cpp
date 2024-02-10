#include <iostream>
using namespace std;

struct array {
    int a[20];
    int size;
    int length;

    // Passed by value
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void display() {
        cout << "array content : ";
        for (int i = 0; i < length; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void append(int value) {
        if (length < size) {
            a[length] = value;
            length++;
        }
    }

    void insert(int index, int value) {
        if (length < size && index >= 0 && index <= length) {
            for (int i = length; i > index; i--) {
                a[i] = a[i - 1];
            }
            a[index] = value;
            length++;
        }
    }

    void get(int value) {
        for (int i = 0; i < length; i++) {
            if (a[i] == value) {
                cout << value << " is present at " << i << " index in array" << endl;
            }
        }
    }

    // Reversing array method#1
    void reverseM1() {
        int b[20];
        for (int i = length - 1, j = 0; i >= 0; i--, j++) {
            b[j] = a[i];
        }
        for (int i = 0; i < length; i++) {
            a[i] = b[i];
        }
        cout << "Reversed array : ";
        display();
    }

    // Reversing array method#2
    void reverseM2() {
        for (int i = 0, j = length - 1; i < j; i++, j--) {
            swap(a[i], a[j]);
        }
        cout << "Reversed array (M2) : ";
        display();
    }

    void sortedInsertion(int x) {
        int i = length - 1;
        while (i >= 0 && a[i] > x) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = x;
        length++;
    }
};

// Passed by reference
void append(struct array &arr1, int value) {
    if (arr1.length < arr1.size) {
        arr1.a[arr1.length++] = value;
    }
}

void get(const struct array &arr1, int value) {
    for (int i = 0; i < arr1.length; i++) {
        if (arr1.a[i] == value) {
            cout << value << " is present at " << i << " index in array" << endl;
        }
    }
}

void insert(struct array &arr1, int index, int value) {
    if (arr1.length < arr1.size && index >= 0 && index <= arr1.length) {
        for (int i = arr1.length; i > index; i--) {
            arr1.a[i] = arr1.a[i - 1];
        }
        arr1.a[index] = value;
        arr1.length++;
    }
}

void del(struct array &arr1, int index) {
    if (index >= 0 && index < arr1.length) {
        for (int i = index; i < arr1.length - 1; i++) {
            arr1.a[i] = arr1.a[i + 1];
        }
        arr1.length--;
    } else {
        cout << "Invalid index";
    }
}

int linearSearch(const struct array &arr1, int key) {
    for (int i = 0; i < arr1.length; i++) {
        if (arr1.a[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const struct array &arr1, int key) {
    int l = 0;
    int h = arr1.length - 1;

    while (h >= l) {
        int mid = l + (h - l) / 2;

        if (arr1.a[mid] == key) {
            return mid;
        } else if (key < arr1.a[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return -1;
}

void display(const struct array &arr1) {
    cout << "array content (passed by reference) : ";
    for (int i = 0; i < arr1.length; i++) {
        cout << arr1.a[i] << " ";
    }
    cout << endl;
}

void set(struct array &arr1, int index, int value) {
    if (index >= 0 && index < arr1.length) {
        arr1.a[index] = value;
        cout << "Value set successfully" << endl;
    } else {
        cout << "Invalid index" << endl;
    }
}

void mergeArray(const struct array &arr1, const struct array &arr2) {
    struct array arr3;
    arr3.size = arr1.size + arr2.size;
    arr3.length = arr1.length + arr2.length;

    int i = 0, j = 0, k = 0;

    while (i < arr1.length && j < arr2.length) {
        if (arr1.a[i] < arr2.a[j]) {
            arr3.a[k++] = arr1.a[i++];
        } else {
            arr3.a[k++] = arr2.a[j++];
        }
    }

    // Copy the remaining elements of arr1, if any
    while (i < arr1.length) {
        arr3.a[k++] = arr1.a[i++];
    }

    // Copy the remaining elements of arr2, if any
    while (j < arr2.length) {
        arr3.a[k++] = arr2.a[j++];
    }

    cout << "Merged array: ";
    for (int x = 0; x < arr3.length; x++) {
        cout << arr3.a[x] << " ";
    }
    cout << endl;
}

void Union(const struct array &arr1, const struct array &arr2) {
    struct array arr3;
    arr3.size = arr1.size + arr2.size;
    arr3.length = 0; 

    int i = 0, j = 0, k = 0;

    while (i < arr1.length && j < arr2.length) {
        if (arr1.a[i] < arr2.a[j]) {
            arr3.a[k++] = arr1.a[i++];
        } else if (arr1.a[i] > arr2.a[j]) {
            arr3.a[k++] = arr2.a[j++];
        } else {
            arr3.a[k++] = arr1.a[i++];
            j++;
        }
        arr3.length++; 
    }

    while (i < arr1.length) {
        arr3.a[k++] = arr1.a[i++];
        arr3.length++;
    }

    while (j < arr2.length) {
        arr3.a[k++] = arr2.a[j++];
        arr3.length++;
    }

    cout << "Union array: ";
    for (int x = 0; x < arr3.length; x++) {
        cout << arr3.a[x] << " ";
    }
    cout << endl;
}

void Intersection(const struct array &arr1, const struct array &arr2) {
    struct array arr3;
    arr3.size = min(arr1.size, arr2.size);
    arr3.length = 0;

    int i = 0, j = 0, k = 0;

    while (i < arr1.length && j < arr2.length) {
        if (arr1.a[i] < arr2.a[j]) {
            i++;
        } else if (arr1.a[i] > arr2.a[j]) {
            j++;
        } else {
            arr3.a[k++] = arr1.a[i++];
            j++;
            arr3.length++;
        }
    }

    cout << "Intersection array: ";
    for (int x = 0; x < arr3.length; x++) {
        cout << arr3.a[x] << " ";
    }
    cout << endl;
}

// int main(){
//     struct array arr1;
//     int ch;
//     // arr1.size

//     cout<<"1. Insert"<<endl;
//     cout<<"2. Delete"<<endl;
//     cout<<"3. Append"<<endl;
//     cout<<"4. Linear Search"<<endl;
//     cout<<"5. Binary Search"<<endl;
//     cout<<"6. Merge 2 array"<<endl;
//     cout<<"7. Get"<<endl;
//     cout<<"8. Set"<<endl;
//     cout<<"9. Sorted Insertion"<<endl;
//     cout<<"10. Reverse Method 1"<<endl;
//     cout<<"11. Reverse Method 2"<<endl;
//     cout<<"12. Intersection"<<endl;
//     cout<<"13. Union"<<endl;
// }

int main() {
    struct array arr1 = {{2, 3, 4, 5, 6, 7}, 20, 6};
    struct array arr2 = {{2, 7, 10, 11, 15, 20}, 20, 6};
    mergeArray(arr1, arr2);
    Union(arr1, arr2);
    Intersection(arr1, arr2);
    arr1.append(10);
    append(arr1, 100);
    insert(arr1, 4, 8);
    arr1.insert(7, 11);
    del(arr1, 5);
    int x = linearSearch(arr1, 8);
    cout << "Element found at " << x << " using linear search" << endl;
    int y = binarySearch(arr1, 10);
    cout << "Element found at " << y << " using binary search" << endl;
    get(arr1, 2);
    arr1.get(6);
    // set(arr1, 7, 34);
    arr1.display();
    display(arr1);
    arr1.sortedInsertion(15);
    arr1.reverseM1();
    arr1.reverseM2();

    return 0;
}
