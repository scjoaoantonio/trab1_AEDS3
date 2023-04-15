#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "./bibliotecas/ponto.h"
#include "./bibliotecas/file.h"
#include "./bibliotecas/retas.h"

int main(int argc, char *argv[]) {

  file_opt(argc, argv, &input, &output); //get_opt

  if (input == NULL) {
    printf("ERRO: INPUT VAZIO OU INEXISTENTE.\n");
    return 1;
  }

  FILE *entrada;
  entrada = fopen(input, "r");

  FILE *saida;
  saida = fopen(output, "w");

  if (entrada == NULL) {
    printf("ERRO: ABRIR ARQUIVO.\n");
    return 1;
  }

  A.y = 0;
  B.y = 0;
  fscanf(entrada, "%d %d %d", &N, &A.x, &B.x);

  if (B.x < A.x) {
    printf("ERRO: ANCORA A < ANCORA B.\n");
    return 1;
  }

  Ponto * Pontos = (Ponto * ) malloc(N * sizeof(Ponto));
  if (Pontos == NULL) {
    printf("ERRO: ALOCAR MEMÓRIA\n");
    return 1;
  }

  for (int i = 0; i < N; i++) {
    //(A.x, A.y, i + 1, Pontos[i].x, Pontos[i].y);
    //(i + 1, Pontos[i].x, Pontos[i].y, B.x, B.y);
    fscanf(entrada, "%d %d", &(Pontos[i].x), &(Pontos[i].y));
  }

  int max_intersecao = maxIntersecao(Pontos, N, A, B);
  fprintf(saida, "O número max eh %d\n", max_intersecao);


  // Tempo decorrido (Tempo: segundos.microsegundos)
  struct timeval tempo;
  gettimeofday(&tempo, NULL);
  fprintf(saida, "Tempo até hoje: %ld.%lds\n", tempo.tv_sec, tempo.tv_usec);
  
  struct rusage usage;
  getrusage (RUSAGE_SELF, &usage);
  fprintf (saida, "Tempo de uso do usuário: %ld.%05lds\n", usage.ru_utime.tv_sec,
	   usage.ru_utime.tv_usec);
  fprintf (saida, "Tempo de uso do sistema: %ld.%05lds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
  
  fclose(entrada);
  free(Pontos);
  return 0;
}