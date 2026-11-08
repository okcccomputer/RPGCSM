#ifndef RPGSTRUCTS_H
#define RPGSTRUCTS_H

typedef struct {
    float forca;
    float agilidade;
    float magia;
}Atributos;

typedef struct{
    char nome[102];
    int data_registro;
    char email[102];
    char ID_jogador[22];
}Jogador;

typedef struct{
    char nome[102];
    int classe;
    int especie;
    char ID_personagem[22];
    int nivel;
    float exp;
    Atributos stats;
}Personagem;

typedef struct{
    int numero;
    char ID_personagem[22];
    char ID_jogador [22];
    int data_sessao;
    float exp_recebida;
    int dano_causado;
}Sessao;

#endif