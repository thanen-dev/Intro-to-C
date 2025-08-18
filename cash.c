#include <stdio.h>

int calculate_quarters(int *cents)
{
    // Calculate how many quarters you should give customer
    int quarters = 0;
    while (*cents >= 25){
        // Subtract the value of those quarters from remaining cents
        quarters++;
        *cents -= 25;
    }
    return quarters;
}

int calculate_dimes(int *cents)
{
    // Calculate how many dimes you should give customer
    int dimes = 0;
    while (*cents >= 10){
        // Subtract the value of those dimes from remaining cents
        dimes++;
        *cents -= 10;
    }
    return dimes;
}

int calculate_nickels(int *cents)
{
    // Calculate how many quarters you should give customer
    int nickels = 0;
    while (*cents >= 5){
        // Subtract the value of those nickels from remaining cents
        nickels++;
        *cents -= 5;
    }
    return nickels;
}

int calculate_pennies(int *cents)
{
    // Calculate how many quarters you should give customer
    int pennies = 0;
    while (*cents >= 1){
        // Subtract the value of those pennies from remaining cents
        pennies++;
        *cents -= 1;
    }
    return pennies;
}

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do {
        printf("Change owed: ");
        scanf("%d", &cents);
    } while (cents < 0);

    // Calculate how many quarters you should give customer
    int quarters = calculate_quarters(&cents);
    int dimes = calculate_dimes(&cents);
    int nickels = calculate_nickels(&cents);
    int pennies = calculate_pennies(&cents);

    // Print the total number of coins
    int total = quarters + dimes + nickels + pennies;
    printf("%d\n", total);
    printf("Quarters: %d, Dimes: %d,  Nickels: %d, Pennies: %d\n", quarters, dimes, nickels, pennies);
}

