#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstNonRepeating(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    
    for (int num : nums) {
        freqMap[num]++;
    }
    
    for (int num : nums) {
        if (freqMap[num] == 1) {
            return num;
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    
    int result = firstNonRepeating(nums);
    
    if (result != -1) {
        cout << "First non-repeating element: " << result << endl;
    } else {
        cout << "No non-repeating element found" << endl;
    }
    
    return 0;
}