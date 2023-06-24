#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    long long int low = 1;
    long long int high = stalls[n-1]-stalls[0];

    while(low <= high){
        long long int mid = low + (high-low)/2;

        // now we will see that keeping a minimal distance of mid can we place k cows on the stalls or not
        // if we cannot than we reduce the distance by high = mid-1
        // if we can then we will find the maximum possible value of this distance by low = mid+1

        int count = 1;
        int track = 0;
        for(int i = 1; i < n; i++){
            if(count == k){
                break;
            }

            if((stalls[i] - stalls[track]) >= mid){
                track = i;
                count++;
            }
        }

        if(count >= k){
            low = mid+1;
        }
        else if(count < k){
            high =  mid-1;
        }

    }

    return high;
    
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        int c;
        cin >> n >> c;
        vector<int> stalls(n);
        for(int i = 0; i < n; i++){
            cin >> stalls[i];
        }
        
        cout << aggressiveCows(stalls, c) << endl;
    }
}