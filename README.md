# Light Sensor

Algoritmo utilizado com sensor que está instalado no odômetro.
O código calcula o número de estágios percorridos pelo odômetro instalado na roda direita e envia o valor para o ROS.

## Sensor

A entrada digital 2 está setada para contagem da roda direita.
A entrada digital 3 está setada para contagem da roda esquerda.
Os valores são captados utilizando interrupção para as duas rodas.

## Odômetro

O cálculo do odômetro é feito pela leitura do sensor e publicado no ROS, o envio é feito após cada ciclo de leitura.
Um ciclo de leitura é mensurado por 4 ciclos do odômetro, e é enviado após cada 10 iterações do ciclo de leitura.

A roda possui diâmetro de 34 cm, e o odômetro possui 1200 ciclos para uma volta completa. Assim, com 1200 ciclos do odômetro andamos aproximadamente um metro, ((1200/1200)*3.14*0.34).

Reduzimos o número de ciclos para 300 por volta. Assim, para andar um metro o cálculo fica ((300/300)*3,14*0,34). O sensor publica no ROS a cada 10 ciclos contados, obtendo então o menor movimento obtido no ROS de 03 cm.

## ROS

O ROS utiliza o canal right_sensor para captura dos dados da roda direita e left_sensor para captura dos dados da roda esquerda.
