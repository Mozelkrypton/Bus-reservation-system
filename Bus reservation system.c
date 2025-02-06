#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>

typedef struct{
         char name[50];
		 int bus_num;
		 int num_of_seats;
		 }pd;


void reservation(void);
void viewdetails(void);
void printticket(char name[], int, int, float);
void specificbus(int);
float charge(int, int);

int main()
{
        system ("cls");
	printf("\t\t-------------------KRYPTON SHUTTLE---------------------------\n");
	printf("\t\t-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-..-.-.-.-.-.-.-.-.-.-.-\n");
	printf("\t\t welcome to online booking krypton shuttle \n");
	printf("\t\tP.O Box 34-2700.\n");
	printf("\t\tNairobi.\n");
	printf("\t\tYou plan your future we take you there in time.\n");
	getch();
	system("cls");
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n==================================================================\n");
	printf("\t BUS RESERVATION SYSTEM\n");
	printf("====================================================================\n");
	printf("\n1>>Reserve a ticket ");
	printf("---------------------------------------------------------------------\n");
	printf("\n2>>view available bus ");
	printf("\n3>>Exit");
	printf("----------------------------------------------------------------------\n");
	printf("\n\n--->");
	scanf("%d",&menu_choice);
	switch(menu_choice)
	      {
		    case 1:
			       reservation();
			case 2:
			       viewdetails();
				   printf("\n\nPress any key to the main menu");
				   getch();
				   break;
			case 3:
			       return(0);
			default:
                   printf("\n Invalid choice");
			}
void viewdetails(void)
{
       system("cls");
	   printf("\n Bus.Number\tBus name\tDestinations \tBus Fare\t Time \n");
	   printf("\n 1753001\t Bus 1\tThika to Nairobi\tKsh.150\t 8am");
	   printf("\n 1753002\t Bus 2\tThika to Banana\tKsh.300\t 9am");
	   printf("\n 1753003\t Bus 3\tNairobi to Thika\tKsh.200\t 4pm");
	   printf("\n 1753004\t Bus 4\tBanana to Thika\tKsh.250\t 5pm");
	   printf("\n 1753005\t Bus 5\tNairobi to Banana\tKsh.80\t 8am");
	   printf("\n 1753006\t Bus 6\tBanana to Nairobi\tKsh50\t 4pm");
}

void reservation(void)
   {
   char confirm;
   int i=0;
   float charges;
   pd passdetails;
   FILE *fp;
   fp=fopen("seats_resrved.txt","a");
   system("cls");

   Printf("\nEnter your name: ");
   fflush(stdin);
   gets(passdetails.name);

   printf("\nEnter number of seats:");
   scanf("%d", &passdetails.num_of_seats);
   printf("\n\n>>press enter to view available bus<<");
   getch();
   system("cls");
   viewdetails();
   printf("\n\nEnter bus number:");
  /* start_1;
   scanf("%d", &passdetails.bus_num);
   if (passdetails.bus_num>=1753001 && passdetails.bus_num<=1753005)
   {











	 }*/

float charge(int bus_num, int num_of_seats)
    {
		if (bus_num==1753001)
		{
		return(150*num_of_seats);
		}
		if(bus_num==1753002)
		{
		return(300*num_of_seats);
		}
		if (bus_num==1753003)
		{
		return(200*num_of_seats);
		}
		if (bus_num==1753004)
		{
		return(250*num_of_seats);
		}
		if (bus_num==1753005)
		{
		return(80*num_of_seats);
		}
		if (bus_num==1753006)
		{
		return(50*num_of_seats);
		}
	}


void printticket(char name[],int num_of_seats,int bus_num,float charges)
{

	system("cls");
	printf("====================KRYPTON SHUTTLE================================");
	printf("\t BUS TICKET");
	printf("===================================================================");
	printf("Name:\t \t%s",name);
	printf("\n Seat number: \t %d",num_of_seats);
	printf("\n Bus number:\t\t %d",bus_num);
	specificbus(bus_num);
	printf("\n Charges: \t\t %.3f",charges);
}

void specificbus(int bus_num)
   {
	   if (bus_num==1753001)
	   {
		printf("\nBus:\t\t\tBus 1");
		printf("\nDestination:\t\tThika to Nairobi");
		printf("\nDepature time: \t\t8am");
	   }
	   if (bus_num==1753002)
	   {
		printf("\nBus:\t\t\tBus 2");
		printf("\nDestination:\t\tThika to Banana");
		printf("\nDepature time: \t\t9am");
	   }
	   if (bus_num==1753003)
	   {
		printf("\nBus:\t\t\tBus 3");
		printf("\nDestination:\t\tNairobi to Thika");
		printf("\nDepature time: \t\t4am");
	   }
	   if (bus_num==1753004)
	   {
		printf("\nBus:\t\t\tBus 4");
		printf("\nDestination:\t\tBanana to Thika");
		printf("\nDepature time: \t\t5am");
	   }
	   if (bus_num==1753005)
	   {
		printf("\nBus:\t\t\tBus 5");
		printf("\nDestination:\t\tNairobi to Banana");
		printf("\nDepature time: \t\t8am");
	   }
	   if (bus_num==1753006)
	   {
		printf("\nBus:\t\t\tBus 6");
		printf("\nDestination:\t\tBanana to Nairobi");
		printf("\nDepature time: \t\t4pm");
	   }
   }

