#include <stdio.h>
#include <stdlib.h>


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

    printf("%s\n", buffer);


    // Clean up
    fclose(file);
    free(buffer);

    return 0;
}

