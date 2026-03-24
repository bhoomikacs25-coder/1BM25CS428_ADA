#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[high-low+1];
    while(i<=mid&&j<=high){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            i++;k++;
        }else{
            temp[k]=arr[j];
            j++;k++;
        }
    }
    while(i<=mid){
        temp[k++]=arr[i];
        i++;
    }
    while(j<=high){
        temp[k++]=arr[j];
        j++;
    }
    for(int i=low,k=0;i<high;i++,k++){
        arr[i]=temp[k];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}



int main(){
    //int n=10000;

    /*printf("enter the number of elementrs to be inserted into the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }


    printf("elements before sorted:\n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
    mergeSort(arr,0,n-1);
    printf("elements after sorted:\n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }*/
    int n;

    for(n=1000; n<=10000; n+=1000){

        int arr[n];

        srand(time(NULL));

        for(int i=0;i<n;i++){
            arr[i] = rand()%10000;
        }

        clock_t start,end;

        start = clock();

        mergeSort(arr,0,n-1);

        end = clock();

        double time_taken = (double)(end-start)/CLOCKS_PER_SEC;

        printf("%d %f\n", n, time_taken);
    }
    return 0;



}
