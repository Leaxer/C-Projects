#include <stdio.h>
#include <stdlib.h>

typedef union {
    char name[50];
    char address[50];
    int phone;
}Person;

typedef union {
    float amount;
    float interestRate;
    int period;
}Loan;

typedef struct {
    Person Customer;
    Loan Loans[3];
}BankAccount;

/*
Function: listCustomer
----------------------------------
It does: get the customers from struct and list them

*bankAccounts: customer struct
*/
void listCustomer(BankAccount *bankAccounts, int);
/*
Function: addCustomer
----------------------------------
It does: add new customer

*bankAccounts: customer struct
id: current customer id
*/
void addCustomer(BankAccount *bankAccounts, int *id);
/*
Function: newLoan
----------------------------------
It does: add new loan for customer

*bankAccounts: customer struct
int: total customer
*/
void newLoan(BankAccount *bankAccounts,int);
/*
Function: calculateLoan
----------------------------------
It does: calculate total loan

amount: loan amount
period: loan period
interestRate: loan interest rate
*/
double calculateLoan(float amount, int period, float interestRate);
/*
Function: getReport
----------------------------------
It does: get the customer and loan lists' detail

int: total customer
*/
void getReport(int);

int main(){
    int id = 0;
    
    int txtId;
    long phone;
    char name[50],address[50];
    FILE *customerTxt = fopen("customers.txt","r");
    if(customerTxt != NULL){
    while(!feof(customerTxt)){//Loop id time and get this customer's details. When it turns 2 times,it will get second customer's detail and loop will end
        fscanf(customerTxt,"%d",&txtId);
        fscanf(customerTxt,"%[^\n]%*c",name);
        fscanf(customerTxt,"%ld",&phone);
        fscanf(customerTxt,"%[^\n]%*c\n",address);
        id++;
    }
    fclose(customerTxt);
    }
    BankAccount *bankAccounts = (BankAccount *) malloc(50*sizeof(BankAccount)); //Allocate memory
    int select = 0;
    printf("=====================================\n");
    printf("Welcome to the Bank Management System\n");
    printf("=====================================\n");
    while(select != 5){//Selection Menu
        printf("\t1. List All Customers\n");
        printf("\t2. Add New Customer\n");
        printf("\t3. New Loan Application\n");
        printf("\t4. Report Menu\n");
        printf("\t5. Exit System\n");
        scanf("%d",&select);
        if(select == 1) listCustomer(bankAccounts,id);
        else if(select == 2) addCustomer(bankAccounts,&id);
        else if(select == 3) newLoan(bankAccounts,id);
        else if(select == 4) getReport(id);
        else if(select == 5) ;//Do nothing and finish the program
        else printf("There is no operation for this selection\n");
    }
    return 0;
}

void listCustomer(BankAccount *bankAccounts, int id){
    for(int i = 0;i < id;i++){//List all customers
        printf("Customer ID = %d\n",i + 1);
        printf("Customer Name = %s\n",bankAccounts[i].Customer.name);
        printf("\n");
    }
}

void addCustomer(BankAccount *bankAccounts, int *id){
    if(*id > 50){//If id > 50, memory is full. Can't get more customer
        printf("Reached to limit. You can't add customer\n");
        return;
    }
    char address[50];
    long phone;

    FILE *customerTxt;
    customerTxt = fopen("customers.txt","a");//Open file to write customer's detail
    printf("Enter the customer's name: ");
    fflush(stdin);
    getchar();
    scanf("%[^\n]%*c",bankAccounts[*id].Customer.name);
    fprintf(customerTxt,"%d ",*id + 1);
    fprintf(customerTxt,"%s\n",bankAccounts[*id].Customer.name);
    printf("Enter the customer's phone: ");
    scanf("%ld",&phone);
    fprintf(customerTxt,"%ld",phone);
    printf("Enter the customer's address: ");
    fflush(stdin);
    getchar();
    scanf("%[^\n]%*c",address);
    fprintf(customerTxt," %s\n",address);
    printf("\n");
    *id+=1;//Next customer's id
    fclose(customerTxt);
}

void newLoan(BankAccount *bankAccounts,int totalCustomers){
    int period,id,userID,loans = 0;
    float totalMoney,amount,interestRate;
    printf("Enter Customer Id: ");//Enter id for customer you want to give loan
    scanf("%d",&id);
    if(totalCustomers == 0){
            printf("No customer on list\n");
            return;
    }
    while(id > totalCustomers){
        printf("No customer for this id, please enter a valid id: ");
        scanf("%d",&id);
    }
    FILE *loanTxt;
    loanTxt = fopen("loan.txt","r");
    if(loanTxt != NULL){//If open exist
        while(!feof(loanTxt)){//Control how many loan this customer have
            fscanf(loanTxt,"%d %f %d %f",&userID,&amount,&period,&interestRate);
            if(userID == id) loans++;//If id which you input and id from file equal that means this customer has a loan.
        }
        fclose(loanTxt);
    }
    if(loans == 3){//If loans equal to 3 that means can't get more loans
        printf("This customer can't get more loan\n");
        return;
    }
    printf("Enter the amount: ");
    scanf("%f",&amount);
    printf("Enter the period: ");
    scanf("%d",&period);
    printf("Enter the interest rate: ");
    scanf("%f",&interestRate);
    totalMoney = calculateLoan(amount,period,interestRate/100);//Calculate loan
    printf("Total Credit Value = %.4f\n",totalMoney);
    bankAccounts[id].Loans[loans].amount = amount;
    loanTxt = fopen("loan.txt","a");
    fprintf(loanTxt,"\n%d %f %d %f",id,amount,period,interestRate);//Print to file for detail
    fclose(loanTxt);
    printf("\n");
}

double calculateLoan(float amount, int period, float interestRate){
    if (period != 0) return ((1 + interestRate) * calculateLoan(amount, period - 1, interestRate));
    else return amount;
}

void getReport(int totalCustomers){
    int choose,id,userID,i;
    float totalLoan = 0,amount,interestRate;
    int period;
    printf("1. Customer List\n");//Selection
    printf("2. Loan List\n");
    scanf("%d",&choose);
    printf("Enter id: ");
    scanf("%d",&id);
    if(choose == 1){
        long phone;
        char name[50],address[50];
        if(totalCustomers == 0){
            printf("No customer on list\n");
            return;
        }
        while(id > totalCustomers){
            printf("No customer for this id, please enter a valid id: ");
            scanf("%d",&id);
        }
        FILE *customerTxt = fopen("customers.txt","r");
        int j = id;
        for(i = 0;i < j;i++){//Loop id time and get this customer's details. When it turns 2 times,it will get second customer's detail and loop will end
            fscanf(customerTxt,"%d",&id);
            fscanf(customerTxt,"%[^\n]%*c",name);
            fscanf(customerTxt,"%ld",&phone);
            fscanf(customerTxt,"%[^\n]%*c\n",address);
        }
        fclose(customerTxt);
        printf("Customer ID = %d\n",id);//Print the customer detail's
        printf("Customer Name = %s\n",name);
        printf("Customer Phone = %ld\n",phone);
        printf("Customer Address = %s\n",address);
        FILE *loanTxt = fopen("loan.txt","r");
        if(loanTxt != NULL){
            printf("Loans = [");
            while(!feof(loanTxt)){//Check if customer have loans
                fscanf(loanTxt,"%d %f %d %f",&userID,&amount,&period,&interestRate);
                if(userID == id){
                    amount = calculateLoan(amount,period,interestRate/100);
                    printf("%.2f + ",amount);
                    totalLoan = totalLoan + amount;
                }
            }
            printf("] => %.2f\n",totalLoan);
        fclose(loanTxt);
        }
    }else if(choose == 2){
        float monthInstallment;
        int loanId,loanControl = 0;
        int find = 0;
        FILE *loanTxt = fopen("loan.txt","r");
        if(loanTxt == NULL){
            printf("There are no loans for customers\n");
            return;
        }
        printf("Enter the loan number: ");//Which loan you want to see detailly
        scanf("%d",&loanId);
            while(!feof(loanTxt) && loanControl != loanId){//Get the details each time until it reach to same number with loanId
                fscanf(loanTxt,"%d %f %d %f",&userID,&amount,&period,&interestRate);
                if(id == userID) loanControl++;
            }
            fclose(loanTxt);
                if(userID == id && loanControl == loanId) {//If this loan exist,print it
                    amount = calculateLoan(amount,period,interestRate/100);
                    printf("Total Amount: %.4f\n",amount);
                    monthInstallment = amount/period;
                    for(int i = 0;i < period;i++) printf("%d. Month Installment = %.4f\n",i+1,monthInstallment);
                }else printf("No loan for this customer\n");
    }
}
