#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int> &arr, int s, int e)
{
     int mid = s + (e-s)/2;

     int len1 = mid - s + 1;
     int len2 = e - mid;

     //creating dynamic memory(heap)
     int *first = new int[len1];
     int *second = new int[len2];


     //copy left array
     int mainArrayIndex = s;
     for(int i = 0; i < len1; i++){
        first[i] = arr[mainArrayIndex++];
     }

     //copy right array
     mainArrayIndex = mid + 1;
     for(int i = 0; i < len2; i++){
        second[i] = arr[mainArrayIndex++];
     }

     //merge 2 sorted array
     int index1 = 0, index2 = 0, counter = 0;
     mainArrayIndex = s;

     while(index1 < len1){
        if(first[index1] > second[index2]){
            counter++;
            cout<<"( "<<first[index1] <<", " <<second[index2] <<" )"<<endl;
        }

        index2++;

        if(index2 == len2){
            index2 = 0;
            index1++;
        }
     }

     //delete the dynamic memory(heap) created by us
     delete[] first;
     delete[] second;
}

void mergeSort(vector<int> &arr, int s, int e)
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
    vector<int> arr = {1,20,6,4,5};

    mergeSort(arr, 0, arr.size() - 1);

    return 0;
}

