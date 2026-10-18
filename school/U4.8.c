#include <stdio.h>

int main() {
    int score;
    scanf("%d", &score);
    if (score < 0 || score > 100) {
        puts("error");
        return 0;
    }
    int r = score / 10;
    char rank;
    switch (r) {
        case 10:
        case 9:
            rank = 'A';
            break;
        case 8:
            rank = 'B';
            break;
        case 7:
            rank = 'C';
            break;
        case 6:
            rank = 'D';
            break;
        default: rank = 'E';
    }
    putchar(rank);
    return 0;
}