# [Monsters Raid](https://github.com/cirocosta/monsters-raid/)

> Um River-Raid, 3D, em C e com **monstros** ಠ_ಠ! Projeto para a discplina Laboratório de Programação 1


## Quickstart

Para inicializar o programa e partir para a diversão, execute em sua linha de comando:

```sh
$ make && ./main.out
```

e então o mesmo inicializará.

Para sair do laço principal de execução basta pressional `ESC`.


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

Adotamos então o sistema de [Issues](https://github.com/cirocosta/monsters-raid/issues) do github para fazermos um *track* de decisões a serem tomadas e questões levantadas.

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

-	Implementar corretamente a exibição dos elementos dado um campo de visão
-	Limpar todos os memory leaks :(
-	De maneira eficiente e satisfatória captar o input em tempo real do teclado


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

| ![Ciro Costa](https://avatars1.githubusercontent.com/u/3574444?s=100) | ![Rodrigo Alves](https://avatars2.githubusercontent.com/u/337906?s=100) |
| --------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| [Ciro S. Costa](https://github.com/cirocosta)                         | [Rodrigo Alves](https://github.com/rasouza)                             |


## Discussões/etc

https://github.com/cirocosta/monsters-raid/

