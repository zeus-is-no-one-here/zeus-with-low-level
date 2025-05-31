#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filemaker {
    char name[1000];
    char content[1000];
    int size;
};

void create_file(struct filemaker *file) {
    file->size = strlen(file->content);
    FILE *filee = fopen(file->name, "w");
    if (filee == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fwrite(file->content, sizeof(char), file->size, filee);
    fclose(filee);
    printf("File created successfully\n");
}

int main() {
    struct filemaker file;

    printf("Enter the file name:\n");
    scanf("%999s", file.name);
    getchar();  // Clear the input buffer

    printf("Enter the file content:\n");
    fgets(file.content, sizeof(file.content), stdin);
    file.content[strcspn(file.content, "\n")] = 0;  // Remove trailing newline

    create_file(&file);

    return 0;
}
