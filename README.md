# [![42](https://i.imgur.com/9NXfcit.jpg)](i.imgur.com/9NXfcit.jpg) Minitalk 

O objetivo deste projeto é codificar um pequeno programa de troca de dados usando sinais UNIX.

Um projeto introdutório para outros maiores que aparecerão depois durante a formação 42.

---

## Descrição

- Um programa de comunicação no formato cliente e servidor;
- O `server` deve ser iniciado primeiro, exibindo o seu `PID`;
- O `client` então é inicializado recebendo dois parâmetros, sendo:
  - O `PID` do server;
  - A mensagem a ser enviada;
---
## Funcionamento

- Após inicializado, o `client` transmite a mensagem para o servidor atráves de 2 sinais representando 0 e 1. A cada 8 bits enviados, 1 caractere e impresso no terminal.
- O `server` recebe os sinais e os converte para a tabela ASCII, transformando os binários em um inteiro entre 0 e 127.

## Objetivos
- Comunicação utilizadno apenas os sinais SIGUSR1 e SIGUSR2;
- O server consegue receber multiplas mensagens sem ser reiniciado;
- Apenas duas variáveis globais no máximo;
- O server envia um sinal quando a mensagem foi recebida;
- O server imprime caracteres UNICODE.

## Usage

- Clone repository

```shell=
git clone git@github.com:jcaetano-c/42SP_minitalk.git
```

- Compile server and client

```shell=
make
```
Execute os arquivos `./server` e `./client` em terminais separados.

---

## Ambiente de execução
[![Linux](https://img.shields.io/badge/Linux-FF6600?style=for-the-badge&logo=linux&logoColor=white)](https://github.com/seu-usuario/seu-repositorio/releases)


## Contato

[![Linkedin](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/jairo-caetano-junior/)
