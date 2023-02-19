#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void merge(vector<int> &nums, int s, int e)
    {
        int mid = s + (e - s) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        int mainArrayIndex = s;

        for (int i = 0; i < len1; i++)
        {
            first[i] = nums[mainArrayIndex++];
        }

        for (int i = 0; i < len1; i++)
        {
            second[i] = nums[mainArrayIndex++];
        }

        int i = 0, j = 0;
        mainArrayIndex = s;

        while (i < len1 && j < len2)
        {
            if (first[i] < second[j])
            {
                nums[mainArrayIndex++] = first[i++];
            }
            else
            {
                nums[mainArrayIndex++] = second[j++];
            }
        }

        while (i < len1)
        {
            nums[mainArrayIndex++] = first[i++];
        }
        while (j < len2)
        {
            nums[mainArrayIndex++] = second[j++];
        }

        delete []first;
        delete []second;
    }

    void mergeSort(vector<int> &nums, int s, int e)
    {
        if (s >= e)
        {
            return;
        }

        int mid = s + (e - s) / 2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);

        merge(nums, s, e);
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k){
        // mergeSort(nums, 0, nums.size() - 1);
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> temp;
        int counter = 0;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != nums[i + 1]){
                temp.push_back(make_pair(nums[i], counter+1));
                counter = 0;
                continue;
            }
            counter++;
        }

        vector<int> ans;
        int mostFrequentCount = 0;
        int mostFrequentCountNumb = 0;
        int flag = INT_MAX;

        for(int i = 0; i < k; i++){
            mostFrequentCount = 0; 
            mostFrequentCountNumb = 0;

            for(int j = 0; j < temp.size(); j++){
                if(temp[j].second > mostFrequentCount && temp[j].second < flag){
                    mostFrequentCount = temp[j].second; 
                    mostFrequentCountNumb = temp[j].first;
                }
            }
            ans.push_back(mostFrequentCountNumb);
            flag = mostFrequentCount;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1};
    vector<int> ans = s.topKFrequent(nums, 1);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}