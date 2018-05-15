#include <stdio.h>
#include <stdbool.h>
#include <mem.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void to_token(char * s, char tokens[strlen(s)][strlen(s)+1], int * j) {
    bool number = false;
    int number_counter = 0;
    *j = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] >= 48 && s[i] <= 57) {
            //number
            number = true;
            number_counter++;
        } else {
            if(number == true) {
                char number_token[number_counter+1];
                for (int z = number_counter; z > 0; z--) {
                    number_token[number_counter - z] = s[i - z];
                }
                number_token[number_counter] = '\0';
                strcpy(tokens[(*j)++],number_token);
                number_counter = 0;
                number = false;
            }
            tokens[*j][0] = s[i];
            tokens[(*j)++][1] = '\0';
        }
    }
    if(number == true) {
        char number_token[number_counter+1];
        for (int z = number_counter; z > 0; z--) {
            number_token[number_counter - z] = s[strlen(s) - z];
        }
        number_token[number_counter] = '\0';
        strcpy(tokens[(*j)++],number_token);
    }
    for(int i = 0; i < *j; i++) {
        if(strlen(tokens[i]) > 0)
            printf("%s", tokens[i]);
    }
}

int not_null_position(char * s) {
    int i;
    for (i = 0; i < strlen(s) - 1; ++i)
        if (s[i] != '0')
            break;
    return i;
}

bool alphanumericLess(char * s1, char * s2) {
    bool more_nulls = false;
    if(strcmp(s1, s2) == 0)
        return false;
    char tokens1[strlen(s1)][strlen(s1)+1];
    char tokens2[strlen(s2)][strlen(s2)+1];
    int * x = malloc(sizeof(int));
    int * y = malloc(sizeof(int));
    to_token(s1, tokens1, x);
    to_token(s2, tokens2, y);
    for(int i = 0; i < *y; i++){
        if(strlen(tokens1[i]) == 1 && (tokens1[i][0] > 57 || tokens1[i][0] < 48)) {
            if((strlen(tokens2[i]) > 1) || (tokens2[i][0] < tokens1[i][0]))
                return false;
            else if((strlen(tokens2[i]) == 1) && (tokens2[i][0] > tokens1[i][0]))
                return true;
        } else if(tokens2[i][0] <= 57 && tokens2[i][0] >= 48) {
            if(strtoumax(tokens1[i], NULL, 10) > strtoumax(tokens2[i], NULL, 10))
                return false;
            else if (strtoumax(tokens2[i], NULL, 10) == strtoumax(tokens1[i], NULL, 10)) {
                if(not_null_position(tokens2[i]) > not_null_position(tokens1[i]))
                    more_nulls = true;
            } else {
                return true;
            }
        }
    }
    if(more_nulls == true)
        return false;
    else
        return true;
}

int main() {
    printf("%s", alphanumericLess("9999999999999999999", "9999999999999999998") ? "true" : "false");
    return 0;
}