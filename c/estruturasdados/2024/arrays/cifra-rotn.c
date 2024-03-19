#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate_n(char *palavra, int n);
void pega_string_e_exibe();

int main(int argc, char *argv[]) {
  if (argc != 1) {
    if (argc == 3) {
      printf("Você digitou %d argumentos\n", argc);
      printf("o 1º: %s\n", argv[0]);
      printf("o 2º: %s\n", argv[1]);
      printf("o 3º: %c\n", (int)argv[2][0]);
      rotate_n(argv[1], (int)argv[2][0]- '0'); 
      /* Para converter o valor de um argumento em C que é um char para seu valor numérico em int, você pode simplesmente subtrair o valor do caractere '0' do caractere em questão. Isso funciona porque os caracteres numéricos em C são armazenados como inteiros em uma tabela ASCII, onde os caracteres '0' a '9' são armazenados consecutivamente. Portanto, subtrair o valor de '0' de um caractere numérico retorna o valor numérico correspondente.*/
    }else{
    rotate_n(argv[1], 13);}
  } else {
    pega_string_e_exibe();
  }
}

void rotate_n(char *palavra, int n) {
  int i;
  printf("Antes: %s\n", palavra);
  for (i = 0; i < strlen(palavra); i++) {
    palavra[i] = palavra[i] + n;
  }
  printf("Depois: %s\n", palavra);
}

void pega_string_e_exibe() {
  char palavra[100];
  printf("Digite uma frase: ");
  fgets(palavra, 100, stdin);
  printf("Digite o valor da cifra: ");
  int n = scanf(" %d", &n);
  rotate_n(palavra, n);
}