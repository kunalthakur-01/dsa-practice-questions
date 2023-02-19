#include<iostream>
using namespace std;

int main(){
    int n,i,ins,pos,del;
    int arr[10];


    cout<<"enter the total numbers in list: ";
    cin>>n;


    cout<<"enter the numbers="<<endl;
    for(i = 1 ;i <= n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the number which you insert into the list:";
    cin>>ins;

    cout<<"Enter the position where you insert the list:";
    cin>>pos;

    for(i = n+1;i >= pos;i--){
        arr[i] = arr[i-1];

        if(pos == i){
            arr[i] = ins;
        }
    }

    cout<<"result is:"<<endl;
    for(i = 1 ;i <= n+1;i++){
        cout<<arr[i];
        cout<<endl;
    }

    cout<<endl<<sizeof(arr)/sizeof(arr[0]);



    //deletion of a number

    cout<<endl<<"enter the total numbers in list: ";
    cin>>n;


    cout<<"enter the numbers="<<endl;
    for(i = 1 ;i <= n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the position from where you delete the number:";
    cin>>pos;

    for(i = pos;i <= n;i++){
        arr[i] = arr[i+1];
    }

    cout<<"result is:"<<endl;
    for(i = 1 ;i <= n-1;i++){
        cout<<arr[i];
        cout<<endl;
    }



    return 0;

}
