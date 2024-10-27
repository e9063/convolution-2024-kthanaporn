#include<stdio.h>
#include<stdlib.h>
#include <omp.h>

int main(){
    // ---- input and malloc A, F ----
    int NA, NF;
    scanf("%d %d", &NA, &NF);
    int *A = malloc(sizeof(int) * NA);
    int *F = malloc(sizeof(int) * NF);

    for(int i = 0; i < NA; i++){
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < NF; i++){
        scanf("%d", &F[i]);
    }
    // ---- end input and malloc----

    double start, end;
    start = omp_get_wtime();
    // implement here
    omp_set_num_threads(8);
    #pragma omp parallel for
    for(int i=0;i<=NA-NF;i++){
        int sum = 0;
        for(int j=0;j<NF;j++){
            sum += A[i+j] * F[NF-j-1];
        }
        // printf("%d\n", sum);
    }
    end =omp_get_wtime();
    printf("Time: %lf\n", (double)(end - start));

    // ---- free memory ----
    free(F);
    free(A);
    // ---- end free ----
    return 0;
}

