#include <stdio.h>

int main() {
  printf("******************************************\n");
  printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
  printf("******************************************\n\n");
  printf(
      "Existe um número secreto guardado nesse código, você deverá acertar que "
      "número é esse. O que eu posso te dizer é que o número é inteiro\n\n");
  printf(
      "A pontuação funcionará da seguinte forma: Você começa com 1000 pontos "
      "de vida, a cada erro será feita a seguinte operação: O seu chute, se "
      "errado, irá subtrair pelo número secreto e irá dividir o resultado da "
      "diferença por 2, o resultado será os pontos de vida restante!\n\n");
  printf(
      "Caso você queira brincar com seus colegas com esse jogo, você pode "
      "alterar o número secreto no código e adicionar algumas dicas do seu "
      "número secreto escrevendo dentro de novos printf, se divirta!\n\n");

  int numerosecreto = 50;
  int chute;
  int tentativas = 1;
  double pontos = 1000;

  while (1) {
    printf("Tentativa %d\n", tentativas);
    printf("Qual é o seu chute? ");

    scanf("%d", &chute);
    printf("Seu chute foi %d\n", chute);

    if (chute < 0) {
      printf("Você não pode chutar números negativos!\n");
      continue;
    }

    int acertou = (chute == numerosecreto);
    int maior = chute > numerosecreto;

    if (acertou) {
      printf("Você acertou o número secreto no seu chute\n");
      break;
    } else if (maior) {
      printf("Seu chute foi maior que o número secreto!\n");
      printf("Não desista, você consegue acertar!\n");
    } else {
      printf("Seu chute foi menor que o número secreto!\n");
      printf("Não desista, você consegue acertar!\n");
    }

    tentativas++;

    if (chute < 50) {
      double pontosperdidos = (numerosecreto - chute) / 2.0;
      pontos -= pontosperdidos;

    } else if (chute > 50) {
      double pontosperdidos = (chute - numerosecreto) / 2.0;
      pontos -= pontosperdidos;
    }

    printf("Total de pontos: %.1f\n", pontos);
  }

  int pontosfinais = pontos;
  printf("Fim de Jogo!\n");
  printf("Você acertou na tentativa %d!\n", tentativas);
  printf("Sua vida final foi de %d!\n", pontosfinais);
}