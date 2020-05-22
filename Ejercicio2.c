/*

*/

long pow(int i, size_t n){
    if(n == 0)
        return 1;
    else
        return i * pow(i, n-1);
}