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

int brandIndex = 0;
int firstTypeSum = 0;
int secondTypeSum = 0;
int thirdTypeSum = 0;
int fourthTypeSum = 0;

int processed[NUM_OF_BRANDS] = {0}; // Array to track which indices have been processed
int processedCount = 0;


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

//this function gets the car brand index and the four car type sums and inserts the data accordingly
void enterBrandDailyData(int brandIndex, int firstSum, int secondSum, int thirdSum, int fourthSum) {
    days++;
    cube[days][brandIndex][0] = firstSum;
    cube[days][brandIndex][1] = secondSum;
    cube[days][brandIndex][2] = thirdSum;
    cube[days][brandIndex][3] = fourthSum;
}

//this function populates data for all car types
void populateForAllBrands(int brandIndex, int firstSum, int secondSum, int thirdSum, int fourthSum) {
    if (processed[brandIndex] == 0) {
        processed[brandIndex] = 1;
        processedCount++;
    }

    enterBrandDailyData(brandIndex, firstSum, secondSum, thirdSum, fourthSum);
    printf("No data for brands");
    // Only print the brands that haven't been processed
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        if (processed[i] == 0) {
            printf(" %s", brands[i]);
        }
    }

    printf("\nPlease complete the data\n");
}

void dailyStat(int day) {
    int sum = 0;
    int sumByBrand = 0;
    int sumByType = 0;
    for (int i = 0; i < NUM_OF_BRANDS; i++) {
        for (int j = 0; j < NUM_OF_TYPES; j++) {
            sum += cube[day][i][j];
        }

    }
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
                printf("Please enter a car brand index and the daily sales sum for each car type: \n");
                scanf(" %d %d %d %d %d", &brandIndex, &firstTypeSum, &secondTypeSum, &thirdTypeSum, &fourthTypeSum);

                if (brandIndex < 0 || brandIndex > NUM_OF_TYPES) {
                    printf("This brand is not valid\n");
                    break;
                }

                enterBrandDailyData(brandIndex, firstTypeSum, secondTypeSum, thirdTypeSum, fourthTypeSum);

                break;

            case addAll:
                printf("No data for brands Toyoga HyunNight Mazduh FolksVegan Key-Yuh\nPlease complete the data\n");
                scanf(" %d %d %d %d %d", &brandIndex, &firstTypeSum, &secondTypeSum, &thirdTypeSum, &fourthTypeSum);

                if (brandIndex < 0 || brandIndex > NUM_OF_TYPES) {
                    printf("This brand is not valid\n");
                    break;
                }

                populateForAllBrands(brandIndex, firstTypeSum, secondTypeSum, thirdTypeSum, fourthTypeSum);

                while (processedCount < NUM_OF_BRANDS) {
                    scanf(" %d %d %d %d %d", &brandIndex, &firstTypeSum, &secondTypeSum, &thirdTypeSum, &fourthTypeSum);
                    populateForAllBrands(brandIndex, firstTypeSum, secondTypeSum, thirdTypeSum, fourthTypeSum);
                }

                break;

            case stats:
                int day = 0;
                printf("What day would you like to analyze?");
                scanf(" %d", &day);

                while (cube[day][brandIndex][0] == -1 || day < 0 || day > DAYS_IN_YEAR) {
                    printf("Please enter a valid day\nWhat day would you like to analyze?\n");
                    scanf(" %d", &day);
                }


            default:
                printf("Invalid input\n");
        }
        printMenu();
        scanf("%d", &choice);
    }
    printf("Goodbye!\n");
    return 0;
}
