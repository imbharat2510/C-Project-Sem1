#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct credential{
	char name[20];
	int password;
};
int admin(){
	struct credential k,l;
	char a[20];
	printf("Enter passkey: ");
	scanf("%s",a);
	if (strcmp(a,"passkey")==0){
		printf("\nAdmin name: ");
		scanf("%s",k.name);
		printf("\nPassword: ");
		scanf("%d",k.password);
	
	FILE *fp=fopen("../data/admin","r");
	if (fp==NULL){return -1;}
	while(fscanf(fp,"%s %d",l.name,&l.password)==2){
		if(strcmp(l.name,k.name)==0){
			if (l.password==k.password) return 1;
			else return 0;
		}
		
	}
	return 3;
	}


	return 2;
}

void sign_up(){
	FILE *z=fopen("../data/login.txt","r+");
	struct credential k;
	printf("\nEnter a username(max char 20): \n");
	scanf("%s",k.name);
	char check[20];
	int temp;
	while(fscanf(z,"%s %d",check,&temp)==2){
		if (strcmp(k.name,check)==0){
			printf("\nYou already have a account\n");
			fclose(z);
			return;}
	}
	printf("\nEnter a valid numeric password: \n");
	scanf("%d",&k.password);
	printf("\nRe-enter the password: \n");
	scanf("%d",&temp);
	if (temp!=k.password){
	printf("Password not verified\nCouldnt sign up\n");
	fclose(z);
	return;
	}
	else{
		fprintf(z,"%s %d\n",k.name,k.password);
		printf("Successfully signed up\n");

	}
	fclose(z);
			
}

void sign_in(){


