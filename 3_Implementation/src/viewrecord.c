#include"viewrecord.h"
#include "record.c"
void viewrecord( )

{

    FILE *fpointer ;

    system("cls");

    struct record user ;

    char time[6],userchoice,name[9];

    int choice;

    printf("\n\n\t\t*******************************\n");

    printf("\t\t* WELCOME TO VIEWING MENU  *");

    printf("\n\t\t*******************************\n\n");

   

    do

    {
//ASKS YOUR TO ENTER THE DATE
        printf("\n\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:");


        fgets(name,20,stdin);

        fpointer = fopen ( name, "rb" ) ;

        if ( fpointer == NULL )

        {

            puts ( "\nTHE ENTERED RECORD DOES NOT EXIST...\n" ) ;

            printf("PRESS ANY KEY TO EXIT...");

            

            return ;

        }

        system("cls");
//ASKS YOUR ITS PREFERENCES
        printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");
        //WITH DAY
        printf("\n\t1.RECORD OF WHOLE OF THE DAY.");
      //  OR WITH TIME
        printf("\n\t2.RECORD OF A FIX TIME.");
        printf("\n\t\tPLEASE ENTER YOUR CHOICE:");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
//SHOWS THE RECORD ACC TO CHOICE
            printf("\nTHE WHOLE RECORD FOR  %s IS:",name);

            while ( fread ( &user, sizeof ( user ), 1, fpointer ) == 1 )

            {
                printf("\n");
                printf("\nTIME: %s",user.timee);

                printf("\nMEETING WITH: %s",user.namee);

                printf("\nMEETING AT: %s",user.placee);

                printf("\nDURATION: %s",user.durationn);

                printf("\nNOTE: %s",user.notee);

                printf("\n");
            }

            break;

        case 2:



            printf("\nENTER TIME:[hh:mm]:");

            fgets(time,20,stdin);

            while ( fread ( &user, sizeof ( user ), 1, fpointer ) == 1 )

            {

                if(strcmp(user.timee,time)==0)

                {

                    printf("\nYOUR RECORD IS:");

                    printf("\nTIME: %s",user.timee);

                    printf("\nMEETING WITH: %s",user.namee);

                    printf("\nMEETING AT: %s",user.placee);

                    printf("\nDUARATION: %s",user.durationn);

                    printf("\nNOTE: %s",user.notee);

                }

            }

            break;
//DEFAULT CASE FOR WRONG INPUTS
        default:
            printf("\nYOU TYPED SOMETHING ELSE...\n");

            break;

        }
//LOOP
        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");


        scanf("%c",&userchoice);

    }
    while(userchoice=='Y'||userchoice=='y');

    fclose ( fpointer ) ;

    return ;

}