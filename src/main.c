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
//    printf("%s\n", cafeteria->month_name);

    // Opening the CSV file for reading
    FILE *csv_file = fopen(csv_file_name, "r");
    if (csv_file == NULL) {
        printf("Error: Could not open CSV file\n");
        return;
    }

    // Reading the menus from the CSV file line by line
    char line[256];
    int day_count_normal = 0;
    int day_count_vegan = 0;
    int day_count_vegeterian = 0;

    while (fgets(line, sizeof(line), csv_file)) {
        char menu_type[10];
        char date[10];
        char soup[50];
        char main_dish[50];
        char side_dish[50];
        char extra[50];

//        printf("%s", line);
        // pulling data and assigning to variables line by line
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]", menu_type, date, soup, main_dish, side_dish, extra);
//        printf("%s , %s , %s , %s , %s , %s\n", menu_type, date, soup, main_dish, side_dish, extra);

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
        }
        else if (strcmp(menu_type, "\"Vegan\"") == 0) {
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

void record_customer_counts(struct Cafeteria *cafeteria) {
    // This function will generate random customer counts for each menu item and update the sale_count array accordingly
    size_t num_elements = sizeof(cafeteria->normal) / sizeof(cafeteria->normal[0]);
    printf("Number of elements in cafeteria->normal: %zu\n", num_elements);

    for (int i = 0; i < 22; i++) {
//        printf("%s\n",cafeteria->normal[i].date);
        int student_count = randomNumGenerator(0, 50);
        int academic_count = randomNumGenerator(0, 50);
        int administrative_count = randomNumGenerator(0, 50);

        cafeteria->normal[i].sale_count[0] = student_count;
        cafeteria->normal[i].sale_count[1] = academic_count;
        cafeteria->normal[i].sale_count[2] = administrative_count;

    }

}

void calc_and_show_income(struct Cafeteria *cafeteria) {
    // This function will calculate the total income and show it in three different ways
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
    return 0;
}
