#include <stdio.h>

const char text[] = "Na strane 123 v 5-tem odstavci najdete 123 oddelenych slov";

/*size_t strlen(const char *array) {
    size_t len = 0;
    while (*(array++))
        ++len;
    return len;
}*/

int find(const char *hay, const char *needle, int pos, int hay_len, int needle_len) {
    /*size_t hay_len = strlen(hay);
    size_t needle_len = strlen(needle);*/
    int counter = 0;
    for (int i = 0; i < hay_len; ++i) {
        if (hay[i] == needle[0]) {
            for (int j = 1; j < needle_len; ++j) {
                if (hay[i + j] != needle[j]) {
                    goto outer;
                }
            }
            if (++counter == pos){
                return i;
            }
        }
        outer:;
    }

    return -1;
}

int main() {
    char s[] = "ran";
    printf("%i\n",find(text, s, 1, sizeof(text) - 1, sizeof(s) - 1));
    return 0;
}
