#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        double *arr = new double[a.size() + b.size()];
        int i = 0, j = 0, k = 0;

        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                arr[k++] = a[i++];
            }
            else{
                arr[k++] = b[j++];
            }
        }

        while(i < a.size()){
            arr[k++] = a[i++];
        }
        while(j < b.size()){
            arr[k++] = b[j++];
        }

        double n = a.size() + b.size();
        if( (a.size() + b.size()) % 2 == 0){
            int even = n / 2;
            double median = (arr[even-1] + arr[even]) / 2;
            delete[] arr;
            return median;
        }
        else{
            int odd = n / 2.000;
            double median = arr[odd];
            delete[] arr;
            return median;
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {34,54,67,94,123};
    vector<int> arr2 = {1,24,77,99,100};
    cout<<s.findMedianSortedArrays(arr1, arr2);

    /*cout<<endl;
    for(auto i = arr1.end()-1; i != arr1.begin()-1; i--){
        cout<<*i<<endl;
    }*/

    return 0;
}
