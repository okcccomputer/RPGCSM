#include <stdio.h>
#include <string.h>
#include "rpgfunc.h"



// CRUD DO JOGADOR 

int buscarJogador(Jogador jogador[], int quantidade, char codigo[]) {

    if (jogador == NULL || codigo == NULL || quantidade < 0) {
        return -1;
    }
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(jogador[i].ID_jogador, codigo) == 0) {
            return i;
        }
    }

    return -1;
}   

int cadastrarJogador(Jogador jogador[], int *quantidade, Jogador novo) {

    if (jogador == NULL || quantidade == NULL || *quantidade < 0 ||
        *quantidade >= MAX) {
        return 0;
    }

    if (buscarJogador(jogador, *quantidade, novo.ID_jogador) != -1) {
        return 0;
    }

    jogador[*quantidade] = novo;
    (*quantidade)++;

    return 1;
}

void listarJogadores(Jogador jogador[], int quantidade) {

    if (jogador == NULL || quantidade <= 0) {
        printf("Nenhum jogador cadastrado.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("Jogador %d\n", i + 1);
        printf("Nome: %s\n", jogador[i].nome);
        printf("Data de registro: %d\n", jogador[i].data_registro);
        printf("E-mail: %s\n", jogador[i].email);
        printf("ID: %s\n\n", jogador[i].ID_jogador);
    }
}

int alterarJogador(Jogador jogador[], int quantidade, char codigo[], Jogador atualizado) {

    int posicao = buscarJogador(jogador, quantidade, codigo);

    if (posicao == -1) {
        return 0;
    }
    strcpy(atualizado.ID_jogador, jogador[posicao].ID_jogador);
    jogador[posicao] = atualizado;

    return 1;
}

int excluirJogador(Jogador jogador[], int *quantidade, char codigo[]) {

    if (quantidade == NULL) {
        return 0;
    }
    int posicao = buscarJogador(jogador, *quantidade, codigo);

    if (posicao == -1) {
        return 0;
    }
    for (int i = posicao; i < *quantidade - 1; i++) {
        jogador[i] = jogador[i + 1];
    }
    (*quantidade)--;
    return 1;
}

//CRUD DO PERSONAGEM

int buscarPersonagem(Personagem personagem[], int quantidade, char codigo[]) {

    if (personagem == NULL || codigo == NULL || quantidade < 0) {
        return -1;
    }

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(personagem[i].ID_personagem, codigo) == 0) {
            return i;
        }
    }

    return -1;
}

int cadastrarPersonagem(Personagem personagem[], int *quantidade, Personagem novo) {

    if (personagem == NULL || quantidade == NULL || *quantidade < 0 ||
        *quantidade >= MAX) {
        return 0;
    }

    if (buscarPersonagem(personagem, *quantidade, novo.ID_personagem) != -1) {
        return 0;
    }

    personagem[*quantidade] = novo;
    (*quantidade)++;

    return 1;
}

void listarPersonagens(Personagem personagem[], int quantidade) {

    if (personagem == NULL || quantidade <= 0) {
        printf("Nenhum personagem cadastrado.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("Personagem %d\n", i + 1);
        printf("Nome: %s\n", personagem[i].nome);
        printf("Classe: %d\n", personagem[i].classe);
        printf("Especie: %d\n", personagem[i].especie);
        printf("ID: %s\n", personagem[i].ID_personagem);
        printf("Nivel: %d\n", personagem[i].nivel);
        printf("Experiencia: %.2f\n", personagem[i].exp);
        printf("Forca: %.2f\n", personagem[i].stats.forca);
        printf("Agilidade: %.2f\n", personagem[i].stats.agilidade);
        printf("Magia: %.2f\n\n", personagem[i].stats.magia);
    }
}

int alterarPersonagem(Personagem personagem[], int quantidade, char codigo[], Personagem atualizado) {

    int posicao = buscarPersonagem(personagem, quantidade, codigo);

    if (posicao == -1) {
        return 0;
    }

    strcpy(atualizado.ID_personagem, personagem[posicao].ID_personagem);
    personagem[posicao] = atualizado;

    return 1;
}

int excluirPersonagem(Personagem personagem[], int *quantidade, char codigo[]) {
    
    if (quantidade == NULL) {
        return 0;
    }

    int posicao = buscarPersonagem(personagem, *quantidade, codigo);

    if (posicao == -1) {
        return 0;
    }
    for (int i = posicao; i < *quantidade - 1; i++) {
        personagem[i] = personagem[i + 1];
    }

    (*quantidade)--;
    return 1;
}

//CRUD DA SESSAO

int buscarSessao(Sessao sessao[], int quantidade, int numero) {

    if (sessao == NULL || quantidade < 0) {
        return -1;
    }

    for (int i = 0; i < quantidade; i++) {
        if (sessao[i].numero == numero) {
            return i;
        }
    }

    return -1;
}

int cadastrarSessao(Sessao sessao[], int *quantidade, Sessao nova) {

    if (sessao == NULL || quantidade == NULL || *quantidade < 0 ||
        *quantidade >= MAX) {
        return 0;
    }
    if (buscarSessao(sessao, *quantidade, nova.numero) != -1) {
        return 0;
    }

    sessao[*quantidade] = nova;
    (*quantidade)++;

    return 1;
}

void listarSessoes(Sessao sessao[], int quantidade) {

    if (sessao == NULL || quantidade <= 0) {
        printf("Nenhuma sessao cadastrada.\n");
        return;
    }
    for (int i = 0; i < quantidade; i++) {
        printf("Sessao %d\n", i + 1);
        printf("Numero: %d\n", sessao[i].numero);
        printf("ID do personagem: %s\n", sessao[i].ID_personagem);
        printf("ID do jogador: %s\n", sessao[i].ID_jogador);
        printf("Data da sessao: %d\n", sessao[i].data_sessao);
        printf("Experiencia recebida: %.2f\n", sessao[i].exp_recebida);
        printf("Dano causado: %d\n\n", sessao[i].dano_causado);
    }
}

int alterarSessao(Sessao sessao[], int quantidade, int numero, Sessao atualizada) {

    int posicao = buscarSessao(sessao, quantidade, numero);

    if (posicao == -1) {
        return 0;
    }

    atualizada.numero = sessao[posicao].numero;
    sessao[posicao] = atualizada;

    return 1;
}

int excluirSessao(Sessao sessao[], int *quantidade, int numero) {

    if (quantidade == NULL) {
        return 0;
    }
    int posicao = buscarSessao(sessao, *quantidade, numero);

    if (posicao == -1) {
        return 0;
    }
    for (int i = posicao; i < *quantidade - 1; i++) {
        sessao[i] = sessao[i + 1];
    }

    (*quantidade)--;
    return 1;
}
