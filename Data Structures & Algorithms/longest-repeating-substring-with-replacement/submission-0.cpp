class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int l=0, r=0, maxLen=0, maxFreq=0;
        while(r<s.length()){
            freq[s[r]-'A']++;
            maxFreq=max(maxFreq, freq[s[r]-'A']);
            while((r-l+1)-maxFreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxLen=max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};