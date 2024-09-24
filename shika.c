#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_MENU_ITEMS 10
#define MAX_INGREDIENTS 10

typedef struct 
{
    char name[50];
    float price;
}MenuItem;

typedef struct
 {
    char name[50];
    int quantity;
}Ingredient;

MenuItem menu[MAX_MENU_ITEMS];
Ingredient inventory[MAX_INGREDIENTS];
int menu_count = 0;
int ingredient_count = 0;

void add_menu_items(){
    if(menu_count<MAX_MENU_ITEMS)
    {
       printf("Enter the item name:");
       scanf("%s",menu[menu_count].name);

       printf("Enter the item price:");
       scanf("%f",&menu[menu_count].price);
       menu_count++;

       printf("Item is added\n");
    }
    else{
        printf("Menu is Full\n");
    }
}

void view_menu()
{
   printf("Menu:\n");

   for(int i = 0; i<menu_count;i++)
   {
    printf("%d.%s - $%.2f\n",i+1, menu[i].name, menu[i].price);
   }
 
}

void place_order(){
    view_menu();
    int choice;
    printf("Enter the item number for order:");
    scanf("%d",&choice);

    if(choice>0 && choice<=menu_count)
    {
        printf("You ordered:%s of $%.2f\n",menu[choice - 1].name, menu[choice - 1].price);
    }
    else{
        printf("Invaid Choice!\n");
    }
}

void add_ingredients()
{
    if(menu_count<MAX_INGREDIENTS)
    {
        printf("Enter the ingredient name:");
        scanf("%s",inventory[ingredient_count].name);

        printf("Enter the ingredient quantity:");
        scanf("%d",&inventory[ingredient_count].quantity);
        ingredient_count++;

        printf("Ingredient is added\n");
    }
    else{
        printf("Inventory is Full\n");
    }
}

void view_inventory(){
    printf(" Inventory :\n");

    for(int i=0;i<ingredient_count;i++)
    {
        printf("%d.%s-%d kg \n",i+1, inventory[i].name, inventory[i].quantity);
    }
}

void manage_billing()
{
    view_menu();
    int choice;
    printf("Enter the item no. for manage billing:");
    scanf("%d",&choice);

    if(choice>0 && choice<=menu_count)
    {
        printf("Total bill of %s is $%.2f\n", menu[choice - 1].name, menu[choice - 1].price);
    }
    else{
        printf("Invalid choice!\n");
    }

}

void main_menu()
{
    int option;
    do
    {
       printf("RESTAURANT MANAGEMENT SYSTEM \n");
       printf("1. Add menu items \n");
       printf("2. View menu \n");
       printf("3. Place order \n");
       printf("4. Add ingredients \n");
       printf("5. View inventory \n");
       printf("6. Manage billing \n");
       printf("0. Exit...\n");
       printf("Choose the option :");
       scanf("%d", & option);

       switch(option){
        case 1:
                add_menu_items();
                break;
        case 2:
                view_menu();
                break;
        case 3:
                place_order();
                break;
        case 4:
                add_ingredients();
                break;
        case 5:
                view_inventory();
                break;
        case 6:
                manage_billing();
                break;
        case 0:
                printf("Exiting...\n");
                break;
        default:
                printf("Invalid option !\n");
                break;        
       }
    } while(option!=0);
}

int main (){
    main_menu();
    return 0;
    
}



