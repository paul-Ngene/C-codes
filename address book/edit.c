#include<stdio.h>

int edit()
{
	printf("\n\n\t***Address book***\n******Edit by***\n");
	printf("\n 0. Back\n 1. Name\n 2. Phone No\n 3. Email ID\n 4. serial No\n ");
	printf("\n please select an option:  ");
	scanf("%d",&option);
}

void save(contact t)
{
	FILE *fp=fopen("address.txt","a");
	if(!fp)
	{
		FILE *fp=fopen("address.txt","w");
	}
	
	fwrite(&t,sizeof(t),1,fp);
	fclose(fp);
}
