KMP (Knuth Morris Pratt) Algorithm
Detailed video explanation: https://youtu.be/klaWddXp0TM
=======================================


C++:
----

#include <iostream>
#include <vector>
using namespace std;

void KMP(string T, string P) { 
    int m = P.length(), n = T.length();
    vector<int> lps(m, 0);
    
    for(int i = 1; i < m; ++i){
        int j = lps[i-1];
        while(j > 0 && P[i] != P[j]) j = lps[j-1];
        if(P[i] == P[j]) j++;
        lps[i] = j;
    }
    
    int i = 0, j = 0;
    while(i < n){
        if(P[j] == T[i]){
            i++;
            j++;
        }
        if( j == m){
            cout << "Found pattern at index " << (i-j) << endl;
            j = lps[j-1];
        }
        else if(i < n && P[j] != T[i]){
            if(j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
} 

int main(){
    KMP("abababcabababcababac", "ababac"); 
   
   return 0;
}
