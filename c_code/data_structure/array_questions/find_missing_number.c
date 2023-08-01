/* 
Link: https://www.geeksforgeeks.org/find-the-missing-number/

Given an array arr[] of size N-1 with integers in the range of [1, N], the task 
is to find the missing number from the first N integers.

Note: There are no duplicates in the list.

Examples
Input: arr[] = {1, 2, 4, 6, 3, 7, 8}, N = 8
Output: 5
Explanation: The missing number between 1 to 8 is 5

Input: arr[] = {1, 2, 3, 5}, N = 5
Output: 4
Explanation: The missing number between 1 to 5 is 4

*/

#include <stdio.h>
#include <string.h>

void find_missing_number(int arr[], int size)
{
    int missed_number = 0;
    int temp[size + 1];
    int temp_size = sizeof(temp)/sizeof(temp[0]);

    for(int i = 0; i < temp_size; i++)
    {
        temp[i] = 0;
    }

    for(int i = 0; i < size; i++)
    {
        temp[arr[i] - 1] = 1;
    }

    for(int i = 0; i < temp_size; i++)
    {
        if(temp[i] == 0){
            missed_number = i + 1;
        }
    }

    printf("%d\r\n", missed_number);
}

int main(int argc, char** argv)
{
    int arr_1[] = {1, 2, 4, 6, 3, 7, 8};
    find_missing_number(arr_1, sizeof(arr_1)/sizeof(arr_1[0]));

    int arr_2[] = {1, 2, 3, 5};
    find_missing_number(arr_2, sizeof(arr_2)/sizeof(arr_2[0]));

    int arr_3[] = {2, 6, 7, 4, 5, 3};
    find_missing_number(arr_3, sizeof(arr_3)/sizeof(arr_3[0]));

    printf("\r\n");
    return 0;
}
