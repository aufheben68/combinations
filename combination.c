#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int check();
int giveN();
int * giveNumbers(int N);
int * giveX();
int * giveY();
long int plithos(int N);
long int fact(int n);
void combinations(int *numbers, int N, int n, int k);
void print(int *ar, int len, int *elements);
int epomenos_sunduasmos(int *ar, int n, int k);
void selectionSort(int * arr, int n);
void swap(int* xp, int* yp);

int main(int argc, char **argv){
	int* numbers;
	int* xarr;
	int* yarr;
	int i,j,N;
	long int n;
	
	N = giveN();
	numbers = giveNumbers(N);
	xarr = giveX();
	yarr = giveY();
	printf("Starting table of combinations : ");
	for(i=0; i<N; i++){
		printf(" %d ", *(numbers+i));
	}
	printf("\nLimits X1 X2: [ %d ... %d ]\n", *xarr,*(xarr+1));
	printf("Limits Y1 Y2: [ %d ... %d ]\n", *yarr,*(yarr+1));
	n = plithos(N);
	
	int * arr = malloc(sizeof(int)*6);
	for(i=0; i<6; i++){
		*(arr + i )= i;
	}
	int item = 1;
	int counter_notfirst = 0;
	int counter_first_but_not_second = 0;
	int x1 = *xarr;
    int x2 = *(xarr+1);
    int y1 = *yarr;
    int y2 = *(yarr+1);
    int *arrfreq;
    arrfreq = malloc(sizeof(int)*N);
    for(i=0; i<N; i++){
    	*(arrfreq + i) = 0;
	}
    printf("Combinations that comply with both terms:\n\n");
	do {
		int counter_plithos = 0;
    	int sum_psifiwn = 0;
		for (i = 0; i < 6; i++) {
        if(*(numbers+*(arr + i))%2 == 0){
        	counter_plithos ++;
		}
		sum_psifiwn = sum_psifiwn + *(numbers+*(arr + i));
    	}
    	
    	if(counter_plithos>=x1 && counter_plithos<=x2 && sum_psifiwn>=y1 && sum_psifiwn<=y2){
    		printf("Sum of even numbers: %d Sum of all numbers: %d\n", counter_plithos, sum_psifiwn);
	    	printf(" %d: ", item);
	    	selectionSort(numbers,N);
	        print(arr,6, numbers);
	        for(i=0; i<6; i++){
	        	for(j=0; j<N; j++){
		        	if(*(numbers+*(arr+i)) == *(numbers + j)){
		        		*(arrfreq + j) = *(arrfreq + j) + 1;
					}
				}
			}
	        printf("\n");
	        item++;
		}
		if(!(counter_plithos>=x1 && counter_plithos<=x2)){
	        counter_notfirst++;
		}else if((counter_plithos>=x1 && counter_plithos<=x2) && !(sum_psifiwn>=y1 && sum_psifiwn<=y2)){
			counter_first_but_not_second++;
		}
    } while (epomenos_sunduasmos(arr, N, 6));
    
    printf("\n");
    printf("How many combinations do we have in total for A = %d on B = 6 : %ld.\n", N, n);
    printf("How many combinations didnt comply with the first term: %d\n", counter_notfirst);
    printf("How many of the combinations complied with first term, but not with the second one: %d\n", counter_first_but_not_second);
    printf("How many combinations were printed: %d\n", item-1);
	printf("The frequency of each one of the N numbers on the combinations that were printed:\n");
	for(i=0; i<N; i++){
		printf("Number %d :",*(numbers+i));
		printf("was printed %d times.\n",*(arrfreq+i));
	}
    return 0;
}

void swap(int* xp, int* yp){ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int * arr, int n) { 
    int i, j, min_idx; 
   
    for (i = 0; i < n - 1; i++) {  
        min_idx = i; 
        for (j = i; j < n; j++){
            if (*(arr+j) < *(arr+min_idx)){
                min_idx = j; 
        	}
  		} 
        swap((arr+min_idx), (arr+i)); 
    } 
} 

void print(int *ar, int len, int *elements){
    int i;
	for (i = 0; i < len; i++) {
	    printf("%d", *(elements+*(ar + i)));
	    if (i < len - 1) {
	        printf(" ");
	    }
	}
}

int epomenos_sunduasmos(int *ar, int n, int k){
    int finished = 0;
    int changed = 0;
    int i;

    if (k > 0) {
        for (i = k - 1; !finished && !changed; i--) {
            if (*(ar+i) < (n - 1) - (k - 1) + i) {
                
                *(ar+i) = *(ar+i) + 1;
                if (i < k - 1) {
                    
                    int j;
                    for (j = i + 1; j < k; j++) {
                        *(ar+j) = *(ar+j-1) + 1;
                        
                    }
                }
                changed = 1;
            } 
            finished = i == 0;
        }
        if (!changed) {
            
            for (i = 0; i < k; i++) {
                *(ar+i) = i;
            }
        }
    }
    return changed;
}

long int plithos(int N){
	long int apotelesma1, apotelesma2, apotelesma3, sunolo;
	int n = N;
	int afairesi;
	apotelesma1 = fact(n);
	apotelesma2 = fact(6);
	afairesi = n - 6;
	apotelesma3 = fact(afairesi);
	sunolo = apotelesma1 / (apotelesma2 * apotelesma3); //a! / b! * ((a-b))!
	return sunolo;
}


int giveN(){
	int N;
	do{
		printf("Please pick a positive integer greater than 6 and less than 49:\n");
		N = check();
	}while(N<6 || N>49);
	system("cls");
	printf("Number of integers is: %d.\n", N);
	return N; 
}

int * giveNumbers(int N){
	int plithos = N;
	int i,j,numarray;
	int eisagwgi;
	
	int* numbers = malloc(sizeof(int)*plithos);
	
	int counter = plithos - 1;
	for(i=0; i<N; i++){
		do{
			printf("Please pick a number, greater or even than 1 and less than 49(it should be different than the previous given numbers):\n");
			numarray = check();
			eisagwgi = 0;
			for(j=0; j<N; j++){
				if(numarray == *(numbers + j)){
					printf("Number %d , has already been stored.\n", numarray);
					eisagwgi = 1;
				}
			}
		}while((numarray<1 || numarray>49) || eisagwgi == 1);
		*(numbers + i) = numarray;
		printf("Number %d is stored. %d  more numbers to go!\n" , numarray, counter--);
	}
	system("cls");
	printf("%d numbers have been stored.\n",N);
	
	return numbers;
}

int *giveX(){
	int i,x;
	int * xarr = malloc(sizeof(int)*2);
	for(i=0; i<2; i++){
		if(i==0){
			do{
				printf("Please pick a number X1(a positive integer number greater or even with 0 and less than 6):\n");
				x = check();
			}while(x < 0 || x > 6);
			*(xarr + i) = x; 
		}
		if(i==1){
			do{
				printf("Please pick a number X2(a positive integer number greater or even with 0 and less than 6):\n",*xarr);
				x = check();
			}while(x < 0 || x < *xarr || x > 6);
			*(xarr + i) = x; 
		}
	}
	system("cls");
	printf("X limits have been stored X1 X2: 0 <= %d <= %d <= 6\n", *xarr,*(xarr+1));
	return xarr;	
}

int *giveY(){
	int i,y;
	int * yarr = malloc(sizeof(int)*2);
	for(i=0; i<2; i++){
		if(i==0){
			do{
				printf("Please pick a number Y1(a positive integer number greater or even with 21, or less or even with 279):\n");
				y = check();
			}while(y < 21 || y > 279);
			*(yarr + i) = y; 
		}
		if(i==1){
			do{
				printf("Please pick a number Y2(a positive integer number greater or even with 21, or less or even with 279):\n",*yarr);
				y = check();
			}while(y < 21 || y < *yarr || y>279);
			*(yarr + i) = y; 
		}
	}
	system("cls");
	return yarr;	
}

int check(){
	int num;
	char term;
	fflush(stdin);
	if(scanf("%d%c", &num, &term) != 2 || term != '\n'){
		return 0;
	}else{
    	return num;
	}
}

long int fact(int n) {
    if (n>=1)
        return n*fact(n-1);
    else
        return 1;
}
