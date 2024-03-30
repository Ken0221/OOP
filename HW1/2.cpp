#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct book{
    int catalog;
    char title[10];
    char author[10];
    int price;
    int issued;
}typedef Book;

void Add(Book *b){
    int n;
    for(int i = 0; i < 100; i++){
        if(b[i].catalog == -1){
            n = i;
            break;
        }
    }
    printf("catalog number: ") ;
    scanf("%d", &b[n].catalog);
    printf("title: ");
    scanf("%s", b[n].title);
    printf("author: ");
    scanf("%s", b[n].author);
    printf("price: ");
    scanf("%d", &b[n].price);
    printf("issued (0, 1): ");
    scanf("%d", &b[n].issued);
    return;
}

void Display_Catalog(Book *b){
    int cat;
    printf("catalog number: ");
    scanf("%d", &cat);
    printf("title      author     price issued\n");
    printf("----------------------------------\n");
    for(int i = 0; i < 100; i++){
        if(cat == b[i].catalog){
            printf("%-10s %-10s %-5d ", b[i].title, b[i].author, b[i].price);

            if(b[i].issued == 1)
                printf("true \n");
            else
                printf("false \n");
        }
    }
    return;
}

void List_Author(Book *b){
    char auth[10];
    printf("author: ");
    scanf("%s", auth);
    printf("\n");
    printf("catalog title      price issued\n");
    printf("-------------------------------\n");
    for(int i = 0; i < 100; i++){
        if(!strcmp(auth, b[i].author)){
            printf("%-7d %-10s %-5d ", b[i].catalog, b[i].title, b[i].price);
            if(b[i].issued == 1)
                printf("true \n");
            else
                printf("false \n");

        }
    }
    return;
}

void List_Not_Issued(Book *b){
    int num = 0;
    for(int i = 0; i < 100; i++){
        if(b[i].issued == 0){
            num++;
        }
    }
    printf("#book in the library: %d\n", num);
    return;
}

void List_All_Catalog(Book *b){
    printf("catalog title      author     price issued\n");
    printf("------------------------------------------\n");
    for(int i = 0; i < 100; i++){
        if(b[i].catalog > 0){
            printf("%-7d %-10s %-10s %-5d ", b[i].catalog, b[i].title, b[i].author, b[i].price);
            if(b[i].issued == 1)
                printf("true \n");
            else
                printf("false \n");

        }
    }
    return;
}

int main(){
    Book books[100] = {
        {13, "NCTU", "ECE", 230, true},
        {42, "World", "ECE", 523, false}, 
        {4, "Coding", "CS", 300, true}, 
        {10, "HsinChu", "CS", 750, false},
        {12, "Hello", "ECE", 220, false}, 
        {15, "NYCU", "EE", 600, false},
        {34, "C++", "CS", 800, false},
        {33, "Lab", "ECE", 850, true}
    };
    for(int i = 8; i < 100; i++){
        books[i].catalog = -1;
        books[i].issued = -1;
    }
    void (*f[6])(Book*) = {Add, Display_Catalog, List_Author, List_Not_Issued, List_All_Catalog};
    
    while(true){
        for(int i = 0; i < 100; i++){
            for(int j = i; j < 100; j++){
                if(books[i].catalog > books[j].catalog && books[j].catalog != 0){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
        printf("===============================\n");
        printf("1. Add one new book information\n");
        printf("2. Display one book information according to the catalog number\n");
        printf("3. List all books of given author\n");
        printf("4. List the number of books which is not issued in the library\n");
        printf("5. List the books in the ascending order of catalog number\n");
        printf("6. Exit\n===============================\n");
        int opt;
        printf("Option: ");
        scanf("%d", &opt);
        printf("\n");
        if(1 <= opt && opt <= 6){
            if(opt == 6)
                break;
            else{
                (*f[opt - 1])(books);
            }
        }
        printf("\n");
    }
    return 0;
}
