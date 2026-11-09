#ifndef RPGFUNC_H
#define RPGFUNC_H

#include "rpgstructs.h"

#define MAX 5

int cadastrarJogador(Jogador jogador[], int *quantidade, Jogador novo);
void listarJogadores(Jogador jogador[], int quantidade);
int buscarJogador(Jogador jogador[], int quantidade, char ID[]);
int alterarJogador(Jogador jogador[], int quantidade, char ID[], Jogador atualizado);
int excluirJogador(Jogador jogador[], int *quantidade, char ID[]);

int cadastrarPersonagem(Personagem personagem[], int *quantidade, Personagem novo);
void listarPersonagens(Personagem personagem[], int quantidade);
int buscarPersonagem(Personagem personagem[], int quantidade, char ID[]);
int alterarPersonagem(Personagem personagem[], int quantidade, char ID[], Personagem atualizado);
int excluirPersonagem(Personagem personagem[], int *quantidade, char ID[]);

int cadastrarSessao(Sessao sessao[], int *quantidade, Sessao nova);
void listarSessoes(Sessao sessao[], int quantidade);
int buscarSessao(Sessao sessao[], int quantidade, int numero);
int alterarSessao(Sessao sessao[], int quantidade, int numero, Sessao atualizada);
int excluirSessao(Sessao sessao[], int *quantidade, int numero);

#endif