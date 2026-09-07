class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
    
    // 1. Count frequencies using a hash map
    std::unordered_map<int, int> counts;
    for (int num : nums) {
        counts[num]++;
    }

    // 2. Create buckets where index = frequency
    // Maximum possible frequency is n, so we need n + 1 buckets
    std::vector<std::vector<int>> buckets(n + 1);
    for (auto& pair : counts) {
        int element = pair.first;
        int frequency = pair.second;
        buckets[frequency].push_back(element);
    }

    // 3. Gather the top k elements by iterating backward from the highest frequency bucket
    std::vector<int> result;
    for (int i = n; i >= 0 && result.size() < k; --i) {
        if (!buckets[i].empty()) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
    }

    return result;
    }
};