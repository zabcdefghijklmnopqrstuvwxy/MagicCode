#include<bitset>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int bound = 40000;
        bitset<80000> result;
        result[bound] = 1;

        for(auto stone:stones)
        {
            result = result << stone | result >> stone;
        }

        for(int i = 0 ; i < 30001; i++)
        {
            if(result[bound + i])
            {
                return i;
            }
        }

        return 0;
    }
};
