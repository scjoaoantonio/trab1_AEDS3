#ifndef PONTO_H
#define PONTO_H

typedef struct {
  int x;
  int y;
}Ponto;

int N; //número de pontos P
Ponto A, B; //âncoras (x,0)
Ponto P1, P2; //pontos P(n) a serem comparados para ver se existe interseção.

#endif