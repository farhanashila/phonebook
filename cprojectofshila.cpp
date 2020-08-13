#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
struct person
{
    char name[35];
    char address[50];

    long int mble_no;
    char g[8];
    char mail[100];


    };
    class phonebook
{
    public:
           void back();
           };

void menu();
char *gets(char *name);
void start();

void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();

int main()
{   phonebook obj;
    obj.back();
    system("color ");
    start();
    return 0;
}
void phonebook :: back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
    system("cls");
printf("\t\t**********WELCOME TO PHONEBOOK*************\n\n\t\t\tCreated By Farhana Kabir");

printf("\n\n\n\t\t\t  MENU\t\t\n\n");
printf("\n\t1.Add New   \n\t2.List   \n\t3.Exit  \n\t4.Modify \n\t5.Search\n\t6.Delete");
 printf("\n\n\nChoose Any Key From 1 to 6");

switch(getch())
{
    case '1':

                addrecord();
    break;
   case '2': listrecord();
    break;
    case '3': exit(0);
    break;
    case '4': modifyrecord();
    break;
    case '5': searchrecord();
    break;
    case '6': deleterecord();
    break;
    default:
                system("cls");
                printf("\nEnter 1 to 6 only");
                printf("\n Enter any key");
                getch();

menu();
}
}
        void addrecord()
{
        system("cls");
        FILE *f;
        struct person p;
        f=fopen("project","ab+");
        cout<<"\n\nEnter name: ";
        gets(p.name);
        cout<<"\n\nEnter the address: ";
       gets(p.address);
        cout<<"\n\nEnter phone no.:";
        scanf("%ld",&p.mble_no);
        cout<<"\nEnter gender:";
        gets(p.g);
        cout<<"\n\nEnter e-mail:";
         gets(p.mail);

        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);
        cout<<"\nrecord saved";

fclose(f);

    cout<<"\n\nEnter any key";

	 getch();
    system("cls");
    menu();
}
void listrecord()
{
    struct person p;
    FILE *f;
f=fopen("project","rb");
if(f==NULL)
{
printf("\nfile opening error in listing :");

//exit(1);
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n YOUR RECORD IS\n\n ");
        printf("\nName=%s\nAdress=%s\nMobile no=%ld\nGender=%s\nE-mail=%s",p.name,p.address,p.mble_no,p.g,p.mail);


}
fclose(f);

 getch();
    system("cls");
menu();
}
void searchrecord()
{
    struct person p;
FILE *f;
char name[100];

f=fopen("project","rb");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");


}
cout<<"\nEnter name of person to search\n";
gets(name);
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\tDetail Information About %s",name);
        printf("\nName:%s\naddress:%s\nMobile no:%ld\ngender:%s\nE-mail:%s",p.name,p.address,p.mble_no,p.g,p.mail);
    }
    }
    while(fread(&p,sizeof(p),1,f)==1)
    if(strcmp(p.name,name)!=0)
        printf("file not found");

//}
 fclose(f);
  printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}
void deleterecord()
{
    struct person p;
    FILE *f,*ft;
	int flag;
	char name[100];
	f=fopen("project","rb");
	if(f==NULL)
		{

			printf("\n\nCONTACT'S DATA NOT ADDED YET.");

		}
	else
	{
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("file opaning error");
		else

        {


		printf("\n\nEnter CONTACT'S NAME:");
		gets(name);

		fflush(stdin);
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)
				fwrite(&p,sizeof(p),1,ft);
			if(strcmp(p.name,name)==0)
               flag=1;

    }
	fclose(f);
	fclose(ft);
	if(flag!=1)
	{

               printf("\n\nNo  record to delete.");


    }

		else
		{

		remove("project");
		rename("temp","project");


			printf("\n\nRECORD DELETED SUCCESSFULLY.");

		}
	}
}
 printf("\n Enter any key");

	 getch();
    system("cls");
menu();
}

void modifyrecord()
{
    int c;
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");
	if(f==NULL)
		{

			printf("\nCONTACT'S DATA NOT ADDED YET.");
			exit(1);


		}
	else
	{
	    system("cls");
		printf("\n\nEnter CONTACT'S NAME TO MODIFY:\n");
            gets(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)
                {



                    printf("\n Enter name:");
                    gets(s.name);
                    printf("\nEnter the address:");
                    gets(s.address);

                    printf("\nEnter phone no:");
                    scanf("%ld",&s.mble_no);
                    printf("\nEnter gender:");
                    gets(s.g);
                    printf("\nEnter e-mail:");
                    gets(s.mail);

                    fseek(f,-sizeof(p),SEEK_CUR);
                    fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            if(flag==1)
            {
                printf("\n your data id modified");

            }
            else
            {
                    printf(" \n data is not found");

            }
            fclose(f);
	}
	 printf("\n Enter any key");
	 getch();
    system("cls");
	menu();

}
char *gets(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}
