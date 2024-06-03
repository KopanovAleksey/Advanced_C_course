#include <stdio.h>
#include <string.h>

#define SIZE 1000

void zFunction2 (char *s, int z[]) {
    int n = strlen(s);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
        z[i] = (r-i+1) > (z[i-l]) ? (z[i-l]) : (r-i+1);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i, r = i+z[i]-1;
    }
}

int findMaxSuff(char *str1, char *str2){
    char s[SIZE + SIZE] = {0};
    int z[SIZE + SIZE] = {0};
    sprintf(s, "%s#%s", str1, str2);
    zFunction2(s, z);
    int sLen = strlen(s);
    int str1Len = strlen(str1);
    int str2Len = strlen(str2);
    int minLen = (str1Len < str2Len ? str1Len : str2Len);
    int maxIn = 0;
    for (int i = 0; i < sLen; i++)
    {
        printf("%d ", z[i]);
    }
    printf("\n");
    
    for (int i = 0; i < minLen; i++)
    {
        if(z[sLen - minLen + i ] == minLen - i){
            maxIn = z[sLen - minLen + i];
            break;
        }
    }
    return maxIn;
}


int main(int argc, char const *argv[])
{
    char str1[100] = "nick_is_a_mastodon";
    char str2[100] = "don't_panic";
    
    printf("Max = %d\n", findMaxSuff(str1, str2));
    printf("Max = %d\n", findMaxSuff(str2, str1));
    return 0;
}