// Distributing M items in a circle of size N starting from K-th position
// link: https://www.geeksforgeeks.org/distributing-m-items-circle-size-n-starting-k-th-position/

int lastPosition(int n, int m, int k)
{
    if(n==1) return 1;
    return ((k-1+m)%n);
}