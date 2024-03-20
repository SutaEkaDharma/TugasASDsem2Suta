#include <stdio.h>
#include <string.h>

int get_card_value(char card) {
    if (card == 'J') return 11;
    else if (card == 'Q') return 12;
    else if (card == 'K') return 13;
    else if (card == '1') return 10;
    else return card - '0';
}

int main() {
    int n, i, j, min_swaps = 0;
    char cards[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c", &cards[i]);
    }
    for (i = 0; i < n; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (get_card_value(cards[j]) < get_card_value(cards[min_idx])) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            char temp = cards[i];
            cards[i] = cards[min_idx];
            cards[min_idx] = temp;
            min_swaps++;
            printf("pertukaran ke-%d: ", min_swaps); 
            for (int k = 0; k < n; k++) {
                printf("%c ", cards[k]); 
            }
            printf("\n");
        }
    }
    printf("%d\n", min_swaps); 
    return 0;
}
