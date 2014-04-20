## Nave


## Cenário

### Estrutura

Para representarmos cenário devemos primeiramente pensar em Mapas.

**Mapas**, no nosso caso mais simples, são pré-determinados e contidos em uma lista ligada.

**Cenário** é o consumo atual do mapa.

### Atualizacao do Cenário

À medida que a nave navega pelo mapa há o consumo do mesmo. Precisamos então, para cada iteração sobre a Lista, realizar os cálculos quanto às interações ocorridas no instante e, por fim, renderizar esses elementos na tela.

#### Velocidade da Nave

A velocidade da nave é um fator determinante quanto à atualização do cenário.

Como o cenário pode ser entendido como o que está sendo consumido no momento pelo buffer circular, podemos então inferir que a velocidade com a qual a nave circula deve ser diretamente relacionada à velocidade com a qual o buffer consome tal mapa.

Podemos então pensar em algo como:

```c
void consome_LL(float *velocidade, LL *mapa)
{
    while (!EOF mapa) {
        sleep(velocidade) // sendo velocidade um ponteiro, pode-se alterar
                          // valor do mesmo em tempo real e ir alterando a
                          // velocidade do sleep.
        atualiza_cenario(mapa_consumido)
    }
}
```
