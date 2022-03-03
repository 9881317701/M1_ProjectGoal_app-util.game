#include"deleterecord.h"
#include"record.c"

void deleterecord( )
/**
 * @brief This function is used to Delete the record
 * 
 */
{
//CLEAR THE SCREEN
    system("cls");

    FILE *fp,*fptr ;

    struct record filee ;

    char filename[10],REPEAT = 'Y' ,time[9];;

  

    printf("\n\n\t\t*************************\n");

    printf("\t\t* WELCOME TO THE DELETE MENU*");

    printf("\n\t\t*************************\n\n");


    while ( REPEAT == 'Y' )

    {
          int choice;
//CHOICE IS GIVENT TO THE USER
        printf("\n\n\tWHAT WOULD YOU LIKE TO DELETE.");

        printf("\n\n\t#WHOLE RECORD\t\t\t[1]");

        printf("\n\t#A PARTICULAR RECORD BY TIME\t[2]");

        do

        {

            printf("\n\t\tPLEASE ENTER YOU CHOICE:");

            scanf("%d",&choice);

            switch(choice)

            {

            case 1:
//ASKS USER TO ENTER THE DATE OF RECORD
                printf("\n\tENTER THE DATE OF RECORD TO BE DELETED:\n IN THE FORMAT [yyyy-mm-dd]:");

                

                    fgets(filename,20,stdin);

                fp = fopen (filename, "wb" ) ;
// IF THERE IS NO SUCH FILE
                if ( fp == NULL )

                {

                    printf("\nTHE ENTERED FILE DOES NOT EXISTS");

                    printf("\nPLEASE PRESS ANY KEY TO GO BACK.");

                    

                    return ;

                }
//IF THERE IS ,THEN DELETE THE FILE
                fclose(fp);

                remove(filename);

                printf("\nSELECTED FILE DELETED SUCCESFULLY...");

                break;
//SAME GOES WITH THE CHOICE 2
            case 2:

                printf("\n\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");

                

                fgets(filename,20,stdin);

                fp = fopen (filename, "rb" ) ;

                if ( fp == NULL )

                {

                    printf("\nTHE ENTERED FILE DOES NOT EXISTS");

                    printf("\nPRESS ANY KEY TO GO BACK.");

                    

                    return ;

                }

                fptr=fopen("temp","wb");
//NULL PTR CHECK
                if(fptr==NULL)

                {

                    printf("\nSYSTEM ERROR");

                    printf("\nPRESS ANY KEY TO GO BACK");

                    

                    return ;

                }

                printf("\n\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");

                

                fgets(time,20,stdin);

                while(fread (&filee,sizeof(filee),1,fp)==1)

                {

                    if(strcmp (filee.timee,time)!=0)

                        fwrite (&filee,sizeof(filee),1,fptr);

                }

                fclose(fp);

                fclose(fptr);

                remove(filename);

                rename("temp",filename);

                printf("\nFILE DELETED SUCCESFULLY...");

                break;
//INCASE OF ERROR INPUT
            default:

                printf("\n\tYOU ENTERED WRONG CHOICE ");

                break;

            }

        }
        while(choice<1||choice>2);
//TO NAVIGATE
        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");

        

        scanf("%c",&REPEAT);

    }

    printf("\n\n\t PLEASE PRESS ANY KEY TO EXIT... ");

    

}