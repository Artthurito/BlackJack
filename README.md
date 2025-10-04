# BlackJack
## Jogo de Blackjack (21) em C
Este é um projeto simples de um jogo de Blackjack (também conhecido como 21) desenvolvido inteiramente em linguagem C. O jogo é totalmente funcional e jogável diretamente no terminal.

Este projeto foi criado como um exercício de aprendizado para praticar conceitos fundamentais da programação em C, como structs, arrays, funções, laços de repetição e lógica condicional.

## ♠️ Funcionalidades
Baralho de 52 cartas gerado e embaralhado aleatoriamente a cada jogo.

Turno do jogador com opções de Comprar (Hit) ou Parar (Stand).

Lógica para "estourar" (bust) caso a pontuação do jogador ou do Dealer passe de 21.

"Inteligência" do Dealer que segue a regra padrão de comprar cartas até atingir 17 pontos ou mais.

Cálculo de pontuação que lida com o valor dinâmico do Ás (pode valer 1 ou 11).

Determinação clara do vencedor ao final da rodada (Jogador vence, Dealer vence ou Empate).

Interface de texto simples e jogável diretamente no console.

## 🛠️ Tecnologias Utilizadas
Linguagem: C

Bibliotecas Padrão: stdio.h, stdlib.h, time.h, locale.h

Uso opcional de <windows.h> para a exibição correta de caracteres especiais (naipes ♠ ♥ ♦ ♣) no console do Windows.
Caso os naipes não funcionem, utilize char com a inicial de cada naipe para fazer uma melhor exibição.
