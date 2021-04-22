#define N 10
#define true 1
#define false 0
#define SIZES sizeof(a1)/sizeof(a1[0])
int repeat(){
    //printf("N2= %d\n",N);
    int a=0;
    printf("enter a number: ");
    scanf("%d",&a);
    int bchu=a;
    int arr[N]={0};
    int index=0;
    int i;
    int flag=false;
    while(bchu>0){
        int shang=bchu/10;
        int yu=bchu%10;
        bchu=shang;
        arr[yu]++;
    }
    for(i=0;i<N;i++){
        if(arr[i]>1){
            flag=true;
            //printf(" repeat number is %d",i);
        }
        printf("%d \n",arr[i]);
    }
    if(!flag){
        printf(" no repeat number");
    }
}


int f_arr(){
    int a1[]={1,2,3,4,5,6,7,8,9,10};
    printf("%d ",SIZES);

}
# define YEAR 5
int cent_money(){
    double rate=0.06;
    double money=100;
    int i;
    for(i=0;i<YEAR;i++){
        money=money*(1+rate);
    }
    printf("%f\n",money);


}


