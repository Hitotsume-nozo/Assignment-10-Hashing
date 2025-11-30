#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void countFrequency(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    
    for (int num : nums) {
        freqMap[num]++;
    }
    
    cout << "Frequency count:" << endl;
    for (auto& pair : freqMap) {
        cout << pair.first << " -> " << pair.second << " times" << endl;
    }
}

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    
    countFrequency(nums);
    
    return 0;
}