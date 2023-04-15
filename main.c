#include <stdio.h> //entrada e saída de dados
#include <stdlib.h> //alocação de memória 
#include <unistd.h>  //fornece acesso a recursos do S.O
#include <getopt.h> //  analisar argumentos da linha de comando
#include <sys/resource.h> // verificar uso do sistema
#include <sys/time.h> //funções de tempo e duração

#include "./bibliotecas/ponto.h"
#include "./bibliotecas/file.h"
#include "./bibliotecas/retas.h"

int main(int argc, char *argv[]) {

  arq(argc, argv, &input, &output); //envia para a função do getopt

  if (input == NULL) {
    printf("ERRO: INPUT VAZIO OU INEXISTENTE.\n");
    return 1;
  }

  //inicia os arquivos de entrada e saída
  FILE *entrada;
  entrada = fopen(input, "r");

  FILE *saida;
  saida = fopen(output, "w");

  if (entrada == NULL) {
    printf("ERRO: ABRIR ARQUIVO.\n");
    return 1;
  }

  //inicia e recebe as coordenadas das âncoras
  A.y = 0;
  B.y = 0;
  fscanf(entrada, "%d %d %d", &N, &A.x, &B.x);

  if (B.x < A.x) {
    printf("ERRO: ANCORA A < ANCORA B.\n");
    return 1;
  }

  //alocação da memória dos pontos recebidos
  Ponto * Pontos = (Ponto * ) malloc(N * sizeof(Ponto));
  if (Pontos == NULL) {
    printf("ERRO: ALOCAR MEMÓRIA\n");
    return 1;
  }

  // recebe as  coordenadas dos demais pontos
  for (int i = 0; i < N; i++) {
    //(A.x, A.y, i + 1, Pontos[i].x, Pontos[i].y);
    //(i + 1, Pontos[i].x, Pontos[i].y, B.x, B.y);
    fscanf(entrada, "%d %d", &(Pontos[i].x), &(Pontos[i].y));
  }

  // envia os pontos para calcular as interseções
  int max_intersecao = maxIntersecao(Pontos, N, A, B);
  fprintf(saida, "O número max eh %d\n", max_intersecao);


  // Tempo decorrido (Tempo: segundos.microsegundos)
  struct timeval tempo;
  gettimeofday(&tempo, NULL);
  fprintf(saida, "Tempo até hoje: %ld.%lds\n", tempo.tv_sec, tempo.tv_usec);
  
  // calcula o tempo de uso da CPU
  struct rusage usage;
  getrusage (RUSAGE_SELF, &usage);
  fprintf (saida, "Tempo de uso do usuário: %ld.%05lds\n", usage.ru_utime.tv_sec,
	   usage.ru_utime.tv_usec);
  fprintf (saida, "Tempo de uso do sistema: %ld.%05lds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
  
  //fecha os arquivos de entrada e saída, e libera a memória alocada para os pontos
  fclose(entrada);
  fclose(saida);
  free(Pontos);
  return 0;
}