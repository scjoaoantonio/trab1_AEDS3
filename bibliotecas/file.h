#ifndef FILE_H
#define FILE_H

char *input = NULL;
char *output = NULL;

void file_opt(int argc, char *argv[], char **input, char **output) {
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