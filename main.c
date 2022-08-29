#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct record
{
    char productName[100];
    float rate;
    int quantity,code;
}r;

FILE *fp;

void department_menu()
{
    int choice;
        
    while(1){
        printf("\n");

        printf("\n\t\t\t\t MENU\n\t\t\t\t ___________________________");
        printf("\n\t\t\t\t| 1 ADD PRODUCT                          |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 2 DESPLAY PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 3 UPDATE PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 4 BUY PRODUCT                             |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 5 EXIT                                     |\n\t\t\t\t__________________________");
        printf("\n\t\t\t\tPLEASE CHOOSE A NUMBER IN THE BOX ABOVE:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                exit(0);

            case 1:
                deparment_addProduct();
                break;

            case 2:
                department_displayProduct();
                break;

            case 3:
                department_updateProduct();
                break;

            case 4:
                department_buyProduct();
                break;

            default:
                printf("Invalid choice..: ");
                break;
        }

        printf("Enter any key to continue: ");
        getch();
    }
    return 0;
}


void deparment_addProduct()
{
    fp = fopen("product.txt", "w++");

    printf("Enter product code: ");
    scanf("%d", &r.code);

    printf("Enter product name: ");
    fflush(stdin);
    gets(r.productName);

    printf("Enter quantity: ");
    fflush(stdin);
    scanf("%d", &r.quantity);

    printf("Product added: ");

    fprintf(&r. sizeof(r), fp);
    fclose(fp);
}

void department_displayProduct()
{
    printf("  Product list   ");

    fp = fopen("product.txt", "w++");
    while (fread(&r, sizeof(r), fp) == 1)
    {
        printf("%d %s %d %f", r.code, r.productName, r.quantity, r.rate);
    }

    fclose(fp)
    
}

void department_updateProduct()
{
    int code;
    printf("Update product");
    printf("Enter product code: ");
    scanf("%d", &code);

    FILE *fp;

    fp = fopen("product.txt", "w++");

    while(fread(&r, sizeof(r), fp) == 1)
    {
        
    }

}
