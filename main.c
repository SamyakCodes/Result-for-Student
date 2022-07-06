#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
void add();
void view();
void edit();
void del();
void quit();
void nowmen();
int main(){
	int option;
	printf("\n\n\t\t\tCreated by SAMYAK BHATTARAI");
	printf("\n\n _____________________________________________________________________");
	printf("\n|\t\t\t\t\t\t\t\t      |\n|\t\t\tOccidental Public School\t\t      |");
	printf("\n|\t\t\tAnamnagar, Kathmandu\t\t\t      |");
	printf("\n|\t\t\t\t\t\t\t\t      |\n|\t\t\tSchool Result\t\t\t\t      |");
	printf("\n|_____________________________________________________________________|");
	printf("\n\n  Choose your task below: \n");
	printf("\n\t[1] Add new student's record");
	printf("\n\t[2] View the results");
	printf("\n\t[3] Edit previous records");
	printf("\n\t[4] Delete previous records");
	printf("\n\t[5] Quit the program");
	printf("\n\n\t\tEnter your choice[1/2/3/4/5]: ");
	scanf("%d", &option);
	switch(option){
		case 1:
			add();
			break;
		case 2:
			view();
			break;
		case 3:
			edit();
			break;
		case 4:
			del();
			break;
		case 5:
			quit();
			break;
		default:
			printf("Not an option[auto quit]");
			break;
	}
	return 0;
}
void add(){
	system("CLS");
	int science,social,math,computer;
	FILE *fptr, *list;
	char fname[20];
	char lname[20];
	char uname[30];
	char roll[10];
	char new_roll[20];
	printf("Enter the first name of the student: ");
	scanf("%s", fname);
	strcpy(uname,fname);
	printf("Enter the last name of the student: ");
	scanf("%s", lname);
	printf("Enter the student's roll number: ");
	scanf("%s", roll);
	char ex[7] = ".txt";
	list = fopen("student_list.txt", "a");
	strcpy(new_roll,roll);
	fptr = fopen(strcat(roll,ex), "a");
	fprintf(list,"[%s] %s %s\n", new_roll,uname,lname);
	printf("\nScience: ");
	scanf("%d", &science);
	printf("\nSocial: ");
	scanf("%d", &social);
	printf("\nMathematics: ");
	scanf("%d", &math);
	printf("\nComputer: ");
	scanf("%d", &computer);
	float total = math+social+science+computer;
	float new = total/400*100;
	fprintf(fptr,"Student's name: %s %s\nRoll number: %s", uname,lname,new_roll);
	fprintf(fptr,"\n\nS.N\t\tSubject\t\tFull marks\t\tObtained");
	fprintf(fptr,"\n1\t\tScience\t\t  100\t\t\t  %d", science);
	fprintf(fptr,"\n2\t\tSocial\t\t  100\t\t\t  %d", social);
	fprintf(fptr,"\n3\t\tMathematics\t  100\t\t\t  %d", math);
	fprintf(fptr,"\n4\t\tComputer\t  100\t\t\t  %d", computer);
	fprintf(fptr,"\n\nPercentage: %.2f %%", new);
	if(new>=90){
		fprintf(fptr,"\t\tGrade: A+");	
	}else if(new<=90 && new>=80){
		fprintf(fptr,"\t\tGrade: A");
	}else if(new<=80 && new>=70){
		fprintf(fptr,"\t\tGrade: B+");
	}else if(new<=70 && new>=60){
		fprintf(fptr,"\t\tGrade: B");
	}else if(new<=60 && new>=50){
		fprintf(fptr,"\t\tGrade: C+");
	}
	if(new>40){
		fprintf(fptr,"\nStatus: PASS");
	}else{
		fprintf(fptr,"\nStatus: FAIL");
	}
	fclose(fptr);
	fclose(list);
	system("CLS");
	main();
}
void view(){
	system("CLS");
	char name[100];
	FILE *list;
	list = fopen("student_list.txt", "r");
	char ch = getc(list);
	while(ch!=EOF){
		printf("%c", ch);
		ch = getc(list);
	}
	printf("\n");
	printf("Enter students roll number: ");
	scanf("%s", name);
	char ext[10] = ".txt";
	FILE *fptr;
	fptr = fopen(strcat(name,ext), "r");
	system("CLS");
	char nch = getc(fptr);
	while(nch!=EOF){
		printf("%c", nch);
		nch = getc(fptr);
	}
	int wait;
	printf("\n");
	printf("\n\n1 to exit\n2.New Student\n3.Main Menu\n");
	printf("Choose: ");
	scanf("%d", &wait);
	if(wait==1){
		quit();
	}else if(wait==2){
		system("CLS");
		view();
	}else if(wait==3){
		system("CLS");
		main();
	}
	else{
		system("CLS");
		main();
	}
	getch();
	
}
void edit(){
	system("CLS");
	char name[100];
	FILE *list, *file;
	list = fopen("student_list.txt", "r");
	char ch = getc(list);
	while(ch!=EOF){
		printf("%c", ch);
		ch = getc(list);
	}
	printf("\n");
	char roll[10];
	char new_roll[20];
	printf("\nEnter the student's roll: ");
	scanf("%s", roll);
	strcpy(new_roll,roll);
	file = fopen(strcat(roll,".txt"), "w");
	int science,social,math,computer;
	char fname[20];
	char lname[20];
	char uname[30];
	printf("Enter the first name of the student: ");
	scanf("%s", fname);
	strcpy(uname,fname);
	printf("Enter the last name of the student: ");
	scanf("%s", lname);
	char ex[7] = ".txt";
	list = fopen("student_list.txt", "a");
	
	printf("\nScience: ");
	scanf("%d", &science);
	printf("\nSocial: ");
	scanf("%d", &social);
	printf("\nMathematics: ");
	scanf("%d", &math);
	printf("\nComputer: ");
	scanf("%d", &computer);
	float total = math+social+science+computer;
	float new = total/400*100;
	fprintf(file,"Student's name: %s %s\nRoll number: %s", uname,lname,new_roll);
	fprintf(file,"\n\nS.N\t\tSubject\t\tFull marks\t\tObtained");
	fprintf(file,"\n1\t\tScience\t\t  100\t\t\t  %d", science);
	fprintf(file,"\n2\t\tSocial\t\t  100\t\t\t  %d", social);
	fprintf(file,"\n3\t\tMathematics\t  100\t\t\t  %d", math);
	fprintf(file,"\n4\t\tComputer\t  100\t\t\t  %d", computer);
	fprintf(file,"\n\nPercentage: %.2f %%", new);
	if(new>=90 && new<=100){
		fprintf(file,"\t\tGrade: A+");	
	}else if(new<=90 && new>=80){
		fprintf(file,"\t\tGrade: A");
	}else if(new<=80 && new>=70){
		fprintf(file,"\t\tGrade: B+");
	}else if(new<=70 && new>=60){
		fprintf(file,"\t\tGrade: B");
	}else if(new<=60 && new>=50){
		fprintf(file,"\t\tGrade: C+");
	}
	if(new>40){
		fprintf(file,"\nStatus: PASS");
	}else{
		fprintf(file,"\nStatus: FAIL");
	}
	fclose(file);
	fclose(list);
	system("CLS");
	main();
}
void del(){
	//rm file_name
	FILE *list;
	char name[10];
	list = fopen("student_list.txt", "r");
	char d;
	d = getc(list);
	while(d != EOF){
		printf("%c", d);
		d = getc(list);
	}
	printf("\n");
	printf("Enter student's roll number: ");
	scanf("%s", name);
	char exte[7] = ".txt";
	char fnc[100] = "rm ";
	strcat(name,exte);
	strcat(fnc, name);
	system(fnc);
	
	
}
void quit(){
	system("CLS");
	system("COLOR 4");
	printf("Bye | Sayonara | Adios | Au Revoir");
	printf("\n\nCopyright of Samyak Bhattarai");
}
void nowmen(){
	printf("Worked!");
	main();
}
