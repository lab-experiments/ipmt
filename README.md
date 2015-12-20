# ipmt 

Programa desenvolvido em C++, similar ao [Grep-GNU](https://www.gnu.org/software/grep/) para busca de padrões em texto usando indexação(casamento offline exato) e compressão;

Estrutura principal do projeto:

```
ipmt/
 +-- doc/
 +-- src/
 +-- README
 +-- LICENSE
 ```

 doc -  relatório com testes de desempenho;
 
 src - arquivos .h e .cpp


## Guia de Execução

####Criar um executável

- clone ou baixe esse o projeto em seu computador

- extraia o arquivo baixado ou acessse a pasta a qual o projeto foi clonado. Navegue até o diretório **ipmt/src/** ou **ipmt-master/src/**

- abra seu terminal(Shell) e execute execute o comando **cd** afim de chegar até o diretório **ipmt/src/** ou **ipmt-master/src/**

- estando no diretório **ipmt/src/** ou **ipmt-master/src/** na linha de comando em seu terminal execute o comando ***make***

Após realizar os passos indicados acima, será criada uma pasta **bin/** no diretório **ipmt** contendo os arquivos **.o** e o executável do programa.

Exemplo da estrutura gerada:
```
ipmt/
 +-- bin/ <--- executável
     +--obj/
 +-- doc/
 +-- src/
 +-- README
 +-- LICENSE
 ```

####Executar o programa

- após a execução dos passos [Criar um executável](https://github.com/lab-experiments/ipmt/#criar-um-executável), acesse via terminal o diretório onde seu executável se encontra - **ipmt/bin/** ou **ipmt-master/bin/**- execute o comando ***./ipmt -h*** ou ***./ipmt --help*** para fins de compreensão dos parâmetros de entrada do programa.

- para realizar um busca é necessário que os arquivos  de texto e/ou padrões estajam no mesmo diretório do arquivo executável do programa(**ipmt/bin/** ou ou **ipmt-master/bin/**) ou que seja passado como parâmetro o caminho absoluto;


## Comandos

####Modo Indexação

```
$ ipmt index [options] textfile [textfile...]

```
-  ***textfile***: arquivo(s) com extensão .txt, podendo ser um ou vários. Os arquivos podem ser lidos via [wildcard](https://www.gnu.org/software/make/manual/html_node/Wildcard-Examples.html) ex: nome*.txt. 

- ***[option]***:
  - ***--compression LZ78***: a compressão dos arquivos de indexes passarão a serem realizados atravéz do algoritmo. Mais informações na seção de referências.

####Busca Padrão

```
$ ipmt search pattern [options] indexfile [indexfile...]

```

-  ***pattern***: uma string com o padrão para busca no texto.

-  ***indexfile***: arquivo(s) com extensão .idx, podendo ser um ou vários. Os arquivos podem ser lidos via [wildcard](https://www.gnu.org/software/make/manual/html_node/Wildcard-Examples.html) ex: nome*.idx. 

:warning: - Arquivos serão lidos pela ordem de inserção.


```
$ ipmt -pattern patternfile indexfile [indexfile...]

    ou

$ ipmt -p patternfile indexfile [indexfile...]
```
-   ***-p**, ***--pattern***: opção de argumento para padrão via arquivo de texto

-   ***patternfile***: arquivo de texto com extensão .txt, podendo conter um ou mais padrões por linha.
Para mais de um arquivo de texto para busca e mais de um padrão de texto, cada padrão(linha do arquivo), será executada uma busca em todos os textos.

-  ***indexfile***: arquivo(s) com extensão .idx, podendo ser um ou vários. Os arquivos podem ser lidos via [wildcard](https://www.gnu.org/software/make/manual/html_node/Wildcard-Examples.html) ex: nome*.idx. (Obs.Arquivos serão lidos pela ordem de inserção.)


```
$ipmt --help
    ou
$ipmt -h
```
- ***-h, --help***: obter informações sobre os parâmetros utilizados e as sintaxes de comando.



##Algoritmos utilizados:

:construction:

[D. Gusfielld. Linear-Time Construction of Suffix Trees. Cambrige, University Press, New York, NY, USA, 1997.](http://web.stanford.edu/~mjkay/gusfield.pdf)

[ZIV, Jacob, LEMPEL, Abraham; A Universal Algorithm for Sequential Data Compression, IEEE Transactions on Information Theory, 23(3), pp. 337–343, maio de 1977.](http://www.cs.duke.edu/courses/spring03/cps296.5/papers/ziv_lempel_1977_universal_algorithm.pdf)

[ZIV, Jacob, LEMPEL, Abraham; Compression of Individual Sequences Via Variable-Rate Coding, IEEE Transactions on Information Theory, September 1978.](http://www.cs.duke.edu/courses/spring03/cps296.5/papers/ziv_lempel_1978_variable-rate.pdf)


Desenvolvida por @thaisamirely :raising_hand:
