#include<iostream>
using namespace std;

void printTheDiamond(int r, int c, int s)
{
	for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int startInnerRow = 0;
            int startInnerColumn = 0;
            int mid = s-1;
            int endir = (s*2) - 1;
            int counter = endir;
            while(startInnerRow  <= endir){


                while(startInnerColumn <= endir){

                    //printing e's(outside blank space)
                    if(startInnerColumn == 0 && startInnerRow == 0 || startInnerColumn == endir && startInnerRow == endir){
                        cout<<"e";
                    }
                    if(startInnerColumn == endir && startInnerRow == 0 || startInnerColumn == 0 && startInnerRow == endir){
                        cout<<"e";
                    }

                    //printing O's(blank space)
                    if(startInnerRow > 0 && startInnerRow < endir){
                        if(startInnerRow <= mid && startInnerColumn > (mid - startInnerRow) && startInnerColumn <= (mid + startInnerRow)){
                            cout<<"O";
                        }
                        if(startInnerRow > mid && startInnerColumn >= (startInnerRow - mid) && startInnerColumn <= ((endir-startInnerRow) + mid)){
                            cout<<"O";
                        }
                    }


                    //printing forward and backward slash
                    if(startInnerRow <= mid){
                        if(startInnerColumn == (mid - startInnerRow)){
                            cout<<"/";
                        }
                        if(startInnerColumn == (s + startInnerRow)){
                            cout<<"\\";
                        }
                    }

                    if(startInnerRow > mid){
                        if(startInnerColumn == (startInnerRow - s)){
                            cout<<"\\";
                        }
                        if(startInnerColumn == (counter)){
                            cout<<"/";
                            counter--;
                        }
                    }

                    cout<<" ";

                    startInnerColumn++;
                }


                startInnerColumn = 0;
                cout<<endl;

                startInnerRow ++;
            }
        }
        cout<<endl;
	}
}

int  main()
{
    printTheDiamond(1,1,2);

    return 0;
}
