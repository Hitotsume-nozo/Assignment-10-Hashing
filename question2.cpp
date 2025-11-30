#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findCommon(vector<int>& A, vector<int>& B) {
    unordered_set<int> setA(A.begin(), A.end());
    vector<int> common;
    
    for (int num : B) {
        if (setA.find(num) != setA.end()) {
            common.push_back(num);
            setA.erase(num);
        }
    }
    
    return common;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    
    vector<int> result = findCommon(A, B);
    
    cout << "Common elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}