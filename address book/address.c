#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int option;
void addcont(),searchcont(),editcont(),deletecont(),listcont(),savecont();

void menu()
{
	system("clear");
	printf("\n\n\t***Address book***\n\t***menu***\n");
	printf("\n 0. Exit\n 1. Add Contact\n 2. search Contact\n 3. Edit Contact\n 4. Delete Contact\n 5. List Contact\n ");
	printf("\n please select an option:  ");
	scanf("%d",&option);
	if(option==0)
		return;
	switch(option)
	{
		case 1:
			addcont();
			break;
		
		case 2:
			searchcont();
			break;
			
		case 3:
			//editcont();
			break;
			
		case 4:
			deletecont();
			break;
		
		case 5:
			listcont();
			break;
			
		default:
			menu();
			break;
	}

	menu();
}

typedef struct 
{
	char name[20];
	char phone[12];
	char email[20];
	char birthday[9];
		
}contact;
	
contact add;
	
void save(contact *t)
{
	FILE *fp=fopen("address.txt","a");
	if(fp==NULL)
	{
		FILE *fp=fopen("address.txt","w");
	}
	
	fwrite(t,sizeof(*t),1,fp);
	fclose(fp);
	printf("\n contact saved\n");
}
int main()
{
	main:
	menu();
	
}


void addcont()
{
	
	
	int add_option=0;
	system("clear");
	printf("\n\n\t***Address book***\n*****Add Contact***\n");
	printf("\n 1. Add Name\n 2. phone Number\n 3. Email ID\n 4. Birthday Date\n 5. Back\n 6. SAVE\n ");
	printf("\n please select an option:  ");
	//add:
	scanf("%d",&add_option);
	do
	{
		switch(add_option)
		{
				case 1:
					system("clear");
					printf("\n Enter name:  ");
					scanf("%s",add.name);
					printf("\n 1. Add Name: %s \n 2. phone Number\n 3. Email ID\n 4. Birthday Date\n 5. Back\n 6. SAVE\n",add.name);
					printf("\n please select an option:  ");
					scanf("%d",&add_option);
					//goto add;
					break;
				case 2:
					system("clear");
					printf("\n Enter phone number:  ");
					scanf("%s",add.phone);
					printf("\n 1. Add Name: %s \n 2. phone Number: %s\n 3. Email ID\n 4. Birthday Date\n 5. Back\n 6. SAVE\n",add.name,add.phone);
					printf("\n please select an option:  ");
					scanf("%d",&add_option);
					//goto add;
					break;
				case 3:
					system("clear");
					printf("\n Enter Email ID:  ");
					scanf("%s",add.email);
					
					
					printf("\n 1. Add Name: %s \n 2. phone Number: %s\n 3. Email ID: %s\n 4. Birthday Date:\n 5. Back\n 6. SAVE\n",add.name,add.phone,add.email);	
					printf("\n please select an option:  ");
					scanf("%d",&add_option);				
					
					//goto add;
					break;
				case 4:
					system("clear");
					printf("\n Enter Birthday");
					scanf("%s",add.birthday);
					printf("\n 1. Add Name: %s \n 2. phone Number: %s\n 3. Email ID: %s\n 4. Birthday Date:  %s\n 5. Back\n 6. SAVE\n",add.name,add.phone,add.email,add.birthday);	
					printf("\n please select an option:  ");
					scanf("%d",&add_option);
					//savecont();
					//goto add;
					break;
				case 5:
					menu();
					break;
				default:
					system("clear");
					savecont();
					
					int k;
					printf("\n press 1 to goto main menu\n");
					scanf("%d",&k);
					if(k==1)
					{
						menu();
					}
					//goto main;
					break;
						
		}
	}while(add_option!=-1);
}

void savecont()
{
	save(&add);
}

void searchcont()
{
	FILE *fp=fopen("address.txt","r");
	if(fp==NULL)
	{
		printf("\n Error in reading file");
		return;
	}

	int search_option;
	system("clear");
	printf("\n\n\t******Search by***\n");
	printf("\n 0. Back\n 1. Name\n 2. Phone No\n 3. Email ID\n 4. main menu\n ");
	printf("\n please select an option:  ");
	scanf("%d",&search_option);
	switch(search_option)
	{
		case 1:
			char name[20];
			printf("\n Enter the name of contact\n");
			scanf("%s",name);
			int no=1;
			while(fread(&add,sizeof(add),1,fp)==1)
			{
				
				if(strcmp(add.name,name)==0)
				{
				printf("\n Name: %s,  Phone: %s, email: %s, Birthday: %s",add.name,add.phone,add.email,add.birthday);
				 no=0;
				}
			}
			if(no==1)
				printf("\n No such contact \n");

			fclose(fp);
			break;

		case 2:
			char phone[15];
			printf("\n Enter the phone number to search\n");
			scanf("%s",phone);
			no=1;
			while(fread(&add,sizeof(add),1,fp)==1)
			{
				
				if(strcmp(add.phone,phone)==0)
				{
					printf("\n Name: %s,  Phone: %s, email: %s, Birthday: %s",add.name,add.phone,add.email,add.birthday);
					no=0;
				}
			}

			if(no==1)
				printf("\n No such contact \n");

			fclose(fp);
			break;
			
		case 3:
			char email[20];
			printf("\n Enter the phone number to search\n");
			scanf("%s",phone);
			no=1;
			while(fread(&add,sizeof(add),1,fp)==1)
			{
				
				if(strcmp(add.email,email)==0)
				{
					printf("\n Name: %s,  Phone: %s, email: %s, Birthday: %s",add.name,add.phone,add.email,add.birthday);
					no=0;
				}
			}

			if(no==1)
				printf("\n No such contact \n");

			fclose(fp);
			break;
			
	
		default:
			menu();
			break;
	}
	
	
	int k;
	printf("\n press 1 to goto main menu\n");
	scanf("%d",&k);
	//fclose(fp);
	if(k==1)
	{
		menu();
	}

	
}

void listcont()
{
	system("clear");
	FILE *fp=fopen("address.txt","r");
	if(fp==NULL)
	{
		printf("\n Error in reading file");
		return;
	}
	int i=0;
	//printf("**********************************************************************\n");
	//printf("\n \tName  |  Phone   |email   |Birthday  |\n");
	//printf("**********************************************************************\n");
	while(fread(&add,sizeof(add),1,fp)==1)
	{
		i=i+1;

		printf("\n %d....\tNAME: %s, \n \tPHONE: %s,\n \tEMAIL: %s, \n \tBIRTHDAY: %s \n",i,add.name,add.phone,add.email,add.birthday);

	}	

	int k;
	printf("\n \t press 1 to goto main menu\n");
	scanf("%d",&k);
	fclose(fp);
	if(k==1)
	{
		menu();
	}
}

void deletecont()
{
	FILE *fp=fopen("address.txt","r");
	if(fp==NULL)
	{
		printf("\n Error in reading file");
		return;
	}
	
	//system("rm address.txt");
	printf("\n\taddress deleted\n");
}
