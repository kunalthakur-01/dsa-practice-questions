#include <iostream>
#include <vector>
using namespace std;


void merge(vector<vector<int>> &arr, int s, int e)
{
     int mid = s + (e-s)/2;

     int len1 = mid - s + 1;
     int len2 = e - mid;

     //creating dynamic memory(heap)
     int first[len1][2];
     int second[len2][2];
     /*int *first = new int[len1 * 2];
     int *second = new int[len2 * 2];*/


     //copy left array
     int mainArrayIndex = s;
     for(int i = 0; i < len1; i++){
        for(int j = 0; j < 2; j++){
            first[i][j] = arr[mainArrayIndex][j];
        }
        mainArrayIndex++;
     }

     //copy right array
     mainArrayIndex = mid + 1;
     for(int i = 0; i < len2; i++){
        for(int j = 0; j < 2; j++){
            second[i][j] = arr[mainArrayIndex][j];
        }
        mainArrayIndex++;
     }

     //merge 2 sorted array
     int index1 = 0, index2 = 0;
     mainArrayIndex = s;

     while(index1 < len1 && index2 < len2){
            cout<<first[index1][0]<<endl;
        if(first[index1][1] > second[index2][0]){
            arr[mainArrayIndex++] = {first[index1++][0], second[index2++][1]};
        }
        else{
            mainArrayIndex++;
        }
     }



    /* while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
     }

     while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
     }

     //delete the dynamic memory(heap) created by us
     delete[] first;
     delete[] second;*/
}

void mergeSort(vector<vector<int>> &arr, int s, int e)
{
    //base condition
    if(s >= e){
        return;
    }

    //calculating mid
    int mid = s + (e-s)/2;

    //sort left array
    mergeSort(arr, s, mid);

    //sort right array
    mergeSort(arr, mid+1, e);

    //merge left and right array
    merge(arr, s, e);

}

int main()
{
    vector<vector<int>> arr = {{1,3}, {2,6}, {8,10} ,{15,18}};

    mergeSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++){
            for(int j= 0; j < 2; j++){
                cout << arr[i][j] << " ";
            }
            cout<<endl;
    }

    return 0;
}

