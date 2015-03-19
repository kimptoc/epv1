#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char ans;
int c;
int choice;
int num_of_prdct;
float change;
float payment;
float final_price;

int Cash_Register();
int Product_Information();
int Disp_Inventory();
int Update_Records();

struct products
{
	char prdct_name[20][5];
    float prdct_prce;
	int prdct_amnt;	
}product[100];

int Cash_Register()
{
	FILE*f;
	f=fopen("productinventory.txt", "r");
	   	if (f == NULL)
    	{
    		printf ("\n\n\t\t\t\t This process cannot be completed. \n\n\n");
      		system("pause");
            return (0);
    	}
	
	printf("\n\nPlease enter the product being purchased.\n");
	scanf("%s", product[c].prdct_name);
	printf("Please enter the price of the product being purchased.\n");
	scanf("%f", &product[c].prdct_prce);
	printf("Please enter the number of products being purchased.\n");
	scanf("%f", &num_of_prdct);
	
	fscanf(f,"%s %f", product[c].prdct_name, &product[c].prdct_prce);
	
	final_price = num_of_prdct * product[c].prdct_prce; 
	printf("The final price is: %.2f \n\n", final_price);
	printf("What is the customer's payment? \n");
	scanf("%f", &payment);
	change=payment-final_price;
	
		if (final_price>payment)
		{
			float extra=final_price-payment;
			printf("\nThe final price of %s is %f. The customer paid %f.", product[c].prdct_name, final_price, payment);
			printf("\n\t\t The customer's payment is not enough. \n To purchase, the customer must add: $%.2f \n\n",extra);
			system("pause");
			return (0);
		}
		else
		{
			printf("\nProduct Name= %s \nQuantity= %d \nPayment= $%.2f\nFinal Price= $%.2f \nChange= $%.2f \n\n\n",product[c].prdct_name, num_of_prdct, payment, final_price, change);	
		}
	
	getch();	
}

int Product_Information()
{
    
   	FILE*f;
   
    do{      
     
    f= fopen("temp_productinventory.txt", "r");
    printf ("\n\nWhat is the name of the poduct you want to add?\n");
    scanf ("%s", &product[c].prdct_name);
    printf ("What is the price of this product?\n");
    scanf ("%f", &product[c].prdct_prce);
    printf ("How much stock is there of this product?\n");
    scanf ("%f", &product[c].prdct_amnt);
    printf ("\nTo continue adding, enter: 1         To return to main page, enter: 2\n");
    scanf ("%d", &ans);
     
    if (f == NULL)
     {
      f= fopen("productinventory.txt", "w");
     }
    else 
     {
      f= fopen("productinventory.txt", "a");
     }
   
    fprintf(f,"%s \t\t\t\t%f \t\t\t %f\n", product[c].prdct_name, product[c].prdct_prce, product[c].prdct_amnt);
    fclose(f);  
   
    f= fopen("temp_productinventory.txt", "w");
    fprintf(f,"%s \t\t\t\t%f \t\t\t %f\n", product[c].prdct_name, product[c].prdct_prce, product[c].prdct_amnt);
    fclose(f);  
      
    }while (ans==1);
   
    if (ans==2)
     { 
      return(0);
     }
    system("pause"); 
}   

int Update_Records()
{
	FILE*f;
	f=fopen("productinventory.txt", "r");
	   	if (f == NULL)
    	{
    		printf ("\n\n\t\t\t\t This process cannot be completed. \n\n\n");
      		system("pause");
            return (0);
    	}
	
	do 
	{	
		Disp_Inventory();
		printf("What is the name of the item you would like to update? \n");
		scanf("%s", product[c].prdct_name);	
		printf("The record selected is: \n");
		printf("%-23s %-23.10f $%.2f\n",product[c].prdct_name, product[c].prdct_prce, product[c].prdct_amnt);
		printf("\n\n What would you like to update: \n");
		printf("1. Change name of item");
		printf("2. Change price of item");
		printf("3. Change amount of item");	
		printf("4. Delete entire record of item");	
		scanf("%d", &choice);
		getchar();
		
		switch(choice);
			{
				case 1:
				break;
				
				case 2;
				break;
				
				case 3;
				break;
				
				case 4;
				break;
				
				default:
				printf("This is an invalid option.");	
			}
			
		printf("\n\n\t\tWould you like to continue updating your file?\n");	
		scanf("%c", ans);	
	}while (ans == 'y' | ans == 'Y');
}

int Disp_Inventory();

    FILE*f=fopen("productinventory.txt", "r");	
   		if (f == NULL)
    	{
    		printf ("\n\nThe product inventory is empty.");
      		return (0);
    	}
	
	fscanf(f,"%s \t\t\t\t%f \t\t\t %f\n", product[c].prdct_name, product[c].prdct_prce, product[c].prdct_amnt);
    printf("Product Name \t\tPrice \t\t\tAmount in Stock\n\n");
    
       while (!feof(f))
	   {
			 printf("%-23s %-23.10f $%.2f\n",product[c].prdct_name, product[c].prdct_prce, product[c].prdct_amnt);
             printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
             fscanf(f,"%s \t\t\t%f \t\t\t\t%f \n",product[c].prdct_name, product[c].prdct_prce, product[c].prdct_amnt);
                    			
	   }
	   
	fclose(f);
	
	f=fopen("temp_productinventory.txt", "r");
	fscanf(f,"%s \t\t\t%f \t\t\t\t%f \n",product[c].prdct_name, product[c].prdct_prce, product[c].prdct_amnt);
	
	printf("%-23s %-23.10f $%.2f\n",product[c].prdct_name, product[c].prdct_prce, product[c].prdct_amnt);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	
	fclose(f);      
}


int main ()
{

	char password[30];
    char pword[12];
	int difference;

    char cont;
  
    FILE *pfile;
    pfile = fopen ("thepassword.txt", "w");
    strcpy (pword, "manager");
    //sets the password to manager and store it in the variable pword
  
    fprintf (pfile, "%s", pword);
    //writes the contents of pword to the file thepassword.txt
  
    fclose (pfile);
	system ("COLOR FC");
	printf("\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("\t\t\tWelcome to The Front Porch\n\n");
	printf("\t\t\"Your one stop shop for Art and Craft\"\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("\t\t\tPlease press enter to continue. ");
	getchar();
	
	do 
	{
		system ("cls");
		system ("COLOR 0C");
		printf("\t\tThis service offers you the following options.\n\n");
		printf("1. Cash Register \n");
		printf("2. Add Product to Inventory\n");
		printf("3. Update Product Information\n");
		printf("4. Search Product Inventory\n");
		printf("5. Display Product Inventory\n");
		printf("6. Exit\n\n");
		printf("\t\t Please enter the number of your selection.\n");	
		scanf("%d", &choice);
		getchar();
		switch (choice)
			{
			case 1:
            system("cls");
            printf("\t\t\t Cash Register\n");
            Cash_Register();
			break;
			
			case 2:
			system("cls");
			printf("\t\t\t Product Inventory\n");
			Product_Information();		
			break;
			
			case 3:
            system("cls");
			printf("\t\t\t Update Product Information\n");
			printf ("Enter password: ");
   			scanf ("%s", password);
     
   			pfile = fopen ("thepassword.txt", "r");
   			if (pfile == NULL)
   				{
    			printf ("An Error Has Occured");
    			exit (0);
    			}//exits the program if the file, thepassword.txt, is not found
   			
    		fscanf (pfile, "%s", pword);

    		difference = strcmp (password, pword);

    		while (difference != 0)
    		{
     	 	  printf ("\n\n______________________________________\n");
     		  printf ("INCORRECT PASSWORD\n");
    		  printf ("Enter password (OR 999 to Exit Program) \n >");
     		  scanf ("%s", password);
     		  difference = strcmp (password, pword);
     		  printf ("______________________________________\n");
     		  int exxit = strcmp (password, "999");
     		  if (exxit == 0)
        	  exit (0);
    		}
    		Update_Records();
			break;
			
			case 4:
			system("cls");
			printf("\t\t Search Product Inventory\n\n");
			break;
			
			case 5:
			system("cls");
			printf("\t\t Product Inventory\n\n");
			int Disp_Inventory();
			getchar();
			break;
			
			case 6:
			system("cls");
			system ("COLOR 03");
			printf("\n\n\t\t\t GOODBYE !");
			getchar();
			exit (0);
			break;
			
			default:
			printf("This is an invalid option.");
			}
			
	}while (choice != 6);
	system("pause");
	return 0;
	
}
