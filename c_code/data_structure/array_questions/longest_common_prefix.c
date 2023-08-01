#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* longest_common_prefix(char** strs, int n)
{
    int end = 0;
    bool stop = false;

    while(strs[0][end] != '\0' && !stop)
    {
        for(int i = 1; i < n; i++)
        {
            if(strs[0][end] != strs[i][end])
            {
                stop = true;
                break;
            }
        }

        if(!stop) end++;
    }
    
    char *msg = (char *)malloc(sizeof(char) * (end + 1));
    memcpy(msg, strs[0], end);
    msg[end] = '\0';
    return msg;
}

int main(int argc, char** argv)
{
    char *strs_1[] = { "geeksforgeeks", "geeks", "geek", "geezer" };
    char *answer = NULL;
    answer = longest_common_prefix(strs_1, sizeof(strs_1)/sizeof(strs_1[0]));
    printf("> %s\r\n", answer);
    free(answer);

    char *strs_2[] = { "flower", "flow", "april" };
    answer = longest_common_prefix(strs_2, sizeof(strs_2)/sizeof(strs_2[0]));
    printf("> %s\r\n", answer);
    free(answer);

    char *strs_3[] = { "flower", "day", "april" };
    answer = longest_common_prefix(strs_3, sizeof(strs_3)/sizeof(strs_3[0]));
    printf("> %s\r\n", answer);
    free(answer);

    char *strs_4[] = { "flow", "flow", "flow" };
    answer = longest_common_prefix(strs_4, sizeof(strs_4)/sizeof(strs_4[0]));
    printf("> %s\r\n", answer);
    free(answer);

    puts("");
    return 0;
}