#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> arr, int target){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s) / 2;
    
    while(s <= e) {
        if(arr[mid][0] <= target && arr[mid][arr[mid].size() - 1] >= target){
            int start = 0;
            int end = arr[mid].size() - 1;
            int mid2 = start + (end - start) / 2;
            
            while(start <= end) {
                if(arr[mid][mid2] == target) {
                    return true;
                }
                
                if(arr[mid][mid2] < target){
                    start = mid2 + 1;
                }
                
                else{
                    end = mid2 - 1;
                }
                
                mid2 = start + (end - start) / 2;
            }
            
        }

        if(arr[mid][0] < target){
            s = mid + 1;
        }
        
        else {
            e = mid - 1;
        }
        
        mid = s + (e-s) / 2;
    }
    
    return false;
}

int main()
{
    vector<vector<int>> arr = { {1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    
    cout<< searchMatrix(arr, 16);
    return 0;
}