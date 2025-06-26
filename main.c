#include <stdio.h>
#include<string.h>
#define FILENAME "led_control.txt"

void save_leds(int led[], int size){
    FILE *fp = fopen(FILENAME, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d\n", led[i]);
    }
    fclose(fp);
    printf("LED states saved to %s\n", FILENAME);
}
void load_leds(int led[], int size){
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return;
    }
    for (int i = 0; i < size; i++) {
        if (fscanf(fp, "%d", &led[i]) != 1) {
            led[i] = 0; // Default to 0 if read fails
        }
    }
    fclose(fp);
    printf("LED states loaded from %s\n", FILENAME);
}

int main(void){
    int led[8] = {0};
    char cmd[10];
    int num;

    // Load initial LED states from file
    load_leds(led, 8);

    printf("Virtual LED Control (type 'on', 'off', 'show', 'save','load','exit')\n");
    while (1) {
        printf("Enter command: ");
        scanf("%s", cmd);

        if (strcmp(cmd, "on") == 0) {
            printf("Enter LED number (0-7): ");
            scanf("%d", &num);
            if (num >= 0 && num < 8) {
                led[num] = 1;
                printf("LED %d turned ON\n", num);
            } else {
                printf("Invalid LED number. Please enter a number between 0 and 7.\n");
            }
        } else if (strcmp(cmd, "off") == 0) {
            printf("Enter LED number (0-7): ");
            scanf("%d", &num);
            if (num >= 0 && num < 8) {
                led[num] = 0;
                printf("LED %d turned OFF\n", num);
            } else {
                printf("Invalid LED number. Please enter a number between 0 and 7.\n");
            }
        } else if (strcmp(cmd, "show") == 0) {
            printf("Current LED states: ");
            for (int i = 0; i < 8; i++) {
                printf("%d ", led[i]);
            }
            printf("\n");
        } else if (strcmp(cmd, "save") == 0) {
            save_leds(led, 8);
        } else if (strcmp(cmd, "load") == 0) {
            load_leds(led, 8);
        } else if (strcmp(cmd, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Please use 'on', 'off', 'show', or 'exit'.\n");
        }
    }
    return 0;

}