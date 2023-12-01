#include <stdio.h>
#include <stdlib.h>


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
    int first_index = 0;
    int second_index = 0;
    int first_index_set = 0;
    int total_sum = 0;
        
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
        }


        if (buffer[i] >= 48 && buffer[i] <= 57) {
            if (first_index_set == 0) {
                first_index = buffer[i];
                first_index_set = 1; 
            } else {
                second_index = buffer[i];
            }
        }

    
        i++;
    }

    printf("total: %d", total_sum);


    
    
    // Clean up
    fclose(file);
    free(buffer);

    return 0;
}

