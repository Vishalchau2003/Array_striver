

// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cout<<"enter the value of n";
//     cin>>n;
//     int arr[n];
//     cout<<"enter array elements";
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int xor1=0;
//     int xor2=0;
//     for(int i=0;i<n;i++){
//      xor1^=arr[i];
//      xor2^=(i+1);
//     }
//     int xorans=0;
//     xorans=xor1^xor2;
//     cout<<xorans;
//     return 0;
// }

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;
//     int arr[n];
//     cout << "Enter the array elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int low=0;
//     int mid=0;
//     int high=n-1;
//     while(mid<=high){
//         if(arr[mid]==0){
//           swap(arr[mid],arr[low]);
//           low++;
//           mid++;
//         }
//         else if(arr[mid]==1){
//            mid++;
//         }
//         else{
//            swap(arr[high],arr[mid]);
//            high--;
//         }
//     }

//     cout << "sorted array elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i];
//     }
//     return 0;

// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//       int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;
//     int arr[n];
//     cout << "Enter the array elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     if(arr[0]>arr[1]){
//         return arr[0];
//     }
//     if(arr[n-1]>arr[n-2]){
//         return arr[n-1];
//     }
//     for(int i=1;i<n-1;i++){

//         if(arr[i]>arr[i+1]&&arr[i]>arr[i-1]){
//             return arr[i];
//         }
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//       int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;
//     int arr[n];
//     cout << "Enter the array elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int k;
//     cout<<"enter the given sum";
//     cin>>k;
//    int i=0;
//    int j=n-1;
//    int sum=0;
//    while(i<j){
//      sum=arr[i]+arr[j];
//      if(sum==k){
//         return {arr[i],arr[j]};
//      }
//      if(sum>k){
//         j--;
//      }
//      else{
//        i++;
//      }
//    }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    return 0;
    int n, m;
    cout << "enter rows and columns";
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> spiral(n, vector<int>(m));
    int left = 0;
    int right = m - 1;
    int top = 0;
    int bottom = n - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            spiral.push_back(arr[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            spiral.push_back(arr[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                spiral.push_back(arr[bottom][i]);
            }

            bottom--;
        }
        if(left <= right)
        {
            for (int i = bottom; i <= top; i--)
            {
                spiral.push_back(arr[i][left]);
            }
            left++;
        }
    }
}