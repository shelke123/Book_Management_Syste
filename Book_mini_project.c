#include<stdio.h>
#include<string.h>

struct book
{
	int id;
	char b_name[100];
	char author[100];
	double price;
	double rating;
};


void store(struct book * , int);
void display(struct book * ,int);
void searchById(struct book * , int);
void searchByName(struct book *,int);
void updateByPrice(struct book *, int);
void updateByRating(struct book *, int);
void del_1(struct book *, int *);
void topprice(struct book *,int);
void toprating(struct book *, int);

void main()
{
	int size=4;
    struct book brr[size];


	printf("\t ***BOOK MANAGEMENT SYSTEM*** \n");
	int choice,exit;
	//printf("Size  %d ",size);
	do
	{
	printf("\t***Menu*** \t\n1.Store\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Top 3\n");
	printf("Enter the Choice: ");
	scanf("%d",&choice);
	
	
	
	switch(choice)
	{
	case 1:
	    store(brr,size);
		break;
		
	case 2:
		display(brr,size);
		break;
		
	case 3:
    {
        int ch1;
        printf("Menu: \n1.Search by ID\n2.Search by Name\n");
        scanf("%d", &ch1);

        if(ch1 == 1)
        {
            searchById(brr,size); 
        }
        else if(ch1 == 2)
        {
            searchByName(brr,size); 
        }
        else
        {
            printf("Invalid choice.\n");
        }
        break;
    }
    
    case 4:
    {
        int ch1;
        printf("Menu: \n1.Update by Price\n2.Update by Rating\n");
        scanf("%d", &ch1);

        if(ch1 == 1)
        {
            updateByPrice(brr,size); 
        }
        else if(ch1 == 2)
        {
           updateByRating(brr,size); 
        }
        else
        {
            printf("Invalid choice.\n");
        }
        break;
    }
   
   case 5:
   	{
		del_1(brr,&size);
		break;
	}
	
   case 6:
   	{
		int ch1;
        printf("Menu: \n1.Top3 by Price\n2.Top3 by Rating\n");
        scanf("%d", &ch1);

        if(ch1 == 1)
        {
           topprice(brr,size); 
        }
        else if(ch1 == 2)
        {
          toprating(brr,size); 
        }
        else
        {
            printf("Invalid choice.\n");
        }
        break;
	}
}
printf("enter 1 to continue or 0 to exist : ");
scanf("%d",&exit);
} 
while(exit==1);
//printf("Size  %d ",size);
}


void store(struct book * arr, int t)
{
 	int i;
	for(i=0;i<t;i++)
	{
		printf("----------------------------------------------------------------------------------------------\n");
		printf("enter the id of the book:-");
		scanf("%d",&arr[i].id);
		printf("enter the name of the book:-");
		scanf("%s",&arr[i].b_name);
		printf("enter the authors name:-");
		scanf("%s",&arr[i].author);
		printf("enter the price of the book:-");
		scanf("%lf",&arr[i].price);
		printf("enter the rating of the book:-");
		scanf("%lf",&arr[i].rating);
		printf("---------------------------------------------------------------------------------------------\n");
	}
}


void display(struct book * arr,int t)
{
	//printf("we ar in display()");
	int i;
	for(i=0;i<t;i++)
	{
		printf("\t ID is:%d BookName is %s BookAuthorName is %s Price of book is %lf Rating is %lf \n",arr[i].id,arr[i].b_name,arr[i].author,arr[i].price,arr[i].rating);
	}
}




void searchById(struct book * a, int t)
{

	int search;
	int count=0;
	printf("enter the bookid for search : \n");
	scanf("%d",&search);
	
	int i;
	
    for(i=0;i<t;i++)
    {
		if(a[i].id==search) 
		{
		count++;
		}
	}
	if(count==1)
	printf("found \n");
	else
	printf("not found \n");
}


void searchByName(struct book * a, int t)
{
    char search[20];
	int count=0;
	printf("enter the book name for search : \n");
	scanf("%s",search);
	
	int i;
	
    for(i=0;i<t;i++)
    {
	    if(strcmpi(a[i].b_name, search)==0)  //a[i].b_name==serch is not because we can not compare string with assignment opertor
		{
		count++;
		}
	}
	if(count==1)
	printf("found \n");
	else
	printf("not found \n");
}

void updateByPrice(struct book * a, int t)
{
	int i,count=0;
	int search;
	double newprice;
	printf("enter the bookid for search : ");
	scanf("%d",&search);
	
    printf("Enter the new price: ");
    scanf("%lf", &newprice);

	for(i = 0;i<t;i++) 
	{
        if(a[i].id == search)
		{
            a[i].price = newprice;
            count++;
        }
    }

    if (count>0) 
	{
        printf("Updated Price of Book Using ID %d\n", search);
    } 
	else 
	{
        printf("Book with ID %d not found for price update\n", search);
    }
}


void updateByRating(struct book *a, int t)
{
	int i,count=0;
	int search;
	double newrating;
	printf("enter the bookid for search : ");
	scanf("%d",&search);
	
    printf("Enter the new price: ");
    scanf("%lf", &newrating);

	for (i = 0;i<t;i++) 
	{
        if (a[i].id == search)
		{
            a[i].rating = newrating;
            count++;
        }
    }

    if (count>0) 
	{
        printf("Updated Rating of Book Using ID %d\n", search);
    } 
	else 
	{
        printf("Book with ID %d not found for Rating update\n", search);
    }
	
}

void del_1(struct book *a,int *t)
{
	int i,j;
	int search;
	printf("Enter the Id for delete the record : ");
	scanf("%d",&search);
	for(i=0;i<*t;i++)
	{
		if(a[i].id==search)
		{
		  for(j=i;j<(*t)-1;j++)
		  {
		  	a[j]=a[j+1];
		  }
		  (*t)--;
		  printf("book has be remove \n");
		  break;
		}
	}
	//printf("\n %d",*t); to check the size after remove the record
}

void topprice(struct book *a, int t) 
{
    int i, j, k, b;
    for (i=0; i<t; i++) {
        for (j = i+1; j<t; j++) {
            if (a[i].price > a[j].price) {
                b = a[i].price;
                a[i].price = a[j].price;
                a[j].price = b;
            }
        }
    }
    for (k=t-1; k>=t-3;k--) {
        printf("\t %d,%s,%s,%lf,%lf \n", a[k].id, a[k].b_name, a[k].author, a[k].price, a[k].rating);
    }
}

void toprating(struct book *a, int t)
{
    int i, j, k, b;
    for (i=0; i<t; i++) {
        for (j = i+1; j<t; j++) {
            if (a[i].rating > a[j].rating) {
                b = a[i].rating;
                a[i].rating = a[j].rating;
                a[j].rating = b;
            }
        }
    }
    for (k = t-1; k>=t-3; k--) {
        printf("\t %d,%s,%s,%lf,%lf \n", a[k].id, a[k].b_name, a[k].author, a[k].price, a[k].rating);
    }
}

	




