#include<stdio.h>
int add_option
void addcont()
{
	typedef struct 
	{
			char name[20];
			char phone[12];
			char email[20];
			char birthday[9];
			
	}contact;
	
	contact add;
	printf("\n\n\t***Address book***\n*****Add Contact***\n");
	printf("\n 0. Back\n 1. Add Name\n 2. phone Number\n 3. Email ID\n 4. Birthday Date\n ");
	printf("\n please select an option:  ");
	//add:
	scanf("%d",&add_option);
	do
	{
		switch(add_option)
		{
				case 1:
					printf("\n Enter name:  ");
					scanf("%s",add.name);
					printf("\n 0. Back\n 1. Add Name: %s \n 2. phone Number\n 3. Email ID\n 4. Birthday Date\n ",add.name);
					printf("\n please select an option:  ");
					//goto add;
					break;
				case 2:
					printf("\n Enter phone number:  ");
					scanf("%s",add.phone);
					printf("\n 0. Back\n 1. Add Name: %s \n 2. phone Number: %s\n 3. Email ID\n 4. Birthday Date\n ",add.name,add.phone);
					printf("\n please select an option:  ");
					//goto add;
					break;
				case 3:
					printf("\n Enter Email ID:  ")
					scanf("%s",add.email);
					printf("\n 0. Back\n 1. Add Name: %s \n 2. phone Number: %s\n 3. Email ID: %s\n 4. Birthday Date\n ",add.name,add.phone,add.email);
					printf("\n please select an option:  ");
					//goto add;
					break;
				case 4:
					printf("\n Enter Birthday");
					scanf("%s",add.birthday);
					printf("\n 0. Back\n 1. Add Name: %s \n 2. phone Number: %s\n 3. Email ID: %s\n 4. Birthday Date:  %s\n ",add.name,add.phone,add.email,add.birthday);
					printf("\n please select an option:  ");
					//goto add;
					break;
				default:
					save(add);
						
		}
	}while(add_option!=-1);
}
