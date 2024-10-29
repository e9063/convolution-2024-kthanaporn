#include<stdio.h>
#include<stdlib.h>
#include <omp.h>

int main(){
    // ---- input and malloc A, F, ANS ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);
    long long int *ANS = malloc(sizeof(long long int) * (NA - NF + 1));

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    // implement here
    omp_set_num_threads(8);
    #pragma omp parallel for
    for(int i=0;i<=NA-NF;i++){
        long long int sum = 0;
        for(int j=0;j<NF;j++){
            sum += A[i+j] * F[NF-j-1];
        }
        ANS[i] = sum;
    }

    for(int i=0;i<=NA-NF;i++){
        printf("%lld\n", ANS[i]);
    }

    // ---- free memory ----
    free(F);
    free(A);
    free(ANS);
    // ---- end free ----
    return 0;
}

