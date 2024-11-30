#include <stdio.h>
#include "contact.h"
#include "file.h"

int main() 
{
    
    int opt,flag=0;
    AddressBook book;
    char option;  
    
    loadContactsFromFile(&book);      
    //initialize(&book);
    do
    {
        printf("Address Book Menu\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
        printf("6. Exit\n");
        scanf("%d",&opt);
        switch(opt)
            {
                case 1: createContact(&book);
                        break;
                case 2: searchContact(&book);
                        break;
                case 3: editContact(&book);
                        break;
                case 4:deleteContact(&book);
                        break;
                case 5:listContacts(&book);
                        break;
                case 6:printf("Do you want to save the file : (y/n)\n");
                        getchar();
                        scanf("%c",&option);
                        if(option=='y')
                        {
                        saveContactsToFile(&book); 
                        printf("File saved successfully\n");
                        flag=1;
                        }
                        break;
                        if(option=='n')
                        flag=1;
                        break;
                default:printf("Invalid option");
            }
            if(flag)
            break;
    }while(opt>=1 && opt<=5);     
}
