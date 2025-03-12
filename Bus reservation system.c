#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for passenger details
typedef struct {
    char name[50];
    int bus_num;
    int num_of_seats;
} pd;

// Function Prototypes
void reservation(void);
void viewdetails(void);
void printticket(char name[], int, int, float);
void specificbus(int);
float charge(int, int);

int main() {
    system("cls");
    printf("\t\t-------------------KRYPTON SHUTTLE---------------------------\n");
    printf("\t\t-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n");
    printf("\t\t Welcome to online booking krypton shuttle \n");
    printf("\t\t P.O Box 34-2700.\n");
    printf("\t\t Nairobi.\n");
    printf("\t\t You plan your future, we take you there in time at a lower price.\n");
    getchar();
    
    int menu_choice;
    
    while (1) {
        system("cls");
        printf("\n==================================================================\n");
        printf("\t BUS RESERVATION SYSTEM\n");
        printf("====================================================================\n");
        printf("\n1>> Reserve a ticket ");
        printf("\n2>> View available buses ");
        printf("\n3>> Exit\n");
        printf("\n\n---> ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                reservation();
                break;
            case 2:
                viewdetails();
                printf("\n\nPress any key to return to the main menu...");
                getchar();
                getchar();
                break;
            case 3:
                exit(0);
            default:
                printf("\n Invalid choice. Try again.");
        }
    }

    return 0;
}

// Function to view bus details
void viewdetails(void) {
    system("cls");
    printf("\nBus Number\tBus Name\tDestinations\t\tBus Fare\tTime\n");
    printf("====================================================================\n");
    printf("1753001\t\tBus 1\t\tThika to Nairobi\tKsh.150\t\t8am\n");
    printf("1753002\t\tBus 2\t\tThika to Banana\t\tKsh.300\t\t9am\n");
    printf("1753003\t\tBus 3\t\tNairobi to Thika\tKsh.200\t\t4pm\n");
    printf("1753004\t\tBus 4\t\tBanana to Thika\t\tKsh.250\t\t5pm\n");
    printf("1753005\t\tBus 5\t\tNairobi to Banana\tKsh.80\t\t8am\n");
    printf("1753006\t\tBus 6\t\tBanana to Nairobi\tKsh.50\t\t4pm\n");
}

// Function to handle ticket reservation
void reservation(void) {
    char confirm;
    float charges;
    pd passdetails;
    FILE *fp = fopen("seats_reserved.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }

    system("cls");
    printf("\nEnter your name: ");
    getchar();  // To consume the newline left by scanf
    fgets(passdetails.name, 50, stdin);
    passdetails.name[strcspn(passdetails.name, "\n")] = 0;  // Remove newline character

    printf("\nEnter number of seats: ");
    scanf("%d", &passdetails.num_of_seats);

    printf("\n\n>> Press Enter to view available buses <<");
    getchar();
    getchar();
    system("cls");
    
    viewdetails();
    
    printf("\n\nEnter bus number: ");
    scanf("%d", &passdetails.bus_num);

    // Calculate charges
    charges = charge(passdetails.bus_num, passdetails.num_of_seats);

    // Print ticket
    printticket(passdetails.name, passdetails.num_of_seats, passdetails.bus_num, charges);

    // Save to file
    fprintf(fp, "Name: %s, Seats: %d, Bus No: %d, Charges: %.2f\n",
            passdetails.name, passdetails.num_of_seats, passdetails.bus_num, charges);

    fclose(fp);

    printf("\n\nConfirm ticket (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        printf("\nTicket Reserved Successfully!\n");
    } else {
        printf("\nReservation Cancelled.\n");
    }

    printf("\nPress any key to return to the main menu...");
    getchar();
    getchar();
}

// Function to calculate ticket charge
float charge(int bus_num, int num_of_seats) {
    switch (bus_num) {
        case 1753001: return 150 * num_of_seats;
        case 1753002: return 300 * num_of_seats;
        case 1753003: return 200 * num_of_seats;
        case 1753004: return 250 * num_of_seats;
        case 1753005: return 80 * num_of_seats;
        case 1753006: return 50 * num_of_seats;
        default: return 0;
    }
}

// Function to print the ticket
void printticket(char name[], int num_of_seats, int bus_num, float charges) {
    system("cls");
    printf("===================================================================\n");
    printf("\t\tKRYPTON SHUTTLE - BUS TICKET\n");
    printf("===================================================================\n");
    printf("Name: \t\t%s\n", name);
    printf("Seats: \t\t%d\n", num_of_seats);
    printf("Bus Number: \t%d\n", bus_num);
    specificbus(bus_num);
    printf("\nCharges: \tKsh %.2f\n", charges);
    printf("===================================================================\n");
}

// Function to print bus details based on the bus number
void specificbus(int bus_num) {
    switch (bus_num) {
        case 1753001:
            printf("Bus: Bus 1\nDestination: Thika to Nairobi\nDeparture: 8am\n");
            break;
        case 1753002:
            printf("Bus: Bus 2\nDestination: Thika to Banana\nDeparture: 9am\n");
            break;
        case 1753003:
            printf("Bus: Bus 3\nDestination: Nairobi to Thika\nDeparture: 4pm\n");
            break;
        case 1753004:
            printf("Bus: Bus 4\nDestination: Banana to Thika\nDeparture: 5pm\n");
            break;
        case 1753005:
            printf("Bus: Bus 5\nDestination: Nairobi to Banana\nDeparture: 8am\n");
            break;
        case 1753006:
            printf("Bus: Bus 6\nDestination: Banana to Nairobi\nDeparture: 4pm\n");
            break;
        default:
            printf("Invalid Bus Number\n");
    }
}
