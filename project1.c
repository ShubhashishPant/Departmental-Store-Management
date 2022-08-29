	#include <stdio.h>
    
    typedef struct record
{
    char name[100],code[100];
    float rate;
    int quantity;
} record;

int main(void)
    {
        int choice;
        
        printf("\n");

        printf("\n\t\t\t\t MENU\n\t\t\t\t ___________________________");
        printf("\n\t\t\t\t| [1] ADD PRODUCT                          |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| [2] DELETE PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| [3] MODIFY PRODUCT                           |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| [4] VIEW PRODUCT                             |");
        printf("\n\t\t\t\t| ______________________________________|");
        printf("\n\t\t\t\t| [5] EXIT                                     |\n\t\t\t\t__________________________");
        printf("\n\t\t\t\tPLEASE CHOOSE A NUMBER IN THE BOX ABOVE:");
        scanf("%d",&choice);
    }
    