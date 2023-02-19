#include<iostream>
using namespace std;

void findMedian(int ma[], int k)
{
    float result;
    int median;
    if(k % 2 != 0){
        median = (k + 1) / 2;
        cout<<"median of odd="<<ma[median - 1];
    }
    else{
        median = k / 2;
        result = (ma[median - 1] + ma[median]) / 2.0;
        cout<<"median of even="<<result;
    }
}

int main()
{
    int m, n, i, j,temp;

    cout<<"enter the value of m:";
    cin>>m;

    cout<<"enter the value of n:";
    cin>>n;

    int nums1[m];
    int nums2[n];

    cout<<"enter the numbers in 1st array="<<endl;
    for(i = 0; i < m;i++){
        cin>>nums1[i];
    }

    cout<<"enter the numbers in 2nd array="<<endl;
    for(i = 0; i < n;i++){
        cin>>nums2[i];
    }

    int ma[m+n];


    //merge the two array
    for(i = 0;i < m+n;i++){
        if(i < m) {
            ma[i] = nums1[i];
        }
        else {
            ma[i] = nums2[i-m];
        }
    }


    //sort the array
    for(i = 0; i < m+n - 1;i++){
        if(ma[i] > ma[i+1]){
            temp = ma[i];
            ma[i] = ma[i+1];
            ma[i+1] = temp;
        }
    }



    //find the median
    findMedian(ma, m+n);

    return 0;

}

