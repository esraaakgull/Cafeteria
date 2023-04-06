#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct of menus

struct normal_menu {
    char date[6];
    char soup[20];
    char main_dish[20];
    char side_dish[20];
    char extra[20];
    int sale_count[3];
};

struct vegan_menu {
    char date[6];
    char soup[20];
    char main_dish[20];
    char side_dish[20];
    char extra[20];
    int sale_count[3];
};

struct vegetarian_menu {
    char date[6];
    char soup[20];
    char main_dish[20];
    char side_dish[20];
    char extra[20];
    int sale_count[3];
};

struct Cafeteria {
    char *month_name;
    struct normal_menu normal[100];
    struct vegan_menu vegan[100];
    struct vegetarian_menu vegetarian[100];
};

void initialize_menus(struct Cafeteria *cafeteria, char *csv_file_name) {
    // This function will read the CSV file and initialize the cafeteria structure with the menu data
    // Open the CSV file for reading
    FILE *csv_file = fopen(csv_file_name, "r");
    if (csv_file == NULL) {
        printf("Error: Could not open CSV file\n");
        return;
    }

    // Read the month name from the CSV file name
    // find the underscore characters in the string
    int underscore_indexes[2];
    int found = 0;
    for (int i = 0; i < strlen(csv_file_name); i++) {
        if (csv_file_name[i] == '_') {
            underscore_indexes[found] = i;
            found++;
        }
    }

    // Extract the month name substring between the first underscore and the second underscore
    char *month_name = malloc(underscore_indexes[1] - underscore_indexes[0]);
    memcpy(month_name, csv_file_name + underscore_indexes[0] + 1, underscore_indexes[1] - underscore_indexes[0] - 1);
    month_name[underscore_indexes[1] - underscore_indexes[0] - 1] = '\0';

    // cafeterianın monthına bunu assign etmen gerekiyor bulduğun ayı
//    strcpy(cafeteria->month_name, month_name);

    // Print the month name
    printf("%s\n", month_name);


    // Read the menus from the CSV file line by line
    char line[256];
    int day_count = 0;
    while (fgets(line, sizeof(line), csv_file)) {
        char menu_type[10];
        char date[10];
        char soup[50];
        char main_dish[50];
        char side_dish[50];
        char extra[50];
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]", menu_type, date, soup, main_dish, side_dish, extra);

        //printf("%s",menu_type);
        //printf("%s",date);
        // Allocate memory for the menu struct and initialize its attributes
        if (strcmp(menu_type, "\"Normal\"") == 0) {
//            cafeteria->normal[day_count].date = malloc(strlen(date) + 1);

            strcpy(cafeteria->normal[day_count].date, date);
            //printf("%s",cafeteria->normal[day_count].date);
//            cafeteria->normal[day_count].soup = malloc(strlen(soup) + 1);
            strcpy(cafeteria->normal[day_count].soup, soup);
//            cafeteria->normal[day_count].main_dish = malloc(strlen(main_dish) + 1);
            strcpy(cafeteria->normal[day_count].main_dish, main_dish);
//            cafeteria->normal[day_count].side_dish = malloc(strlen(side_dish) + 1);
            strcpy(cafeteria->normal[day_count].side_dish, side_dish);
//            cafeteria->normal[day_count].extra = malloc(strlen(extra) + 1);
            strcpy(cafeteria->normal[day_count].extra, extra);
            cafeteria->normal[day_count].sale_count[0] = 0;
            cafeteria->normal[day_count].sale_count[1] = 0;
            cafeteria->normal[day_count].sale_count[2] = 0;
        } else if (strcmp(menu_type, "\"Vegan\"") == 0) {
//            cafeteria->vegan[day_count].date = malloc(strlen(date) + 1);
            strcpy(cafeteria->vegan[day_count].date, date);
            //printf("%s",cafeteria->vegan[day_count].date);
//            cafeteria->vegan[day_count].soup = malloc(strlen(soup) + 1);
            strcpy(cafeteria->vegan[day_count].soup, soup);
//            cafeteria->vegan[day_count].main_dish = malloc(strlen(main_dish) + 1);
            strcpy(cafeteria->vegan[day_count].main_dish, main_dish);
//            cafeteria->vegan[day_count].side_dish = malloc(strlen(side_dish) + 1);
            strcpy(cafeteria->vegan[day_count].side_dish, side_dish);
//            cafeteria->vegan[day_count].extra = malloc(strlen(extra) + 1);
            strcpy(cafeteria->vegan[day_count].extra, extra);
            cafeteria->vegan[day_count].sale_count[0] = 0;
            cafeteria->vegan[day_count].sale_count[1] = 0;
            cafeteria->vegan[day_count].sale_count[2] = 0;
        } else if (strcmp(menu_type, "\"Vegetarian\"") == 0) {
//            cafeteria->vegetarian[day_count].date = malloc(strlen(date) + 1);
            strcpy(cafeteria->vegetarian[day_count].date, date);
            //printf("%s",cafeteria->vegetarian[day_count].date);
//            cafeteria->vegetarian[day_count].soup = malloc(strlen(soup) + 1);
            strcpy(cafeteria->vegetarian[day_count].soup, soup);
//            cafeteria->vegetarian[day_count].main_dish = malloc(strlen(main_dish) + 1);
            strcpy(cafeteria->vegetarian[day_count].main_dish, main_dish);
//            cafeteria->vegetarian[day_count].side_dish = malloc(strlen(side_dish) + 1);
            strcpy(cafeteria->vegetarian[day_count].side_dish, side_dish);
//            cafeteria->vegetarian[day_count].extra = malloc(strlen(extra) + 1);
            strcpy(cafeteria->vegetarian[day_count].extra, extra);
            cafeteria->vegetarian[day_count].sale_count[0] = 0;
            cafeteria->vegetarian[day_count].sale_count[1] = 0;
            cafeteria->vegetarian[day_count].sale_count[2] = 0;
        }
        day_count++;



        // Parse sale counts
//        char *token = strtok(sale_counts, ",");
//        int i = 0;
//        while (token != NULL) {
//            cafeteria->normal[day_count].sale_count[i] = atoi(token);
//            token = strtok(NULL, ",");
//            i++;
//        }
    }

}

void record_customer_counts(struct Cafeteria *cafeteria) {
    // This function will generate random customer counts for each menu item and update the sale_count array accordingly
}

void calc_and_show_income(struct Cafeteria *cafeteria) {
    // This function will calculate the total income and show it in three different ways
}


int main() {
    char csv_file_name[80] = "C:\\Users\\ozgur\\CLionProjects\\Cafeteria2\\cafeteria_march_menu.csv";
    // bi tane düzgün Cafetaria structure ı oluştur, onu yolla. Nasıl yapılıyor bilmiyom, böyle çalışmıyo
    struct Cafeteria *cafeteria = malloc(sizeof(struct Cafeteria));
    initialize_menus(cafeteria, csv_file_name);

    return 0;
}
