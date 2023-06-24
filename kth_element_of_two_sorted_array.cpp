#include <iostream>
#include <vector>
using namespace std;

int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int m, int n, int k)
{

    if (n > m)
    {
        return ninjaAndLadoos(arr2, arr1, n, m, k);
    }

    // if (k == (m + n))
    // {
    //     return max(arr1[m - 1], arr2[n - 1]);
    // }

    int l1, l2, r1, r2;

    int left1, left2, right1, right2;

    int low = 0;
    int high = m;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        cout << low << "  " << mid << "  " << high << endl;

        while (k < mid)
        {
            high = mid;
            mid = low + (high - low) / 2;
        }

        while ((k - mid) > n)
        {
            low = mid + 1;
            mid = low + (high - low) / 2;
        }

        l1 = mid - 1;
        r1 = mid;
        l2 = k - r1 - 1;
        r2 = l2 + 1;

        if (l1 <= -1)
        {
            left1 = INT_MIN;
        }
        else
        {
            left1 = arr1[l1];
        }

        if (l2 <= -1)
        {
            left2 = INT_MIN;
        }
        else
        {
            left2 = arr2[l2];
        }

        if (r1 >= m)
        {
            right1 = INT_MAX;
        }
        else
        {
            right1 = arr1[r1];
        }

        if (r2 >= n)
        {
            right2 = INT_MAX;
        }
        else
        {
            right2 = arr2[r2];
        }

        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = mid;
        }
        else if (left2 > right1)
        {
            low = mid + 1;
        }
    }

    return -1;

    // int i = 0;
    // int j = 0;
    // int count = 0;
    // int value = -1;
    // while(i < m && j < n){
    //     if(count == k){
    //         break;
    //     }
    //     if(arr1[i] < arr2[j]){
    //         value = arr1[i];
    //         i++;
    //         count++;
    //     }else{
    //         value = arr2[j];
    //         j++;
    //         count++;
    //     }
    // }

    // while(i < m){
    //     if(count == k){
    //         break;
    //     }
    //     value = arr1[i];
    //     i++;
    //     count++;
    // }
    // while(j < n){
    //     if(count == k){
    //         break;
    //     }
    //     value = arr2[j];
    //     j++;
    //     count++;
    // }

    // return value;
}

int main()
{
    // Test the ninjaAndLadoos function

    // Create sample input arrays
    vector<int> arr1 = {1, 3, 5, 7, 9, 11};
    // vector<int> arr1 = {1, 10, 10, 25, 40, 54, 79};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    // vector<int> arr2 = {15, 24, 27, 32, 33, 39, 48, 68, 82, 88, 90};

    int m = arr1.size();
    int n = arr2.size();
    // int k = 10;

    for (int i = 1; i <= m + n; i++)
    {
        // Call the function
        int result = ninjaAndLadoos(arr1, arr2, m, n, i);

        // Display the result
        cout << "Result: " << result << endl;
    }

    // int result = ninjaAndLadoos(arr1, arr2, m, n, k);
    // cout << "Result: " << result << endl;

    return 0;
}
