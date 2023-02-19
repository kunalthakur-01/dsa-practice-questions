#include<iostream>
#include<math.h>
using namespace std;

int clumsyFactorial(int n)
{
    float res, total = 0;
    for(int j = n; j > 0; j = j - 4){
        res = j;
        if((j-1) > 0){
            res = j * (j-1);
        }
        if((j-2) > 0){
            res = res / (j-2);
        }
        if(total == 0){
            total = res - total;
        }
        if(j != n){
            total = total - res;
        }
        if((j-3) > 0){
            total = total + (j-3);
        }
    }
    cout<<total;
    return round(total);
}



          // or




int clumsy(int N) {

   	if (N == 1) return 1;
	if (N == 2) return 2;
	if (N == 3) return 6;
	if (N == 4) return 7;
	if (N % 4 == 1) return N + 2;
	if (N % 4 == 2) return N + 2;
	if (N % 4 == 3) return N - 1;
	return N + 1;

}


int main()
{
    int fact = clumsyFactorial(10);
    clumsy(10);

    return fact;
}
