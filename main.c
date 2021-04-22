#include <stdio.h>
#include <stdlib.h>
#define true  1
#define false 0
typedef int bool;

int main8_1_3()
{
  int i=0;
  bool a[7]={true,0,0,0,0,0,true};
  int len=sizeof(a)/sizeof(a[0]);
  for(i=0;i<len;i++){
    printf("%d ",a[i]);
  }
}

int main8_1_4()
{
    int a=0;
    int b=1;
    int tmp=0;
    int n=0;
    while(n<=40){
        if(n==0){
            printf("%d ",a);
        }
        printf("%d ",b);
        tmp=a+b;
        a=b;
        b=tmp;
        n++;
    }
}

typedef int eleType;
struct node{
    eleType element;
    struct node *next;
};
typedef struct node *pNode;



void print_struct(struct node *pnode){
    printf("%d \n",pnode->element);
}

void test(){
    printf("test");
}

void add(){
    printf("add");
}

int main5()
{
  //int a,b,c=3;
  //int *a,d,c=10;
  //printf("%p %d %d ",a,d,c);

  pNode p_node=malloc(sizeof(struct node));
  pNode p_node2=malloc(sizeof(struct node));
  if(p_node==NULL){
    printf("error");
    exit(0);
  }
  if(p_node2==NULL){
    printf("error");
    exit(0);
  }
  p_node2->element=20;
  p_node2->next=NULL;
  p_node->element=10;
  p_node->next=p_node;
  print_struct(p_node);
  print_struct(p_node2);
  getchar();
}

int main6()
{
  void (*fun)()= test;
  fun=add;
  fun();
}


int main9()
{
   int *ptr1=NULL;
   int *ptr2=NULL;

   ptr1=(int *)malloc(sizeof(int));
   ptr2= malloc(sizeof(int));

   printf("%p ",ptr1);
   printf("%p ",ptr2);
}

int main21(){
    int *p1=NULL;
    int *p2=NULL;
    p1=(int *)malloc(sizeof(int));
    p2=(int *)malloc(sizeof(int));
    printf("%p \n",p1);
    printf("%p \n",p2);
}

int main8()
{
  int a[]={1,2,3,4,5};
  int i=0;
  int len=sizeof(a)/sizeof(a[0]);
  for(i=0;i<len;i++){
    printf("%p ",&a[i]);
  }
}
# define N 10
int main22(){
    int a[N];
    int i;
    init_arr(a,N);
    print_arr(a,N);
    clear_arr(a,N);
    print_arr(a,N);
    init_arr(a,N);
    print_arr(a,N);
}

void init_arr(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        a[i]=i+1;
    }
}

void clear_arr(int *a,int n){
    int *tmp=a;
    for(;a<tmp+n;a++){
        *a=0;
    }
    printf("\n");
}

void print_arr(int *a,int n){
    int i;
    for(i=0;i<N;i++){
       printf("a[%d]=%d \n",i,a[i]);
    }
    printf("\n");
}

void scanf_arr(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void print_reverse_arr(int *a,int n){
    int i;
    for(i=n-1;i>=0;i--){
        printf("a[%d]=%d \n",i,a[i]);
    }
}

int main31(){
    int a[N];
    scanf_arr(a,N);
    print_arr(a,N);
    print_reverse_arr(a,N);
}

int main32(){
    //printf("N1= %d\n",N);
    repeat();
}

int main33(){
    cent_money();
}

struct Student{
 char name[100];
 int age;
 int stu_no;
};

struct Teacher{
 char name[100];
 int  age;
 int  tea_no;
};

struct People{
    char name[100];
    int age;
    int sex;//male 0 female 1
};


void printfTeacher(struct Teacher * teacherPtr){
    printf("%s\n",teacherPtr->name);
    printf("%d\n",teacherPtr->age);
    printf("%d\n",teacherPtr->tea_no);
}

struct Teacher *constructTeacher(char *name,int age,int no){
  struct Teacher *teacher= malloc(sizeof(struct Teacher));
  strcpy(teacher->name,name);
  teacher->age=age;
  teacher->tea_no=no;
  return teacher;
};

struct Student *constructStudent(char*name,int age, int no){

};
int *get_point();

int *get_p1();

int *get_p2();

int *get_p1(){
    int i=10;
    int *p1=&i;
    return p1;
}

int *get_p2(){
    int arr[10]={0};
    return arr;
}

int get_i1(){
    int a=10;
    return a;
}

char *get_p3(){
    char *s3="hello";
    return s3;
}

char *get_p4(){
    char s4[10]="hello";
    return s4;
}

void get_arrs(int a1[]){
    /*
        数组向指针的退化
        数组作为形式参数在function中传递时，会退化为指针。
        故这里如果想传递一个数组时，需要额外多传递一个参数记录数组的长度，
        数组退化为指针设计的原因，可以理解为约定，可能是这样简化了编译器的设计，
        函数的形式参数中不会放入太多的东西。
    */
    printf("%d\n",sizeof(a1));
}


void get_arrs_2(int a1[][10]){
    printf("%d\n",sizeof(a1));
    printf("%d\n",sizeof(a1[0]));
}


int main(){
    //写成数组形式的数组,必须显示指定结束符\0
    char arrs[]={'h','e','l','l','o','\0'};
    char *str="hello";
    char arrs2[][10]={"hello","world"};
    /*
        数组和指针的比较
        数组的sizeof可以求出其大小(包括结束符\0),指针sizeof只能求出指针大小(4个bytes),
        数组名书中定义可以理解为常量指针(不可以改变的指针),但是其本质也是计算机内存中的一个地址指向了
        一段连续的内存区域,但是数组比较特殊，其中还包含数据的长度范围，这些信息都记录在数组名中,
        所以数组名通过sizeof可以求出数组的大小。数组像一个皇家的仪仗队，纪律森严，长度限制明确固定，
        但是指针就像随时加入的起义民兵，给出一个地址，从这个地址开始，到哪里不确定。所以数组包含了比指针
        更多，更丰富的信息。但是本质上二者都是一个地址而已。
    */
    /*
    printf("%d\n",sizeof(arrs));
    printf("%d\n",sizeof(str));
    printf("%s\n",arrs);
    */
    //get_arrs(arrs);
    get_arrs_2(arrs2);
    return 0;
}


int main2(){
    char *s1="hello";
    char *s2="hello";
    char *s3=get_p3();
    char *s4=get_p4();
    printf("%p \n",s1);
    printf("%p \n",s2);
    printf("%p \n",s3);
    printf("%p \n",s4);
    return 0;
}
    /*
    int *p1=get_p1();
    int *p2=get_p2();

    //printf("%d\n", *p1);
    printf("%d\n",*p2);
    */
    /*
    int n=8;
    int *p=NULL; //NULL指针
    int *p1;     //野指针
    int *p2=&n;  //常量地址指针赋值
    //int *p3=malloc(sizeof(int));
    printf("%p\n",p);
    printf("%p\n",p1);
    printf("%p\n",*p2);
    //printf("%p\n",*p3);
    return 0;
    */
    //int *p1=get_point();
    //printf("%p %d\n",p1,*p1);
    //printf("%p\n",p1);

    /*
    int a = 10; //告诉编译器，分配4个字节的内存
    int b[10];  //告诉编译器，分配4*10 = 40 个字节的内存

    printf("%p \n",sizeof(b));
    printf("%p \n",sizeof(&b));
    */
    //printf("b:%p, b+1: %p, &b:%p, &b+1: %p\n", b, b + 1, &b, &b + 1);
    //b+1 和 &b+1的结果不一样 （+1 ---> +4; +1 ---> +40）
    //是因为 b 和 &b 所代表的数据类型不一样
    //b  代表数组首元素的地址
    //&b 代表整体数组的地址



int *get_point(){
    /*
    int a1=10;
    int *p1=&a1;
    return p1;
    */
    /*
    int a1[10];
    a1[0]=0;
    return a1;
    */
    int* a_ptr=malloc(sizeof(int));
    //int a1[10];
    int a1=10;
    printf("%p %p\n",a_ptr,&a1);
    int *temp=&a1;
    return temp;
}




int main20210326(){
    /*
    char name[100]="张飞";
    int age=40;
    int no=1;
    struct Teacher *teacherPtr= constructTeacher(name,age,no);
    printfTeacher(teacherPtr);
    char str_arrs[40]="hello c1";
    char *str="hello c2";
    printf("%s\n",str_arrs);
    printf("%s\n",str);
    printf("=================\n");
    printf("str_arrs size is %d\n",sizeof(str_arrs));
    printf("str size is %d\n",sizeof(str));
    */
    /*
    char name[400]="hello name";
    char *str=name;
    printf("%s \n",name);
    printf("%s \n",str);
    */
    /*
    char arrs[40][3]={"hello c!","hello java!"};
    int arrs_len=sizeof(arrs);
    printf("%d\n",arrs_len);
    for(int i=0;i<3;i++){
        printf("%s \n",arrs[i]);
    }
    */
    /*
    int a1[10]={1,2,3,4};
    int a[2][40]={{1,2,3},{11,22,33}};
    int a3[2][3][4]={{{1,2,3,4},{11,22,33,44},{111,222,333,444}},{{5,6,7,8},{55,66,77,88},{555,666,777,888}}};
    printf("size=%d",sizeof(a3));  //4*80=320
    */
    /*
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    */
    char arr[10];
    arr[0]='1';
    arr[1]='9';
    arr[2]='9';
    arr[3]='0';
    arr[4]='\0';
    printf("%s\n",arr);
}


int main202010231003(){
    /*
    struct A a={"paul",20};
    printf("%s %d",a.name,a.age);
    */
    int i1=0;
    char *str3=NULL;
    char *str2;
    char *str="hello \n";
    char strarr[100]="welcome to china ";
    str2=str;
    //*str="hi";
    printf("%p \n",i1);
    printf("%p \n",str3);
    printf("%p \n",str2);
    printf("%p \n",str);

    printf("%s \n",strarr);

}



