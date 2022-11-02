#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void department_addProduct();
void department_displayProduct();
void department_updateProduct();
void department_deleteProduct();
void department_buyProduct();
void del_func();

struct record
{
    char productName[100];
    int quantity,code,rate;
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
        printf("\n\t\t\t\t| 2 DISPLAY PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 3 UPDATE PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 4 Delete PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 5 BUY PRODUCT                             |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| 0 EXIT                                     |\n\t\t\t\t__________________________");
        printf("\n\t\t\t\tPLEASE CHOOSE A NUMBER IN THE BOX ABOVE: ");
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
                break;
            
            default:
                printf("  ----Error---- ");
        }

        // printf("\nEnter any key to continue: ");
        system("pause");
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
    scanf("%s", r.productName);

    printf("Enter quantity: ");
    fflush(stdin);
    scanf("%d", &r.quantity);

    printf("Enter rate: ");
    fflush(stdin);
    scanf("%d", &r.rate);

    printf(" \n----Product added---- ");

    fwrite(&r, sizeof(r),1, fp);
    fclose(fp);
}

void department_displayProduct() 
{
    system("cls");
    printf("   ----Product list----\n\n   ");
    printf("%-10s %-30s %-30s %s\n", "Code", "Product Name", "Quantity", "Rate");

    fp = fopen("product.txt", "rb");
    while(fread(&r, sizeof(r),1, fp) == 1)
    {
        printf("%-10d %-30s %-30d %d", r.code, r.productName, r.quantity, r.rate);
        printf("\n");
    }

    fclose(fp);
}

void department_updateProduct()
{
    int code, f;

    system("cls");
    printf("    ----Update product----\n\n    ");
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
            scanf("%s", r.productName);

            printf("Enter quantity of new product: ");
            fflush(stdin);
            scanf("%d", &r.quantity);

            printf("Enter rate: ");
            fflush(stdin);
            scanf("%d", &r.rate);

            fseek(fp, -sizeof(r), 1);
            fwrite(&r, sizeof(r),1 , fp);
            fclose(fp);
            break;
        }
    }
    if (f == 1)
    {
        printf("\n----Product updated----");
        
    }
    else
        {
            printf("\n\n----Error----");
        }
}

void department_deleteProduct()
{
    int code, f;

    system("cls");
    printf("----Delete products----\n\n");
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
        printf("\n--Product deleted--");
        del_func(code);
    }
    else
    {
        printf("\n\n----Error----");
    }
}

void department_buyProduct()
{
    int code, f = 0, num;

    system("cls");
    printf("----Buy Product----\n\n");
    printf("Enter code of the product to buy: ");
    scanf("%d", &code);
    printf("Enter quantity of the product: ");
    scanf("%d", &num);


    fp = fopen("product.txt", "rb+");

    while (fread(&r, sizeof(r), 1, fp) == 1)
    {
        if (code == r.code)
        {
            f = 1;
            r.quantity = r.quantity - num;
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

    if (f == 0)
    {
        printf("\n\n----Error----");
    }
    else
    {
        printf("\n----Product bought----");
    }
}

void del_func(int code)
{
    int f = 0;

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