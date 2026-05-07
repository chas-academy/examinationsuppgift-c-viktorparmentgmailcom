#include <stdio.h>  // printf och scanf
#include <string.h> // strlen
#include <ctype.h>  // toupper

// Funktion som räknar ut medelvärdet av en elevernas provresultat
float calculate_average(int results[], int tests) {
    int sum = 0;
    for (int i = 0; i < tests; i++) {
        sum += results[i];     // Summera alla provresultat
    }
    return (float)sum / tests;   // Returnera medelvärdet som en float
}

// Funktion för att göra första bokstaven i ett namn till stor bokstav
void capitalize_name(char name[]) { 
    if (strlen(name) > 0) { /* kollar så att namnet inte är tomt */
        name[0] = toupper(name[0]); /* gör första bokstaven versal med toupper från ctype.h */
    }
}

int main() {
    // Arrays för att lagra namn och provresultat
    char names[5][11];
    int results[5][13];
    
    // Läs in namn och provresultat för alla 5 elever
    for (int i = 0; i < 5; i++) {
        scanf("%s", names[i]);   // Matar in elevens namn
        for (int j = 0; j < 13; j++) { // Matar in 13 provresultat för varje elev
            scanf("%d", &results[i][j]);
        }
    }
    
    // Räkna ut medelpoäng för varje elevsprovresultat och lagrar det i averages
    float averages[5];
    for (int i = 0; i < 5; i++) {
        averages[i] = calculate_average(results[i], 13);
    }
    
    // Hitta eleven med högst medelpoäng
    float highest_average = averages[0]; // Ger floaten ett värde att börja på.
    int highest_index = 0;
    for (int i = 1; i < 5; i++) {
        if (averages[i] > highest_average) { // Går igenom alla elever 
            highest_average = averages[i]; // Uppdatera högsta medelpoäng
            highest_index = i;  // Spara index för eleven med högst snitt
        }
    }
    
    // Räkna ut det totala genomsnittet för alla elever
    float total_average = 0;
    for (int i = 0; i < 5; i++) {
        total_average += averages[i]; // Summera alla elevers medelpoäng
    }
    total_average /= 5;  // Delar summan av medelpoängen med antal elever
    
    // Skriv ut eleven med högst medelpoäng (med stor första bokstav)
    capitalize_name(names[highest_index]);
    printf("%s\n", names[highest_index]);
    
    // Skriv ut alla elever som ligger under gruppens snitt (med stor första bokstav)
    for (int i = 0; i < 5; i++) {
        if (averages[i] < total_average) {
            capitalize_name(names[i]);
            printf("%s\n", names[i]);
        }
    }
    
    return 0;
}