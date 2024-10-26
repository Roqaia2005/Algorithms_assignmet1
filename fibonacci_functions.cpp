#include <iostream>
# define ll long long
using namespace std;

// implement fibonacci function using recursion ---->//Done

int Fib(int n) {
    if (n <= 1) {
        return n;
    }
    return Fib(n - 1) + Fib(n - 2);
}


// implement fibonacci function using divide and conquer (martix multiplication)
//f(n)=f(n-1)+f(n-2)

 
/* 
 * function to multiply two matrices
 */

/*
 matrix A   
 [a00 , a01]
 [a10 , a11]

matrix B 
 [b00 b01]
 [b10 b11]


 A*B
 result 
 [x y]
 [z w]

 [a00*b00+a01*b10   a00*b01+a01*b11]
 [a10*b00+a11*b10   a10*b01+a11*b11]

*/
void multiply(ll A[2][2], ll B[2][2])
{
    ll x =  A[0][0] * B[0][0] + A[0][1] * B[1][0];
    ll y =  A[0][0] * B[0][1] + A[0][1] * B[1][1];
    ll z =  A[1][0] * B[0][0] + A[1][1] * B[1][0];
    ll w =  B[1][0] * B[0][1] + A[1][1] * B[1][1];
    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

// function to calculate the power of matrix

void power(ll A[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1,1},{1,0}};
    // M 
    //[1,1]
    //[1,0]
    power(A, n / 2);
    multiply(A, A);// A power n/2 * A power n/2 = > A power n
    if (n % 2 != 0)
        multiply(A, M);
}

// function to return nth fobonacci number

ll fibonacci_matrix(ll n)
{
    ll A[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(A, n - 1);
    return A[0][0];
}



// implement fibonacci function using dynamic programming 

// write function here 



// test your function in main ,good luck fatima and nada :-)

int main(){

    ll n;
    cin>>n;
 
    // Test recursive Fibonacci
    cout <<  "Recursive Fibonacci: " << Fib(n) << endl;
   // Test Multiplication Fibonacci
    cout<< "Matrix Multiplication Fibonacci: " << fibonacci_matrix(n) << endl;

    return 0;
}
