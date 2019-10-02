/*

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

*/

#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << "]";
}

void printMatrix(vector<vector<int>>& m) {
    cout << "[";
    for (int i = 0; i < m.size(); i++) {
        printVector(m[i]);
        if (i != m.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

// This problem is an evolution to the Two Sum problem, but in this
// case, since we have to check 3 numbers, we need to have one fixed point while we
// check the other two elements to find our triplets. That way the complexity will be
// at least O(n^2), but we can't do any better unless we use really obscure algorithms 
// to improve that. The study of an improvement for the time complexity of 3Sum is a subject
// still being researched in Computer Science so we will keep ourselves to a O(n^2) solution.
// Knowing that, we can sort our array, since this operation will take O(n log n), we don't 
// need to worry about it affecting the overall time complexity. This way we can prevent
// duplicates easily. We just need to fix one point and check if the next two numbers which
// should be equal or bigger than said number are already bigger than 0, so we can't possibly
// find a pair, breaking out of our loop, or if the fixed number plus the last two are smaller
// than 0, so we need to move our fixed point. These optimizations, although small, can help 
// us improve our real time performance. After that we just set a window with two elements at
// the extremes and then we start checking if we arrive in our target, moving our left and right
// accordingly. When we find a triplet, we should also move our left and right until they are in
// a different element they were before, to avoid duplicates.
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> answer;
    if (nums.size() < 3) return answer;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        if ((nums[i] + nums[i+1] + nums[i+2]) > 0) break;
        if ((nums[i] + nums[n-2] + nums[n-1]) < 0) continue;

        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                answer.push_back({nums[i], nums[left], nums[right]});
                do {
                    left++;
                } while (left < right && nums[left - 1] == nums[left]);
                do {
                    right--;
                } while (left < right && nums[right + 1] == nums[right]);
            }
        }
    }

    return answer;
}

int main() {
    // Read input
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    // Write output
    auto answer = threeSum(v);
    printMatrix(answer);

    return 0;
}
