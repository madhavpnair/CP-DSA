class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        for(int i=0;i<=n;i++)xor_all ^= i;
        for(int i=0;i<n;i++)xor_all ^= nums[i];
        return xor_all;
    }
};

// alternative approach is to use the formula n*(n+1)/2 
// to get the sum of first n natural numbers and then subtract the sum of all elements in the input array from it 
// to get the missing number. 
// This approach also has O(n) time complexity and O(1) space complexity, 
// but it may cause integer overflow for large values of n. The XOR approach does not have this issue.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum_all = n*(n+1)/2;
        int sum_input = 0;
        for(int i=0;i<n;i++)sum_input += nums[i];
        return sum_all - sum_input;
    }
};