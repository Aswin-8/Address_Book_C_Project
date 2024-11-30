#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"


void listContacts(AddressBook *addressBook) 
{
    int i;
    printf("Contacts: \n");
    printf("Name \t\t Phone.no \t  email id\n");
    for(i=0;i<addressBook->contactCount;i++)               //printing name,phone no and email
    {
        printf("%s \t %s \t  %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}

/*void initialize(AddressBook *addressBook) 
{
   populateAddressBook(addressBook) ;
} */

void saveAndExit(AddressBook *addressBook) 
{
}


void createContact(AddressBook *addressBook) 
{
    char Name[20],Phone[15],Email[20];
    int i,j,flag,pos;
    printf("Enter the details:\n");
    printf("Name: ");
    getchar();
    scanf("%[^\n]",Name);
    printf("Phone: ");
    getchar();
    scanf("%[^\n]",Phone);
    for(i=0;i<addressBook->contactCount;i++)
    {
       
        flag=strcmp(Phone, addressBook->contacts[i].phone);                  //checking if the entered phone no already exists
        if(flag==0)
            {
                printf("Phone no already exists\n");
                printf("Phone: \n");
                getchar();
                scanf("%[^\n]",Phone);
                flag=1;
                break;
            }
    }
    if(flag)
    {
        printf("Email: ");
        getchar();
        scanf("%[^\n]",Email);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=strcmp(Email, addressBook->contacts[i].email);            //checking if the entered email already exists
            if(flag==0)
            {
                printf("Email ID already exists\n");
                printf("Email: \n");
                getchar();
                scanf("%[^\n]",Email);
                flag=1;
                break;
            }
        } 
        if(flag)
        {    
            addressBook->contacts = realloc(addressBook->contacts,(addressBook->contactCount+1) * sizeof(Contact));  //increasing dynamically allocated memory 
            addressBook->contactCount++;
            pos=addressBook->contactCount;
            strcpy(addressBook->contacts[pos-1].name,Name);               //storing the newly added name,phone no and email
            strcpy(addressBook->contacts[pos-1].phone,Phone);
            strcpy(addressBook->contacts[pos-1].email,Email);
        }
    }
}

void searchContact(AddressBook *addressBook) 
{
    int i,flag=1,opt;
    char str[20];
    getchar();
    printf("1.search by name\n");                               //asking user how to search
    printf("2.search by phone number\n");
    printf("3.search by mail_id\n");
    printf("Select an option: \n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:printf("Enter the name :\n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=(strcmp(str,addressBook->contacts[i].name));                     //checking the entered name exist in address book
            if(flag==0)
            {
            printf("%s \t %s \t  %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            break;
            }
        }
        break;
        case 2:printf("Enter the phone number :\n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=(strcmp(str,addressBook->contacts[i].phone));              //checking the entered phone no exist in address book
            if(flag==0)
            {
            printf("%s \t %s \t  %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            break;
            }
        }
        break;
        case 3:printf("Enter the email id :\n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=(strncmp(str,addressBook->contacts[i].email,strlen(str)));       //checking the entered email exist in address book
            if(flag==0)
            {
            printf("%s \t %s \t  %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            break;
            }
        }
        break;
        default: printf("Enter a valid option\n");
    }
    if(flag)
    {
        printf("Contact not found\n");
    }
}

void editContact(AddressBook *addressBook) 
{
    int i,index,flag=1,opt,opt1;
    printf("Which contact detail do you want to edit: \n");             //asking the user how to search in address book
    printf("1.Select by name\n");
    printf("2.Select by  phone number\n");
    printf("3.Select by mail_id\n");
    scanf("%d",&opt);
    char str[20],Name[20],Phone[20],Email[20];
    switch(opt)
    {
        case 1: printf("Enter the name : \n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=(strcmp(str, addressBook->contacts[i].name) );       //checking the entered name exist in address book
            if(flag==0)
            {
               printf("Do you want to :\n");
               printf("1.Edit Name\n");                                  //asking the user which category he wnt to edit
               printf("2.Edit phone number\n");                        
               printf("3.Edit Email id\n");
               printf("Enter the option : \n");
               scanf("%d",&opt1);
                switch(opt1)
                {
                    case 1: printf("Enter the name: \n");
                                getchar();
                                scanf("%[^\n]",Name);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].name,Name);
                                break;
                    case 2: printf("Enter the phone no: \n");
                                getchar();
                                scanf("%[^\n]",Phone);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].phone,Phone);
                                break;
                    case 3: printf("Enter the email id: \n");
                                getchar();
                                scanf("%[^\n]",Email);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].email,Email);
                                break;
                    default : printf("Invalid option \n");
                }
                break;
            }
        }
        break;
        
        case 2: printf("Enter the phone no : \n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=(strcmp(str, addressBook->contacts[i].phone) );          //searching by phone no
            if(flag==0)
            {
               printf("Do you want to :\n");
               printf("1.Edit Name\n");
               printf("2.Edit phone number\n");
               printf("3.Edit Email id\n");
               printf("Enter the option : \n");
               scanf("%d",&opt1);
                switch(opt1)
                {
                    case 1: printf("Enter the name: \n");
                                getchar();
                                scanf("%[^\n]",Name);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].name,Name);
                                break;
                    case 2: printf("Enter the phone no: \n");
                                getchar();
                                scanf("%[^\n]",Phone);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].phone,Phone);
                                break;
                    case 3: printf("Enter the email id: \n");
                                getchar();
                                scanf("%[^\n]",Email);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].email,Email);
                                break;
                    default : printf("Invalid option \n");
                }
                break;
            }
        }
        break;

        case 3: printf("Enter the Email id : \n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=(strncmp(str, addressBook->contacts[i].email,strlen(str)));          //checking the entered email exist in address book
            if(flag==0)
            {
               printf("Do you want to :\n");
               printf("1.Edit Name\n");
               printf("2.Edit phone number\n");
               printf("3.Edit Email id\n");
               printf("Enter the option : \n");
               scanf("%d",&opt1);
                switch(opt1)
                {
                    case 1: printf("Enter the name: \n");
                                getchar();
                                scanf("%[^\n]",Name);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].name,Name);
                                break;
                    case 2: printf("Enter the phone no: \n");
                                getchar();
                                scanf("%[^\n]",Phone);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].phone,Phone);
                                break;
                    case 3: printf("Enter the email id: \n");
                                getchar();
                                scanf("%[^\n]",Email);
                                printf("Contact updated successfully.\n");
                                index=i;
                                strcpy(addressBook->contacts[index].email,Email);
                                break;
                    default : printf("Invalid option \n");
                }
                break;
            }
        }
        break;
        default :printf("Invalid option\n");
    }
    if(flag)
    {
        printf("Contact not found\n");
    }
}

void deleteContact(AddressBook *addressBook) 
{
    char str[20];
    int *ptr;
    int i,j,flag,opt,opt1;
    printf("Which contact detail do you want to delete: \n");        //asking the user to how to select the data
    printf("1.Select by name\n");
    printf("2.Select by phone number\n");
    printf("3.Select by mail_id\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1: printf("Enter the name : \n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=strcmp(str, addressBook->contacts[i].name);           //checking the entered name exist in address book
            if(flag==0)
            {
                for(j=i;j<addressBook->contactCount;j++)
                {
                    addressBook->contacts[j]=addressBook->contacts[j+1];              //updating the address book
                }
                printf("Contact deleted succesfully\n");
                break;
            }
        }
        break;
        case 2: printf("Enter the phone no : \n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=strcmp(str, addressBook->contacts[i].phone);             //checking the entered phone exist in address book
            if(flag==0)
            {
                for(j=i;j<addressBook->contactCount;j++)
                {
                    addressBook->contacts[j]=addressBook->contacts[j+1];     //updating address book
                }
                printf("Contact deleted succesfully\n");
                break;
            }
        }
        break;
        case 3: printf("Enter the email id : \n");
        getchar();
        scanf("%[^\n]",str);
        for(i=0;i<addressBook->contactCount;i++)
        {
            flag=strncmp(str, addressBook->contacts[i].email,strlen(str));        //checking the entered email exist in address book
            if(flag==0)
            {
                for(j=i;j<addressBook->contactCount;j++)
                {
                    addressBook->contacts[j]=addressBook->contacts[j+1];          //updating address book
                }
                printf("Contact deleted succesfully\n");
                break;
            }
        }
        break;
        default : printf("Invalid option");
                  break;
    }
    if(flag==0)
    {
    ptr = realloc(addressBook->contacts,(addressBook->contactCount-1) * sizeof(Contact));           //reducing the size of dynamically allocated contact
    addressBook->contactCount--;
    }
    if(flag)
    {
        printf("Contact not found\n");
    }
}