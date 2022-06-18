#ifndef __Lotery__
#define __Lotery__


#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"
#include "stdio.h"
#include "time.h"

int random_number(int min_num, int max_num)
    {
        int result = 0, low_num = 0, hi_num = 0;

        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }

        srand(time(NULL));
        result = (rand() % (hi_num - low_num)) + low_num;
        return result;
    }
/*
Essa implementação levava em conta uma matriz de tickets, porém o algoritmo demorava demais
void lotery_calculate_time(Process *p, int len){
    int i = 0;
    int j = 0;
    int aux = 0;
    int r;
    int winner;
    int again = 1;
    int curr_time = 0;
    int drawn[len]; // cindo tickets cada processo
    int tickets_matrix[len][2];

    // populando a matriz
    for (i=0; i < len; i++){
        drawn[i] = 0;
        // 2 numeros a partir de i
        for (j=0; j < 2; j++){
            tickets_matrix[i][j] = aux;
            aux++;
        }
    }

    while(again){

        // gerando um numero aleatorio entre 0 e len*2
        r = random_number(0, len*2);

        // verificando ganhador
        aux = 0;
        for (i=0; i < len; i++){
            for (j=0; j < 2; j++){
                printf("%d == %d \n", tickets_matrix[i][j], r);
                if (tickets_matrix[i][j] == r && drawn[i] == 0){

                    p[i].waiting_time = curr_time - p[i].arrive_time;
                    p[i].response_time = curr_time; // add tempo de resposta

                    p[i].completed = TRUE;


                    curr_time += p[i].burst;


                    p[i].return_time = curr_time;

                    p[i].turnaround_time = p[i].return_time - p[i].arrive_time;

                    drawn[i] = 1;
                    aux++;
                }
            }
        }
        if (aux == len - 1){
            again = 0;
        }
    }

    for (i=0; i < len;i++){
        printf("%d ", drawn[i]);
    }

    // executar



    
}
*/

void lotery_calculate_time(Process *p, int len){
    int curr_time = 0;
    int i;
    int r;
    int aux;
    int run_again = 1;
    int drawn[len];

    for (i=0; i < len; i++){
        drawn[i] = 0;
    }

    for (i=0; i < len; i++){
        run_again = 1;
        while(run_again){
            r = random_number(0, len);
            if (drawn[r] != 1){

                p[i].waiting_time = curr_time - p[i].arrive_time;
                p[i].response_time = curr_time; // add tempo de resposta

                p[i].completed = TRUE;

                curr_time += p[i].burst;


                p[i].return_time = curr_time;

                p[i].turnaround_time = p[i].return_time - p[i].arrive_time;

                drawn[i] = 1;
                run_again = 0;
                curr_time += p[i].burst;
            }
        }

    }
    

}

void lotery_print_gantt_chart(Process *p, int len) {
    //trabalhar na implementacao aqui
}

void Lotery(Process *p, int len) {
    int i;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;

	process_init(p, len);

	merge_sort_by_arrive_time(p, 0, len);

	lotery_calculate_time(p, len);

    // calculando tempos de resposta, retorno e de espera
    for (i = 0; i < len; i++)
    {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
        total_response_time += p[i].response_time;
    }
	printf("Lotery: Implememtado pelo aluno. \n");


    //lotery_print_gantt_chart(p, len);
    printf("\n\tAverage Waiting Time     : %-2.2lf\n", (double)total_waiting_time / (double)len);
    printf("\tAverage Turnaround Time  : %-2.2lf\n", (double)total_turnaround_time / (double)len);
    printf("\tAverage Response Time    : %-2.2lf\n\n", (double)total_response_time / (double)len);
    quick_sort_by_return_time(p, len);
    print_table(p, len);

}

#endif