/******************
Name: Lee Anne Rachman
ID: 323917286
Assignment: ex3
*******************/

#include <stdio.h>

#define NUM_OF_BRANDS 5
#define BRANDS_NAMES 15
#define NUM_OF_TYPES 4
#define TYPES_NAMES 10
#define DAYS_IN_YEAR 365
#define addOne  1
#define addAll  2
#define stats  3
#define print  4
#define insights  5
#define deltas  6
#define done  7

char brands[NUM_OF_BRANDS][BRANDS_NAMES] = {"Toyoga", "HyunNight", "Mazduh", "FolksVegan", "Key-Yuh"};
char types[NUM_OF_TYPES][TYPES_NAMES] = {"SUV", "Sedan", "Coupe", "GT"};

int cube[DAYS_IN_YEAR][NUM_OF_BRANDS][NUM_OF_TYPES];
int days = 0;

void printMenu() {
    printf("Welcome to the Cars Data Cube! What would you like to do?\n"
        "1.Enter Daily Data For A Brand\n"
        "2.Populate A Day Of Sales For All Brands\n"
        "3.Provide Daily Stats\n"
        "4.Print All Data\n"
        "5.Provide Overall (simple) Insights\n"
        "6.Provide Average Delta Metrics\n"
        "7.exit\n");
}

void enterBrandDailyData(int carBrandIndex, int SUVSum, int SedanSum, int CoupeSum, int GTSum) {
    days++;
    cube[days][carBrandIndex][0] = SUVSum;
    cube[days][carBrandIndex][1] = SedanSum;
    cube[days][carBrandIndex][2] = CoupeSum;
    cube[days][carBrandIndex][3] = GTSum;
}

int main() {
    //initialize all of cube's values to -1
    for (int i = 0; i < DAYS_IN_YEAR; i++) {
        for (int j = 0; j < NUM_OF_BRANDS; j++) {
            for (int k = 0; k < NUM_OF_TYPES; k++) {
                cube[i][j][k] = -1;
            }
        }
    }

    int choice;
    printMenu();
    scanf("%d", &choice);
    while (choice != done) {
        switch (choice) {
            case addOne:
                int brandIndex = 0;
                int firstTypeSum = 0;
                int secondTypeSum = 0;
                int thirdTypeSum = 0;
                int fourthTypeSum = 0;

                printf("Please enter a car brand index and the daily sales sum for each car type: \n");
                scanf(" %d %d %d %d %d", &brandIndex, &firstTypeSum, &secondTypeSum, &thirdTypeSum, &fourthTypeSum);

                if (brandIndex < 0 || brandIndex > 4) {
                    printf("This brand is not valid\n");
                    break;
                }
                enterBrandDailyData(brandIndex, firstTypeSum, secondTypeSum, thirdTypeSum, fourthTypeSum);
                break;
            case addAll:
                printf("Please enter a car brand index and the daily sales sum for each car type: \n");
                scanf(" %d %d %d %d %d", &brandIndex, &firstTypeSum, &secondTypeSum, &thirdTypeSum, &fourthTypeSum);

                break;
            /*
             ......
             */
            default:
                printf("Invalid input\n");
        }
        printMenu();
        scanf("%d", &choice);
    }
    printf("Goodbye!\n");
    return 0;
}
