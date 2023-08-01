/*
Link: https://www.geeksforgeeks.org/find-first-repeating-element-array-integers/?ref=lbp

Given an array of integers arr[], The task is to find the index of first 
repeating element in it i.e. the element that occurs more than once and 
whose index of the first occurrence is the smallest. 

Input: arr[] = {10, 5, 3, 4, 3, 5, 6}
Output: 5 
Explanation: 5 is the first element that repeats

Input: arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}
Output: 6 
Explanation: 6 is the first element that repeats

*/

#include <stdio.h>
#include <stdbool.h>

int first_repeating_element(int arr[], int size)
{
    for(int i = 0; i < size; i++) 
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }

    return -1;
}

int main(int argc, char** argv)
{
    int arr_1[] = {10, 5, 3, 4, 3, 5, 6};
    int answer = first_repeating_element(arr_1, sizeof(arr_1)/sizeof(arr_1[0]));
    printf("%d\r\n", answer);
    
    int arr_2[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
    answer = first_repeating_element(arr_2, sizeof(arr_2)/sizeof(arr_2[0]));
    printf("%d\r\n", answer);

    printf("\r\n");
    return 0;
}