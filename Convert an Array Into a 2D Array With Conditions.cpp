class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        map<int,int>mp;
        for(auto &i :nums)
        {
            mp[i]++;
        }
        vector<vector<int>>ab;
        while(!mp.empty())
        {
            vector<int> c;
            vector<int>arr;
            for(auto i:mp)
            {
                c.push_back(i.first);
                mp[i.first]--;
                if (mp[i.first]==0)
                {
                    arr.push_back(i.first);
                }
            }
            ab.push_back(c);
            for(auto &i : arr){
                mp.erase(i);
            }
        }
        return ab;
    }
};
