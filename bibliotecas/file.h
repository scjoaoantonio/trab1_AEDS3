#ifndef FILE_H
#define FILE_H

//Cria as variáveis de input e output vazias
char *input = NULL;
char *output = NULL;

// Recebe o arquivo de entrada e a indicação do arquivo de saída e armazena nas variáveis criadas acima
void arq(int argc, char *argv[], char **input, char **output) {
  int opt;
  while ((opt = getopt(argc, argv, "i:o:")) != -1) {
    if (opt == 'i') {
      *input = optarg;
    } else if (opt == 'o') {
      *output = optarg;
    } else {
      printf("ERRO: -i OU -o.\n");
    }
  }
}

#endif