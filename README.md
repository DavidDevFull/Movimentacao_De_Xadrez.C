# ♟️ Simulador de Movimentos de Peças de Xadrez em C

Este projeto em C simula os movimentos básicos de quatro peças do xadrez: **Torre**, **Bispo**, **Cavalo** e **Rainha**. O programa interage com o usuário, solicita direções e número de casas para movimentação, e exibe os movimentos em tempo real no terminal.

## 🚀 Tecnologias Utilizadas

- Linguagem C
- Biblioteca padrão `<stdio.h>` e `<string.h>`
- Terminal para entrada e saída de dados

## 📦 Funcionalidades

- ✅ Movimentação personalizada da **Torre** (horizontal e vertical)
- ✅ Movimentação personalizada do **Bispo** (diagonais)
- ✅ Escolha entre dois padrões de movimentação do **Cavalo**
- ✅ Movimentação da **Rainha**, combinando lógicas da Torre e do Bispo

## 📄 Como Funciona

Ao executar o programa, o usuário poderá escolher uma das peças e definir:

1. A direção do movimento
2. Quantas casas deseja mover (quando aplicável)
3. Visualizar as movimentações passo a passo no terminal

### 🧠 Exemplo de Interação:
```bash
Qual peça deseja movimentar?
1. Torre | 2. Bispo | 3. Cavalo | 4. Rainha
> 1

Qual direção deseja movimentar?
1. Cima | 2. Baixo | 3. Esquerda | 4. Direita
> 4

Quantas casas deseja movimentar?
> 3

A torre se movimentou 1 casa(s) para a Direita.
A torre se movimentou 2 casa(s) para a Direita.
A torre se movimentou 3 casa(s) para a Direita.
```
