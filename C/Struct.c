#include <stdio.h>
#define maxHeight 225

typedef struct stats {
    int weight;
    int height;
} stats;

int main() {
    stats person1;
    person1.weight = 85;
    person1.height = 175;

    printf("Weight: %d, Height: %d\n", person1.weight, person1.height);

    if (person1.height > maxHeight) {
        printf("Max Height exceeded!\n");
    } else {
        printf("Max height not exceeded!\n");
    }

    return 0;
}
