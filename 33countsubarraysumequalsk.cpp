//*********BRUTE************//
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the size: ";
//     cin >> n;

//     // Declare the matrix
//     int arr[n]  ;
//     cout << "Enter the elements of the array:\n";
//     for (int i = 0; i < n; i++)
//     {

//         cin >> arr[i]; // Input the matrix elements
//     }
//     int k;
//     cout<<"enter the subarray sum k"<<endl;
//     cin>>k;
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum=0;
//             for(int k=i;k<=j;k++){
//                 sum=sum+arr[k];
//             }
//             //pura for loop jab over ho jayega then ye condition will get checked
//             if(sum==k){
//             cnt++;
//         }
//         }

//     }
//     cout<<cnt<<endl;

//     return 0;
// }

//*********BETTER************//
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the size: ";
//     cin >> n;

//     // Declare the matrix
//     int arr[n]  ;
//     cout << "Enter the elements of the array:\n";
//     for (int i = 0; i < n; i++)
//     {

//         cin >> arr[i]; // Input the matrix elements
//     }
//     int k;
//     cout<<"enter the subarray sum k"<<endl;
//     cin>>k;
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//         sum+=arr[j];
//         if(sum==k){
//             cnt++;
//         }
//         }
//         }

//     cout<<cnt<<endl;

//     return 0;
// }

// //*********OPTIMAL***********//
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "Enter the size: ";
//     cin >> n;

//     // Declare the matrix
//     int arr[n];
//     cout << "Enter the elements of the array:\n";
//     for (int i = 0; i < n; i++)
//     {

//         cin >> arr[i]; // Input the matrix elements
//     }
//     map<int, int> mpp;
//     mpp[0] = 1;
//     int presum = 0;
//     int cnt = 0;
//     int k;
//     cout << "enter the subarray sum k" << endl;
//     cin >> k;
//     for (int i = 0; i < n; i++)
//     {
//         presum += arr[i];
//         int remove = presum - k;
//         cnt += mpp[remove];
//         mpp[presum] += 1;//Add the current presum to the map or update its frequency.frequency means count
//     }
//     //remove = presum - k calculates the prefix sum needed to form a subarray with sum k
//     //If remove exists in the map, it means there exists at least one subarray ending at the current index i whose sum equals k
//     //cnt += mpp[remove] increments the count of valid subarrays by the frequency of the prefix sum remove


//     cout << cnt << endl;

//     return 0;
// }








// Approach 1: Without mpp[0] = 1 (Need Special Case) ///leetcode

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {

//         int n = nums.size();

//         // Stores: prefixSum -> frequency
//         map<int, int> mpp;

//         int sum = 0;
//         int cnt = 0;

//         for (int i = 0; i < n; i++) {

//             // Current Prefix Sum
//             sum += nums[i];

//             // ------------------------------
//             // Special Case:
//             // If the prefix sum itself equals k,
//             // then subarray [0...i] has sum = k.
//             // ------------------------------
//             if (sum == k)
//                 cnt++;

//             // We need a previous prefix sum = (sum - k)
//             // so that:
//             // currentPrefix - previousPrefix = k
//             int rem = sum - k;

//             // If such a prefix exists,
//             // all its occurrences form valid subarrays.
//             if (mpp.find(rem) != mpp.end()) {
//                 cnt += mpp[rem];
//             }

//             // Store current prefix sum
//             mpp[sum]++;
//         }

//         return cnt;
//     }
// };
// // Approach 2: Standard Prefix Sum Template (Recommended)
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {

//         int n = nums.size();

//         // Stores: prefixSum -> frequency
//         map<int, int> mpp;

//         // Imaginary prefix sum before index 0.
//         // This helps count subarrays starting from index 0.
//         mpp[0] = 1;

//         int sum = 0;
//         int cnt = 0;

//         for (int i = 0; i < n; i++) {

//             // Current Prefix Sum
//             sum += nums[i];

//             // We need a previous prefix sum = (sum - k)
//             int rem = sum - k;

//             // If found, every occurrence gives
//             // one valid subarray.
//             if (mpp.find(rem) != mpp.end()) {
//                 cnt += mpp[rem];
//             }

//             // Store current prefix sum
//             mpp[sum]++;
//         }

//         return cnt;
//     }
// };