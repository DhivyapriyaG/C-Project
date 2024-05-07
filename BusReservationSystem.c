#include <stdio.h>
#include <string.h>


#define MAX_PASSENGERS_PER_BUS 50
#define MAX_NAME_LENGTH 50
#define TOTAL_SEATS_PER_BUS 50


// Global Declaration


int passengerId=50;
int busTicket=150;
int bListCount=0;


// Using Structure to Store Passenger Details


struct Passenger {
    char name[MAX_NAME_LENGTH];
    int age;
    int passId;
    char password[5];
    int seatC;
};
struct Passenger passengers[MAX_PASSENGERS_PER_BUS];


// Using Structure to Store Booking Details


struct bookingList
{
    char name[10];
    char date[11];
    char city[11];
    char status[10];
    int seatC;
    int sNumber[50];
    int total;
    int arrayC;
}bList[100];


// Function prototypes


void signin();
void signup();
void displayMenu();
void displayAvailableSeats(int seats[]);
void bookSeat(int seats[],int Id);
int totalSeatsBooked(int seats[]);
int avlSeats(int seats[]);
void displayGraphicalRepresentation(int seats[]);
void printBillReceipt(int Id);
void history(int Id);
void cancellation(int seats[],int Id);




int seats[TOTAL_SEATS_PER_BUS] = {0}; // Initialize all seats as available (0)
int seatC=0;    //  Initializing Seat Count from 0


// Main Function


int main() {
    int choice;
    printf("\n              ***** Welcome to Bus Booking *****\n");
    printf("-----------------------------------------------------------------------\n");
   
    int Opt;
    do{
        printf("\nMain Menu :\n");
        printf("\t    1. Sign In\n\t    2. Sign UP\n\t    3. Exit\n");
        printf("\nEnter your Option: ");
        while (scanf("%d", &Opt) != 1) {
        printf("\n             -----Invalid Choice-----\n\nPlease enter a Valid Option: ");


        // Clear the input buffer
        while (getchar() != '\n');
        }
   
        switch(Opt){
            case 1:
                printf("-----------------------------------------------------------------------\n");
                printf("\n            ----- Welcome to SignIn Page -----\n");
                signin();
                break;
            case 2:
                signup();
                break;
            case 3:
                printf("\n           \t ----- THANK YOU USING OUR SERVICE -----\n\t\t\t    Visit Again..! :)");
                printf("\n           \t                  ***");
                printf("\n-----------------------------------------------------------------------\n");
                break;
            default:
                printf("\n            ----- Enter valid option..! -----\n");
        }


    }while(Opt!=3);
}


// Function SignIn process


void signin(){
    int Id;
    int f=0;
    char Password[8];
    do
    {
        printf("\nEnter Your Id       : ");
        scanf("%d",&Id);
        printf("\nEnter Your Password : ");
        scanf("%s",&Password);
       
        if((Id==passengers[Id-50].passId) && (strcmp(Password,passengers[Id-50].password)==0))
        {
            printf("\n            ----- SignIn Successfully..! -----\n");
            printf("-----------------------------------------------------------------------\n");
            f=2;
            int choice;
            do {
                displayMenu();


                while (scanf("%d", &choice) != 1) {
                printf("             -----Invalid Choice-----\n\nPlease enter a Valid Option: ");


                // Clear the input buffer
                while (getchar() != '\n');
                }
               
                switch(choice) {
                    case 1:
                        printf("\n-----------------------------------------------------------------------\n");
                        displayAvailableSeats(seats);
                        break;
                    case 2:
                        printf("-----------------------------------------------------------------------\n");
                        if(avlSeats(seats)>0)
                        {
                            bookSeat(seats,Id);
                        }
                        else
                        {
                            printf("               ----- Oops..! BUS Was FULL -----");
                        }
                        break;
                    case 3:
                        printf("\n-----------------------------------------------------------------------\n");
                        printf("\nTotal Seats Booked   : %d\n", totalSeatsBooked(seats));
                        printf("Total Available Seats: %d\n", avlSeats(seats));
                        printf("\n-----------------------------------------------------------------------\n");
                        break;
                    case 4:
                        printf("\n-----------------------------------------------------------------------\n");
                        displayGraphicalRepresentation(seats);
                        break;
                    case 5:
                        printBillReceipt(Id);
                        break;
                    case 6:
                        history(Id);
                        break;
                    case 7:
                        cancellation(seats, Id);
                        break;
                    case 8:
                        printf("\n            ----- Signed Out Successfully..! -----\n");
                        printf("\n-----------------------------------------------------------------------\n\n");
                        break;
                    default:
                        printf("\n            ----- Invalid choice. Please try again...! -----\n");
                }
            } while(choice != 8);
        }
        else{
            f=1;
            printf("\n           ----- Oops..! Entered details are Invalid -----\n");
            printf("\n      ----- If you don't have exitng account SIGN UP first -----\n");
            printf("\n-----------------------------------------------------------------------\n");
        }
        if(f==1)
        {
            int press;
            printf("\nto CONTINUE (Press 1): or to SIGN UP (Press 2):  or to EXIT (Press 3): \n");
           
            do
            {
                printf("\nEnter your Option:  ");
                while (scanf("%d", &press) != 1) {
                printf("\n                  -----Invalid Choice-----\n\nPlease enter a Valid Option: ");


                // Clear the input buffer
                while (getchar() != '\n');
                }
                switch(press)
                {
                    case 1:
                        f=2;
                        signin();
                        break;
                    case 2:
                        f=2;
                        signup();
                        break;
                    case 3:
                        f=2;
                        printf("\n-----------------------------------------------------------------------\n");
                        break;
                    default:
                        printf("\n               ----- Enter Valid Option -----\n");
                }
            }while(f!=2);
           
        }
    }while(f!=2);
}


// Function of SignUp Process


void signup()
{
    printf("-----------------------------------------------------------------------\n");
    printf("\n              ----- Welcome to SignUp Page -----\n");
    printf("\nEnter your Name      : ");
    scanf("%s",passengers[passengerId-50].name);
    do{
        printf("\nEnter your Age\n(above 18 only)      : ");
        while (scanf("%d", &passengers[passengerId-50].age) != 1) {
                printf("\n                ----- Numbers Only -----\nEnter a valid AGE : ");


                // Clear the input buffer
                while (getchar() != '\n');
        }
    }while(passengers[passengerId-50].age<18);


    printf("\nEnter your Password  : ");
    scanf("%s",&passengers[passengerId-50].password);
    passengers[passengerId-50].passId=passengerId;
    printf("\n\t\t*** Your Id Number is %d ***",passengerId);
    passengerId++;
    printf("\n\n             ----- SignUp Successfully..! -----");
    printf("\n-----------------------------------------------------------------------\n");


}


// Display Menu Function


void displayMenu() {
    printf("\nMenu :");
    printf("\n\t    1. Display available seats\n");
    printf("\t    2. Book a seat\n");
    printf("\t    3. Display total seats booked\n");
    printf("\t    4. Display graphical representation of seats\n");
    printf("\t    5. Print Bill Receipt\n");
    printf("\t    6. View History\n");
    printf("\t    7. Cancel Ticket\n");
    printf("\t    8. Sign Out\n\n");
    printf("Enter your choice: ");
}


// Function of Displaying Available Seats


void displayAvailableSeats(int seats[]) {
    printf("\nAvailable Seats:\n\n");
    for(int i = 0; i < TOTAL_SEATS_PER_BUS; i++)
    {
        if(seats[i] == 0 ) {
            printf("%-10d ", i + 1);
        }
        else{
            printf("[Booked]   ");
        }
        if((i+1)%10==5 || (i+1)%10==0) printf("\n");
    }
    printf("\n-----------------------------------------------------------------------\n");
}


// Function of Booking Process


void bookSeat(int seats[],int Id) {
    int sNumber[50]={};
    int arrLength=0;
    int seatNumber,seatCount;
    int count=1;
    int cityOpt=0;
    char City[10];
    printf("\n            ------ Welcome to Booking Page ------\n\n");
    while(1!=0)
    {
        printf("Select City :");
        printf("\n\t\t1. Trichy\n\t\t2. Chennai\n\t\t3. Madurai\n\t\t4. Coimbatore\n\t\t5. Salem\n\nEnter Your Option : ");
        while (scanf("%d", &cityOpt) != 1) {
            printf("             -----Invalid Number...!-----\n\nPlease enter a Valid Number: ");


            // Clear the input buffer
            while (getchar() != '\n');
        }
        if(cityOpt==1)
        {
            strcpy(City,"Trichy");
            break;
        }
        else if(cityOpt==2)
        {
            strcpy(City,"Chennai");
            break;
        }
        else if (cityOpt==3)
        {
            strcpy(City,"Madurai");
            break;
        }
        else if(cityOpt==4)
        {
            strcpy(City,"Coimbatore");
            break;
        }
        else if(cityOpt==5)
        {
            strcpy(City,"Salem");
            break;
        }
    }
    printf("\nEnter the Number of seats to be booked: ");
    while (scanf("%d", &seatCount) != 1) {
        printf("             -----Invalid Number...!-----\n\nPlease enter a Valid Number: ");


        // Clear the input buffer
        while (getchar() != '\n');
    }
    int confirm=0;
    if(avlSeats(seats)>=seatCount)
    {
        passengers[Id-50].seatC=seatCount;
       
        do
        {
            printf("\nEnter seat number(%d): ",count);
            while (scanf("%d", &seatNumber) != 1) {
                printf("             -----Invalid Seat Number...!-----\n\nPlease enter a Valid Number: ");


                // Clear the input buffer
                while (getchar() != '\n');
            }


            if(seatNumber < 1 || seatNumber > TOTAL_SEATS_PER_BUS) {
                printf("\n            ----- Please Check the Seat Number...! and try again.-----\n");
            }


            else{
                if(seats[seatNumber - 1] == 1) {
                    printf("\n            ----- Oops...!   Seat %d is already booked...! -----\n", seatNumber);
                    printf("                                 Try Again..!\n");
                }
                else {
                    seats[seatNumber - 1] = 1;
                    confirm =1;
                    count++;
                    bList[bListCount].sNumber[arrLength] = seatNumber;
                    arrLength++;
                    printf("\n            ----- Seat %d booked successfully...!-----\n", seatNumber);
                }
            }
           
        }while(count-1 != seatCount);
    }
    else
    {
        printf("\n            ----- Oops..! There are no Enough Seats -----\n\nAvailable Seats = %d\n",avlSeats(seats));
    }
   
    if (confirm == 1)
    {
        printf("\nEnter Journey Date(dd-mm-yyyy): ");
        scanf("%s",&bList[bListCount].date);
        strcpy(bList[bListCount].name,passengers[Id-50].name);
        //strcpy(bList[bListCount].date,passengers[Id-50].Date);
        strcpy(bList[bListCount].city,City);
        bList[bListCount].seatC = seatCount;
        bList[bListCount].arrayC = arrLength;
        strcpy(bList[bListCount].status,"Booked");
        bList[bListCount].total=seatCount*busTicket;
       
        bListCount++;
    }
    printf("\n-----------------------------------------------------------------------\n");
   
}


// Function of Bill Receipt


void printBillReceipt(int Id)
{
    int tot=0;
    int sNo;
    printf("\n-----------------------------------------------------------------------\n");
    printf("\n                           ----- Bill Receipt -----\n");
    printf("   User Name : %s\n",passengers[Id-50].name);
    printf("   User ID   : %d",Id);
    printf("\n\n            --------------------------------------------------------------------\n");
    printf("            S.No   City         Journey Date   Seat Count   Amount    Status\n");
    printf("            --------------------------------------------------------------------\n\n");
    for(int i=0,sNo=1;i<bListCount;i++){
        //printf("%s\n",bList[i].date);
        if(strcmp(passengers[Id-50].name,bList[i].name)==0  && strcmp(bList[i].status,"Booked")==0)
        {
            tot+=bList[i].total;
            printf("            %-6d %-12s %-14s %-12d %-9d %s\n",sNo,bList[i].city,bList[i].date,bList[i].seatC,bList[i].total,bList[i].status);
            sNo++;
        }
    }
   
    printf("\n            --------------------------------------------------------------------\n");
    printf("                                                            %-6s    $%d\n","Total",tot);
    printf("                                                           ---------------------\n");
    printf("\n                                     ***");
    printf("\n\n-----------------------------------------------------------------------\n");
}


// Function to find the Count of Total Booked Seats


int totalSeatsBooked(int seats[]) {
    int total = 0,avl=0;
    for(int i = 0; i < TOTAL_SEATS_PER_BUS; i++) {
        if(seats[i] == 1) {
            total++;
        }
    }
    return total;
}


// Function to Find the Count of Available Seats


int avlSeats(int seats[]) {
    int avl=0;
    for(int i = 0; i < TOTAL_SEATS_PER_BUS; i++) {
        if(seats[i] == 0) {
            avl++;
        }
    }
    return avl;
}


// Function of Graphical Representation of Bus Seats


void displayGraphicalRepresentation(int seats[])
{
    printf("\nGraphical Representation:\n\n");
    for(int i = 0; i < TOTAL_SEATS_PER_BUS; i++) {
        printf("\t");
        if(seats[i] == 1) {
            printf("[X] ");
        } else {
            printf("[ ] ");
        }
        if((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n-----------------------------------------------------------------------\n");
}


// Funtion to View History of booking


void history(int Id)
{
    printf("\n-----------------------------------------------------------------------\n");
    printf("\n                       ----- History Page -----\n\n");
    if(bListCount>0)
    {
        printf("   User Name : %s\n",passengers[Id-50].name);
        printf("   User ID   : %d",Id);
        printf("\n\n            --------------------------------------------------------------------\n");
        printf("            S.No   City         Journey Date   Seat Count   Amount    Status\n");
        printf("            --------------------------------------------------------------------\n\n");
        for(int i=0,sNo=1;i<bListCount;i++){
            //printf("%s\n",bList[i].date);
            if(strcmp(passengers[Id-50].name,bList[i].name)==0)
            {
                printf("            %-6d %-12s %-14s %-12d %-9d %s\n",sNo,bList[i].city,bList[i].date,bList[i].seatC,bList[i].total,bList[i].status);
                sNo++;
            }
        }
        printf("\n            --------------------------------------------------------------------\n\n");
    }
    else
    {
        printf("                      ----- No Records Found..! -----\n");
    }
    printf("\n-----------------------------------------------------------------------\n");
}


// Function of cancellation


void cancellation(int seats[],int Id)
{
    int sNo,f=0;
    int arr[]={};
    int arrLen=0;
    int exist=0;
    printf("\n\n-----------------------------------------------------------------------\n");
    printf("\n                 ----- Cancellation Page -----\n\n");
    if(bListCount>0)
    {
        printf("   User Name : %s\n",passengers[Id-50].name);
        printf("   User ID   : %d",Id);
        printf("\n\n            --------------------------------------------------------------------\n");
        printf("            S.No   City         Journey Date   Seat Count   Amount    Status\n");
        printf("            --------------------------------------------------------------------\n\n");
        for(int i=0;i<bListCount;i++)
        {
            if(strcmp(passengers[Id-50].name,bList[i].name)==0  && strcmp(bList[i].status,"Booked")==0)
            {
                f=1;
                arr[arrLen]=i;
                printf("            %-6d %-12s %-14s %-12d %-9d %s\n",i,bList[i].city,bList[i].date,bList[i].seatC,bList[i].total,bList[i].status);
                arrLen++;
            }
        }
        if(f==0)
        {
            printf("\n                                   --- No Records found ---");
            printf("\n            --------------------------------------------------------------------\n\n");
        }
        else
        {
            printf("            --------------------------------------------------------------------\n\n");
            do
            {
                printf("\nPlease Enter the S.No to be Cancelled : ");
                while (scanf("%d", &sNo) != 1) {
                printf("\n             -----Invalid Choice-----\n\nPlease enter a Valid Option: ");


                // Clear the input buffer
                while (getchar() != '\n');
                }
                if(strcmp(bList[sNo].status,"Cancelled")==0)
                {
                    printf("\n            ----- Please Check the S.No Number. It's Invalid..! -----\n");
                }
                else if(sNo >= bListCount || sNo<0)
                {
                    printf("\n            ----- Please Check the S.No Number. It's Invalid..! -----\n");
                }
                else if(strcmp(passengers[Id-50].name,bList[sNo].name)==-1)
                {
                    printf("\n            ----- Please Check the S.No Number. It's Invalid..! -----\n");
                }
                else
                {
                    if(strcmp(passengers[Id-50].name,bList[sNo].name)==0)
                    {
                        int cfm=0;
                        printf("\nPlease CONFIRM to CANCEL the Ticket :\n\n\t\t1. YES           2. NO\n");
                        printf("\nEnter your Option : ");
                        while (scanf("%d", &cfm) != 1) {
                            printf("\n             -----Invalid Choice-----\n\nPlease enter a Valid Option: ");


                            // Clear the input buffer
                            while (getchar() != '\n');
                        }
                        if(cfm == 1)
                        {
                            strcpy(bList[sNo].status,"Cancelled");
                            printf("\n            --- Ticket for %s on %s has been cancelled successfully ---\n",bList[sNo].name,bList[sNo].date);
                            //bList[sNo].total=0;
                            for(int i=0;i<bList[sNo].arrayC ;i++)
                            {
                                seats[(bList[sNo].sNumber[i])-1]=0;
                            }
                            break;
                        }
                        else if(cfm==2)
                        {
                            printf("\n                ----- Cancellation UNSUCCESSFUL..! -----\n");
                            break;
                        }
                        else{
                            printf("\n            ----- Please Check the S.No Number. It's Invalid..! -----\n");
                        }
                    }
                    else
                    {
                        printf("\n            ----- Please Check the S.No Number. It's Invalid..! -----\n");
                    }
                }
               
            }while(1!=0);
        }
    }
    else{
        printf("                  ----- No Records Found..! -----\n");
    }
    printf("\n-----------------------------------------------------------------------\n");
}

