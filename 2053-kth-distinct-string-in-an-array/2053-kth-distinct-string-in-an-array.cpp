class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_set<string> distinctStrings;
        unordered_set<string> duplicateStrings;
        for (auto& str : arr) {
            if (duplicateStrings.count(str)) {
                continue;
            }
            if (distinctStrings.count(str)) {
                distinctStrings.erase(str);
                duplicateStrings.insert(str);
            } else {
                distinctStrings.insert(str);
            }
        }
        for (auto& str : arr) {
            if (!duplicateStrings.count(str)) {
                k--;
            }
            if (k == 0) {
                return str;
            }
        }
        return "";
    }
};