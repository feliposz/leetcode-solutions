class Solution
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        return sortArray(nums, 0, nums.size() - 1);
    }

    vector<int> sortArray(vector<int>& nums, int a, int b)
    {
        vector<int> result;
        if ((a < b) && (a >= 0) && (b < nums.size()))
        {
            int mid = (a + b) / 2;
            vector<int> x = sortArray(nums, a, mid);
            vector<int> y = sortArray(nums, mid+1, b);

            int i = 0, j = 0;
            while ((i < x.size()) && (j < y.size()))
            {
                if (x[i] < y[j])
                {
                    result.push_back(x[i++]);
                }
                else
                {
                    result.push_back(y[j++]);
                }
            }
            while (i < x.size())
            {
                result.push_back(x[i++]);
            }
            while (j < y.size())
            {
                result.push_back(y[j++]);
            }
        }
        else if (a == b)
        {
            result.push_back(nums[a]);
        }
        return result;
    }
};