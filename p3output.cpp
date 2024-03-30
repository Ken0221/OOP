#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person{
    char Name[11];
    int sex;
    char edu;
    char major[3];
    char nation[4];
    char Ac[3];
    char no[8];
};

int main(){
    printf("------text file------\n");
	printf("------Part A.------\n");
	printf("      name sex edu major nation   telphone\n");

    Person record;
    FILE *f2;
	f2=fopen("3.txt", "r");
	while(fscanf(f2,"%s %d %c %s %s %s %s", record.Name, &record.sex, &record.edu, record.major, record.nation, record.Ac, record.no) != EOF)
	{
	
		if(record.sex == 1 && record.edu == 'B' && strcmp(record.major, "EE") == 0)
		{
			printf("%10s %3d %3c %5s %6s %s-%s\n",record.Name, record.sex, record.edu, record.major, record.nation, record.Ac, record.no);
		}
	}
	fclose(f2);

	printf("------Part B.------\n");
	printf("      name sex edu major nation   telphone\n");
    
	f2=fopen("3.txt", "r");
	while(fscanf(f2,"%s %d %c %s %s %s %s", record.Name, &record.sex, &record.edu, record.major, record.nation, record.Ac, record.no) != EOF)
	{
	
		if(strcmp(record.nation, "ROC") == 0 && strcmp(record.Ac, "02") == 0)
		{
			printf("%10s %3d %3c %5s %6s %s-%s\n",record.Name, record.sex, record.edu, record.major, record.nation, record.Ac, record.no);
		}
	}
	fclose(f2);

	printf("------Part C.------\n");
	printf("      name sex edu major nation   telphone\n");
    
	f2=fopen("3.txt", "r");
	while(fscanf(f2,"%s %d %c %s %s %s %s", record.Name, &record.sex, &record.edu, record.major, record.nation, record.Ac, record.no) != EOF)
	{
	
		if(strcmp(record.nation, "JPN") == 0 && record.edu == 'C')
		{
			printf("%10s %3d %3c %5s %6s %s-%s\n",record.Name, record.sex, record.edu, record.major, record.nation, record.Ac, record.no);
		}
	}
	fclose(f2);


//BINARY
    printf("\n------binary file------\n");
	printf("------Part A.------\n");
	printf("      name sex edu major nation   telphone\n");

    FILE *fb2;
	fb2=fopen("3.dat", "rb");
	while(fread(&record, sizeof(record), 1, fb2))
	{
	
		if(record.sex == 1 && record.edu == 'B' && strcmp(record.major, "EE") == 0)
		{
			printf("%10s %3d %3c %5s %6s %s-%s\n",record.Name, record.sex, record.edu, record.major, record.nation, record.Ac, record.no);
		}
	}
	fclose(fb2);

	printf("------Part B.------\n");
	printf("      name sex edu major nation   telphone\n");
    
	fb2=fopen("3.dat", "rb");
	while(fread(&record, sizeof(record), 1, fb2))
	{
	
		if(strcmp(record.nation, "ROC") == 0 && strcmp(record.Ac, "02") == 0)
		{
			printf("%10s %3d %3c %5s %6s %s-%s\n",record.Name, record.sex, record.edu, record.major, record.nation, record.Ac, record.no);
		}
	}
	fclose(fb2);

	printf("------Part C.------\n");
	printf("      name sex edu major nation   telphone\n");
    
	fb2=fopen("3.dat", "rb");
	while(fread(&record, sizeof(record), 1, fb2))
	{
	
		if(strcmp(record.nation, "JPN") == 0 && record.edu == 'C')
		{
			printf("%10s %3d %3c %5s %6s %s-%s\n",record.Name, record.sex, record.edu, record.major, record.nation, record.Ac, record.no);
		}
	}
	fclose(fb2);
    return 0;
}
