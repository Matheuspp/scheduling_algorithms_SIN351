# scheduling_algorithms_SIN351
# Nome: Matheus Vieira da Silva
# Matricula: 6002

Este projeto propõe ao estudante a implementação dos algoritmos de escalonamento para Sistemas Operacionais. O estudante deverá implementar o comportamento do algoritmo de escalonamento no formato de uma função em Linguagem C. A estrutura da função recebe alguns parâmetros a depender do tipo do algoritmo, esses parâmetros podem ser uma lista do tipo definido &lt;Process>, o quanto o processo quer executar bem como outras informações.<br />

## modo de usar:
Basta executar o comando:
'''make run'''
<br />
## Implementação:
Foram implementados diversos algorimos de escalonamento, sendo eles:<br />
Round-robin (Round-robin scheduling)<br />
First Come First Serve (FCFS) <br />
Shortest Job First (SJF) <br />
Shortest Remaining Time Next (SRTN) <br />
Lotery <br />
## OBS:
Aparentemente o comando '''system("pause")''' não funciona muito bem no linux.
Não mudei nada pois o código base já estava assim. Aqui um link útil: [1]https://stackoverflow.com/questions/1107705/systempause-why-is-it-wrong
<br />
O algoritmo de loteria pode ser preemptivo ou não preemptivo, como nos parametros
do código base não tinha nenhum quantum especificado, eu implementei o não preemptivo.
# github repo
[sin351-project]https://github.com/Matheuspp/scheduling_algorithms_SIN351



