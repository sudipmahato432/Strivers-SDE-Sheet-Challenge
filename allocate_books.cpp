#include <iostream>
#include <vector>

using namespace std;

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // if (n > m)
    // {
    //     return -1;
    // }

    int low = INT_MIN;
    int high = 0;

    for (int i = 0; i < m; i++)
    {
        if (time[i] > low)
        {
            low = time[i];
        }

        high += time[i];
    }

    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // now we will find that how many groups we can create by taking mid as the highest value
        // groups having sum of <= mid are allowed
        int numOfgroups = 1;
        int totalTime = 0;
        for (int i = 0; i < m; i++)
        {
            totalTime += time[i];

            if (totalTime > mid)
            {
                totalTime = time[i];
                numOfgroups++;
            }
        }

        if (numOfgroups == n)
        {
            // the mid value can be an answer
            // but we need the minimum value of margin that form this group

            result = mid;
            high = mid - 1;
        }
        else if (numOfgroups > n)
        {
            low = mid + 1;
        }
        else if (numOfgroups < n)
        {
            high = mid - 1;
        }
    }

    return max(result,low);
};

int main()
{
    // int n, m;
    // cout << "Enter the number of groups (n): ";
    // cin >> n;
    // cout << "Enter the number of elements in the time array (m): ";
    // cin >> m;

    // vector<int> time(m);
    // cout << "Enter the time values: ";
    // for (int i = 0; i < m; i++) {
    //     cin >> time[i];
    // }

    // long long result = ayushGivesNinjatest(n, m, time);

    int n = 5; // Number of groups
    int m = 5; // Number of elements in the time array

    vector<int> time = {2, 4, 1, 3, 5}; // Time values

    long long result = ayushGivesNinjatest(n, m, time);

    cout << "Minimum margin for creating " << n << " groups: " << result << endl;

    return 0;
}
