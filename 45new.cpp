#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* left;
  node* right;
  node(int val){
    data=val;
    left=nullptr;
    right=nullptr;
  }
};
node* build(vector<int>&v,int i,int n){
    node* root=new node(v[i]);

    root->left=build(v,2*i+1,n);
    root->right=build(v,2*i+2,n);

    return root;

}
int main() {
    int n;
    cout<<"enter the value of n";
    cin>>n;
    cout<<"enter array";
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
    cin>>v[i];
    }

    node*head=build(v,0,n);
  


    return 0;
}
