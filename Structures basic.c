#include <stdio.h>

struct workers {
    char firstName[20];
    char LastNmae[20];
    int workID;
    double bonusWage;
};

int main () {
    struct workers one = {"Abigail", "Smith", 8264, 1183.09};
    struct workers two = {"Anna", "Garcia", 3768, 1265.76};
    printf("Worker ID's: %d %d\n", one.workID, two.workID);
    printf("Wage bonuses for these employees: %.2lf", (one.bonusWage + two.bonusWage));
    return 0;
}
