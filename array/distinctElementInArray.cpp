// C++ program to count distinct elements
// in a given array
#include <iostream>
using namespace std;

//**********************************************************Time Complexity: O(n2)*****************************************************************************

int countDistinct(int arr[], int n)
{
	int res = 1;

	// Pick all elements one by one
	for (int i = 1; i < n; i++) {
		int j = 0;
		for (j = 0; j < i; j++){
			if (arr[i] == arr[j])
				break;
		}

		// If not printed earlier, then print it
		if (i == j)
			res++;
	}
	return res;
}




//**********************************************************Time Complexity: O(nLogn)*****************************************************************************

#include <algorithm>
#include <iostream>
using namespace std;

int countDistinct(int arr[], int n)
{
    // First sort the array so that all
    // occurrences become consecutive
    sort(arr, arr + n);

    // Traverse the sorted array
    int res = 0;
    for (int i = 0; i < n; i++) {

        // Move the index ahead while
        // there are duplicates
        while (i < n - 1 && arr[i] == arr[i + 1])
            i++;

        res++;
    }

    return res;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1,2,1,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countDistinct(arr, n);
	return 0;
}

