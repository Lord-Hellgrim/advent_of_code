#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void reverse(char *str1)  
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(str1); // use strlen() to get the length of str string  
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}

int strindex(char* string, char* substring) {
    char* loc = strstr(string, substring);
    if (loc != NULL) {
        int result = loc - string;
        return result;
    } else {
        return 10000;
    }
}

int main() {
    FILE *file;
    char *buffer;
    long file_size;

    
    // Open the file in read mode
    file = fopen("puzzle_input.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for the buffer to hold the file content
    buffer = malloc(sizeof(char) * (file_size + 1));

    // Check if the memory was allocated successfully
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return -1;
    }

    // Read the file into the buffer
    fread(buffer, sizeof(char), file_size, file);
    buffer[file_size] = '\0'; // Null-terminate the string

    int i = 0;
    int first_num = 10000;
    int last_num = 0;
    int first_num_index = 10000;
    int last_num_index = 0;

    int first_text = 10000;
    int last_text_index = 0;
    int first_text_index = 10000;
    int last_text = 0;

    int final_first = 0;
    int final_last = 0;
    int total_sum = 0;

    char* one = "one";
    char* two = "two";
    char* three = "three";
    char* four = "four";
    char* five = "five";
    char* six = "six";
    char* seven = "seven";
    char* eight = "eight";
    char* nine = "nine";
    char* zero = "zero";

    char* eno = "eno";
    char* owt = "owt";
    char* eerht = "eerht";
    char* ruof = "ruof";
    char* evif = "evif";
    char* xis = "xis";
    char* neves = "neves";
    char* thgie = "thgie";
    char* enin = "enin";
    char* orez = "orez";
    char* delim = "\n";
        
    char* token = strtok(buffer, delim);
    while (token) {

        first_num_index = 10000;
        first_text_index = 10000;
        last_num_index = 10000;
        last_text_index = 10000;

        long long positions[10] = {1000};
        long long positions_reverse[10] = {1000};

        positions[1] = strindex(token, one);
        positions[2] = strindex(token, two);
        positions[3] = strindex(token, three);
        positions[4] = strindex(token, four);
        positions[5] = strindex(token, five);
        positions[6] = strindex(token, six);
        positions[7] = strindex(token, seven);
        positions[8] = strindex(token, eight);
        positions[9] = strindex(token, nine);
        positions[0] = strindex(token, zero);

        int i = 0;
        int min = 10000;
        while (i<10) {
            if (positions[i] < first_text_index) {
                min = i;
                first_text_index = positions[i];
            }
            i++;
        }
        first_text = min;

        int j = 0;
        while (j < strlen(token)) {
            if (token[j] >= 48 && token[j] <= 57) {
                first_num = token[j] - 48;
                first_num_index = j;
                break;
            }
            j++;
        }

        reverse(token);

        positions_reverse[1] = strindex(token, eno);
        positions_reverse[2] = strindex(token, owt);
        positions_reverse[3] = strindex(token, eerht);
        positions_reverse[4] = strindex(token, ruof);
        positions_reverse[5] = strindex(token, evif);
        positions_reverse[6] = strindex(token, xis);
        positions_reverse[7] = strindex(token, neves);
        positions_reverse[8] = strindex(token, thgie);
        positions_reverse[9] = strindex(token, enin);
        positions_reverse[0] = strindex(token, orez);

        int n = 0;
        int text_min = 10000;
        while (n < 10) {
            if (positions_reverse[n] < last_text_index) {
                text_min = n;
                last_text_index = positions_reverse[n];
            }
            n++;
        }
        last_text = text_min;

        int m = 0;
        while (m < strlen(token)) {
            if (token[m] >= 48 && token[m] <= 57) {
                last_num = token[m] - 48;
                last_num_index = m;
                break;
            }
            m++;
        }

        if (first_num_index < first_text_index) {
            final_first = first_num;
        } else {
            final_first = first_text;
        }

        if (last_num_index < last_text_index) {
            final_last = last_num;
        } else {
            final_last = last_text;
        }

        total_sum += final_first*10 + final_last;
        token = strtok(NULL, delim);
    }
    
    printf("total: %d\n", total_sum);

    
    
    // Clean up
    fclose(file);
    free(buffer);

    return 0;
}

