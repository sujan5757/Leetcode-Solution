class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int v) {
        vector<pair<int,int>>a;
        for(int i=0;i<reward1.size();i++){
            a.push_back({(reward1[i]-reward2[i]),i});      
        
    }
    sort ( a.begin(), a.end(), greater<pair<int,int>>());
    int max=0;
    for(int i=0;i<v;i++){
        max+=reward1[a[i].second];
    }
        for(int i=v;i<a.size();i++){
            max+=reward2[a[i].second];
            
            }
    return max;
    }

};
