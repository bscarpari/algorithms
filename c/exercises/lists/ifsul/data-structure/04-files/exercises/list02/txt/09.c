#include <stdio.h>

/*
Faça   um   programa   que   descriptografe   um   arquivo   criado
pelo   programa   decriptografia, do exercício anterior, realizando 
a operação inversa: ler o arquivo textocodificado, descodificar e
escrever o novo arquivo texto descriptografado.
*/

int main() {
  FILE *file;
  FILE *file2;
  char filename[255], c;

  printf("Digite o nome do arquivo de texto: ");
  scanf("%s", filename);

  file = fopen(filename, "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo de leitura");
    return 1;
  }

  file2 = fopen("exemplo5.txt", "w");

  if (file2 == NULL) {
    printf("Erro ao abrir o arquivo de escrita");
    return 1;
  }

  while ((c = fgetc(file)) != EOF) {
    fputc(c - 1, file2);
  }

  fclose(file);
  fclose(file2);

  return 0;
}