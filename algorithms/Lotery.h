#ifndef __Lotery__
#define __Lotery__


#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"
#include "stdlib.h"

void lotery_calculate_time(Process *p, int len){
    int i = 0;
    int j = 0;
    int aux = 0;
    int r;
    int winner;
    int again = 1;
    int curr_time = 0;
    int drawn[len]; // cindo tickets cada processo
    int tickets_matrix[len][5];

    // populando a matriz
    for (i=0; i < len; i++){
        drawn[i] = 0;
        // 5 numeros a partir de i
        for (j=0; j < 5; j++){
            aux++;
            tickets_matrix[i][j] = aux;
        }
    }

    while(again){

        // gerando um numero aleatorio entre 0 e len*5
        int r = rand() % len*5;

        // verificando ganhador
        for (i=0; i < len; i++){
            for (j=0; j < 5; j++){
                if (tickets_matrix[i][j] == r && drawn[i] == 0){
                    drawn[i] = 1;

                    p[i].waiting_time = curr_time - p[i].arrive_time;
                    p[i].response_time = curr_time; // add tempo de resposta

                    p[i].completed = TRUE;


                    curr_time += p[i].burst;


                    p[i].return_time = curr_time;

                    p[i].turnaround_time = p[i].return_time - p[i].arrive_time;
                }
            }
        }
    }

    // executar



    
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

    print_table(p, len);

}

#endif