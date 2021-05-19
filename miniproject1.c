
                         //PHONEBOOK CONSOLE APPLICATION

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void menu();
void menu_item();
void add_contact();
void append_contact();
void view_contact();
void change_file();
void delete_contact();
void error();


typedef struct info
{
  char name[15];
  char no[10];
}student;

  int ch;
  student p;

void menu()
{ system("color 4B");
	printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
    printf("\n \t\t\t\t\tWELCOME TO PHONEBOOK");
    printf("\n\t\t\t\t\t---------------------\n");
    printf("\n\t\t\t\t\t 1-> Add Contact\n\t\t\t\t\t 2-> APPEND CONTACT\n\t\t\t\t\t 3-> View Contact\n\t\t\t\t\t 4-> delete contact\n\t\t\t\t\t 5-> change_file\n\t\t\t\t\t 6->exit\n\n");
    printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
}


void menu_item()
{
	 printf("\n\n\t\t\t\t ENTER ANY ONE CHOICE :- ");
     scanf("%d",&ch);
     switch(ch)
       {
	        case 1:
	           add_contact();
	           break;
	        case 2:
	     	   append_contact();
	     	   break;
            case 3:
   	            view_contact();
   	            break;
	        case 4:
   	     	    delete_contact();
   	     	    break;
   	     	case 5:
   	     		  change_file();
   	     		  break;
            case 6:
    	        exit(0);
            default:
		      {
    	        error();
              }
       }
}

void add_contact()
{   system("color 1C");
     FILE *fp;
     fp=fopen("student.dat","wb");
     printf("\n\n\t\t__________________________________________________________________________");
     printf("\n\n\t\t\tENETR THE NAME:- ");
     fflush(stdin);
     gets(p.name);
     printf("\n\t\t\tENTER PHONE NO:- ");
     gets(p.no);
     fwrite(&p,sizeof(p),1,fp);
     fclose(fp);
     printf("\n\n\t\t\t***************NOW YOUR RECORD HAS SAVED ******************");
     printf("\n\n\t\t\t\t\tPRESS ANY KEY TO PROCEED NEXT--");
     printf("\n\n\t\t_________________________________________________________________________");
     getche();
     system("cls");
}


void append_contact()
{    system("color 1C");
     FILE *fp;
     fp=fopen("student.dat","ab");
     printf("\n\n\t\t__________________________________________________________________________");
     printf("\n\n\t\t\tENETR THE NAME:- ");
     fflush(stdin);
     gets(p.name);
     printf("\n\t\t\tENTER PHONE NO:- ");
     gets(p.no);
     fwrite(&p,sizeof(p),1,fp);
     fclose(fp);
     printf("\n\n\t\t\t***************NOW YOUR RECORD HAS SAVED ******************");
     printf("\n\n\t\t\t\t\tPRESS ANY KEY TO PROCEED NEXT--");
     printf("\n\n\t\t_________________________________________________________________________");
     getche();
     system("cls");
}


void view_contact()
{ 	 system("color 1C");
     char ch;
     FILE *f1;
     f1=fopen("student.dat","rb");
     if(f1==NULL)
     {
	      printf("\n dont exist");
          exit(0);
      }

     while(fread(&p,sizeof(p),1,f1)>0)
       {
	      printf("\t\t\t\t\nname=%s",p.name);
          printf("\t\t\t\t\nphone no= %s",p.no);
       }

     fclose(f1);
     printf("\n\nenter any key");
     getche();
     system("cls");
}


void change_file()
 { system("color 2b");
 int a;
  a=rename("shift.dat","student.dat");
  if(a==0)
  {
      printf("\n file renamed");
  }
   /*FILE *fp;
   fp=fopen("shift.dat","rb");
    if(fp==NULL)
     {
	     printf("\n dont exist");
         exit(0);
     }
    while(fread(&p,sizeof(p),1,fp)>0)
    {
    	printf("\t\t\t\t\nname=%s",p.name);
          printf("\t\t\t\t\nphone no= %s",p.no);
	}
	fclose(fp);*/
	// printf("\n\nenter any key");
    // getche();
    // system("cls");

//      b=rename("shift.dat","student.dat");
//	  if(b==0)
//     	{
//	      printf("\n\t\t\trenamed");
//     	}
  }


void delete_contact()
{    system("color 1C");
     int a;
     char name[10];
     FILE *f1;
     FILE *f2;
     f1=fopen("student.dat","rb");
     if(f1==NULL)
     {
	     printf("\n dont exist");
         exit(0);
     }
     printf("\n enter the name of person to delete the contact:- ");
     fflush(stdin);
     gets(name);
      f2=fopen("shift.dat","wb");

     while(fread(&p,sizeof(p),1,f1)>0)
     {
         if(strcmp(name,p.name)!=0)
          {

             fwrite(&p,sizeof(p),1,f2);
             printf("\nsucessfull 1");

          }
     }
        fclose(f2);
     fclose(f1);
     a=remove("student.dat");
     if(a==0)
       {
	      printf("\n\t\t\tremoved");
	   }


	 change_file();
     printf("\n\nenter any key");
     getche();
     system("cls");
}


void error()
{    system("color 1C");
  	 printf("\n\a\t\t\t\t__________________________________________________");
	 printf("\n\n\n\t\t\t\t\t***********OOPS!!!!....*************");
	 printf("\n\n\t\t\t\t\t YOU CHOOSE INVALID CHOICE---<TRY AGAIN> ");
	 printf("\n\t\t\t\t\t PRESS ANY KEY:- ");
	 printf("\n\t\t\t\t__________________________________________________\n");
	 getche();
     system("cls");
}


int main()
{
    while(1)
   {
      menu();
      menu_item();
   }
   return 0;
}
