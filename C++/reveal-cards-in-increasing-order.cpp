class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        
        queue<int> index;
        int sz = deck.size();
        for (int i = 0; i < sz; i++) {
            index.push(i);
        }
        
        vector<int> ans(sz);
        for (int card: deck) {
            ans[index.front()] = card;
            index.pop();
            if (!index.empty()) {
                index.push(index.front());
                index.pop();
            }
        }
        
        return ans;
    }
};