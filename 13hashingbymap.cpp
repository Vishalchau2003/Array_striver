
#include<bits/stdc++.h>
using namespace std;
int main(){
    
   int n;
   cout<<"enter the size of array"<<endl;
   cin>>n;
   int arr[n];
   cout<<"enter array elements"<<endl;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
    // unordered_map<int,int>mpp;
   map<int,int>mpp;
    for(int i=0;i<n;i++){ 
        mpp[arr[i]]++;
    }
         int q;
    cout<<"enter for how many number you want to check its occurance"<<endl;
    cin>>q;
    cout<<"enter the number"<<endl;
    while(q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
        //mpp[number] will give the number of times it is appearing in or the value of map
        
       
    }


    return 0;
}