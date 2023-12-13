#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void firstset( int i);//function for normal account set
void fd(int j);// function for fixed deposits
void pplus();//function for power plus children account
char accountset1 [6][50]={"***Normal Account***","***Ran Kekulu***","***14+ Teenagers' Savings Account***","***18+ Youth Savings Account***","***Ran Ulpataha***"};
float rateset1 [6]={3.0,4.5,4.0,3.5,6.0};//account set 1 rates
float *rptr=&rateset1[0];// pointers use to print accounts rates
char accountset2 [15][50]={"***1 Month FD***","***3 Months FD***","***6 Months FD***","***1 Year FD***","***2 Year FD***","***3 Year FD***","***4 Year FD***","***5 Year FD***","Senior Citizens(Special) FD","Senior Citizens (General) FD"};
float rateset2 [25]={4.25,4.75,5.0,5.25,5.0,6.0,5.75,5.25,6.25,5.75,5.25,6.5,5.75,5.25,6.75,5.75,5.25,15.0,14.06,6.25,6.0};// FD Rates
float pp1[15]={1200,1400,1500,1700,1900,2200,2500,2800,3300,3800,4600,5500,6900,9000,12400};// power plus monthly amounts
float pp2[15]={11900,13200,14800,16500,18600,21100,24100,27700,32100,37700,45000,54700,68500,89200,123800};//power plus monthly amounts
int age;//used in pplus function
int age2; //used in pplus function
int ans; // used inn main functio
int ans2;// used in main function under the else if(ans==6) command
int ans3; // used in pplus function and fd function(under the senior citizen section)
float amount; // used in all function
char str[2];


int main(){

printf("\n\n\t**** Welcome to BOC Personal Banking Unit Help Center ****\n\n");
printf("(1) Normal Account\n\n");
printf("(2) Ran Kekulu\n\n");
printf("(3) 14+ Account\n\n");
printf("(4) 18+ Acount\n\n");
printf("(5) Ranulpatha\n\n");
printf("(6) Fixed Deposit\n\n");
printf("(7) BOC Power Plus\n\n");
printf("(8) Exit\n\n\n");

printf("Enter Your Selection \t: ");
scanf("%s",str);
ans= atoi(str);
printf("**************************\n\n\n");

if(ans>=1 && ans<=5){
    firstset(ans-1);
}


else if(ans==6){

    printf("\t(1) 1 Month FD \n");
    printf("\t(2) 3 Month FD \n");
    printf("\t(3) 6 Month FD \n");
    printf("\t(4) 1 Year FD \n");
    printf("\t(5) 2 Years FD \n");
    printf("\t(6) 3 Years FD \n");
    printf("\t(7) 4 Years FD \n");
    printf("\t(8) 5 Years FD \n");
    printf("\t(9) Senior Citizens FD\n\n");
    printf("Enter Your Selection :");
    scanf("%s",str);
    ans2= atoi(str);
    printf("**************************\n\n\n");
    if(ans2<10&&ans2>0){
    fd(ans2-1);
    }
    else{main();}
}
else if(ans==7){
    pplus();
}
else if(ans==8){
    exit(0);
}
else {
    printf("\n\t\t***Wrong Input***\n\t**Please Enter Values Between 1 and 8**\n");
    main();
}


return 0;
}

//firstset()={Normal Account,Ran Kekulu,4+ Teenagers' Savings Account,18+ Youth Savings Account,Ran Ulpataha}
void firstset(int i){


int choice;

puts(accountset1[i]);
printf("\n\tAnnual Rate \t: %.2f%% \n",rptr[i]);// pointers
printf("\tEnter Amount \t: ");
scanf("%f",&amount);
float aninterest= (amount*rateset1[i])/100;
printf("\tAnnual Interest : Rs.%.2f\n",aninterest);
printf("\tMonthly Interest: Rs.%.2f\n",aninterest/12);
printf("\tAmount With Annual Interest : Rs.%.2f\n\n",amount+aninterest);
if(i==1){
    printf("\t**The account cannot be closed until the child is 18 years old**\n\n\n");
}
else if(i==4){
    printf("\t**Only One Withdrawal for a Month**\n\n\n");
}



printf("1 Back to Main Menu\n");
printf("2 Enter New Amount \n");
printf("3 Exit\n\n");
printf("Enter Your Selection\t:");
scanf("%d",&choice);
printf("**************************\n\n\n");

switch(choice){
case 1:
    main();
    break;
case 2:
    firstset(i);
    break;
case 3:
    exit(0);
    break;
default:
    main();
}


}

void fd(int j){
int choice;

if(j<3){
    puts(accountset2[j]);
    printf("\n\tAnnual Rate \t: %.2f%% \n",rateset2[j]);
    printf("\tEnter Amount \t: ");
    scanf("%f",&amount);
    float aninterest= (amount*rateset2[j])/100;
    printf("\tAnnual Interest : Rs.%.2f\n",aninterest);

    printf("\tAmount With Annual Interest : Rs.%.2f\n\n",amount+aninterest);

        printf("\t**Interest Pay After Maturity Period Only**\n\n\n");

    printf("1 Back to Main Menu\n");
    printf("2 Enter New Amount \n");
    printf("3 Exit\n\n");
    printf("Enter Your Selection\t:");
    scanf("%d",&choice);
    printf("**************************\n\n\n");
    switch(choice){
    case 1:
        main();
        break;
    case 2:
       fd(j);
        break;
    case 3:
        exit(0);


    }

}
//for i year fd
else if(j==3){

    puts(accountset2[j]);
    printf("\n\tEnter Amount \t: ");
    scanf("%f",&amount);
    for(int l=j;l<=j+1;l++){
        if(l==j){printf("\n\tAt Maturity\n ");}//to add Interest Payment Method.
        else{printf("\n\tAt Monthly\n ");}//to add Interest Payment Method.

        printf("\tAnnual Interest Rate \t: %.2f%% \n",rateset2[l]);

        float aninterest= (amount*rateset2[l])/100;

        printf("\tAnnual Interest \t: Rs.%.2f\n",aninterest);
        if(l>j){printf("\tMonthly Interest \t: Rs.%.2f\n",aninterest/12);}//to add monthly Interest it add only for Monthly Payment Method.
        printf("\tAmount With Annual Interest : Rs.%.2f\n\n\t\t***\n\n\n",amount+aninterest);
    }


    printf("1 Back to Main Menu\n");
    printf("2 Enter New Amount \n");
    printf("3 Exit\n\n");
    printf("Enter Your Selection\t:");
    scanf("%d",&choice);
    printf("**************************\n\n\n");
    switch(choice){
    case 1:
        main();
        break;
    case 2:
       fd(3);
        break;
    case 3:
        exit(0);
    }
}
//for 2 Years FD
else if(j==4){

    puts(accountset2[j]);
    printf("\n\tEnter Amount \t: Rs. ");
    scanf("%f",&amount);
    for(int l=j+1;l<=j+3;l++){
        if(l==j+1){printf("\n\tAt Maturity\n ");}//to add Interest Payment Method.
        else if(l==j+2){printf("\n\tAt Annually\n ");}//to add Interest Payment Method.
        else if(l==j+3){printf("\n\tAt Monthly\n ");}//to add Interest Payment Method.

        printf("\tAnnual Interest Rate \t: %.2f%% \n",rateset2[l]);

        float aninterest= (amount*rateset2[l])/100;

        printf("\tAnnual Interest \t: Rs.%.2f\n",aninterest);
        if(l==j+3){printf("\tMonthly Interest \t: Rs.%.2f\n",aninterest/12);}//to add monthly Interest it add only for Monthly Payment Method.
        printf("\tTotal Interest \t\t: Rs.%.2f\n",aninterest*2);
        printf("\tTotal Amount With Interest : Rs.%.2f\n\n\t\t***\n\n\n",amount+aninterest*2);
    }


    printf("1 Back to Main Menu\n");
    printf("2 Enter New Amount \n");
    printf("3 Exit\n\n");
    printf("Enter Your Selection\t:");
    scanf("%d",&choice);
    printf("**************************\n\n\n");
    switch(choice){
    case 1:
        main();
        break;
    case 2:
       fd(4);
        break;
    case 3:
        exit(0);
    }
}

//for 3 Years FD
else if(j==5){

    puts(accountset2[j]);
    printf("\n\tEnter Amount \t: Rs. ");
    scanf("%f",&amount);
    for(int l=j+3;l<=j+5;l++){
        if(l==j+3){printf("\n\tAt Maturity\n ");}//to add Interest Payment Method.
        else if(l==j+4){printf("\n\tAt Annually\n ");}//to add Interest Payment Method.
        else if(l==j+5){printf("\n\tAt Monthly\n ");}//to add Interest Payment Method.

        printf("\tAnnual Interest Rate \t: %.2f%% \n",rateset2[l]);

        float aninterest= (amount*rateset2[l])/100;

        printf("\tAnnual Interest \t: Rs.%.2f\n",aninterest);
        if(l==j+5){printf("\tMonthly Interest \t: Rs.%.2f\n",aninterest/12);}//to add monthly Interest it add only for Monthly Payment Method.
        printf("\tTotal Interest \t\t: Rs.%.2f\n",aninterest*3);
        printf("\tTotal Amount With Interest : Rs.%.2f\n\n\t\t***\n\n",amount+aninterest*3);
    }


        printf("1 Back to Main Menu\n");
        printf("2 Enter New Amount \n");
        printf("3 Exit\n\n");
        printf("Enter Your Selection\t:");
        scanf("%d",&choice);
        printf("**************************\n\n\n");

    switch(choice){
    case 1:
        main();
        break;
    case 2:
       fd(5);
        break;
    case 3:
        exit(0);
    }
}
//for 4 Years FD
else if(j==6){

    puts(accountset2[j]);
    printf("\n\tEnter Amount \t: Rs. ");
    scanf("%f",&amount);
    for(int l=j+5;l<=j+7;l++){
        if(l==j+5){printf("\n\tAt Maturity\n ");}//to add Interest Payment Method.
        else if(l==j+6){printf("\n\tAt Annually\n ");}//to add Interest Payment Method.
        else if(l==j+7){printf("\n\tAt Monthly\n ");}//to add Interest Payment Method.

        printf("\tAnnual Interest Rate \t: %.2f%% \n",rateset2[l]);

        float aninterest= (amount*rateset2[l])/100;

        printf("\tAnnual Interest \t: Rs.%.2f\n",aninterest);
        if(l==j+5){printf("\tMonthly Interest \t: Rs.%.2f\n",aninterest/12);}//to add monthly Interest it add only for Monthly Payment Method.
        printf("\tTotal Interest \t\t: Rs.%.2f\n",aninterest*4);
        printf("\tTotal Amount With Interest : Rs.%.2f\n\n\t\t***\n\n",amount+aninterest*4);
    }


        printf("1 Back to Main Menu\n");
        printf("2 Enter New Amount \n");
        printf("3 Exit\n\n");
        printf("Enter Your Selection\t:");
        scanf("%d",&choice);
        printf("**************************\n\n\n");

    switch(choice){
    case 1:
        main();
        break;
    case 2:
       fd(6);
        break;
    case 3:
        exit(0);
    }
}
//for 5 Years FD
else if(j==7){

    puts(accountset2[j]);
    printf("\n\tEnter Amount \t: Rs. ");
    scanf("%f",&amount);
    for(int l=j+7;l<=j+9;l++){
        if(l==j+7){printf("\n\tAt Maturity\n ");}//to add Interest Payment Method.
        else if(l==j+8){printf("\n\tAt Annually\n ");}//to add Interest Payment Method.
        else if(l==j+9){printf("\n\tAt Monthly\n ");}//to add Interest Payment Method.

        printf("\tAnnual Interest Rate \t: %.2f%% \n",rateset2[l]);

        float aninterest= (amount*rateset2[l])/100;

        printf("\tAnnual Interest \t: Rs.%.2f\n",aninterest);
        if(l==j+5){printf("\tMonthly Interest \t: Rs.%.2f\n",aninterest/12);}//to add monthly Interest it add only for Monthly Payment Method.
        printf("\tTotal Interest \t\t: Rs.%.2f\n",aninterest*5);
        printf("\tTotal Amount With Interest : Rs.%.2f\n\n\t\t***\n\n",amount+aninterest*5);
    }


        printf("1 Back to Main Menu\n");
        printf("2 Enter New Amount \n");
        printf("3 Exit\n\n");
        printf("Enter Your Selection\t:");
        scanf("%d",&choice);
        printf("**************************\n\n\n");

    switch(choice){
    case 1:
        main();
        break;
    case 2:
       fd(7);
        break;
    case 3:
        exit(0);
    }
}
//senior Sitizen fd
else if(j==8){
    int ans3;
    printf("\t(1) Special Rate\n\t(2) Normal Rate\n\n Enter Your Selection\t:");
    scanf("%d",&ans3);
    printf("**************************\n");

    if (ans3==1){
        printf("\n\n");
        puts(accountset2[j]);
        printf("\n\tEnter Amount \t: Rs. ");
        scanf("%f",&amount);

        for(int l=j+9;l<=j+10;l++){
        if(l==j+9){printf("\n\tAt Maturity\n ");}//to add Interest Payment Method.
        else{printf("\n\tAt Monthly\n ");}//to add Interest Payment Method.

        printf("\tAnnual Interest Rate \t: %.2f%% \n",rateset2[l]);

        float aninterest= (amount*rateset2[l])/100;

        printf("\tAnnual Interest \t: Rs.%.2f\n",aninterest);
        if(l>j+9){printf("\tMonthly Interest \t: Rs.%.2f\n",aninterest/12);}//to add monthly Interest it add only for Monthly Payment Method.
        printf("\tAmount With Interest : Rs.%.2f\n\n\t\t***\n\n",amount+aninterest);
    }
    }

    if (ans3==2){
        puts(accountset2[j+1]);
        printf("\n\tEnter Amount \t: Rs. ");
        scanf("%f",&amount);

        for(int l=j+11;l<=j+12;l++){
        if(l==j+11){printf("\n\tAt Maturity\n ");}//to add Interest Payment Method.
        else{printf("\n\tAt Monthly\n ");}//to add Interest Payment Method.

        printf("\tAnnual Interest Rate \t: %.2f%% \n",rateset2[l]);

        float aninterest= (amount*rateset2[l])/100;

        printf("\tAnnual Interest \t: Rs.%.2f\n",aninterest);
        if(l>j+11){printf("\tMonthly Interest \t: Rs.%.2f\n",aninterest/12);}//to add monthly Interest it add only for Monthly Payment Method.
        printf("\tAmount With Interest : Rs.%.2f\n\n\t\t***\n\n",amount+aninterest);
    }
    }

        printf("1 Back to Main Menu\n");
        printf("2 Enter New Amount \n");
        printf("3 Exit\n\n");
        printf("Enter Your Selection\t:");
        scanf("%d",&choice);
        printf("**************************\n\n\n");

    switch(choice){
    case 1:
        main();
        break;
    case 2:
       fd(8);
        break;
    case 3:
        exit(0);
    }

}

}

void pplus(){

int choice;
    printf("***BOC Power Plus***\n\n");
    struct pp{
    char plan[35];             // structures use to print account rates
    };
    struct pp s1,s2,s3,s4;
    strcpy(s1.plan,"(1) 500,000 Plan  ");
    strcpy(s2.plan,"(2) 1 Million Plan");
    strcpy(s3.plan,"(3) 2 Million Plan");
    strcpy(s4.plan,"(4) 5 Million Plan");

printf("\t%s\n\t%s\n\t%s\n\t%s\n\n",s1.plan,s2.plan,s3.plan,s4.plan);
printf("Enter Your Selection :");
scanf("%d",&ans3);
printf("**************************\n\n\n");

if(ans3<5&&ans3>0){
    if(ans3==1){

        printf("%s\n\n",s1.plan);
        printf("\tEnter The Age\t: ");
        scanf("%d",&age);
    if(age<16){
        age2=18-age;
        printf("\tMonthly Deposit Amount\t: Rs.%.2f\n",pp1[age-1]);
        printf("\tInvestment Period\t: %d Years\n",age2);
        printf("\tTotal Deposit Amount\t: Rs.%.2f\n",age2*12*pp1[age-1]);
        printf("\tTotal Interest\t\t: Rs.%.2f\n\n\n",500000-(age2*12*pp1[age-1]));
    }
    else{printf("\n\n\t\t***Age must be less than 15***\n\n");};
}

else if(ans3==2){
        printf("%s\n\n",s2.plan);
        printf("\tEnter The Age\t: ");
        scanf("%d",&age);
    if(age<16){
        age2=18-age;
        printf("\tMonthly Deposit Amount\t: Rs.%.2f\n",pp1[age-1]*2);
        printf("\tInvestment Period\t: %d Years\n",age2);
        printf("\tTotal Deposit Amount\t: Rs.%.2f\n",age2*12*pp1[age-1]*2);
        printf("\tTotal Interest\t\t: Rs.%.2f\n\n\n",1000000-(age2*12*pp1[age-1]*2));
    }
    else{printf("\n\n\t\t***Age must be less than 15***\n\n");}
}
else if(ans3==3){
        printf("%s\n\n",s3.plan);
        printf("\tEnter The Age\t: ");
        scanf("%d",&age);
     if(age<16){
        age2=18-age;
        printf("\tMonthly Deposit Amount\t: Rs.%.2f\n",pp1[age-1]*4);
        printf("\tInvestment Period\t: %d Years\n",age2);
        printf("\tTotal Deposit Amount\t: Rs.%.2f\n",age2*12*pp1[age-1]*4);
        printf("\tTotal Interest\t\t: Rs.%.2f\n\n\n",2000000-(age2*12*pp1[age-1]*4));
     }
    else{printf("\n\n\t\t***Age must be less than 15***\n\n");}
}


else if(ans3==4){

        printf("%s\n\n",s4.plan);
        printf("\tEnter The Age\t: ");
        scanf("%d",&age);
        age2=18-age;
     if(age<16){
        printf("\tMonthly Deposit Amount\t: Rs.%.2f\n",pp2[age-1]);
        printf("\tInvestment Period\t: %d Years\n",age2);
        printf("\tTotal Deposit Amount\t: Rs.%.2f\n",age2*12*pp2[age-1]);
        printf("\tTotal Interest\t\t: Rs.%.2f\n\n\n",5000000-(age2*12*pp2[age-1]));
     }
      else{printf("\n\n\t\t***Age must be less than 15***\n\n");}
}
}
else{main();}



        printf("1 Back to Main Menu\n");
        printf("2 Enter New Amount \n");
        printf("3 Exit\n\n");
        printf("Enter Your Selection\t:");
        scanf("%d",&choice);
        printf("**************************\n\n\n");

    switch(choice){
    case 1:
        main();
        break;
    case 2:
       pplus();
        break;
    case 3:
        exit(0);
    }

}



