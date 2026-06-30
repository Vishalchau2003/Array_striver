//*************************using 2 pointer l and r*********************//

// #include<iostream>
// using namespace std;
// void revarray(int l,int r,int n,int arr[]){
   
// if(l>=r){
//     return;
// }
// swap(arr[l],arr[r]);
// revarray(l+1,r-1,n,arr);
// }
// int main()
// {
//     int n, arr[100];
//     cout << "enter the size of the array" << endl;
//     cin>>n;
//     cout << "enter the array elements" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     revarray(0,n-1,n,arr);
//       cout << "array elements in reverse order " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i];
//     }
//     return 0;
// }

//using sinle pointer i
#include<iostream>
using namespace std;
void revarray(int i,int arr[],int n){
if(i>=n/2){
    return ;
}
swap(arr[i],arr[n-i-1]);
revarray(i+1,arr,n);
}
int main()
{
    int n;
    cout << "enter the size of the array" << endl;
    cin>>n;
    int arr[n];
    cout << "enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }
  revarray(0,arr,n);
        cout << "array elements in reverse order " << endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
    }
    return 0;
}

