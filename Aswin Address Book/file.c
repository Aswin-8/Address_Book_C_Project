#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) 
{
    addressBook->fptr=fopen("addressbook.csv","w");          //opening file in write mode so we can save the data in file
    fprintf(addressBook->fptr,"#%d#\n",addressBook->contactCount); //printing the contact count
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(addressBook->fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);  //printing the name,phone no and email
    } 
    fclose(addressBook->fptr);                   //closing file pointer
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    addressBook->fptr=fopen("addressbook.csv","r");                  //opening the file in read mode
    if(addressBook->fptr == NULL)
    {
        printf("File not found");                                    //if file not found returning error message
        return ;
    }
    char str[30];
    int num;
    fscanf(addressBook->fptr,"%s",str);                              //reading data from file and storing in str
    num=atoi(strtok(str+1,"#"));                                     //storing contact count
    addressBook->contactCount=num;
    addressBook->contacts=malloc(num * sizeof(Contact));             //dynamically allocating memory 
    //fgetc(addressBook->fptr);
    for(int i=0;i<num;i++)
    { 
        fgetc(addressBook->fptr);
        fscanf(addressBook->fptr,"%[^\n]",str); 
        strcpy(addressBook->contacts[i].name, strtok(str,","));            //storing name,phone no and email after reading data from file
        strcpy(addressBook->contacts[i].phone,strtok(NULL,","));
        strcpy(addressBook->contacts[i].email,strtok(NULL,","));
    } 
    fclose(addressBook->fptr);
}
