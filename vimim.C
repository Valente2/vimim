#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char file_path[100];
    printf("Create file (please enter the path to file): ");
    fgets(file_path, sizeof(file_path), stdin);
    file_path[strcspn(file_path, "\n")] = '\0';

    FILE *file;
    if ((file = fopen(file_path, "r")) != NULL) {
        printf("\n\tFile already exists!\n");
        char ans;
        printf("Do you want to use this file? (y/n)\n-> ");
        scanf(" %c", &ans);

        if (ans == 'y' || ans == 'Y') {
            file = fopen(file_path, "a");
            printf("Do you want to erase all content? (y/n)\n-> ");
            scanf(" %c", &ans);

            if (ans == 'y' || ans == 'Y') {
                printf("\n\tErasing...\n");
                fclose(file);
                file = fopen(file_path, "w");
            }
        } else {
            exit(0);
        }
    } else {
        printf("\n\tCreating new file...\n");
        file = fopen(file_path, "w");
    }

    int run = 1;
    char line[100];
    while (run == 1) {
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';
        fputs(line, file);
        fputs("\n", file);
        if (feof(stdin)) {
            break;
        }
    }
    fclose(file);

    return 0;
}
