//***********number hashing************//

// #include<iostream>
// using namespace std;

// int main(){
    
//     int n;
//     cout << "enter the size of the array" << endl;
//     cin>>n;
//     int arr[n];
//     cout << "enter the array elements" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i]; 
//     }
//     //precompute
//     int hash[13]={0};
//     ///assume all to be zero
//     for(int i=0;i<n;i++){
//         hash[arr[i]]+=1;
//     }

//     int q;
//     cout<<"enter for how many numbers you want to check its occurance"<<endl;
//     cin>>q;
//     cout<<"enter the numbers"<<endl;
//     while(q--){
//         int number;
//         cin>>number;  
//     //fetch
//     cout<<hash[number]<<endl;
//     }
//     return 0;
// }
//***********character hashing if we have just lowercase letters************//
// #include<iostream>
// using namespace std;

// int main(){
    
//    string s;
//    cout<<"input string"<<endl;
//    cin>>s;
//    int hash[26]={0};
//    for(int i=0;i<s.size();i++){
//     hash[s[i]-'a']++;
//     //ex=hash[5]++
//     //ex-if s[i]=b..so s[i]-a=1.....so hash[1] will be upgraded to 1 from zero
//    }
//      int q;
//     cout<<"enter for how many character you want to check its occurance"<<endl;
//     cin>>q;
//     cout<<"enter the characters"<<endl;
//     while(q--){
//         char c;
//         cin>>c;
//         cout<<hash[c-'a']<<endl;
//         //[c-'a'] represents index 
//         //hash[c-'a'] represents value of hash at that index
//     }

//     return 0;
// }


//***********character hashing for all characters************//
#include<iostream>
using namespace std;
int main(){
    
   string s;
   cout<<"input string"<<endl;
   cin>>s;
   int hash[256]={0};
   for(int i=0;i<s.size();i++){
    hash[s[i]]++;

   }
     int q;
    cout<<"enter for how many character you want to check its occurance"<<endl;
    cin>>q;
    cout<<"enter the characters"<<endl;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
       
    }

    return 0;
}

