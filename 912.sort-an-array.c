/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // Merge-sort
 // merge
void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *) malloc((n1+1) * sizeof(int));
    int *R = (int *) malloc((n2+1) * sizeof(int));
    int counter;
    int i = 0;
    int j = 0;
    int k;
    for (counter = 0; counter < n1; counter++)
    {
        L[counter] = arr[counter+left];
    }
    for(counter = 0; counter < n2; counter++)
    {
        R[counter] = arr[counter+mid+1];
    }
    L[n1] = 50001; // sentinel
    R[n2] = 50001; // sentinel
    for (k = left; k <= right; k++)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
    free(L);
    free(R);
}

// divide
void mergesort(int* arr, int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    mergesort(nums, 0, numsSize-1);
    return nums;
}
// @lc code=end

