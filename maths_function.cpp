//COUNTdIVISORS
ull countDivisors(ull n)
{
    ull count=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0&&n/i==i)
            count++;
        else if(n%i==0)
            count+=2;
    }
    return count;
}
//iSPRIME
bool isPrime(ull n)
{
    ull c=0;
    if(n==1)
        return false;
    else
    {
        for(ull i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
    }
}
//BINARYeXPONENTIATION
//Using function recursion
int binaryExponentiation(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return binaryExponentiation(x*x,n/2);
    else                             //n is odd
        return x*binaryExponentiation(x*x,(n-1)/2);
}
//using iteration
int binaryExponentiation(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=result * x;
        x=x*x;
        n=n/2;
    }
    return result;
}

//PRIME_GENERATION
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    bool b[1000001];

    memset(b,true,1000001);
    b[1]= false;
    //prime number generation
    for(int p=2;p*p<=1000000;p++)
    {
        if(b[p]==true)
        {
            for(int i=p*p;i<=1000000;i+=p)
                b[i]=false;
        }
    }

}
//factorial modulo 10^9+3
ull fact(ull n)
{
    if(n==1 || n==0) return 1;
    return ((n%mod)*(fact(n-1)%mod)%mod);
}
//number of digits
ull numberOfDigits(ull a)
{
    a=(log10(a))+1;
    return a;
}
//hcf&lcm
ull findHcf(ull a,ull b)
{
    if(a<b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    else if(a==b)
        return a;
    while(b>0)
    {
        a=a%b;
        a=a+b;
        b=a-b;
        a=a-b;

    }
    return a;

}
int main()
{
    pace;
    ull t,n,k,hcf=0,lcm=1,p;
    //cout<<findHcf(2,3);
    cin>>t;
    while(t>0)
    {
        cin>>n;
        hcf=0,lcm=1;
        for(ull i=0;i<n;i++)
        {
            cin>>k;
            if(i==0) {
                hcf = k;
                lcm=k;
                //cout<<hcf<<endl;
            }
            else {
                hcf = findHcf(hcf, k);
                lcm = (lcm * k) / hcf;
                hcf=lcm;
            }
        }
        t--;
    }
    cout<<lcm;
}
//Sum of absolute differences of all pairs in a given SORTED array
int sumPairs(int arr[],int n)
{
    // final result
    int sum = 0;
    for (int i=n-1; i>=0; i--)
        sum += i*arr[i] - (n-1-i)*arr[i];
    return sum;
}
//prime factorization
vector<int> factorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}
//number of zeros in n!
#include <bits/stdc++.h>
using namespace std;
#define ull long long int
#define mod 1000003
#define pace ios::sync_with_stdio(false);cin.tie(0)

int main()
{
    pace;
    ull t,n,a,c=5;
    cin>>t;
    while(t>0)
    {
        c=5,a=0;
        cin>>n;
        while (n >=c ) {
            a=a+n/c;
            c*=5;
        }
        cout<<a<<endl;
        t--;
    }



}
// C++ code to find last digit of a^b
#include <bits/stdc++.h>
using namespace std;
 
// Function to find b % a
int Modulo(int a, char b[])
{
    // Initialize result
    int mod = 0;
 
    // calculating mod of b with a to make
    // b like 0 <= b < a
    for (int i = 0; i < strlen(b); i++)
        mod = (mod * 10 + b[i] - '0') % a;
 
    return mod; // return modulo
}
 
// function to find last digit of a^b
int LastDigit(char a[], char b[])
{
    int len_a = strlen(a), len_b = strlen(b);
 
    // if a and b both are 0
    if (len_a == 1 && len_b == 1 && b[0] == '0' && a[0] == '0')
        return 1;
 
    // if exponent is 0
    if (len_b == 1 && b[0] == '0')
        return 1;
 
    // if base is 0
    if (len_a == 1 && a[0] == '0')
        return 0;
 
    // if exponent is divisible by 4 that means last
    // digit will be pow(a, 4) % 10.
    // if exponent is not divisible by 4 that means last
    // digit will be pow(a, b%4) % 10
    int exp = (Modulo(4, b) == 0) ? 4 : Modulo(4, b);
 
    // Find last digit in 'a' and compute its exponent
    int res = pow(a[len_a - 1] - '0', exp);
 
    // Return last digit of result
    return res % 10;
}
