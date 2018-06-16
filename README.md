# FrogRace

> FrogRace

Este repositório contém:

1. Informações sobre a configuração
2. Instruções de compilação
3. Instruções de execução
4. Informações sobre localização dos códigos que serão avaliados


## Tabela de Conteúdos

- [Configuração](#configuração)
- [Compilação](#compilação)
- [Execução](#execução)
- [Códigos Avaliados](#códigos-avaliados)
	- [Passos 1, 2](#passos-1-2)
	- [Passos 3, 4 e 5](#passos-3-4-5)
	- [Passo 6](#passo-6)

## Configuração
Para o desenvolvimento deste projeto foi utilizado apenas as bibliotecas padrão do c++, <iostream>,
<string>, <random>, <fstream>, <istream> e <ostream>. Com excessão da TAD Lista utilizada, que foi
implementada anteriormente e depois incluída no projeto com seu respectivo Iterador.

## Compilação
Para compilar o programa é necessário que existam as demais pastas do projeto. Caso elas não existam,
execute o comando 'make dir' a partir da pasta raíz do projeto. Também é necessária a existência
dos arquivos corridas.csv e sapos.csv dentro da pasta data. Finalmente, basta compilar o programa
executando o comando 'make' ou 'make FrogRace'.

## Execução
O programa ficará localizado na pasta bin. Para executá-lo a partir da pasta raíz do projeto, 
execute o comando './bin/FrogRace'.

## Códigos Avaliados
	Os passos 1, 2 e 6 estão localizados no arquivo dataManager.h.
	Os passos 3, 4, 5 estão localizados ni arquivo main.cpp.
	
## Passos 1, 2
	Linhas 76-79. Função que funciona para ambas classes Sapo e Corrida.

## Passos 3, 4 e 5
	Passo 3: Linhas 184-192 Descrevem a função que exibe o menu na tela. 
		 Linhas 204-233 Contém o loop lógico do menu principal.
	Passo 4: Linhas 152-168 Descrevem a função que retorna a escolha da corrida.
	Passo 5: Linhas 95-135 Descrevem a função que determina a lógica da corrida propriamente dita.

## Passo 6
	Criar o Sapo: Linhas 128-137.
	Criar a Corrida: Linhas 146-163.	 
	Salvar Sapo\Corrida: Linhas 108-119.

