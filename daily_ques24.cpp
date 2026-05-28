class Solution {
    // Flat struct using integers instead of pointers to save memory
    struct Node {
        int child[26];
        int best_idx;
        
        Node(int idx) : best_idx(idx) {
            // Initialize all children to -1 (meaning no child exists)
            memset(child, -1, sizeof(child));
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        // Find the global best (shortest string in wordsContainer, then earliest index)
        int global_best = 0;
        for (int i = 1; i < wordsContainer.size(); ++i) {
            if (wordsContainer[i].length() < wordsContainer[global_best].length()) {
                global_best = i;
            }
        }
        
        // Use a vector to store Trie nodes contiguously
        vector<Node> trie;
        // Pre-allocate memory to avoid reallocations (up to 5 * 10^5 characters)
        trie.reserve(500005); 
        trie.emplace_back(global_best); // Root node is at index 0
        
        // Build the Trie
        for (int i = 0; i < wordsContainer.size(); ++i) {
            int curr = 0; // Start at root
            int len = wordsContainer[i].length();
            
            for (int j = len - 1; j >= 0; --j) {
                int idx = wordsContainer[i][j] - 'a';
                
                if (trie[curr].child[idx] == -1) {
                    // Create a new node and link it
                    trie[curr].child[idx] = trie.size();
                    trie.emplace_back(i);
                } else {
                    // Update best index if necessary
                    int next_node = trie[curr].child[idx];
                    int curr_best = trie[next_node].best_idx;
                    
                    if (len < wordsContainer[curr_best].length()) {
                        trie[next_node].best_idx = i;
                    }
                }
                // Move to the child node
                curr = trie[curr].child[idx];
            }
        }
        
        // Process queries
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& q : wordsQuery) {
            int curr = 0;
            for (int j = q.length() - 1; j >= 0; --j) {
                int idx = q[j] - 'a';
                if (trie[curr].child[idx] == -1) {
                    break; // No further match found
                }
                curr = trie[curr].child[idx];
            }
            ans.push_back(trie[curr].best_idx);
        }
        
        return ans;
    }
};
