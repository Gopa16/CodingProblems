#include <iostream>
#include<unordered_map>
using namespace std;

int charValue(char c) {
    return c - 'a' + 1;
}

int maxCyclicUniqueSubstringSum(string s) {
    int n = s.size();
    string doubled = s + s; 
    unordered_map<char,int> lastSeen;
    int left = 0, maxSum = 0, currSum = 0;

    for (int right = 0; right < doubled.size(); right++) {
        char c = doubled[right];
        currSum += charValue(c);

        while (lastSeen.count(c) && lastSeen[c] >= left || (right - left + 1) > n) {
            currSum -= charValue(doubled[left]);
            left++;
        }

        lastSeen[c] = right;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    string s;
    cin >> s;
    cout << maxCyclicUniqueSubstringSum(s) << endl;
    return 0;
}
