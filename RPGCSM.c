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
    
    int qtdJogadores = 0, qtdPersonagens = 0, qtdSessoes = 0;
    char ID[22];
    int numero;
     
    int opcao;

    do {

        printf("GERENCIADOR DE RPG\n");
        printf("\n\n");

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

            case 1: {
                Jogador novo;

                printf("Nome: ");
                scanf("%101s", novo.nome);
                printf("Data de registro: ");
                scanf("%d", &novo.data_registro);
                printf("E-mail: ");
                scanf("%101s", novo.email);
                printf("ID do jogador: ");
                scanf("%21s", novo.ID_jogador);

                if (cadastrarJogador(jogador, &qtdJogadores, novo)) {
                    printf("Jogador cadastrado com sucesso!\n\n");
                } else {
                    printf("Nao foi possivel cadastrar o jogador.\n");
                }
                break;
            }

            case 2: {
                Personagem novo;

                printf("Nome: ");
                scanf("%101s", novo.nome);
                printf("Classe: ");
                scanf("%d", &novo.classe);
                printf("Especie: ");
                scanf("%d", &novo.especie);
                printf("ID do personagem: ");
                scanf("%21s", novo.ID_personagem);
                printf("Nivel: ");
                scanf("%d", &novo.nivel);
                printf("Experiencia: ");
                scanf("%f", &novo.exp);
                printf("Forca, agilidade e magia: ");
                scanf("%f %f %f", &novo.stats.forca,
                      &novo.stats.agilidade, &novo.stats.magia);

                if (cadastrarPersonagem(personagem, &qtdPersonagens, novo)) {
                    printf("Personagem cadastrado com sucesso!\n");
                } else {
                    printf("Nao foi possivel cadastrar o personagem.\n");
                }
                break;
            }

            case 3: {
                Sessao nova;

                printf("Numero da sessao: ");
                scanf("%d", &nova.numero);
                printf("ID do personagem: ");
                scanf("%21s", nova.ID_personagem);
                printf("ID do jogador: ");
                scanf("%21s", nova.ID_jogador);
                printf("Data da sessao: ");
                scanf("%d", &nova.data_sessao);
                printf("Experiencia recebida: ");
                scanf("%f", &nova.exp_recebida);
                printf("Dano causado: ");
                scanf("%d", &nova.dano_causado);

                if (cadastrarSessao(sessao, &qtdSessoes, nova)) {
                    printf("Sessao cadastrada com sucesso!\n");
                } else {
                    printf("Nao foi possivel cadastrar a sessao.\n");
                }
                break;
            }

            case 4:
                printf("ID do jogador: ");
                scanf("%21s", ID);
                printf("Posicao encontrada: %d\n",
                       buscarJogador(jogador, qtdJogadores, ID));
                break;

            case 5:
                listarJogadores(jogador, qtdJogadores);
                break;

            case 6:
                printf("ID do personagem: ");
                scanf("%21s", ID);
                printf("Posicao encontrada: %d\n",
                       buscarPersonagem(personagem, qtdPersonagens, ID));
                break;

            case 7:
                listarPersonagens(personagem, qtdPersonagens);
                break;

            case 8: {
                int numero;
                printf("Numero da sessao: ");
                scanf("%d", &numero);
                printf("Posicao encontrada: %d\n",
                       buscarSessao(sessao, qtdSessoes, numero));
                break;
            }

            case 9:
                listarSessoes(sessao, qtdSessoes);;
                break;

            case 10: {
                Jogador atualizado;

                printf("ID do jogador a alterar: ");
                scanf("%21s", ID);
                printf("Novo nome: ");
                scanf("%101s", atualizado.nome);
                printf("Nova data de registro: ");
                scanf("%d", &atualizado.data_registro);
                printf("Novo e-mail: ");
                scanf("%101s", atualizado.email);

                if (alterarJogador(jogador, qtdJogadores, ID, atualizado)) {
                    printf("Jogador alterado com sucesso!\n");
                } else {
                    printf("Jogador nao encontrado.\n");
                }
                break;
            }

            case 11:
                printf("ID do jogador a excluir: ");
                scanf("%21s", ID);
                if (excluirJogador(jogador, &qtdJogadores, ID)) {
                    printf("Jogador excluido com sucesso!\n");
                } else {
                    printf("Jogador nao encontrado.\n");
                }
                break;

            case 12: {
                Personagem atualizado;

                printf("ID do personagem a alterar: ");
                scanf("%21s", ID);
                printf("Novo nome: ");
                scanf("%101s", atualizado.nome);
                printf("Nova classe e especie: ");
                scanf("%d %d", &atualizado.classe, &atualizado.especie);
                printf("Novo nivel e experiencia: ");
                scanf("%d %f", &atualizado.nivel, &atualizado.exp);
                printf("Nova forca, agilidade e magia: ");
                scanf("%f %f %f", &atualizado.stats.forca,
                      &atualizado.stats.agilidade, &atualizado.stats.magia);

                if (alterarPersonagem(personagem, qtdPersonagens, ID,
                                       atualizado)) {
                    printf("Personagem alterado com sucesso!\n");
                } else {
                    printf("Personagem nao encontrado.\n");
                }
                break;
            }

             case 13:
                printf("ID do personagem a excluir: ");
                scanf("%21s", ID);
                if (excluirPersonagem(personagem, &qtdPersonagens, ID)) {
                    printf("Personagem excluido com sucesso!\n");
                } else {
                    printf("Personagem nao encontrado.\n");
                }
                break;

            case 14: {
                Sessao atualizada;
                int numero;

                printf("Numero da sessao a alterar: ");
                scanf("%d", &numero);
                printf("Novo ID do personagem e do jogador: ");
                scanf("%21s %21s", atualizada.ID_personagem,
                      atualizada.ID_jogador);
                printf("Nova data da sessao: ");
                scanf("%d", &atualizada.data_sessao);
                printf("Nova experiencia recebida e dano causado: ");
                scanf("%f %d", &atualizada.exp_recebida,
                      &atualizada.dano_causado);

                if (alterarSessao(sessao, qtdSessoes, numero, atualizada)) {
                    printf("Sessao alterada com sucesso!\n");
                } else {
                    printf("Sessao nao encontrada.\n");
                }
                break;
            }

            case 15:
                printf("Numero da sessao a excluir: ");
                scanf("%d", &numero);
                if (excluirSessao(sessao, &qtdSessoes, numero)) {
                    printf("Sessao excluida com sucesso!\n");
                } else {
                    printf("Sessao nao encontrada.\n");
                }
                break;

            case 0:
                printf("\nSistema Encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    


    return 0;
}
