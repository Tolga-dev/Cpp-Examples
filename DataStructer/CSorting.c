#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>

#define MERGE_SIZE
#define INTERVAL (0.1 * CLOCKS_PER_SEC)

static void insertion(unsigned long arr[], long n);
static void selectionSort(unsigned long arr[], long n);
static void MeinSelection(unsigned long arr[]);
static void BubbleSort(unsigned long arr[], long size);
void Merge(long arr[],  long n,   long l,   long r);
void MergeSort( long arr[] , long n,long left, long k, long right); // bi sikinti var
static void QuickSort(unsigned long arr[], int l, int r);
static void Heapify(unsigned long arr[], int S , int P);
static void Heap(unsigned long arr[], int S);

static double get_wall_time();
static float real_time_diff(struct timeval *start, struct timeval *end);


int main()
{

    // vars
        struct Sorts *s;
        struct timeval start, end;
        int choice = 0;
        double wall;
        long size;
//    // inputs

        printf("Please Enter Your Sorting Size: ");
        scanf("%lu",&size);


        printf("0: Heap \n1: Merge \n2: Quick \n3: Bubble \n4: Selection \n5: Insertion\n");
        printf("Please Enter Your Sorting Choice: ");
        scanf("%d",&choice);

        long arr[size], r = 0;

        //rand generate
            srand(time(NULL));
            for(int i = 0; i < size; i++)
            {
                r = rand() % 1000000 + 1;
                arr[i] = r;
            }
        // display
            for(int i = 0 ; i < size ; i ++)
                printf("%d ",arr[i]);
            printf("\n");


            // start time!
            clock_t t;
            gettimeofday(&start, NULL); // SYSTEM CLOCK
            wall = get_wall_time();
            t = clock();

            switch (choice) {

                case 0:
                    printf("heap \n");
                    Heap(arr, size);
                    break;
                case 1:
                          Merge(arr, size, 0, size - 1);
                          break;

                case 2:
                    printf("heap \n");
                    QuickSort(arr, 0, size - 1);
                    break;

                case 3:
                    printf("buble \n");
                    BubbleSort(arr, size);
                    break;
                case 4:
                    printf("selection \n");
                    selectionSort(arr, size);
                    break;
                case 5:
                    printf("insertion \n");
                    insertion(arr, size);
                    break;
                default:
                    printf("Please, Enter Possible input!");
            }
            t = clock() - t;
            gettimeofday(&end, NULL);
            wall = get_wall_time() - wall;

            double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

            printf(" \n ");

            for(int i = 0 ; i < size ; i ++)
            {
                printf("%d ",arr[i]);
                if(i == 30)
                    printf("\n");
            }

            printf("\n");

            printf("CPU TIME %.10f (sec) \n", time_taken);
            printf("RUNNING TIME : %0.8f (sec)\n", real_time_diff(&start, &end));
            printf("WALL TIME : %0.8f (sec)\n", wall);


    return 0;

}



void insertion(unsigned long arr[], long n)
{
    int key, step;
    for(int i = 1; i < n; i++)
    {
        printf(" . ");
        key = arr[i];
        step = i-1;

        while(step >= 0 && arr[step] > key)
        {

            arr[step+1] = arr[step];
            step--;
        }

        arr[step+1] = key;

    }

}

void selectionSort(unsigned long arr[], long n)
{
    int i, index, j, min;
    for (i = 0; i < (n-1); i++) {
        min = arr[n-1];
        index = n-1;
        for (j = i; j < (n-1); j++){
            if (arr[j] < min){
                min = arr[j];
                index = j;
            }
        }
        if (i != index){
            arr[index] = arr[i];
            arr[i] = min;
        }
    }

}

void MeinSelection(unsigned long arr[])
{
    /*
    int key,n;
    for(int i = 0; i < arr.size(); i++)
    {
        key = arr[i];
        n = i;
        for(int j = i; j < arr.size(); j++)
        {
            if(arr[j] < key)
            {
                key = arr[j];
                n = j;
            }

        }
        if(i != n)
        {

            arr[n] = arr[i];
            arr[i] = key;
        }

    }
     */
}

static void BubbleSort(unsigned long arr[], long size)
{
    int i = 0;

    for(;i < size; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {

                arr[j] = arr[j] ^  arr[j+1];
                arr[j+1] = arr[j] ^ arr[j+1];
                arr[j] = arr[j] ^  arr[j+1];

            }
        }

    }
}

void MergeSort(long arr[] , long n,long left, long k, long right) // bi sikinti var
{
     long i,j,m;
     m = 0;
     long temp[n];

    for(i = left, j = k+1; (i <= k) && (j <= right); )
    {

        if(arr[i] < arr[j])
        {
            temp[m]= arr[i];
            i++;
            m++;
        }

        else
        {
            temp[m]= arr[j];
            j++;
            m++;
        }

    }

    while(i <= k)
    {
        temp[m] = arr[i];
        i++;
        m++;
    }

    while (j <= right){
        temp[m] = arr[j];
        j++;
        m++;
    }
    for(i = left, m = 0; i <= right; i++, m++)
    {
        arr[i] = temp[m];
    }


}
void Merge(long arr[],  long n,   long l,   long r)
{
    if(l < r)
    {
          long mid;
          mid = ( r + l ) / 2;
        Merge(arr,n, l, mid);
        Merge(arr,n, mid + 1, r);
        MergeSort(arr,n, l, mid, r);

    }
}

void QuickSort(unsigned long arr[], int l, int r)
{
    int i = l , j = r;
    int p = arr[(i + j) / 2];

    while( i <= j)
    {
        while(arr[j] > p && j > l)
        {
            j--;
        }

        while(arr[i] < p && i < r)
        {
            i++;
        }

        if(i <= j)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
            i++;
        }

    }
    if(l < j)
        QuickSort(arr,l,j);
    if(i < r)
        QuickSort(arr,i,r);

}

void Heapify(unsigned long arr[], int S , int P)
{
    int b = P;
    int l = 2 * P + 1;
    int r = 2 * P + 2;

    if( l < S && arr[l] > arr[b])
        b = l;
    if( r < S && arr[r] > arr[b])
        b = r;

    if(b != P)
    {
        int temp = arr[P];
        arr[P] = arr[b];
        arr[b] = temp;

        Heapify(arr, S, b);
    }
}
void Heap(unsigned long arr[], int S)
{
    for(int i = 2 * S - 1 ; i >= 0; i--)
        Heapify(arr,S,i);

    for(int i = S - 1 ; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr, i, 0);

    }

}

double get_wall_time(){
    struct timeval time;
    if (gettimeofday(&time,NULL)){
        //  Handle error
        return 0;
    }
    return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
float real_time_diff(struct timeval *start, struct timeval *end)
{
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}
void PrintLine()
{
    int i = 0;
    clock_t target;
    char spin[] = "\\|/-";                  // '\' needs escape seq
    printf(" ");
    while(1) {
        printf("\b%c", spin[i]);
        fflush(stdout);
        i = (i + 1) % 4;
        target = clock() + (clock_t)INTERVAL;
        while (clock() < target);
    }
}