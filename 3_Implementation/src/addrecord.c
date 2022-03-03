#include"addrecord.h"
#include"record.c"
void addrecord( )

{

//clear the screen
    system("cls");
//pointer to the file
    FILE *filePtr ;
//to store time and choices
    char other = 'Y' ,time[9];

    struct record instance ;

    char filename[10];


    printf("\n\n\t\t***************************\n");

    printf("\t\t* WELCOME TO THE CREATE MENU *");

    printf("\n\t\t***************************\n\n");

    printf("\n\n\tPLEASE ENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");

  

    fgets(filename,20,stdin);
//save the file with the date as its name
    filePtr = fopen (filename, "ab+" ) ;
//error handling to check null pointer
    if ( filePtr == NULL )

    {

        filePtr=fopen(filename,"wb+");

        if(filePtr==NULL)

        {

            printf("\nSYSTEM  ERROR...");

            printf("\nPLEASE PRESS ANY KEY TO EXIT");

            

            return ;

        }

    }
//take time as input
    while ( other == 'Y'|| other=='y' )

    {

        int choice=0;


        printf ( "\n\tENTER TIME IN THIS FORMAT :[hh:mm]:");

        scanf ("%9s",time);

        rewind (filePtr);

        while
        (fread(&instance,sizeof(instance),1,filePtr)==1)

        {

            if(strcmp(instance.timee,time)==0)

            {

                printf("\n\tTHE ENTERED RECORD ALREADY EXISTS.\n");
//SET CHOICE TO 1
                choice=1;

            }

        }

        if(choice==0)

        {

            strcpy(instance.timee,time);

            printf("\tENTER A NAME:");

        
//SAVE IT IN THE STRUCTURE
            fgets(instance.namee,20,stdin);

        

            printf("\tENTER A PLACE:");

            fgets(instance.placee,20,stdin);

        

            printf("\tENTER THE DURATION:");

            fgets(instance.durationn,20,stdin);

        

            printf("\tENTER A NOTE:");

            fgets(instance.notee,20,stdin);

            fwrite ( &instance, sizeof ( instance ), 1, filePtr ) ;

            printf("\nYOUR RECORD IS ADDED...\n");
//HERE ALL THE RECORD GETS ADDED
        }
//OPTION TO ADD ANOTHER RECORD 


        printf ( "\n\tADD OTHER RECORD...(Y/N) " ) ;

        fflush ( stdin ) ;

        other = getchar( ) ;

    }



    fclose ( filePtr ) ;
// CLOSE THE FILE 

    printf("\n\n\tPLEASE PRESS ANY OF THE KEY TO EXIT...");


    

}