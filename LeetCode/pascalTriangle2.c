#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *ans = NULL;
    *returnSize = rowIndex + 1;
    ans = (int *) malloc (sizeof(int) * (rowIndex + 1));

    ans[0] = 1;
    if (rowIndex == 0 ) {
        return ans;
    }
    
    ans[1] = 1;
    if (rowIndex == 1) {
        return ans;
    }

    for ( int i = 2; i <= rowIndex; i++) {
        int prev = ans[0];
        for ( int j = 1; j <= i; j++) {
            int temp =  prev + ans[j];
            prev = ans[j];
            ans[j] = temp;
        }
        ans[i] = 1;
    }
    return ans;    
}