#ifndef RETAS_H
#define RETAS_H
#include "./ponto.h"

int temIntersecao(Ponto P1, Ponto P2, Ponto A, Ponto B) {
    
    // Coeficiente angular
    float coefangP = 0.0;
    float coefangA = 0.0;
    float coefangB = 0.0;

    if (P2.x - P1.x != 0) {
        coefangP = (P2.y - P1.y) / (P2.x - P1.x); //P1(n) e P2(n)
    } else {
        coefangP = 999.0;
    }
    if (P1.x - A.x != 0) {
        coefangA = (P1.y - A.y) / (P1.x - A.x); //P1(n) e A
    } else {
        coefangA = 999.0;
    }
    if (P1.x - B.x != 0) {
        coefangB = (P1.y - B.y) / (P1.x - B.x); //P1(n) e B
    } else {
        coefangB = 999.0;
    }

    // Verifica se há interseção fora das âncoras
    if (((coefangP < coefangA) && (coefangP < coefangB)) || ((coefangP > coefangA) && (coefangP > coefangB))) {
        return 0; //se retorna 0, não há interseção
    } else {
        return 1; //em caso de 1, há interseção
    }
}

int maxIntersecao(Ponto * Pontos, int n, Ponto A, Ponto B) {
    int max_intersecao = 0;
    int i, j;
    for (i = 0; i < n; i++) {
        int intersecoes = 0;

        for (j = 0; j < n; j++) {

            if (i == j) {
                continue;
            }

            if (!temIntersecao(Pontos[i], Pontos[j], A, B)) { //se não conferir com a função interseção ele conta +1
                intersecoes++;
            }

        }

        if (intersecoes > max_intersecao) {
            max_intersecao = intersecoes;
        }

    }

    if (max_intersecao < 1) {
        max_intersecao = 1;
    }

    return max_intersecao;
}
#endif