#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct atributos{
    float forca;
    float agilidade;
    float magia;
};

struct jogador{
    char nome[102];
    int data_registro;
    char email[102];
    char codigo[22];
};

struct personagem{
    char nome[102];
    int classe;
    int especie;
    char codigo[22];
    int nivel;
    float exp;
    struct atributos stats;
};

struct sessao{
    int numero;
    char nome_personagem[102];
    char nome_jogador[102];
    int data_sessao;
    float exp_recebida;
    int dano_causado;
};