int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize = numRows;
    int** ans = (int**)  malloc (sizeof(int*) * numRows);
    *returnColumnSizes = (int*) malloc (sizeof(int) * numRows);

    for ( int i = 0; i < numRows; i++ ){
        ans[i] = (int*) malloc (sizeof(int) * numRows);
        (*returnColumnSizes)[i] = i+1;
        ans[i][i] = ans[i][0] = 1;

        for (int j = 1; j< i; j++){
            ans[i][j] =  ans[i-1][j-1] + ans[i-1] [j];
        }

    }
    return ans;
}