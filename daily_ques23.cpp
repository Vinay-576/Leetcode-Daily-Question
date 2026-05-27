class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);
        
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] >= 'a' && word[i] <= 'z') {
                lastLower[word[i] - 'a'] = i;
            } else if (word[i] >= 'A' && word[i] <= 'Z') {
                if (firstUpper[word[i] - 'A'] == -1) {
                    firstUpper[word[i] - 'A'] = i;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) {
                count++;
            }
        }
        
        return count;
    }
};
