#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    int first_num_index = 10000;
    int last_num_index = 0;
    int first_text_index = 0;
    int last_text_index = 0;

    int first_text = 10000;
    int last_text = 0;
    int first_num = 10000;
    int last_num = 0;

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
    printf("token: %s\n", token);
    while (token != NULL) {
        token = strtok(NULL, delim);
        printf("token: %s\n", token);
        int i = 0;
        while (i<strlen(token)) {
            if (token[i] >= 48 && token[i] <= 57) {
                first_num_index = token[i] - 48;
                first_num = i;
            }
            i++;
        }

        if (strstr(token, one)) {
            first_text_index = 1;
            first_text = token - strstr(token, one);
        } else if (strstr(token, two)) {
            first_text_index = 2;
            first_text = token - strstr(token, two);
        } else if (strstr(token, three)) {
            first_text_index = 3;
            first_text = token - strstr(token, three);
        } else if (strstr(token, four)) {
            first_text_index = 4;
            first_text = token - strstr(token, four);
        } else if (strstr(token, five)) {
            first_text_index = 5;
            first_text = token - strstr(token, five);
        } else if (strstr(token, six)) {
            first_text_index = 6;
            first_text = token - strstr(token, six);
        } else if (strstr(token, seven)) {
            first_text_index = 7;
            first_text = token - strstr(token, seven);
        } else if (strstr(token, eight)) {
            first_text_index = 8;
            first_text = token - strstr(token, eight);
        } else if (strstr(token, nine)) {
            first_text_index = 9;
            first_text = token - strstr(token, nine);
        } else if (strstr(token, zero)) {
            first_text_index = 0;
            first_text = token - strstr(token, orez);
        }
        reverse(token);

        i = strlen(token) - 1;
        while (i > 0) {
            if (token[i] >= 48 && token[i] <= 57) {
                last_num_index = token[i] - 48;
                last_num = i;
            }
            i--;
        }

        if (strstr(token, eno)) {
            last_text_index = 1;
            last_text = token - strstr(token, eno);
        } else if (strstr(token, owt)) {
            last_text_index = 2;
            last_text = token - strstr(token, owt);
        } else if (strstr(token, eerht)) {
            last_text_index = 3;
            last_text = token - strstr(token, eerht);
        } else if (strstr(token, ruof)) {
            last_text_index = 4;
            last_text = token - strstr(token, ruof);
        } else if (strstr(token, evif)) {
            last_text_index = 5;
            last_text = token - strstr(token, evif);
        } else if (strstr(token, xis)) {
            last_text_index = 6;
            last_text = token - strstr(token, xis);
        } else if (strstr(token, neves)) {
            last_text_index = 7;
            last_text = token - strstr(token, neves);
        } else if (strstr(token, thgie)) {
            last_text_index = 8;
            last_text = token - strstr(token, thgie);
        } else if (strstr(token, enin)) {
            last_text_index = 9;
            last_text = token - strstr(token, enin);
        } else if (strstr(token, orez)) {
            last_text_index = 0;
            last_text = token - strstr(token, orez);
        }


        if (first_num_index < first_text) {
            final_first = first_num;
        } else {
            final_first = first_text;
        }

        if (last_text_index > last_num_index) {
            final_last = last_text;
        } else {
            final_last = last_num;
        }

        total_sum += final_first*10 + final_last;

        printf("total: %d", total_sum);
    }
    

    
    
    // Clean up
    fclose(file);
    free(buffer);

    return 0;
}

