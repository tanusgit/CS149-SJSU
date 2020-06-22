#include <stdio.h>
#include <string.h>
//we cannot define function in struct
//we cannot explicitly initialize a memebr variable inside the struct
//we dont have public or private key work in struct
// strcpy(car_1.name, "ford_ecosport"); to initialize the string variable
int sum_a;
int market_value = 5000;
struct cars
    {
        char name[25];
        int hp;
        int capacity;
        int price;
    };
void average(int n_a, int n_b, int n_c)
{
    sum_a = n_a + n_b + n_c;
    sum_a = sum_a / 3;
    printf("%d\n", sum_a);
}

 void marketV(struct cars a)
    {
        if (a.price > 5000)
        {
            printf("the price is higher than market value");
        }
    }
int main()
{
    struct cars car_1, car_2, car_3;
    car_1.capacity = 6;
    car_1.price = 10000;
    car_1.hp = 4000;
    car_2.price = 5000;
    car_3.price = 1000;
    //error in the following line
    //car_1.name="ford ecosport";
    strcpy(car_1.name, "ford_ecosport");
    printf("%d\n", car_1.capacity);
    printf("%d\n", car_1.price);
    printf("%d\n", car_1.hp);
    printf("%s\n", car_1.name);
    int x, y, z;
    x = car_1.price;
    y = car_2.price;
    z = car_3.price;
    average(x, y, z);
}

/*
#include<stdio.h>
#include<string.h>
int sum_a;
void average(int n_a,int n_b,int n_c)
{
sum_a=n_a+n_b+n_c;
sum_a=sum_a/3;
printf("%d\n",sum_a);

}
//void marketV(cars car_1)
int marketvalue=5000;

int main()
{
struct cars
{
char name[25];
int hp;
int capacity;
int price;

};
struct cars car_1,car_2,car_3;
car_1.capacity=6;
car_1.price=10000;
car_1.hp=4000;
car_2.price=5000;
car_3.price=1000;
//error in the following line
//car_1.name="ford ecosport";
strcpy(car_1.name,"ford_ecosport");
printf("%d\n",car_1.capacity);
printf("%d\n",car_1.price);
printf("%d\n",car_1.hp);
printf("%s\n",car_1.name);
void marketV(struct cars trial_car)
{
int z=trial_car.price;
if(z>5000)
{
printf("market value is greater");
}

}
int x,y,z;
x=car_1.price;
y=car_2.price;
z=car_3.price;
average(x,y,z);
marketV(car_1);



}





pointers:
#include<stdio.h>
int main()
{
int a;
a=5;
int b=7;
int *ptr=&a;
//int ptr=&a;
int c=8;
char d='a';
char e='f';
//printf("%p\n",&a);
//printf("%p\n",ptr);
int arr[5]={1,2,3,4,5};
printf("%p\n",&arr[0]);
printf("%p\n",&arr[1]);
printf("%p\n",&arr[2]);
printf("%p\n",&arr[3]);
printf("%p\n",&arr[4]);
//printf("%p\n",&b);
//printf("%p\n",&c);
//printf("%p\n",&d);
//printf("%p\n",&e);




} 
*/
