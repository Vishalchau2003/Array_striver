// #include<iostream>
// using namespace std;
// printname(){
//     cout<<"vishal"<<endl;
// }
// int main(){

// printname();
// printname();
// printname();
// printname();
// printname();
//     return 0;
// }
//or
#include<iostream>
using namespace std;
void printname(int i , int n){
    
    if(i>n){
        return;
    }
    cout<<"vishal"<<endl; 
    printname(i+1,n);
    
}
int main(){
int n;
cout<<"enter number of times you want to print"<<endl;
cin>>n;
printname(1,n);
    return 0;
}

//or
// #include<iostream>
// using namespace std;
//  void printname(int count){
//     if(count==0){
//         return;
//     }
//     cout<<"vishal"<<endl;
//     printname(count-1);
// }
// int main(){
//     int count;
// cout<<"enter the n"<<endl;
// cin>>count;
// printname(count);
//     return 0;
// }