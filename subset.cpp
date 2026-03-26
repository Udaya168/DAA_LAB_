#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, vector<int>& current, int index) {
    if (index == nums.size()) {
        cout << "{ ";
        for (int x : current) cout << x << " ";
        cout << "}\n";
        return;
    }

    // Include element
    current.push_back(nums[index]);
    generateSubsets(nums, current, index + 1);

    // Exclude element
    current.pop_back();
    generateSubsets(nums, current, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> current;

    generateSubsets(nums, current, 0);
    return 0;
}