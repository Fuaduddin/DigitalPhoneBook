#include<stdio.h>
#include<windows.h>
void add_contact();
void search_contact();
void delete_contact();
void view_all_contact();
void modifyrecord();
void search();
void search_contact_number();
void search_group();
int main()
{
    system("color 6f");
     menu();
    return 0;
}
void menu()
{
    system("cls");
    printf("*****PHONE BOOK*****\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Delete Contact\n");
    printf("4. View All Contact\n");
    printf("5. Modify Contact\n");
    printf("6. Search Group Contact \n");
    printf("7. Exit \n");
    printf(" Enter Your Choice:- \n");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        add_contact();
        break;
    case 2:
        search();
        break;
    case 3:
        delete_contact();
        break;
    case 4:
        view_all_contact();
        break;
    case 5:
      modifyrecord();
    break;
        case 6:
        search_group();
        break;
         case 7:
        exit(0);
    }

}
void search()
{
     printf("1. Search  Contact by Name \n");
    printf("2. Search  Contact by Number \n");
    printf(" Enter Your Choice:- \n");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        search_contact();
        break;
    case 2:
        search_contact_number();
        break;
    }

}
void add_contact()
{
    char mob[100], name[20],gname[50],address[50], email[20], domain[20],lname[50];
    int i=0, len=0,count=0,w,option,n;
    char name1[20],lname1[50];
    FILE *fp;
    fp=fopen("contact.txt","a+");
    system("cls");
    printf("*****ADD CONTACT***** \n");
    printf("First Name    :- \n");
    scanf("%s",&name);
    printf("Last Name    :- \n");
    scanf("%s",&lname);
    if (fp!=NULL)
    {
           while(fscanf(fp,"%s %s %s %s %s %s",name1,lname1,address,gname,mob,email)!=EOF)
        {
            while(strcmp(name,name1)==0 && strcmp(lname,lname1)==0)
            {
               if(strcmp(name,name1)==0 && strcmp(lname,lname1)==0)
                {
                  printf("The Name Is already Exited \n ");
                  printf("First Name    :- \n");
                  scanf("%s",&name);
                  printf("Last Name    :- \n");
                 scanf("%s",&lname);

               }
           }
        }
    }
     printf("The Name is saved\n");
     printf("Address   :- \n");
     scanf("%s",&address);
     printf("Add Group    :- \n");
     scanf("%s",&gname);
     printf("Enter a number: ");
     scanf("%s",&mob);
    while(mob[i]!='\0')

    {
        if((mob[i]>='a' && mob[i]<='z') ||  (mob[i]>='A' && mob[i]<='Z') || mob[i]==' ' || mob[i]=='\n' || mob[i]=='\t')
         {
             printf("your input number is invalid, number must be in  digits.\nplease try again.\n");
             exit(1);
         }
         i++;
    }

    len=strlen(mob);
int a=0;


       if(len==11)
       {
           printf("The number is saved\n");
       }
       else
       {
            printf("Your number is %d digit , its must be 11 digit",len);
            printf("\nEnter phone number again : ");
            scanf("%s",&mob);
            len=strlen(mob);
             if(len!=11)
             {
                 while( len>11 || len<11 )
                {
                     if(len !=11)
                        {
                          printf("PLease Enter Number Again");
                          printf("Your number is %d digit , its must be 11 digit",len);
                          printf("\nEnter phone number again : ");
                          scanf("%s",&mob);
                          len=strlen(mob);

                         }
                }

            }
        }
    printf("The number is saved\n");
    printf("Enter email adress : \n");
    scanf("%s",email);
    printf("Enter domain : ");
    scanf("%s",&domain);
    char dom1[]="@gmail.com";
    char dom2[]="@yahoo.com";
    char dom3[]="@outlook.com";
    printf("Enter Which mail You Want to Check");
    printf(" \n1=gmail     2=yahoo      3=outlook \n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        for(w=0; w<10; w++)
            if(domain[w]==dom1[w])
                count++;
        strcat(email,domain);
        if(count==10)
        {

            printf("The email : %s is saved. \n",email);
            break;
        }
        else
            printf("The email %s is Invalid! \n",email);
            printf("\nEnter email again :");
            scanf("%s",&email);
            printf("Enter domain : ");
            scanf("%s",&domain);
            strcat(email,domain);
            printf("The email : %s is saved. \n",email);
            break;
    case 2:

        for(w=0; w<10; w++)
            if(domain[w]==dom2[w])
                count++;
        strcat(email,domain);
        if(count==10)
        {
            printf("The email :%s is saved. \n",email);
            break;
        }
        else
            printf("The email : %s is Invalid! \n ",email);
            printf("\nEnter email again : \n");
            scanf("%s",&email);
            printf("Enter domain : ");
            scanf("%s",&domain);
            strcat(email,domain);
            printf("The email : %s is saved. \n",email);

        break;
    case 3:

        for(w=0; w<12; w++)
            if(domain[w]==dom3[w])
                count++;
        strcat(email,domain);
        if(count==12)
        {


            printf("The email : %s is saved. \n",email);
            break;
        }

        else
            printf("The email %s is Invalid! \n ",email);
            printf("\nEnter email again : \n");
            scanf("%s",&email);
            printf("Enter domain : \n");
            scanf("%s",&domain);
            strcat(email,domain);
            printf("The email : %s is saved. \n",email);

        break;
    }
    fprintf(fp,"%s %s  %s %s %s %s \n",name,lname,address,gname,mob,email);
    fclose(fp);
    printf("1. Main Menu \n");
    printf("2. Exit \n");
    printf("\nPRESS ANY KEY TO CONTINUE");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        menu();
        break;
    case 2:
        exit(0);
        break;
    }
}
void search_contact()
{

    char name[20],mob[20],email[30],gname[50],address[50],lname[50];
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("*****SEARCH CONTACT***** \n");
    printf("\n Enter First Name :- \n");
    scanf("%s",&name);
    printf("\n Enter Last Name :- \n");
    scanf("%s",&lname);
    char name1[20],lname1[50];
    while(fscanf(fp,"%s %s %s %s %s %s",name1,lname1,address,gname,mob,email)!=EOF)
    {
        if(strcmp(name,name1)==0 && strcmp(lname,lname1)==0)
        {   strcat(name1,lname1);
            printf("\nNAME     :- %s\n",name1);
            printf("\n Address  :- %s\n",address);
            printf("\n Group   :- %s\n\n",gname);
            printf("\nMOB NO.  :- %s\n",mob);
            printf("\nEmail    :- %s\n\n",email);

        }
    }
    fclose(fp);
    printf("1. Main Menu \n");
    printf("2. Exit \n");
    printf("\nPRESS ANY KEY TO CONTINUE");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        menu();
        break;
    case 2:
        exit(0);
        break;
    }
}
void delete_contact()
{
    char name[20],mob[20],email[30],gname[50],address[50],lname[50];
    char name1[20],lname1[50];
    FILE *fp,*fp1;
    fp=fopen("contact.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("*****DELETE CONTACT***** \n");
    printf("\n Enter First Name :- \n");
    scanf("%s",&name);
    printf("\n Enter Last Name :- \n");
    scanf("%s",&lname);
    while(fscanf(fp,"%s %s %s %s %s %s",name1,lname1,address,gname,mob,email)!=EOF)
    {
        if(strcmp(name,name1)==0 && strcmp(lname,lname1)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s %s %s %s %s\n",name1,lname1,address,gname,mob,email);
    }

    fclose(fp);
    fclose(fp1);
    fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s",name1,lname1,address,gname,mob,email)!=EOF)
    {

        fprintf(fp,"%s %s %s %s %s %s\n",name1,lname1,address,gname,mob,email);
    }

    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\nThe Contact has been deleted! \n");
    printf("1. Main Menu \n");
    printf("2. Exit \n");
    printf("\nPRESS ANY KEY TO CONTINUE");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        menu();
        break;
    case 2:
        exit(0);
        break;
    }

}
void view_all_contact()
{
int option,i=0;
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("*****ALL CONTACTS*****\n");
    char name[20],mob[20],email[30],address[50],gname[35],lname[50];
    while(fscanf(fp,"%s %s %s %s %s %s ",name,lname,address,gname,mob,email)!=EOF)
    {

             strcat(name,lname);
            printf("\nNAME     :- %s\n",name);
            printf("\n Address  :- %s\n",address);
            printf("\n Group   :- %s\n\n",gname);
            printf("\nMOB NO.  :- %s\n",mob);
            printf("\nEmail    :- %s\n\n",email);

            i++;

    }
    printf("Total Contacts:- %d \n ",i);
    fclose(fp);
    printf("PRESS ANY KEY TO CONTINUE \n");
    printf("1.Main Menu\n");
    printf("2. Exit\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        main();
        break;
    case 2:
        exit(0);
        break;
    }

}
void search_group()
{

    char name[20],address[50],gname[35],lname[50];
    int option,i=0;
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("*****SEARCH CONTACT***** \n");
    printf(" Group Name :- \n");
    scanf("%s",&gname);
    char gname1[20],mob[20],email[30];
    while(fscanf(fp,"%s %s %s %s %s %s ",name,lname,address,gname1,mob,email)!=EOF)
    {
        if(strcmp(gname,gname1)==0)
        {
            strcat(name,lname);
            printf("\nNAME     :- %s\n",name);
            printf("\n Address  :- %s\n",address);
            printf("\n Group   :- %s\n\n",gname1);
            printf("\nMOB NO.  :- %s\n",mob);
            printf("\nEmail    :- %s\n\n",email);
            i++;
        }
    }
    printf("Total Contacts : %d \n",i);
    fclose(fp);
    printf("PRESS ANY KEY TO CONTINUE \n");
    printf("1.Main Menu\n");
    printf("2. Exit\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        main();
        break;
    case 2:
        exit(0);
        break;
    }
}
void search_contact_number()
{

    char name[20],address[50],gname[35],email[30],mob[50],lname[50];
    int option,i=0;
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("*****SEARCH CONTACT***** \n");
    printf(" Enter Number :- \n");
    scanf("%s",&mob);
    char mob1[20];
    while(fscanf(fp,"%s %s %s %s %s %s ",name,lname,address,gname,mob1,email)!=EOF)
    {
        if(strcmp(mob,mob1)==0)
        {
            strcat(name,lname);
            printf("\nNAME     :- %s\n",name);
            printf("\n Address  :- %s\n",address);
            printf("\n Group   :- %s\n\n",gname);
            printf("\nMOB NO.  :- %s\n",mob1);
            printf("\nEmail    :- %s\n\n",email);

        }
    }
    fclose(fp);
    printf("PRESS ANY KEY TO CONTINUE \n");
    printf("1.Main Menu\n");
    printf("2. Exit\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        main();
        break;
    case 2:
        exit(0);
        break;
    }
}
void modifyrecord()
{   char name[20],mob[20],email[30],gname[50],address[50],lname[50],domain[50];
    char name1[20],lname1[50];
    int i=0;
    FILE *fp,*fp1;
    fp=fopen("contact.txt","r");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("*****MODIFY RECORD***** \n");
    printf("\n Enter First Name :- \n");
    scanf("%s",&name);
    printf("\n Enter Last Name :- \n");
    scanf("%s",&lname);
    while(fscanf(fp,"%s %s %s %s %s %s",name1,lname1,address,gname,mob,email)!=EOF)
    {
        if(strcmp(name,name1)==0 && strcmp(lname,lname1)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s %s %s %s %s\n",name1,lname1,address,gname,mob,email);
    }

    fclose(fp);
    fclose(fp1);
    fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s %s %s %s %s",name1,lname1,address,gname,mob,email)!=EOF)
    {

    if(i<1){
             printf("First Name    :- \n");
             scanf("%s",&name);
             printf("Last Name    :- \n");
             scanf("%s",&lname);
             printf("Address   :- \n");
             scanf("%s",&address);
             printf("Add Group    :- \n");
             scanf("%s",&gname);
             printf("Enter a number: ");
             scanf("%s",&mob);
             printf("Enter email adress : \n");
             scanf("%s",email);
             printf("Enter domain : ");
             scanf("%s",&domain);
             strcat(email,domain);
             fprintf(fp,"%s %s %s %s %s %s\n",name,lname,address,gname,mob,email);
             i++;
    }
        fprintf(fp,"%s %s %s %s %s %s\n",name1,lname1,address,gname,mob,email);
    }

    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\nThe Contact has been Modify! \n");
    printf("1. Main Menu \n");
    printf("2. Exit \n");
    printf("\nPRESS ANY KEY TO CONTINUE");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        menu();
        break;
    case 2:
        exit(0);
        break;
    }

}

