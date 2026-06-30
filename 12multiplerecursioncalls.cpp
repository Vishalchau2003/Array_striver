//*************nth term of fibonacci****************//

#include <iostream>
using namespace std;
int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    //or just simply write
    // if(n<=1){
    //     return n;
    // }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}
int main()
{
    int n;
    cout << "enter the nth fibonacci term that you want" << endl;
    cin >> n;

    cout << fibo(n);
    return 0;
}


//*************1 to n of fibonacci****************//

// #include <iostream>
// using namespace std;
// int fibo(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     else if (n == 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return fibo(n - 1) + fibo(n - 2);
//     }
// }
// int main()
// {
//     int n;
//     cout << "enter till which term you want your fibonacci series" << endl;
//     cin >> n;

//     cout <<"fibonacci series till n is "<<endl;
//     for(int i=0;i<n;i++){
//         cout<<fibo(i)<<" ";

//     }
//     return 0;
// }