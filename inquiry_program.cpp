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
    Person record;
    char next;
    /*FILE *f3;
    f3 = fopen("3.txt", "w");
    do
	{
		printf("name: ");
		scanf("%s", record.Name);
		printf("sex: ");
		scanf("%d", &record.sex);
		printf("education: ");
		scanf(" %c", &(record.edu));
		printf("major: ");
		scanf("%s", record.major);
		printf("nationality: ");
		scanf("%s", record.nation);
		printf("tel.Ac: ");
		scanf("%s", record.Ac);
        printf("tel.no: ");
        scanf("%s", record.no);
		fprintf(f3, "%s %d %c %s %s %s %s", record.Name, record.sex, record.edu, record.major, record.nation, record.Ac, record.no);
        printf("continue or not?");
 		scanf(" %c", &next);
	}
	while(next =='y' || next == 'Y');
    fclose(f3);
*/

//Binary
    FILE *f3;
    f3 = fopen("3.txt", "r");
    FILE *fb3;
    fb3 = fopen("3.dat", "wb");

    while(fscanf(f3,"%s %d %c %s %s %s %s", record.Name, &record.sex, &record.edu, record.major, record.nation, record.Ac, record.no) != EOF)
    {
	    fwrite(&record, sizeof(record), 1, fb3);
    }
    fclose(fb3);
    return 0;
}
