# [cube-raid](https://github.com/cirocosta/cube-raid/)

> Um River-raid, 3D, em C e com **monstros** ಠ_ಠ! Projeto para a discplina Laboratório de Programação 1 (IME-USP)

## Quickstart

Para inicializar o programa e partir para a diversão, execute em sua linha de comando:

```sh
$ make
```
e então o mesmo inicializará.

Tal comando irá construir o jogo e abrir o mesmo em seguida. Tal comando só precisa ser executado na primeira vez, nas outras basta executar `./main.out` e então mosnters-raid será inicializado.

## Comandos

O jogo todo se concentra em: fugir dos elementos jogados pelos objetos de defesa e sobreviver o máximo que puder.
Controle sua nave e o jogo seguindo a tabela a seguir:

|     key      |             desc            |
| ------------ | --------------------------- |
| `w`          | vai para cima               |
| `s`          | vai para baixo              |
| `a`          | vai para esquerda           |
| `d`          | vai para direita            |
| `F1`         | coloca o jogo em tela cheia |
| `q` ou `esc` | fecha o jogo                |

## Testando

Para executar os testes, execute o seguinte comando:

```sh
$ make test
```

o qual irá iniciar a suite de testes - descritos em `./test`.


## Dificuldades/problemas

Segue uma pequena descrição de alguns problemas encontrados para cada fase do projeto

### Primeira entrega

Várias foram as questões, entretanto, que se levantaram ao longo do desenvolvimento: *qual a melhor forma de organizarmos os dados relativos aos mapas? estamos generalizando demais? convenções: quais iremos adotar? como tratar os casos de referência circular?*

Adotamos então o sistema de [Issues](https://github.com/cirocosta/cube-raid/issues) do github para fazermos um *track* de decisões a serem tomadas e questões levantadas.

#### Problemas

- Memory Leak no uso de método construtor de objetos
- Incerteza quanto ao tipo de representação dos mapas

### Segunda entrega

Neste momento do projeto a grande dificuldade foi:

-	como tratar, de modo síncrono, algo de natureza assíncrona (recebimento dos inputs do teclado de maneira non-blocking) ? Chegamos a uma solução parciável porém não satisfatória. Esparamos melhorar (muito) com o `glutKeyboardFunc` na próxima fase :neckbeard: ;
-	qual a maneira mais eficiente de se definir um campo de visão e de fato mostrar apenas o que é visto, guardando-se referência ao que pode vir a ser visto de novo?
-	como verificar as colisões para os diversos objetos apresentados em um trecho do mapa?

Esperamos entao responder tais questões na próxima etapa quando de fato tivermos algo visual.

#### Problemas

Não conseguimos:

-	[x] Implementar corretamente a exibição dos elementos dado um campo de visão (conseguimos na terceira!)
-	[x] Limpar todos os memory leaks (conseguimos no começo da terceira!)
-	[x] De maneira eficiente e satisfatória captar o input em tempo real do teclado ((conseguimos na terceira!)

### Terceira Entrega

Muitas dúvidas quanto ao modo de programar com OpenGL. Como o modo de se pensar é totalmente diferente foi uma grande dificuldade entrar no mindset necessário. Esta foi primeira grande curva de aprendizado.

Em seguida tivemos grande dificuldade em adaptar o que já haviamos feito até então. Como nenhum dos dois havia previamente programado algo com OpenGL percebemos que estavamos utilizando uma grande quantidade de estruturas de forma errônea e que o que pensávamos como um padrão perfeito não era tão perfeito assim.

Percebemos o quão não-trivial ficou para testar o que estava sendo feito: como faríamos testes funcionais com o que estava sendo desenhado sendo que não temos, de modo razoável, simular um usuário? Decidimos então por não implementar os testes nessa fase a manter aqueles unitários feitos anteriormente (de modo a checar se o core de nossas estruturas estava de fato correta e poderíamos então prosseguir com elas - sem nos deixar na mão).

Poderíamos melhorar muito nesta etapa: implementar padrões de projeto mais bem consolidados (observer, command, service-locator, entre outros) porém mais tempo seria necessário (muitas provas comeram o tempo :cry: ).

Esta foi sem dúvidas a mais divertida das entregas já que tinhamos então algo de fato pronto para brincar :neckbeard:

#### Problemas

-	[ ] Adicionar texturas para as fontes e a todo o cenário (não tivemos tempo  :/ )
- [ ] Limpar todos os memory leaks (conseguimos no começo desta fase porém abandonamos a checagem durante a parte de desenho do jogo. Deveríamos ter investido nisso porém foi um tradeoff)
-	[	] Mais fases (isto seria animal!)
-	[ ] Transparência, reflexo, sombras .... :P

## Estrutura

Sua estrutura de pastas é muito simples e alinha-se com o design pattern MVC:

```
.
├── src         // código principal do programa
│   ├── lib     // bibliotecas internas desenvolvidas
│   ├── maps    // arquivos de configuração dos mapas
│   └── models  // modelos dos dados / lógica de negócio associada a eles
└── test        // arquivos de testes a serem executados
```


## Grupo

O grupo é composto por dois integrantes:

| ![Ciro Costa](https://avatars1.githubusercontent.com/u/3574444?s=100) | ![Rodrigo Alves](https://avatars2.githubusercontent.com/u/337906?s=100) |
| --------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| [Ciro S. Costa](https://github.com/cirocosta)                         | [Rodrigo Alves](https://github.com/rasouza)                             |

## Discussões/etc

[cube-raid Issues](https://github.com/cirocosta/cube-raid/issues?state=open)
