#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stu{
	int sid;
	char name[50];
	char branch[50];
	int sem;
	char add[100];
};

void insertStu(){
	FILE *outfile;
	struct Stu stu;
	outfile=fopen("stu.txt","a");
	if(outfile == NULL){
		printf("Error opening file\n");
		return;
	}
	printf("\nEnter SID:");
	scanf("%d",&stu.sid);
	
	while(getchar() != '\n');
	printf("Enter name: ");
	fgets(stu.name,sizeof(stu.name),stdin);
	stu.name[strlen(stu.name)-1]='\0';
	
	printf("Enter branch: ");
	fgets(stu.branch,sizeof(stu.branch),stdin);
	stu.branch[strlen(stu.branch)-1]='\0';
	
	printf("Enter Semester:");
	scanf("%d",&stu.sem);
	
	while(getchar() != '\n');
	printf("Enter address: ");
	fgets(stu.add,sizeof(stu.add),stdin);
	stu.add[strlen(stu.add)-1]='\0';
	
	fprintf(outfile,"\n%d\t%s\t%s\t%d\t %s",stu.sid,stu.name,stu.branch,stu.sem,stu.add);
	
	fclose(outfile);
}

void modifyAddress(int sid){
	FILE *infile,*temp;
	struct Stu stu;
	infile=fopen("stu.txt","r");
	if(infile == NULL){
		printf("Error opening file\n");
		return;
	}
	temp=fopen("temp.txt","w");
	if(temp == NULL){
		printf("Error opening file\n");
		fclose(infile);
		return;
	}
	while(fscanf(infile,"%d%s%s%d%s",&stu.sid,stu.name,stu.branch,&stu.sem,stu.add)!=EOF){
		if(stu.sid==sid){
			printf("Enter new address:");
			scanf("%s",stu.add);
		}
		fprintf(temp,"\n%d %s %s %d %s",stu.sid,stu.name,stu.branch,stu.sem,stu.add);
	}
	fclose(infile);
	fclose(temp);
	remove("stu.txt");
	rename("temp.txt","stu.txt");
}

void deleteStu(int sid){
	FILE *infile,*temp;
	struct Stu stu;
	infile=fopen("stu.txt","r");
	if(infile == NULL){
		printf("Error opening file\n");
		return;
	}
	temp=fopen("temp.txt","w");
	if(temp == NULL){
		printf("Error opening file\n");
		fclose(infile);
		return;
	}
	while(fscanf(infile,"%d%s%s%d%s",&stu.sid,stu.name,stu.branch,&stu.sem,stu.add)!=EOF){
		if(stu.sid!=sid){
			fprintf(temp,"\n%d %s %s %d %s",stu.sid,stu.name,stu.branch,stu.sem,stu.add);
	}
	}
	fclose(infile);
	fclose(temp);
	remove("stu.txt");
	rename("temp.txt","stu.txt");
}

void ListAllStu(){
	FILE *infile;
	struct Stu stu;
	infile=fopen("stu.txt","r");
	if(infile == NULL){
		printf("Error opening file\n");
		return;
	}
	printf("\nSID\tNAME\tBRANCH\tSEMESTER\tADDRESS");
				while(fscanf(infile,"%d%s%s%d%s",&stu.sid,stu.name,stu.branch,&stu.sem,stu.add)!=EOF){
		printf("\n%d\t%s\t %s \t %d\t\t",stu.sid,stu.name,stu.branch,stu.sem);
		puts(stu.add);
	}
	fclose(infile);
}
void ListStuByBranch(char *b){
	FILE *infile;
	struct Stu stu;
	infile=fopen("stu.txt","r");
	if(infile == NULL){
		printf("Error opening file\n");
		return;
	}
	printf("\nSID\tNAME\tBRANCH\tSEMESTER\tADDRESS");
	while(fscanf(infile,"%d%s%s%d%s",&stu.sid,stu.name,stu.branch,&stu.sem,stu.add)!=EOF){
	if(strcmp(stu.branch,b)==0){
		printf("\n%d\t%s\t %s \t %d\t\t",stu.sid,stu.name,stu.branch,stu.sem);
		puts(stu.add);
	}
	}
	fclose(infile);
}

void ListStubyBranchandAddress(char *b, char*a){
	FILE *infile;
	struct Stu stu;
	infile=fopen("stu.txt","r");
	if(infile == NULL){
		printf("Error opening file\n");
		return;
	}
	printf("\nSID\tNAME\tBRANCH\tSEMESTER\tADDRESS");
	while(fscanf(infile,"%d%s%s%d%s",&stu.sid,stu.name,stu.branch,&stu.sem,stu.add)!=EOF){
		if(strcmp(stu.branch,b)==0 && strcmp(stu.add,a)==0){
		printf("\n%d\t%s\t %s \t %d\t\t",stu.sid,stu.name,stu.branch,stu.sem);
		puts(stu.add);
	}
	}
	fclose(infile);
}

int main(){
	int ch,sid;
	char b[50],a[100];
	while(1){
		printf("\nMENU:\n1.Insert a new student\n2.Modify Student address\n3.Delete a Student\n4.List all students\n5.List all students of a specific branch\n6.List all students of a specific branch and living in a particular area\n7.Exit\nEnter choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
			insertStu();
			break;
			case 2:
			printf("Enter sid to modify address:\n");
			scanf("%d",&sid);
			modifyAddress(sid);
			break;
			case 3:
			printf("Enter sid to delete student:\n");
			scanf("%d",&sid);
			deleteStu(sid);
			break;
			case 4:
			ListAllStu();
			break;
			case 5:
			printf("Enter branch to list students:\n");
			scanf("%s",b);
			ListStuByBranch(b);
			break;
			case 6:
			printf("Enter branch:\n");
			scanf("%s",b);
			printf("Enter area:\n");
			scanf("%s",a);
			ListStubyBranchandAddress(b,a);
			break;
			case 7:return 0;
			default:("Invalid choice! Try again\n");
			break;
		}
	}
	return 0;
}
