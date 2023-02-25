int removeDuplicates(int* nums, int numsSize){
    /*1. loop thru array and compare current element with next element
     2. if next is different, then it is unique; else, it's a duplicate.
     3. count the number of duplicates between this element and last 
        unique element 
     4. replace first instance of duplicate with this unique element*/

     int unique = 1, dups = 0;

     for ( int i = 0; i < numsSize - 1; i++){
         if ( nums[i] != nums[i+1] ){
             unique++;
             nums[i + 1 - dups] = nums[i + 1];
         } else {
             dups++;
         }
     }

     return unique;
}