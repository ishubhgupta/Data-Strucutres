#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    // Creating an unordered_map which stores key-value pairs.
    // Keys are of type string, and values are of type int.
    unordered_map<string, int> m;

    // Inserting key-value pairs into the map using method 1 (make_pair and insert function)

    // Creating a pair using make_pair function and inserting it into the map.
    pair<string, int> p = make_pair("shubh", 6);
    m.insert(p);

    // Another way of creating and inserting a pair into the map using the constructor.
    pair<string, int> p2("gupta", 4);
    m.insert(p2);

    // Directly inserting a key-value pair using the [] operator.
    // If the key doesn't exist, a new key-value pair is created.
    m["great"] = 5;

    // Output the current size of the map (i.e., number of key-value pairs stored).
    cout << m.size() << endl;

    // Searching for a key and accessing its value using the [] operator.
    // If the key exists, it returns the associated value.
    cout << m["great"] << endl;

    // Searching for a key that does not exist.
    // When a non-existing key is accessed, it automatically inserts the key with a default value of 0.
    cout << m["unknown"] << endl;  // This will return 0 and add "unknown" to the map.

    // Accessing all key-value pairs using a range-based for loop.
    // 'x' is an element of the map (which is a pair) and x.first is the key, x.second is the value.
    for(auto x: m){
        cout << x.first << " " << x.second << endl;
    }

    // Using an iterator to iterate through the map.
    // An iterator is an object that points to an element in a container.
    unordered_map<string, int>::iterator it = m.begin();

    // Iterate through the map until we reach the end.
    // 'it->first' accesses the key and 'it->second' accesses the value.
    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;  // Move the iterator to the next element.
    }

    return 0;
}
