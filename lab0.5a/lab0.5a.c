#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *function(char *s) {
    if (!strlen(s)) return s;
    char *new = (char*)malloc((2 * strlen(s) + 1) * sizeof(char));
    int i = 0, j = 0, counter = 0;
    while (i < strlen(s)) {
        if ((s[i] != ' ') && (s[i] != '\t')) {
            if (s[i] == '1') {
                counter++;
            }
            new[j] = s[i];
            j++;
            if ((s[i + 1] == ' ') || (s[i + 1] == '\t')) {
                if (counter % 2 == 0) {
                    new[j] = '0';
                }
                else {
                    new[j] = '1';
                }
                new[j + 1] = ' ';
                j = j + 2;
                counter = 0;
            }
        }
        i++;
    }
    // printf("%c\n", new[strlen(new) - 1]);
    if (new[strlen(new) - 1] == ' ') {
        new = (char*)realloc(new, sizeof(char) * strlen(new) + 1);
        new[strlen(new) - 1] = '\0';
    }
    else {
        new = (char*)realloc(new, sizeof(char) * strlen(new) + 1);
        if (counter % 2 == 0) {
            new[strlen(new)] = '0';
        }
        else {
            new[strlen(new)] = '1';
        }
    }
    return new;
}

char *getstr() {
    char *ptr = (char *)malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            free(ptr);
            ptr = NULL; 
            continue;
        }
        if (n == 0)
            scanf("%*c");
        else {
            len += strlen(buf);
            ptr = (char *)realloc(ptr, len + 1);
            strcat(ptr, buf); 
        }
    } while (n > 0);
    if (strlen(ptr) == 0) {
        fprintf(stderr, "Error! The length is zero \n");
      //  free(ptr);
     //   ptr = NULL; 
    }
   // printf("%d \n", strlen(buf));
    return ptr; 
}

void output(char *ptr) {
    printf("The string: %s\n", ptr);
}

int main() {
    char *s = NULL, *p = NULL;
    while( (s = getstr()) ) {
        p = function(s);
       // printf("%ld \n", strlen(p));
        output(p);
        if (s == p) {
            free(s);
        }
        else {
            free(s);
            free(p);
        }
        s = NULL;
        p = NULL;
    }
    return 0;
} 
