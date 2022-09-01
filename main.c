#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record
{
    char productName[100];
    float rate;
    int quantity,code;
} r;

FILE *fp;

int main()
{
    int choice;
        
    while(1)
    {
        system("cls");

        printf("\n");

        printf("\n\t\t\t\t MENU\n\t\t\t\t ___________________________");
        printf("\n\t\t\t\t| 1 ADD PRODUCT                          |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 2 DESPLAY PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 3 UPDATE PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 4 Delete PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 5 BUY PRODUCT                             |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 0 EXIT                                     |\n\t\t\t\t__________________________");
        printf("\n\t\t\t\tPLEASE CHOOSE A NUMBER IN THE BOX ABOVE:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:
                exit(0);

            case 1:
                department_addProduct();
                break;

            case 2:
                department_displayProduct();
                break;

            case 3:
                department_updateProduct();
                break;

            case 4:
                department_deleteProduct();
                break;

            case 5:
                department_buyProduct();
            
            default:
                printf("Invalid choice..: ");
        }

        printf("Enter any key to continue: ");
        getch();
    }
    return 0;
}


void department_addProduct()
{
    fp = fopen("product.txt", "ab");

    printf("Enter product code: ");
    scanf("%d", &r.code);

    printf("Enter product name: ");
    fflush(stdin);
    gets(r.productName);

    printf("Enter quantity: ");
    fflush(stdin);
    scanf("%d", &r.quantity);

    printf("Product added: ");

    fwrite(&r, sizeof(r),1, fp);
    fclose(fp);
}

void department_displayProduct() 
{
    system("cls");
    printf("  Product list   ");

    fp = fopen("product.txt", "rb");
    while (fread(&r, sizeof(r),1, fp) == 1)
    {
        printf("%d %s %d %f", r.code, r.productName, r.quantity, r.rate);
    }

    fclose(fp);
    
}

void department_updateProduct()
{
    int code, f;

    system("cls");
    printf("Update product");
    printf("Enter product code: ");
    scanf("%d", &code);

    FILE *ft;

    fp = fopen("product.txt", "rb+");

    while(fread(&r, sizeof(r),1, fp) == 1)
    {
        if(code == r.code)
        {
            f = 1;
            printf("Enter new product: ");
            fflush(stdin);
            gets(r.productName);

            printf("Enter qualntity of new product: ");
            fflush(stdin);
            scanf("%d", &r.code);

            fseek(fp, -sizeof(r), 1);
            fwrite(&r, sizeof(r),1 , fp);
            fclose(fp);
            break;
        }
    }
    if (f == 1)
    {
        printf("\nProduct updated");
        
    }
    else
        {
            printf("\nError");
        }
}

void department_deleteProduct()
{
    int code, f;

    system("cls");
    printf("Delete products");
    printf("Enter code of the product to delete: ");
    scanf("%d", &code);

    FILE *ft;

    fp = fopen("product.txt", "rb");

    while (fread(&r, sizeof(r), 1, fp) == 1)
    {
        if (code == r.code)
        {
            f = 1;
            fclose(fp);
            break;
        }
    }

    if(f == 1)
    {
        printf("\nProduct deleted");
        del_func(code);
    }
    else
    {
        printf("\n\nError");
    }
}

void department_buyProduct()
{
    int code, f = 0;

    system("cls");
    printf("Enter code of the product to buy: ");
    scanf("%d", code);

    fp = fopen("product.txt", "rb+");

    while (fread(&r, sizeof(r), 1, fp) == 1)
    {
        if (code == r.code)
        {
            f = 1;
            r.quantity = r.quantity - 1;
            fseek(fp, -sizeof(r), 1);
            fwrite(&r, sizeof(r), 1, fp);
            fclose(fp);
            if (r.quantity == 0)
            {
                del_func(r.code);
            }
            break;
        }
    }

    if (f == 1)
    {
        printf("\nProduct bought ");
    }
    else
    {
        printf("\n\nError");
    }
}

void del_func()
{
    int code, f = 0;

    FILE *ft;

    fp = fopen("product.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while (fread(&r, sizeof(r), 1, fp) == 1)
    {
        if (code == r.code)
        {
            f = 1;
        }
        else
        {
            fwrite(&r, sizeof(r),1 , ft);
        }
    }
    fclose(fp);
    fclose(ft);

    remove("product.txt");
    rename("temp.txt", "product.txt");
}