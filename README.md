# Light Sensor

Algoritmo utilizado com sensor que está instalado no odômetro.
O código calcula o número de estágios percorridos pelo odômetro instalado na roda direita e envia o valor para o ROS.

## Sensor

A entrada digital 12 está setada para contagem da roda direita.

## Odômetro

O cálculo do odômetro é feito pela leitura do sensor e publicado no ROS, o cálculo é feito ininterruptamente.

## ROS

O ROS utiliza o canal right_sensor para captura dos dados da roda direita.
