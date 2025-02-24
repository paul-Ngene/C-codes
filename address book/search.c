#include<stdio.h>

int search_by()
{
	printf("\n\n\t***Address book***\n******Search by***\n");
	printf("\n 0. Back\n 1. Name\n 2. Phone No\n 3. Email ID\n 4. main menu\n ");
	printf("\n please select an option:  ");
	scanf("%d",&search_option);
	switch(search_option)
	{
		case 1:
			char name[20];
			printf("\n Enter the name of contact\n");
			scanf("%s",name);
			while(fread(&add,sizeof(add),1,fp)==1)
			{
				
				if(strcmp(add.name,name)==0)
				{
				printf("\n Name: %s,  Phone: %s, email: %s, Birthday: %s",add.name,add.phone,add.email,add.birthday);
				}
			}
			fclose(fp);
			break;
		
		case 2:
			char phone[15];
			printf("\n Enter the phone number to search\n");
			scanf("%s",phone);
			while(fread(&add,sizeof(add),1,fp)==1)
			{
				
				if(strcmp(add.phone,phone)==0)
				{
					printf("\n Name: %s,  Phone: %s, email: %s, Birthday: %s",add.name,add.phone,add.email,add.birthday);
				}
			}
			fclose(fp);
			break;
			
		case 3:
			char email[20];
			printf("\n Enter the phone number to search\n");
			scanf("%s",phone);
			while(fread(&add,sizeof(add),1,fp)==1)
			{
				
				if(strcmp(add.email,email)==0)
				{
					printf("\n Name: %s,  Phone: %s, email: %s, Birthday: %s",add.name,add.phone,add.email,add.birthday);
				}
			}
			fclose(fp);
			break;
			
	
		default:
			menu();
			break;
	}
}
