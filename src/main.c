//ESRA AKGUL - 260201074
//OZGURHAN POLAT - 260201035

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Struct of menus
struct Normal_menu {
    char *date;
    char *soup;
    char *main_dish;
    char *side_dish;
    char *extra;
    int sale_count[3];
};

struct Vegan_menu {
    char *date;
    char *soup;
    char *main_dish;
    char *side_dish;
    char *extra;
    int sale_count[3];
};

struct Vegetarian_menu {
    char *date;
    char *soup;
    char *main_dish;
    char *side_dish;
    char *extra;
    int sale_count[3];
};

// Struct of Cafeteria
struct Cafeteria {
    char *month_name;
    struct Normal_menu *normal;
    struct Vegan_menu *vegan;
    struct Vegetarian_menu *vegetarian;
};

// Prices
const int STUDENT = 6;
const int ACADEMIC_PERS = 16;
const int ADMINISTRATIVE = 12;

int day_count_normal = 0;
int day_count_vegan = 0;
int day_count_vegeterian = 0;

// This function will read the CSV file and initialize the cafeteria structure with the menu data
void initialize_menus(struct Cafeteria *cafeteria, char *csv_file_name) {
    //  finding month name
    char *start = strchr(csv_file_name, '_') + 1; // find the first underscore and move one position forward
    char *end = strchr(start, '_'); // find the second underscore
    int len = end - start; // calculate the length of the text between the underscores
    char *month_name = malloc(len + 1); // allocate a buffer for the result
    strncpy(month_name, start, len); // copy the text between the underscores to the buffer
    month_name[len] = '\0'; // add a null terminator to the buffer
    cafeteria->month_name = month_name;

    // Opening the CSV file for reading
    FILE *csv_file = fopen(csv_file_name, "r");
    if (csv_file == NULL) {
        printf("Error: Could not open CSV file\n");
        return;
    }

    // Reading the menus from the CSV file line by line
    char line[256];
    while (fgets(line, sizeof(line), csv_file)) {
        char menu_type[10];
        char date[10];
        char soup[50];
        char main_dish[50];
        char side_dish[50];
        char extra[50];

        // pulling data and assigning to variables line by line
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]", menu_type, date, soup, main_dish, side_dish, extra);

        // Allocate memory for the menu struct and initialize its attributes
        if (strcmp(menu_type, "\"Normal\"") == 0) {
            // reallocating the array size
            cafeteria->normal = realloc(cafeteria->normal, (day_count_normal + 1) * sizeof(struct Normal_menu));
            // assigning each value
            cafeteria->normal[day_count_normal].date = malloc(strlen(date) + 1);
            strcpy(cafeteria->normal[day_count_normal].date, date);
            cafeteria->normal[day_count_normal].soup = malloc(strlen(soup) + 1);
            strcpy(cafeteria->normal[day_count_normal].soup, soup);
            cafeteria->normal[day_count_normal].main_dish = malloc(strlen(main_dish) + 1);
            strcpy(cafeteria->normal[day_count_normal].main_dish, main_dish);
            cafeteria->normal[day_count_normal].side_dish = malloc(strlen(side_dish) + 1);
            strcpy(cafeteria->normal[day_count_normal].side_dish, side_dish);
            cafeteria->normal[day_count_normal].extra = malloc(strlen(extra) + 1);
            strcpy(cafeteria->normal[day_count_normal].extra, extra);
            cafeteria->normal[day_count_normal].sale_count[0] = 0;
            cafeteria->normal[day_count_normal].sale_count[1] = 0;
            cafeteria->normal[day_count_normal].sale_count[2] = 0;
            day_count_normal++;
        } else if (strcmp(menu_type, "\"Vegan\"") == 0) {
            // reallocating the array size
            cafeteria->vegan = realloc(cafeteria->vegan, (day_count_vegan + 1) * sizeof(struct Vegan_menu));
            // assigning each value
            cafeteria->vegan[day_count_vegan].date = malloc(strlen(date) + 1);
            strcpy(cafeteria->vegan[day_count_vegan].date, date);
            cafeteria->vegan[day_count_vegan].soup = malloc(strlen(soup) + 1);
            strcpy(cafeteria->vegan[day_count_vegan].soup, soup);
            cafeteria->vegan[day_count_vegan].main_dish = malloc(strlen(main_dish) + 1);
            strcpy(cafeteria->vegan[day_count_vegan].main_dish, main_dish);
            cafeteria->vegan[day_count_vegan].side_dish = malloc(strlen(side_dish) + 1);
            strcpy(cafeteria->vegan[day_count_vegan].side_dish, side_dish);
            cafeteria->vegan[day_count_vegan].extra = malloc(strlen(extra) + 1);
            strcpy(cafeteria->vegan[day_count_vegan].extra, extra);
            cafeteria->vegan[day_count_vegan].sale_count[0] = 0;
            cafeteria->vegan[day_count_vegan].sale_count[1] = 0;
            cafeteria->vegan[day_count_vegan].sale_count[2] = 0;
            day_count_vegan++;
        } else if (strcmp(menu_type, "\"Vegetarian\"") == 0) {
            // reallocating the array size
            cafeteria->vegetarian = realloc(cafeteria->vegetarian,
                                            (day_count_vegeterian + 1) * sizeof(struct Vegetarian_menu));
            // assigning each value
            cafeteria->vegetarian[day_count_vegeterian].date = malloc(strlen(date) + 1);
            strcpy(cafeteria->vegetarian[day_count_vegeterian].date, date);
            cafeteria->vegetarian[day_count_vegeterian].soup = malloc(strlen(soup) + 1);
            strcpy(cafeteria->vegetarian[day_count_vegeterian].soup, soup);
            cafeteria->vegetarian[day_count_vegeterian].main_dish = malloc(strlen(main_dish) + 1);
            strcpy(cafeteria->vegetarian[day_count_vegeterian].main_dish, main_dish);
            cafeteria->vegetarian[day_count_vegeterian].side_dish = malloc(strlen(side_dish) + 1);
            strcpy(cafeteria->vegetarian[day_count_vegeterian].side_dish, side_dish);
            cafeteria->vegetarian[day_count_vegeterian].extra = malloc(strlen(extra) + 1);
            strcpy(cafeteria->vegetarian[day_count_vegeterian].extra, extra);
            cafeteria->vegetarian[day_count_vegeterian].sale_count[0] = 0;
            cafeteria->vegetarian[day_count_vegeterian].sale_count[1] = 0;
            cafeteria->vegetarian[day_count_vegeterian].sale_count[2] = 0;
            day_count_vegeterian++;
        }
    }
}

int randomNumGenerator(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// This function will generate random customer counts for each menu item and update the sale_count array accordingly
void record_customer_counts(struct Cafeteria *cafeteria) {
    // for normal menu
    for (int i = 0; i < day_count_normal; i++) {
        int student_count = randomNumGenerator(0, 50);
        int academic_count = randomNumGenerator(0, 50);
        int administrative_count = randomNumGenerator(0, 50);

        cafeteria->normal[i].sale_count[0] = student_count;
        cafeteria->normal[i].sale_count[1] = academic_count;
        cafeteria->normal[i].sale_count[2] = administrative_count;
    }

    // for vegan menu
    for (int i = 0; i < day_count_vegan; i++) {
        int student_count = randomNumGenerator(0, 50);
        int academic_count = randomNumGenerator(0, 50);
        int administrative_count = randomNumGenerator(0, 50);

        cafeteria->vegan[i].sale_count[0] = student_count;
        cafeteria->vegan[i].sale_count[1] = academic_count;
        cafeteria->vegan[i].sale_count[2] = administrative_count;
    }

    // for vegetarian menu
    for (int i = 0; i < day_count_vegeterian; i++) {
        int student_count = randomNumGenerator(0, 50);
        int academic_count = randomNumGenerator(0, 50);
        int administrative_count = randomNumGenerator(0, 50);

        cafeteria->vegetarian[i].sale_count[0] = student_count;
        cafeteria->vegetarian[i].sale_count[1] = academic_count;
        cafeteria->vegetarian[i].sale_count[2] = administrative_count;
    }
}

// displaying first and last days of the month
void display_first_last_of_month(struct Cafeteria *cafeteria) {
    // Example output for Normal menu
    printf("~ ~ ~ ~ Normal menu for the first and last days of the month:\n date--> %s\n soup--> %s\n main_dish--> %s\n side_dish--> %s\n ekstra--> %s\n ",
           cafeteria->normal[0].date, cafeteria->normal[0].soup, cafeteria->normal[0].main_dish,
           cafeteria->normal[0].side_dish, cafeteria->normal[0].extra);
    printf("~ ~ ~ ~ Normal menu for the first and last days of the month:\n date--> %s\n soup--> %s\n main_dish--> %s\n side_dish--> %s\n ekstra--> %s\n\n",
           cafeteria->normal[day_count_normal - 1].date, cafeteria->normal[day_count_normal - 1].soup,
           cafeteria->normal[day_count_normal - 1].main_dish,
           cafeteria->normal[day_count_normal - 1].side_dish, cafeteria->normal[day_count_normal - 1].extra);

    // Example output for Vegan menu
    printf("~ ~ ~ ~ Vegan menu for the first and last days of the month:\n date--> %s\n soup--> %s\n main_dish--> %s\n side_dish--> %s\n ekstra--> %s\n ",
           cafeteria->vegan[0].date, cafeteria->vegan[0].soup, cafeteria->vegan[0].main_dish,
           cafeteria->vegan[0].side_dish, cafeteria->vegan[0].extra);
    printf("~ ~ ~ ~ Vegan menu for the first and last days of the month:\n date--> %s\n soup--> %s\n main_dish--> %s\n side_dish--> %s\n ekstra--> %s\n\n",
           cafeteria->vegan[day_count_vegan - 1].date, cafeteria->vegan[day_count_vegan - 1].soup,
           cafeteria->vegan[day_count_vegan - 1].main_dish,
           cafeteria->vegan[day_count_vegan - 1].side_dish, cafeteria->vegan[day_count_vegan - 1].extra);

    // Example output for Vegetarian menu
    printf("~ ~ ~ ~ Vegetarian menu for the first and last days of the month:\n date--> %s\n soup--> %s\n main_dish--> %s\n side_dish--> %s\n ekstra--> %s\n ",
           cafeteria->vegetarian[0].date, cafeteria->vegetarian[0].soup, cafeteria->vegetarian[0].main_dish,
           cafeteria->vegetarian[0].side_dish, cafeteria->vegetarian[0].extra);
    printf("~ ~ ~ ~ Vegetarian menu for the first and last days of the month:\n date--> %s\n soup--> %s\n main_dish--> %s\n side_dish--> %s\n ekstra--> %s\n\n",
           cafeteria->vegetarian[day_count_vegeterian - 1].date, cafeteria->vegetarian[day_count_vegeterian - 1].soup,
           cafeteria->vegetarian[day_count_vegeterian - 1].main_dish,
           cafeteria->vegetarian[day_count_vegeterian - 1].side_dish,
           cafeteria->vegetarian[day_count_vegeterian - 1].extra);

    //  Example output for Normal menu
    int day = randomNumGenerator(0, day_count_normal);
    printf("Example output for normal menu ====> %s | %s | %s | %s | %s\n", cafeteria->normal[day].date,
           cafeteria->normal[day].soup, cafeteria->normal[day].main_dish,
           cafeteria->normal[day].side_dish, cafeteria->normal[day].extra);

    //  Example output for Vegan menu
    day = randomNumGenerator(0, day_count_vegan);
    printf("Example output for vegan menu ====> %s | %s | %s | %s | %s\n", cafeteria->vegan[day].date,
           cafeteria->vegan[day].soup, cafeteria->vegan[day].main_dish,
           cafeteria->vegan[day].side_dish, cafeteria->vegan[day].extra);

    //  Example output for Vegetarian menu
    day = randomNumGenerator(0, day_count_vegeterian);
    printf("Example output for vegetarian menu ====> %s | %s | %s | %s | %s\n\n", cafeteria->vegetarian[day].date,
           cafeteria->vegetarian[day].soup, cafeteria->vegetarian[day].main_dish,
           cafeteria->vegetarian[day].side_dish, cafeteria->vegetarian[day].extra);

    // Example output for Normal menu
    day = randomNumGenerator(0, day_count_normal);
    printf("Counts for the example normal menu output of %s ====> Student:%d, Academic:%d, Administrative:%d\n",
           cafeteria->normal[day].date, cafeteria->normal[day].sale_count[0], cafeteria->normal[day].sale_count[1],
           cafeteria->normal[day].sale_count[2]);

    // Example output for Vegan menu
    day = randomNumGenerator(0, day_count_vegan);
    printf("Counts for the example vegan menu output of %s ====> Student:%d, Academic:%d, Administrative:%d\n",
           cafeteria->vegan[day].date, cafeteria->vegan[day].sale_count[0], cafeteria->vegan[day].sale_count[1],
           cafeteria->vegan[day].sale_count[2]);

    // Example output for Vegetarian menu
    day = randomNumGenerator(0, day_count_vegan);
    printf("Counts for the example vegetarian menu output of %s ====> Student:%d, Academic:%d, Administrative:%d\n",
           cafeteria->vegetarian[day].date, cafeteria->vegetarian[day].sale_count[0],
           cafeteria->vegetarian[day].sale_count[1],
           cafeteria->vegetarian[day].sale_count[2]);
}

// This function will calculate the total income and show it in three different ways
void calc_and_show_income(struct Cafeteria *cafeteria) {
    int gained_money_normal = 0;
    int gained_money_normal_students = 0;
    int gained_money_normal_academicpers = 0;
    int gained_money_normal_administratives = 0;

    for (int i = 0; i < day_count_normal; i++) {
        gained_money_normal_students = gained_money_normal_students + cafeteria->normal[i].sale_count[0] * STUDENT;
        gained_money_normal_academicpers =
                gained_money_normal_academicpers + cafeteria->normal[i].sale_count[1] * ACADEMIC_PERS;
        gained_money_normal_administratives =
                gained_money_normal_administratives + cafeteria->normal[i].sale_count[2] * ADMINISTRATIVE;
    }
    gained_money_normal =
            gained_money_normal_students + gained_money_normal_academicpers + gained_money_normal_administratives;

    int gained_money_vegan = 0;
    int gained_money_vegan_students = 0;
    int gained_money_vegan_academicpers = 0;
    int gained_money_vegan_administratives = 0;

    for (int i = 0; i < day_count_vegeterian; i++) {
        gained_money_vegan_students = gained_money_vegan_students + cafeteria->vegetarian[i].sale_count[0] * STUDENT;
        gained_money_vegan_academicpers =
                gained_money_vegan_academicpers + cafeteria->vegetarian[i].sale_count[1] * ACADEMIC_PERS;
        gained_money_vegan_administratives =
                gained_money_vegan_administratives + cafeteria->vegetarian[i].sale_count[2] * ADMINISTRATIVE;
    }
    gained_money_vegan =
            gained_money_vegan_students + gained_money_vegan_academicpers + gained_money_vegan_administratives;

    int gained_money_vegetarian = 0;
    int gained_money_vegetarian_students = 0;
    int gained_money_vegetarian_academicpers = 0;
    int gained_money_vegetarian_administratives = 0;

    for (int i = 0; i < day_count_vegan; i++) {
        gained_money_vegetarian_students =
                gained_money_vegetarian_students + cafeteria->vegan[i].sale_count[0] * STUDENT;
        gained_money_vegetarian_academicpers =
                gained_money_vegetarian_academicpers + cafeteria->vegan[i].sale_count[1] * ACADEMIC_PERS;
        gained_money_vegetarian_administratives =
                gained_money_vegetarian_administratives + cafeteria->vegan[i].sale_count[2] * ADMINISTRATIVE;
    }
    gained_money_vegetarian = gained_money_vegetarian_students + gained_money_vegetarian_academicpers +
                              gained_money_vegetarian_administratives;

    int total_gained_money = gained_money_normal + gained_money_vegan + gained_money_vegetarian;
    int total_gained_money_students =
            gained_money_normal_students + gained_money_vegan_students + gained_money_vegetarian_students;
    int total_gained_money_academicpers =
            gained_money_normal_academicpers + gained_money_vegan_academicpers + gained_money_vegetarian_academicpers;
    int total_gained_money_administratives = gained_money_normal_administratives + gained_money_vegan_administratives +
                                             gained_money_vegetarian_administratives;


    display_first_last_of_month(cafeteria);

    printf("\n************ The Sales Results ************\n");
    printf("a. The distribution of the total gained money on the type of menus.\n Normal menu sales: %d TL,\n Vegan menu sales: %d TL,\n Vegetarian menu sales: %d TL.\n",
           gained_money_normal, gained_money_vegan, gained_money_vegetarian);
    printf("b. Overall sales for a month using the customer counts within each menu.\n Students sales: %d TL,\n Academic personal sales: %d TL,\n Administrative personal sales: %d TL.\n",
           total_gained_money_students, total_gained_money_academicpers, total_gained_money_administratives);
    printf("c. Total sales income of the whole month.\n Total sales income: %d TL.\n", total_gained_money);
}


int main() {
    char csv_file_name[30] = "../cafeteria_march_menu.csv";
    // Initialize a Cafeteria struct
    struct Cafeteria *cafeteria = malloc(sizeof(struct Cafeteria));
    cafeteria->month_name = NULL;
    cafeteria->normal = NULL;
    cafeteria->vegan = NULL;
    cafeteria->vegetarian = NULL;
    initialize_menus(cafeteria, csv_file_name);
    srand(time(0));
    record_customer_counts(cafeteria);
    calc_and_show_income(cafeteria);
    return 0;
}
