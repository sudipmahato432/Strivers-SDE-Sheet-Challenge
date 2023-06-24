#include <iostream>
#include <vector>
using namespace std; 
void sort012(vector<int> &arr, int n)
{
   //   Write your code here
   int low=0,mid=0,high=n-1;
   while(mid <= high){
      if(arr[mid]==0){
         swap(arr[mid],arr[low]);
         low++;
         mid++;
      }
      else if(arr[mid]==1){
         mid++;
      }
      else if(arr[mid]==2){
         swap(arr[mid],arr[high]);
         high--;
      }
   }
}

void print(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main(){
   int T;
   cin >> T;
   while(T--){
      int n;
      cin >> n;
      vector<int> arr;
      for(int i = 0; i < n; i++){
        int temp;
         cin >> temp;
         arr.push_back(temp);
      }
      sort012(arr,n);
      print(arr);
   }

}