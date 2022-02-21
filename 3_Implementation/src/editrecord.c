#include"inc/editrecord.h"
#include"record.c"
void editrecord()

{

    system("cls");

    FILE *fpointer ;

    struct record user_record ;

    char time[6],choice,filename[14];

    int choicee,count=0;

    printf("\n\n\t\t********************************\n");

    printf("\t\t* WELCOME TO THE UPDATION MENU *");

    printf("\n\t\t********************************\n\n");

    do

    {
//ASK FOR THE USER TO ENTER RECORD TO BE UPDATED
        printf("\n\tENTER THE DATE OF RECORD TO BE EDITED:[yyyy-mm-dd]: ");

        


        gets(filename);


        printf("\n\tENTER TIME:[hh:mm]:");

        gets(time);

        fpointer = fopen ( filename, "rb+" ) ;

        if ( fpointer == NULL )
// IF IT POOINTS TO MEANS THE RECORD DOESNT EXIST AT FIRST
        {

            printf( "\nTHE ENTERED RECORD DOES NOT EXISTS:" ) ;

            printf("\nPRESS ANY KEY TO GO BACK");

            getch();

            return;

        }

        while ( fread ( &user_record, sizeof ( user_record ), 1, fpointer ) == 1 )

        {

            if(strcmp(user_record.timee,time)==0)

            {

                printf("\nYOUR OLD RECORD WAS AS:");

                printf("\nOF TIME: %s",user_record.timee);

                printf("\nOF MEETING WITH: %s",user_record.namee);

                printf("\nAND MEETING AT: %s",user_record.placee);

                printf("\nWITH DURATION: %s",user_record.durationn);

                printf("\nOF NOTE: %s",user_record.notee);

                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");
//ASKS USER ABOUT WHAT IT WOULD LIKE TO EDIT
                printf("\n1.TIME");
//AND GIVE DIFFERENT CHOICES
                printf("\n2.MEETING PERSON.");

                printf("\n3.MEETING PLACE.");

                printf("\n4.DURATION.");

                printf("\n5.NOTE.");

                printf("\n6.WHOLE RECORD.");

                printf("\n7.GO BACK TO MAIN MENU.");
//PROCESS THE CHOICE
                do

                {

                    printf("\n\tENTER YOUR CHOICE:");

                    

                    scanf("%d",&choicee);

                    
//THEN UPDATE THE RECORD
                    switch(choicee)

                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(user_record.timee);

                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PERSON:");

                        gets(user_record.namee);

                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW MEETING PLACE:");

                        gets(user_record.placee);

                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nDURATION:");

                        gets(user_record.durationn);

                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");

                        printf("\nNOTE:");

                        gets(user_record.notee);

                        break;

                    case 6:
                        printf("\nENTER THE NEW DATA:");

                        printf("\nNEW TIME:[hh:mm]:");

                        gets(user_record.timee);

                        printf("\nNEW MEETING PERSON:");

                        gets(user_record.namee);

                        printf("\nNEW MEETING PLACE:");

                        gets(user_record.placee);

                        printf("\nDURATION:");

                        gets(user_record.durationn);

                        printf("\nNOTE:");

                        gets(user_record.notee);

                        break;

                    case 7:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");

                        getch();

                        return ;

                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");

                        break;

                    }

                }
                while(choicee<1||choicee>8);

                fseek(fpointer,-sizeof(user_record),SEEK_CUR);

                fwrite(&user_record,sizeof(user_record),1,fpointer);

                fseek(fpointer,-sizeof(user_record),SEEK_CUR);

                fread(&user_record,sizeof(user_record),1,fpointer);

                choice=5;

                break;

            }

        }

        if(choice==5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");

            printf("--------------------\n");

            printf("THE NEW RECORD IS:\n");

            printf("--------------------\n");

            printf("\nTIME: %s",user_record.timee);

            printf("\nMEETING WITH: %s",user_record.namee);

            printf("\nMEETING AT: %s",user_record.placee);

            printf("\nDURATION: %s",user_record.durationn);

            printf("\nNOTE: %s",user_record.notee);

            fclose(fpointer);

            printf("\n\n\tWOULD YOU ALSO LIKE TO EDIT ANOTHER RECORD.(Y/N)");

            scanf("%c",&choice);

            count++;

        }

        else

        {

            printf("\nTHE RECORD DOES NOT EXIST ::\n");

            printf("\nWANT TO TRY AGAIN...(Y/N)");

            scanf("%c",&choice);

        }

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpointer ) ;

    if(count==1)

        printf("\n%d FILE IS EDITED...\n",count);

    else if(count>1)

        printf("\n%d FILES ARE EDITED..\n",count);

    else

        printf("\nNO FILES EDITED...\n");

    printf("\tPRESS ENTER TO EXIT EDITING MENU.");

    getch();

}