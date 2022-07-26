
//Project name: Cops and Criminal record//
/*
Welcome to the core of our management system which will run by the Police Commissioner
Mr. Minhazul Islam. The whole program has two parts. One of them is about only officials
and the another one's about criminals.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void greet();
void menu1(void);
void menu2(void);
void greet()
{
    printf("\n\n\n\t\t\t\t\t\tGREETINGS!\t\t\n");
    printf("\n\t\t\t|| WELCOME TO THE COPS AND CRIMINALS MANAGEMENT SYSTEM ||\t\t");
}
void menu1(void)
{

    greet();
    printf("\n\n1.Officers Name ");
    printf("\n\n2.Check Officer details ");
    printf("\n\n3.Recruit New Officer ");
    printf("\n\n4.Retire Any Officer (tried a lot but couldn't make it to the last:'))");
    printf("\n\n5.Main menu ");
    printf("\n\n\n\n Enter your choice:");
}
void menu2(void)
{


    greet();
    printf("\t\n\n1.All Criminals Name with age ");
    printf("\t\n\n2.Add arrested criminal details   ");
    printf("\t\n\n3.Executed criminal(s) details(tried a lot but couldn't make it to the last:'))  ");
    printf("\t\n\n4.Bail a criminal(tried a lot but couldn't make it to the last:')) ");
    printf("\t\n\n5.Main menu ");
    printf("\t\n\n\n\n Enter your choice: ");
}

int i=0;
int n=3;
int m=4;
struct cops
{
    char name[100];
    int id;
    char rank[100];
    char cop_status[100];
};
struct criminals
{
    char name[100];
    int serial;
    char crime[100];
    int age;
    char criminal_status[100];//bailed wanted executed arrested//
};
int main()
{
    ///Scanning Officers details from file>>>>

    FILE *f1 ;
    f1=fopen("cops.txt","r");
    if(f1==NULL)
        printf("File not opened!");
    struct cops c[n];
    for(i=0; i<n+1; i++)
    {
        fscanf(f1,"%s",c[i].name);
        fscanf(f1,"%d",&c[i].id);
        fscanf(f1,"%s",c[i].rank);
        fscanf(f1,"%s",c[i].cop_status);
    }
    fclose(f1);

    /// Scanning Criminals details from file>>>>
    FILE *f2;
    f2=fopen("criminals.txt","r");
    if(f2==NULL)
        printf("File not opened!");
    struct criminals  r[m];
    for(i=0; i<m; i++)
    {
        fscanf(f2,"%s",r[i].name);
        fscanf(f2,"%d",&r[i].serial);
        fscanf(f2,"%s",r[i].crime);
        fscanf(f2,"%d",&r[i].age);
        fscanf(f2,"%s",r[i].criminal_status);
    }
    fclose(f2);

    ///START OF THE PROGRAM//
    int flag=0;
    while(flag<3)
    {
        ///*Password*///
        char email[300]="12";//minhazul.islam01@northsouth.edu
        char inpemail[300];
        char pass[300]="12";//34minhaz
        char inppass[300];
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   Email:");

        scanf("%s",inpemail);

        printf("\t\t\t\t\t   Password:");

        scanf("%s",inppass);
        system("cls");

jump:
        if(strcmp(email,inpemail)==0&&strcmp(pass,inppass)==0)
        {

            greet();
            printf("\t\t\t\n\n\n A. Officers Management.\n\n");
            printf("\t\t\t\n B. Criminals Management.\n\n");
            printf("Enter your choice:  ");
            char alp;
            fflush(stdin);
            scanf("%c",&alp);
            system("cls");
            switch(alp)
            {
            case 'A':
            {
                menu1();
                int b;
                fflush(stdin);
                scanf("%d",&b);
                switch(b)
                {
                case 1:
                    system("cls");
                    printf("\n\n\t\t All Officers Name:\n");

                    for(i=0; i<n+1; i++)
                    {
                        printf("\n\t\t\t\t   %s",c[i].name);
                    }
                    goto jump;
                    break;

                case 2:
                {
                    system("cls");
                    greet();
                    char x[100];
                    printf("\t\t\n\nCheck Officer's Details By Name:\n\n");
                    printf("\tEnter Officer's Name:");
                    fflush(stdin);
                    scanf("%s",x);
                    system("cls");
                    greet();
                    int flag=0;

                    for(i=0; i<n; i++)
                    {
                        if(strcmp(c[i].name,x)==0)
                        {
                            flag=1;
                            printf("\n\n\n\t\t\t Name:%s\n",c[i].name);
                            printf("\t\t\t   ID:%d\n",c[i].id);
                            printf("\t\t\t Rank:%s\n",c[i].rank);
                            printf("\t\t   Cop_Status:%s\n",c[i].cop_status);
                        }
                    }
                    if(flag==0)
                    {
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tWrong Input!!!");
                    }

                }
                goto jump;
                break;
                case 3:
                {
                    system("cls");
                    greet();
                    printf("\t\t\n\nHere you can recruit new officer.\n");
                    f1=fopen("cops.txt","a");
                    if(f1==NULL)
                        printf("File not opened!");
                    int e;
                    printf("Enter how many officers you want to recruit: ");
                    fflush(stdin);
                    scanf("%d",&e);
                    system("cls");
                    greet();

                    for(i=0; i<e; i++)
                    {


                        printf("\n\n\n\n\nName:");
                        scanf("%s",c[n+1].name);

                        printf("id:");
                        scanf("%d",&c[n+1].id);

                        printf("rank:");
                        fflush(stdin);
                        scanf("%s",c[n+1].rank);


                        printf("cop_status:");
                        scanf("%s",c[n+1].cop_status);

                        fprintf(f1,"\n%s\n",c[n+1].name);
                        fprintf(f1,"%d\n",c[n+1].id);
                        fprintf(f1,"%s\n",c[n+1].rank);
                        fprintf(f1,"%s\n",c[n+1].cop_status);

                    }
                    n++;
                    fclose(f1);
                    goto jump;

                    break;
                }
                case 4:
                {
                    int flag1=0;
                    printf("\t\t\n\nHere you can retire any officer.\n");
                    printf("Enter the id of officers you want to retire:");
                    int f;
                    //fflush(stdin);
                    scanf("%d",&f);
                    //printf("%s",ret);

                    f1=fopen("cops.txt","w");
                    if(f1==NULL)
                        printf("File not opened!");
                    for (i=0; i<n ; i++)
                    {
                        if( f==c[i].id )
                        {
                            flag1=1;
                            break;
                        }

                    }
                    if(flag1==1)
                    {
                        n=n-1;
                        fprintf(f1,"%d\n",n);
                        for(int j=0; j<n; j++)
                        {
                            if(i==j)
                                continue;
                            else
                            {

                                fprintf(f1,"%\ns\n",c[j].name);
                                fprintf(f1,"%d\n",c[j].id);
                                fprintf(f1,"%s\n",c[j].rank);
                                fprintf(f1,"%s\n",c[j].cop_status);
                            }
                        }
                    }
                    else
                        printf("not found");

                    goto jump;
                    fclose(f1);


                    break;
                }
                case 5:
                {

                    system("cls");goto jump;
                }
                    ///End of officers records
                }
                case 'B':
                {
                    system("cls");


                    menu2();
                    int d;
                    fflush(stdin);
                    scanf("%d",&d);
                    switch(d)
                    {
                    case 1:
                    {
                        printf("\n\n\n\t\t\tCriminals Name with age:\n\n");
                        for(i=0; i<m; i++)
                        {
                            printf("\n\n\t\t\t\t%s(%d)",r[i].name,r[i].age);
                        }
                    }
                    goto jump;
                    break;
                    case 2:
                    {
                        system("cls");
                        greet();
                        printf("\t\t\n\nYou can add new criminal here.\n");
                        f2=fopen("criminals.txt","a");
                        if(f2==NULL)
                            printf("File not opened!");

                        printf("\nEnter the number of criminals you want to add:");
                        int f;
                        scanf("%d",&f);
                        system("cls");
                        greet();
                        for(i=0; i<f; i++)
                        {
                            printf("\n\n\nName:");

                            scanf(" %s",r[m+1].name);
                            printf("\nSerial:");

                            scanf(" %d",&r[m+1].serial);
                            printf ("\nCrime:");
                            fflush(stdin);
                            scanf(" %s",r[m+1].crime);
                            printf ("\nAge:");

                            scanf(" %d",&r[m+1].age);
                            fflush(stdin);
                            printf ("\ncriminal_status:");
                            scanf(" %s",r[m+1].criminal_status);

                            fprintf(f2,"%s\n",r[m+1].name);
                            fprintf(f2,"%d\n",r[m+1].serial);
                            fprintf(f2,"%s\n",r[m+1].crime);
                            fprintf(f2,"%d\n",r[m+1].age);
                            fprintf(f2,"%s\n",r[m+1].criminal_status);

                        }
                        m++;
                        fclose(f2);

                        goto jump;
                        break;

                    }
                    case 3:
                    {
                        int exe;
                        printf("\t\t\n\nYou can execute any criminal here.\n\n");
                        printf("Enter the serial of the criminal you want to execute:");

                        scanf("%d",&exe);
                        for(i=0; i<m; i++)
                        {
                            if(exe==r[i].serial)
                            {
                                f2=fopen("criminals.txt","w");
                                if(f2==NULL)
                                    printf("File not opened!");
                                fprintf(f2,"\n%s\n",r[i].name);
                                fprintf(f2,"%d\n",r[i].serial);
                                fprintf(f2,"%s\n",r[i].crime);
                                fprintf(f2,"%d\n",r[i].age);
                                fprintf(f2,"Executed\n",r[i].criminal_status);
                            }
                            else
                            {
                                fprintf(f2,"%s",r[i].name);
                                fprintf(f2,"%d",r[i].serial);
                                fprintf(f2,"%s",r[i].crime);
                                fprintf(f2,"%d",r[i].age);
                                fprintf(f2,"%s",r[i].criminal_status);
                            }

                        }
                        fclose(f2);


                        goto jump;
                        break;
                    }
                    case 4:
                    {
                        int flag2=0;
                        printf("\t\t\n\nHere you can bail any criminal.\n");
                        printf("Enter the serial of criminal you want to retire:");
                        int g;
                        //fflush(stdin);
                        scanf("%d",&g);
                        //printf("%s",ret);

                        f2=fopen("criminals.txt","w");
                        if(f2==NULL)
                            printf("File not opened!");
                        for (i=0; i<m ; i++)
                        {
                            if( g==r[i].serial)
                            {
                                flag2=1;
                                break;
                            }

                        }
                        if(flag2==1)
                        {
                            m=m-1;
                            for(int j=0; j<m; j++)
                            {
                                if(i==j)
                                    continue;
                                else
                                {
                                    fprintf(f2,"%d",m);
                                    fprintf(f2,"%\ns\n",r[j].name);
                                    fprintf(f2,"%d\n",r[j].serial);
                                    fprintf(f2,"%s\n",r[j].crime);
                                    fprintf(f2,"%d\n",r[j].age);
                                    fprintf(f2,"%s\n",r[j].criminal_status);
                                }
                            }
                        }
                        else
                            printf("not found");

                        goto jump;
                        fclose(f2);


                        break;
                    }
                    }
                }
                case 5:
                {

                    system("cls");goto jump;
                }
                default:
                    printf("Wrong Input!");
                }//return;
            }
        }
        else
        {
            printf("Wrong input!\n");
            flag++;
            system("cls");
        }
    }
}


