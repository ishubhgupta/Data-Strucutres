#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
        return false;
    }

    map<int, int> count;
    for (int card : hand) {
        count[card]++;
    }

    for (auto it = count.begin(); it != count.end(); ++it) {
        int card = it->first;
        int freq = it->second;

        if (freq == 0) continue;

        for (int i = 0; i < groupSize; ++i) {
            int nextCard = card + i;
            if (count[nextCard] < freq) {
                return false;
            }
            count[nextCard] -= freq;
        }
    }

    return true;
}


int main() {
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    bool result = isNStraightHand(hand, groupSize);
    cout << (result ? "true" : "false") << endl;
    return 0;
}