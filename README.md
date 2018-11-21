# Light Sensor

Algoritmo utilizado com sensor que está instalado no odômetro.
O código calcula o número de estágios percorridos pelo odômetro instalado na roda direita e envia o valor para o ROS.

## Controles

A entrada digital 2 está setada para  contagem da roda direita.

## ROS

O ROS utiliza o canal right_sensor para captura dos dados da roda direita.