# Programação e Algoritimos - Ciêcias da Computação | UECE

## Resumo
Trabalho acadêmico da disciplina Programação e Algoritimos, na criação de um sistema para uma lanchonete.

Atividade proposta: 
"A lanchonete "Tudo que é bom" está bastante desatualizada e necessita de um programa que realize diversas operações necessárias para o seu funcionamento. Com base em suas habilidades, você foi contratado para desenvolver esse sistema."

As mudanças no sistema devem  ficar salvas mesmo após fechar e abrir o sistema, ou seja, precisam ser armazenadas em arquivos.

## Descrição
Apresentar por partes a idealização da criação do sistema desenvolvido.

### Conceitos
Alguns conceitos como “classe” e “objeto” tiveram influência na construção do sistema.

### Funcionalidades
Em termos de funcionalidades, o programa permite ao utilizador:

- Fazer pedidos, visualizar a comida que mais teve lucro
- Criar um cardápio, adicionar as comidas nele. Além de poder editar, visualizar e remover as comidas.
- Poder acrescentar mantimentos no estoque, editar, visualizar e remover. 
- Se há disponibilidade dos mantimentos para fazer a comida.
- Se há saldo suficiente para as compras dos mantimentos.
- Visualizar o relatório, com seus lucros e prejuízos.
- Poder sacar e depositar dinheiro.

### Estrutura do programa
O desenvolvimento do programa teve como base uma divisão estrutural, separamos Estoque,Cardápio, Pedido, Saldo e Relatório por “classes”. Cada classe teve seu código com as suas funcionalidades, uma classe chamada Main chamaria todas essas classes, seria o programa principal que rodaria o sistema. A seguinte divisão:

- Estoque : Cadastrar mantimento, visualizar mantimento, editar mantimento e deletar mantimento. 
- Cardápio : Adicionar comida, visualizar comida, editar comida e remover comida.
- Pedido : Cadastrar pedido, visualizar pedido, editar pedido e deletar pedido.
- Saldo : Visualizar saldo, sacar e depositar.
- Relatório : Visualizar o relatório que indica os lucros ou prejuízos. 
- Main : Chama todas as classes anteriores.


## Ambiente de desenvolvimento
- IDE: VsCode
- Linguagem de programação: C padrão

