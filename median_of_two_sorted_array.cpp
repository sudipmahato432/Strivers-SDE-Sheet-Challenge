#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the double median using binary search approach

// Code for calculating the double median goes here

double median(vector<int> &nums1, vector<int> &nums2)
{
    // Write your code here.
    // Approach 3 (Applying binary search)

    int n = nums1.size();
    int m = nums2.size();

    if(n == 0 && m == 0){
        return 0.0;
    }

    if(m > n){
        return median(nums2,nums1);
    }

    int elementsInLeftSide = (n+m)/2 + 1;

    int low = 0;
    int high = n;
    while( low <= high){
        int cut1 = low + (high-low)/2;
        int cut2 = elementsInLeftSide - cut1;

        while(cut2 > m){
            low = cut1+1;
            cut1 = low + (high-low)/2;
            cut2 = elementsInLeftSide - cut1;
        }

        while (cut2 < 0)
        {
            high = cut1-1;
            cut1 = low + (high-low)/2;
            cut2 = elementsInLeftSide - cut1;
        }

        int l1,l2,r1,r2;

        (cut1 == 0) ? l1 = INT_MIN : l1 = nums1[cut1-1];

        (cut1 == n) ? r1 = INT_MAX : r1 = nums1[cut1];

        (cut2 == 0) ? l2 = INT_MIN : l2 = nums2[cut2-1];

        (cut2 == m) ? r2 = INT_MAX : r2 = nums2[cut2];

        cout << cut1 << " " << cut2 << endl;
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;

        if(l1 <= r2 && l2 <= r1){
            if((n+m)%2 == 0){
                int element1;
                int element2;

                if(l1 > l2){
                    element1 = l1;
                    if(cut1-2 >= 0){
                        element2 = max(l2,nums1[cut1-2]);
                    }else{
                        element2 = l2;
                    }
                }
                else{
                    element1 = l2;
                    if(cut2-2 >= 0){
                        element2 = max(l1,nums2[cut2-2]);
                    }else{
                        element2 = l1;
                    }
                }

                return (element1+element2)/2.0;     
            }
            else{
                return max(l1,l2)/1.0;
            }
        }

        else if(l1 > r2){
            high = cut1 -1;
        }
        else{
            low = cut1+1;
        }

    }

    return 0.0;
}

int main()
{
    // Test case 1
    vector<int> nums1 = {1,4};
    vector<int> nums2 = {2,3};
    double result = median(nums1, nums2);
    cout << "Double Median: " << result << endl;

    // Test case 2
    vector<int> nums3 = {4};
    vector<int> nums4 = {1,2,3,5,6};
    double result2 = median(nums3, nums4);
    cout << "Double Median: " << result2 << endl;

    // Test case 3
    vector<int> nums5 = {1,2};
    vector<int> nums6 = {3,4,5,6};
    double result3 = median(nums5, nums6);
    cout << "Double Median: " << result3 << endl;

    // Add more test cases as needed

    return 0;
}
