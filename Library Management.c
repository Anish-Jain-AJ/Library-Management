#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


void create(void);
void operations(void);
void displaycomplete(void);
void addbook(void);
void exit1(void);
void search(void);
void author(void);
void title(void);
void stock(void);

//int k;
//char info[500];

struct                                                   //structure variable book declared for using in all
    {
        int callnumber;
        char booktitle[200];
        char bookauthor[200];
        int stockavailable;
    }book;

FILE *fp;                                               // declared fp as pinter to the data type FILE


int main(void)
{
    printf("*******************************************************************************");
    printf("\n\n\n\n                 Welcome To Library Management Software System\n\n");
    printf("\n            Developed By : ANISH JAIN , Guided By: DR. K P AGARWAL\n");
    printf("*******************************************************************************\n");

    printf("Press any key to continue and then press enter\n");
    char ch=getchar();
    system("cls");
    int a,b,c;
    printf("Choose an option from below and enter it's serial number\n\n");
    printf("1-Create a new database\n2-Perform operations on the existing database\n");
    printf("\nSerial Number:");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
         printf("\n\nWarning:If you enter the new database , previous database will be deleted\n\n");
         system("cls");
         printf("Press 1 to continue or 2 to go back to main menu\n");
         scanf("%d",&b);
         if(b==2)
             main();
         else
            create();
         break;

    case 2:

        operations();
        break;
    default :
        printf("Please enter a valid input\n");
        printf("Press 0 to go back to main menu or Press 1 to exit after input\n");

        scanf("%d",&c);

        if(c==0)
            main();
        else
            exit1();

    }
    return 0;
}

void displaycomplete(void)
{
    char info[500];
    fp=fopen("librarydata.txt","a+");                       //opening the file for adding data to it for both reading and writing
                                                            //it opens file librarydata.txt and assigns an identifier to the FILE type pointer fp
                                                            //this pointer contains all the information about a file
                                                            //the pointer fp is used as a communication link between the system and the program

    printf("\nCallNumber\tBookTitle\tBookAuthor\tStockAvailable\n",info);
    do
    {
        fgets(info,500,fp);                                 //enter string info,containing 500 characters,from file fp
        printf("%s\n",info);
    }
    while(!feof(fp));                                       //checking end of file condition via function feof of file fp
    fclose(fp);                                             //closing a file of pointer fp
}



void create(void)
{
    int i,c,n;
    printf("\n\nPlease enter the number of books you want to enter in your database\n\n");
    printf("No.:");
    scanf("%d",&n);
    FILE *fp;
    struct                                                 //declared array of structures of variable type struct
    {
        int callnumber;
        char booktitle[200];
        char bookauthor[200];
        int stockavailable;
    }book[n];

     fp= fopen("librarydata.txt","w");                     //opened the file for writing only
    printf("\n\nEnter the details of the book by two spaces between credentials and no space between each particular credential\n\n");


    printf("callnumber  Booktitle  bookauthor  stockavailable\n");

    for(i=0;i<n;i++)
    {
        fscanf(stdin,"%d           \t%s           \t%s        \t%d",&book[i].callnumber,&book[i].booktitle,&book[i].bookauthor,&book[i].stockavailable);
        fprintf(fp,"\n%d           \t%s           \t%s         \t%d",book[i].callnumber,book[i].booktitle,book[i].bookauthor,book[i].stockavailable);

    }
    //fscanf function is used for reading a set of values from a file stdin , which refers to the terminal and it is written by the fprintf function to the file that is being pointed by the file pointer fp

    fclose(fp);                                                               //closed the file of pointer fp
    fprintf(stdout,"\n\n");
    system("cls");

    printf("\n\nThanks , Your Data Has Been Stored\n");

    printf("\nPress 0 to go back to main menu or Press 1 to exit after input\n");

    scanf("%d",&c);

    if(c==0)
        main();
    else
        exit1();

}

void exit1(void)
{
    printf("\n\n                     Thanks For Using The Software                \n");
    printf("\n           Developed By : Anish Jain , Guided By : Dr. K P Agarwal\n\n");
}


void operations(void)
{
    FILE *fp;
    int a,c;
    printf("\nWelcome to operations section\n");
    printf("\nSelect a particular operation and enter it's serial number\n\n");
    printf("1-Add a new book\n2-Search a particular book\n3-Check the stock available\n4-Display the complete database\n");
    printf("\n\nSerial Number:");
    scanf("%d",&a);
    switch(a)
    {
        case 1:addbook();
        system("cls");

        printf("\n\nThe new book has been added\n\n");
        printf("Press 0 to go back to main menu or press 1 to exit\n\n");
        scanf("%d",&c);

        if(c==0)
            main();
        else
            exit1();
        break;

        case 2:search();

        break;


        case 3:stock();
        system("cls");

        printf("\n\nPress 0 to go back to main menu or press 1 to exit\n");
        scanf("%d",&c);

        if(c==0)
            main();
        else
            exit1();
        break;


        case 4:
        system("cls");
        displaycomplete();
        printf("\nThe display is complete\n");
        printf("\nPress 0 to go back to main menu or press 1 to exit\n\n");
        scanf("%d",&c);

        if(c==0)
            main();
        else
            exit1();
        break;

        default:

        printf("Please enter a valid input\n");
        printf("\nPress 0 to go back to main menu or Press 1 to exit after input\n\n");

        scanf("%d",&c);

        if(c==0)
            main();
        else
            exit1();
    }
}



void addbook(void)
{

    fp=fopen("librarydata.txt","a+");
                         //opening the file for adding data to it for both reading and writing
    printf("Enter the call number of the book:\n");
    scanf("%d",&book.callnumber);

    printf("Enter the title of the book:\n");
    scanf("%s",book.booktitle);

    printf("Enter the author of the book:\n");
    scanf("%s",book.bookauthor);

    printf("Enter the stock available of the book:\n");
    scanf("%d",&book.stockavailable);

    fprintf(fp,"\n%d           \t%s           \t%s         \t%d",book.callnumber,book.booktitle,book.bookauthor,book.stockavailable);
    //fprintf function is used to write set of data values to the file

    fclose(fp);                                                             //closed the file of pointer fp
}


void search(void)
{
    int a,c;
    printf("\n\nPlease enter the credential through which you want to perform search\n\n");
    printf("1-Author\n2-Title\n");
    printf("Credential:");
    scanf("%d",&a);
    switch(a)
    {
    case 1:author();
        system("cls");

        printf("Press 0 to go back to main menu or press 1 to exit\n");
        scanf("%d",&c);

        if(c==0)
            main();
        else
            exit1();
        break;


    case 2:title();
        system("cls");

        printf("Press 0 to go back to main menu or press 1 to exit\n");
        scanf("%d",&c);

        if(c==0)
            main();
        else
            exit1();
        break;

    default:

        printf("Please enter a valid input\n");
        printf("\nPress 0 to go back to main menu or Press 1 to exit after input\n\n");

        scanf("%d",&c);

        if(c==0)
            main();
        else
            exit1();

    }

}

void title(void)
{
    int i;
    char Target[25];
    int Found=0;
    if((fp=fopen("librarydata.txt","r"))==NULL)                   //checking whether the file is empty or not
        printf(" ! The File is Empty....\n\n");
    else
    {
        printf("\nEnter The Name Of Book : ");
        scanf("%s",Target);

        while(!feof(fp)&& Found==0)                            //loop continues until file pinter fp reaches end of the file and Found=1
        {

            fscanf(fp,"%d %s %s %d ", &book.callnumber,book.booktitle,book.bookauthor,&book.stockavailable);
            //fscanf function reads a set of data values from a file
            if(strcmp(Target,book.booktitle)==0)        //string is compared with the entered string of user
             Found=1;

        }
        system("cls");
        if(Found)
            printf("\n\nYes the book is available\n\n");                     //if found displaying yes else no
        else if(!Found)
            printf("\n\n! There is no such Entry....\n\n");
        fclose(fp);                                                          //closed the file of pointer fp
    }

}

void author(void)
{
    int i;
    char Target[500];
    int Found=0;

    if((fp=fopen("librarydata.txt","r"))==NULL)                              //checking whether the file is empty or not
    printf(" ! The file is empty....\n\n");
    else
    {
        printf("\nEnter The Name Of Author : ");
        scanf("%s",Target);
        printf("\nBooks:");
        while(!feof(fp))                                                     //running loop until file ends
        {
            fscanf(fp,"%d %s %s %d",&book.callnumber,book.booktitle,book.bookauthor,&book.stockavailable);
            //fscanf function reads a set of data values from a file
            if(strcmp(Target,book.bookauthor)==0)                           //string is compared with the entered string of user
            {
                Found=1;
                system("cls");
                printf("\n\t%s\n",book.booktitle);                          //if found then display the book title
            }

        }
        if(!Found)
        system("cls");
        printf("\n\n ! There is no such Entry....\n\n");
        fclose(fp);                                                         //closed the file of pointer fp
    }

}
void stock()
{
    int i;
    char Target[500];
    int Found=0;

    if((fp=fopen("librarydata.txt","r"))==NULL)                             //checking whether the file is empty or not
    printf("\n\n ! The file is empty.... \n\n");
    else
    {
        printf("\nEnter The Name Of Book : ");
            scanf("%s",Target);
        while(!feof(fp))                                                    //running loop until file ends
        {
            fscanf(fp,"%d %s %s %d",&book.callnumber,book.booktitle,book.bookauthor,&book.stockavailable);
            //fscanf function reads a set of data values from a file
            if(strcmp(Target,book.booktitle)==0)                            //string is compared with the entered string of user
            {
                Found=1;
                system("cls");
                printf("\n\n\tStock:%d\n\n",book.stockavailable);                 //if found displaying stock of that book
            }

        }
        if(!Found)
            system("cls");
            printf("\n\n ! There is no such Entry...\n\n");
        fclose(fp);                                                         //closed the file of pointer fp
    }

}





