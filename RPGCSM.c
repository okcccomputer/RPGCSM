#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rpgstructs.h"
#include "rpgfunc.h"

#define MAX 5

int main (){

    Jogador jogador[MAX];
    Personagem personagem[MAX];
    Sessao sessao[MAX];
    
    int qtdJogadores = 0, qtdPersonagens = 0, qtdSessoes = 0,codigo=0;
     
     int opcao;

    do {

        printf("\n====================================\n");
        printf("       GERENCIADOR DE RPG\n");
        printf("====================================\n");

        printf("\n--- CADASTROS ---\n");
        printf("1 - Cadastrar jogador\n");
        printf("2 - Cadastrar personagem\n");
        printf("3 - Cadastrar sessao\n");

        printf("\n--- CONSULTAS ---\n");
        printf("4 - Consultar jogador\n");
        printf("5 - Listar jogadores\n");
        printf("6 - Consultar personagem\n");
        printf("7 - Listar personagens\n");
        printf("8 - Buscar sessao\n");
        printf("9 - Listar sessoes\n");


        printf("\n--- ALTERACOES ---\n");
        printf("10 - Alterar jogador\n");
        printf("11 - Excluir jogador\n");
        printf("12 - Alterar personagem\n");
        printf("13 - Excluir personagem\n");
        printf("14 - Alterar sessao\n");
        printf("15 - Excluir sessao\n");
        printf("\n0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {

            case 1:
                cadastrarJogador(jogador, &qtdJogadores);
                break;

            case 2:
                cadastrarPersonagem(personagem,&qtdPersonagens,);
                break;

            case 3:
                cadastrarSessao(sessao,&qtdSessoes,);
                break;

            case 4:
                buscarJogador();
                break;

            case 5:
                listarJogadores(jogador, qtdJogadores);
                break;

            case 6:
                buscarPersonagem();
                break;

            case 7:
                listarPersonagens(personagem, qtdPersonagens);
                break;

            case 8:
                buscarSessao();
                break;

            case 9:
                listarSessoes(sessao, qtdSessoes);;
                break;

            case 10:
                alterarJogador();
                break;

            case 11:
                excluirJogador(jogador, &qtdJogadores, codigo);
                break;

            case 12:
                alterarPersonagem(personagem,&qtdPersonagens);
                break;

             case 13:
                excluirPersonagem(personagem,&qtdPersonagens,codigo);
                break;

            case 14:
                alterarSessao();
                break;

            case 15:
                excluirSessao(sessao,qtdSessoes,codigo);
                break;

            case 0:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    


    return 0;
}
