#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct car
{
    char name[15];
    int price;
    int avi_car_buy;
    int rent;
    int avi_car_rent;
    struct car *next;
};

typedef struct car CAR;

CAR *start=NULL;

struct custom_for_buy
{
    char name[30];
    char carname[30];
    struct custom_for_buy *next;
};

typedef struct custom_for_buy CUSTOM_B;
CUSTOM_B *front=NULL;
CUSTOM_B *rear=NULL;

struct custom_for_rent
{
    char name[30];
    char carname[30];
    struct custom_for_rent *next;
};

typedef struct custom_for_buy CUSTOM_R;
CUSTOM_R *front1=NULL;
CUSTOM_R *rear1=NULL;

struct sold
{
    char name[30];
    char carname[30];
    struct sold *next;
};
typedef struct sold SOLD;
SOLD *top=NULL;



void admin();
void customer();
void info();
void display_for_admin();
void customer_list_for_buy(char car_name[30]);
void customer_list_for_rent(char car_name[30]);
void service_info_buy_cars();
void service_info_rent_cars();
void dequeue_customer_list_for_buy();
void dequeue_customer_list_for_rent();
void service_update_buy_cars();
void service_update_rent_cars();
void sold_cars_info();
void last_sold_car();
void count_maintain_buy_car();
void count_maintain_rent_car();
void buy_car();
void display_buy_car();
int search_for_buy();
void rent_car();
void display_rent_car();
int search_for_rent();


int main()
{
    int ch;

    while(1)
    {
        printf("\n 1.Admin \n 2.Customer \n 3.Exit");

        printf("\nSelect :: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            admin();
            break;

        case 2:
            customer();
            break;

        case 3:
            exit(0);
            break;
        }
    }
}

void admin()
{
    int ch;

    while(1)
    {
        printf("\n\n*FOR ADMIN USE ONLY *");
        printf("\n\n 1.Insert Information of Cars :: \n 2.Display \n 3.Service info of car for Buy \n 4.Service info of car for Rent \n 5.Exit.");

        printf("\n\nEnter Your Choice :: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            info();
            break;

        case 2:
            display_for_admin();
            break;

        case 3:
            service_info_buy_cars();
            break;

        case 4:
            service_info_rent_cars();
            break;

        case 5:
            main();
            break;
        }
    }
}

void info()
{
    int n,i;
    char data[20];

    printf("\n Enter how many types of car in agency :: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
	CAR *nc;
	CAR *temp;

	nc=(CAR*)malloc(sizeof(CAR));

	printf("\n Car[%d] :: ",i+1);

	printf("\nEnter the Name of Car :: ");
	scanf("%s",data);

	strcpy(nc->name,data);

	printf("Enter the Price of Car (Rs.):: ");
	scanf("%d",&nc->price);

	printf("No. of Available cars for Buy :: ");
	scanf("%d",&nc->avi_car_buy);

	printf("Enter the Rent of Car (Rs./Km):: ");
	scanf("%d",&nc->rent);

	printf("No. of Available cars for Rent :: ");
	scanf("%d",&nc->avi_car_rent);

	temp=start;

        if(start==NULL)
        {
            nc->next=NULL;
            start=nc;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nc;
            nc->next=NULL;
        }
    }
}

void display_for_admin()
{
    CAR *temp;
    int i=1;

    temp=start;

    if(start==NULL)
    {
        printf("\n Information of Car is not Avaibleble.");
    }
    else
    {
        printf("\nCar_Name\tPrice\t  Cars for Buy\t  Rent\t  Cars for Rent\n\n");
        while(temp!=NULL)
        {
            printf("[%d]%s\tRs.%d\t%d\t  %dRs./Km.\t%d\n\n",i,temp->name,temp->price,temp->avi_car_buy,temp->rent,temp->avi_car_rent);
            temp=temp->next;
            i++;

        }
    }
}

void service_info_buy_cars()
{
    int ch;

    while(1)
    {
        printf("\n\n 1.Display customer list for buy car \n 2.Service Updates \n 3.Last sold car. \n 4.Exit");
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            display_customer_list_for_buy();
            break;

        case 2:
            service_update_buy_cars();
            break;

        case 3:
            last_sold_car();
            break;

        case 4:
            admin();
            break;
        }
    }

}

void service_info_rent_cars()
{
    int ch;

    while(1)
    {
        printf("\n\n 1.Display customer list for rent car \n 2.Service Updates \n 3.Exit");
        printf("\n Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            display_customer_list_for_rent();
            break;

        case 2:
            service_update_rent_cars();
            break;

        case 3:
            admin();
            break;
        }
    }

}


void display_customer_list_for_buy()
{
    int i=1;
    CUSTOM_B *temp;

    temp=front;

    if(front==NULL)
    {
        printf("\n No Customer is present.");
    }
    else
    {
        printf("\nCustomer_Name\tReq.car\n");
        while(temp!=NULL)
        {
            printf("\n[%d]%s\t%s",i,temp->name,temp->carname);
            temp=temp->next;
            i++;
        }
    }

}

void display_customer_list_for_rent()
{
    int i=1;
    CUSTOM_R *temp;

    temp=front1;

    if(front1==NULL)
    {
        printf("\n No Customer is present.");
    }
    else
    {
        printf("\nCustomer_Name\tReq.car\n");
        while(temp!=NULL)
        {
            printf("\n[%d]%s\t%s",i,temp->name,temp->carname);
            temp=temp->next;
            i++;
        }
    }

}

void service_update_buy_cars()
{
    int n;

    printf("\n Is service provide to %s ?",front);
    printf("\n 1.yes 2.No");
    scanf("%d",&n);

    if(n==1)
    {
        sold_cars_info();
        count_maintain_buy_car();
        dequeue_customer_list_for_buy();
    }
}

void dequeue_customer_list_for_buy()
{
    CUSTOM_B *temp;

    temp=front;

    front=front->next;

    free(temp);

}

void sold_cars_info()
{
    CUSTOM_B *temp;

    temp=front;

    SOLD *nc;

    nc=(SOLD*)malloc(sizeof(SOLD));

    strcpy(nc->name,temp->name);
    strcpy(nc->carname,temp->carname);

    if(top==NULL)
    {
        nc->next=NULL;
        top=nc;
    }
    else
    {
        nc->next=top;
        top=nc;
    }

}

void count_maintain_buy_car()
{
    CAR *temp;

    temp=start;

    do
    {
        if(strcmp(temp->name,front->carname)==0)
        {
            temp->avi_car_buy=temp->avi_car_buy-1;
        }
        temp=temp->next;
    }
    while(temp!=NULL);
}

void last_sold_car()
{
    printf("\nCustomer Name\t\tCar Name\n");
    printf("\n%s\t\t%s",top->name,top->carname);
}

void service_update_rent_cars()
{
    int n;
    CUSTOM_R *tenant;

    printf("\n Is service provide to %s ?",front1);
    printf("\n 1.yes 2.No");
    scanf("%d",&n);

    if(n==1)
    {
        count_maintain_rent_car();
        dequeue_customer_list_for_rent();
    }
}

void count_maintain_rent_car()
{
    CAR *temp;

    temp=start;

    do
    {
        if(strcmp(temp->name,front1->carname)==0)
        {
            temp->avi_car_rent=temp->avi_car_rent-1;
        }
        temp=temp->next;
    }
    while(temp!=NULL);
}

void dequeue_customer_list_for_rent()
{
    CUSTOM_R *temp;

    temp=front1;

    front1=front1->next;

    free(temp);

}

void customer()
{
    int ch;
    int name[30];

    while(1)
    {
        printf("\n\n*FOR CUSTOMER USE ONLY *");

        printf("\n\n 1.Buy car \n 2.Car on rent \n 3.Exit.");

        printf("\n\nEnter Your Choice :: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            buy_car();
            break;

        case 2:
            rent_car();
            break;
        }
        main();
    }
}

void customer_list_for_buy(char car_name[30])
{
    char data[30];
    CUSTOM_B *new_custom;
    CUSTOM_B *temp;


    new_custom=(CUSTOM_B*)malloc(sizeof(CUSTOM_B));

    printf("\nEnter Customer Name :: ");
    scanf("%s",data);

    strcpy(new_custom->name,data);
    strcpy(new_custom->carname,car_name);


    temp=front;

    if(front==NULL)
    {
        new_custom->next=NULL;
        front=new_custom;
        rear=new_custom;
    }
    else
    {
        new_custom->next=NULL;
        rear->next=new_custom;
        rear=new_custom;
    }

}

void customer_list_for_rent(char car_name[30])
{
    char data[30];
    CUSTOM_R *new_custom;
    CUSTOM_R *temp;

    new_custom=(CUSTOM_R*)malloc(sizeof(CUSTOM_R));

    printf("\nEnter Customer Name :: ");
    scanf("%s",data);

    strcpy(new_custom->name,data);
    strcpy(new_custom->carname,car_name);

    temp=front1;

    if(front1==NULL)
    {
        new_custom->next=NULL;
        front1=new_custom;
        rear1=new_custom;
    }
    else
    {
        new_custom->next=NULL;
        rear1->next=new_custom;
        rear1=new_custom;
    }

}

void buy_car()
{
    CAR *n;

    n=(CAR*)malloc(sizeof(CAR));

    int no;
    display_buy_car();
    n=search_for_buy();

    if(n!=NULL)
    {
        printf("\n Car is present for buy.");
        printf("\n If you want to Confirm :: 1.Yes \t 2.No");
        scanf("%d",&no);

        if(no==1)
        {
            customer_list_for_buy(n->name);
            printf("\nYour name is added into request list.\nPlease wait for service.\n");
        }
        else
        {
            main();
        }
    }
    else
    {
        printf("\n Car is not present.");
    }
}

void rent_car()
{
    CAR *n;

    n=(CAR*)malloc(sizeof(CAR));

    int no;
    display_rent_car();
    n=search_for_rent();

    if(n!=NULL)
    {
        printf("\n Car is present for rent.");
        printf("\n If you want to Confirm :: 1.Yes \t 2.No");
        scanf("%d",&no);

        if(no==1)
        {
            customer_list_for_rent(n->name);
            printf("\nYour name is added into request list.\nPlease wait for service.\n");
        }
        else
        {
            main();
        }
    }
    else
    {
        printf("\n Car is  not present.");
    }
}

void display_buy_car()
{
    CAR *temp;
    int i=1;

    temp=start;

    if(start==NULL)
    {
        printf("\n Information of Car is not Avaibleble.");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("\n\n Car[%d] :: ",i);
            printf("\n Name :: %s",temp->name);
            printf("\n Price :: %d",temp->price);

            temp=temp->next;
            i++;

        }
    }
}

void display_rent_car()
{
    CAR *temp;
    int i=1;

    temp=start;

    if(start==NULL)
    {
        printf("\n Information of Car is not Avaibleble.");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("\n\n Car[%d] :: ",i);
            printf("\n Name :: %s",temp->name);
            printf("\n Price :: %d/Km",temp->rent);

            temp=temp->next;
            i++;

        }
    }
}

int search_for_buy()
{
    char data[20];
    CAR *temp;

    printf("\n Enter the name of car which you want to Search for Buy:: ");
    scanf("%s",data);

    temp=start;;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,data)==0 && temp->avi_car_buy>0)
        {
            return temp;
        }
        temp=temp->next;
    }
}

int search_for_rent()
{
    char data[20];
    CAR *temp;

    printf("\n Enter the name of car which you want to Search for rent :: ");
    scanf("%s",data);

    temp=start;;

    while(temp!=NULL)
    {
        if(strcmp(temp->name,data)==0 && temp->avi_car_rent>0)
        {
            return temp;
        }
        temp=temp->next;
    }
}


