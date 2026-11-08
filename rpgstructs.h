#ifndef RPGSTRUCTS_H
#define RPGSTRUCTS_H

typedef struct {
    char nome[102];
    int data_registro;
    char email[102];
    char codigo[22];
}Jogador;

typedef struct {
    float forca;
    float agilidade;
    float magia;
}Atributos;

typedef struct {
    char nome[102];
    int classe;
    int especie;
    char codigo[22];
    int nivel;
    float exp;
    Atributos stats;
}Personagem;

typedef struct {
    int numero;
    char nome_personagem[102];
    char nome_jogador[102];
    int data_sessao;
    float exp_recebida;
    int dano_causado;
}Sessao;

#endif