#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *file;
    char *buffer;
    long file_size;

    
    // Open the file in read mode
    file = fopen("puzzle_input.txt", "r");

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for the buffer to hold the file content
    buffer = malloc(sizeof(char) * (file_size + 1));

    // Read the file into the buffer
    fread(buffer, sizeof(char), file_size, file);
    buffer[file_size] = '\0'; // Null-terminate the string

    int i = 0;
    int first_index = 0;
    int second_index = 0;
    int first_index_set = 0;
    int total_sum = 0;
    char tester[10];
    int tester_index = 0;
        
    while (i< file_size) {
        if (buffer[i] == '\n') {
            if (second_index == 20) {
                int middle = (first_index-48)*10 + (first_index-48);
                printf("midsum: %d\n", middle);
                total_sum += middle;
            } else {
                int middle = (first_index-48)*10 + (second_index-48);
                printf("midsum: %d\n", middle);
                total_sum += middle;
            }
            first_index_set = 0;
            first_index = 0;
            second_index = 20;
        } else if (buffer[i] >= 48 && buffer[i] <= 57) {
            memset(tester, 0, strlen(tester));
            if (first_index_set == 0) {
                first_index = buffer[i];
                first_index_set = 1; 
            } else {
                second_index = buffer[i];
            }
        } else if (tester_index == 0) {
            switch (buffer[i])
            {
            case 'o':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 't':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'f':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 's':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'e':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'n':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'z':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            default:
                memset(tester, 0, strlen(tester));
                tester_index = 0;
                break;
            }
        } else if (tester_index == 1) {
            switch (buffer[i])
            {
            case 'n':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'w':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'h':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'o':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'i':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'e':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            default:
                memset(tester, 0, strlen(tester));
                tester_index = 0;
                break;
            }
        } else if (tester_index == 2) {
            switch (buffer[i])
            {
            case 'e':
                if (first_index_set == 0) {
                    first_index = 1 + 48;
                    tester_index = 0;
                    first_index_set = 1;
                } else {
                    second_index = 1 + 48;
                    tester_index = 0;
                }
                break;
            case 'o':
                if (first_index_set == 0) {
                    first_index = 2 + 48;
                    tester_index = 0;
                    first_index_set = 1;
                } else {
                    second_index = 2 + 48;
                    tester_index = 0;
                }        
                break;
            case 'r':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'u':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'v':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'x':
                if (first_index_set == 0) {
                    first_index = 6 + 48;
                    tester_index = 0;
                    first_index_set = 1;
                } else {
                    second_index = 6 + 48;
                    tester_index = 0;
                }
                break;
            case 'g':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'n':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            default:
                memset(tester, 0, strlen(tester));
                tester_index = 0;
                break;
            }
        } else if (tester_index == 3) {
            switch (buffer[i])
            {
            case 'e':
                if (tester == "five") {
                    if (first_index_set == 0) {
                        first_index = 5 + 48;
                        tester_index = 0;
                        first_index_set = 1;
                    } else {
                        second_index = 5 + 48;
                        tester_index = 0;
                    }
                } else if (tester == "nine") {
                    if (first_index_set == 0) {
                        first_index = 9 + 48;
                        tester_index = 0;
                        first_index_set = 1;
                    } else {
                        second_index = 9 + 48;
                        tester_index = 0;
                    }
                } else {
                    tester[tester_index] = buffer[i];
                    tester_index++;
                }
                break;
            case 'r':
                if (first_index_set == 0) {
                    first_index = 4 + 48;
                    tester_index = 0;
                    first_index_set = 1;
                } else {
                    second_index = 4 + 48;
                    tester_index = 0;
                }
                break;
            case 's':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'h':
                tester[tester_index] = buffer[i];
                tester_index++;
                break;
            case 'o':
                if (first_index_set == 0) {
                    first_index = 0 + 48;
                    tester_index = 0;
                    first_index_set = 1;
                } else {
                    second_index = 0 + 48;
                    tester_index = 0;
                }     
                break;
            default:
                memset(tester, 0, strlen(tester));
                tester_index = 0;
                break;
            }
        } else if (tester_index == 4) {
            switch (buffer[i])
            {
            case 'e':
                if (first_index_set == 0) {
                    first_index = 3 + 48;
                    tester_index = 0;
                    first_index_set = 1;
                } else {
                    second_index = 3 + 48;
                    tester_index = 0;
                }
                break;
            case 'n':
                if (first_index_set == 0) {
                    first_index = 7 + 48;
                    tester_index = 0;
                    first_index_set = 1;
                } else {
                    second_index = 7 + 48;
                    tester_index = 0;
                }         
                break;
            case 't':
                if (first_index_set == 0) {
                    first_index = 8 + 48;
                    tester_index = 0;
                    first_index_set = 1;
                } else {
                    second_index = 8 + 48;
                    tester_index = 0;
                }         
                break;
            default:
                memset(tester, 0, strlen(tester));
                tester_index = 0;
                break;
            }
        } else {
            tester_index = 0;
        }

        printf("char: %c\ttester: %s\tfirst_index: %d\tsecond_index: %d\tfirst_index_set: %d\n", buffer[i], tester, first_index-48, second_index-48, first_index_set);
        // one
        // two
        // three
        // four
        // five
        // six
        // seven
        // eight
        // nine
        // zero


        i++;
    }

    printf("total: %d", total_sum);


    
    
    // Clean up
    fclose(file);
    free(buffer);

    return 0;
}

