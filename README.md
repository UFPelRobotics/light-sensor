# Light Sensor

Algoritmo utilizado com sensor que está instalado no odômetro.
O código calcula o número de estágios percorridos pelo odômetro instalado na roda direita e envia o valor para o ROS.

## Sensor

A entrada digital 8 está setada para contagem da roda direita.

## Odômetro

O cálculo do odômetro é zerado em cada troca de estágio, assim, se é dado o comando de movimento para frente, o contador do odômetro inicia em zero, quando posto em neutro (parado), o contador volta para zero.

A ideia é manter o controle de movimento por estágios nos arduinos para então manter o controle geral do odômetro no ROS.

## ROS

O ROS utiliza o canal right_sensor para captura dos dados da roda direita.

Esse valor é zerado no arduino a cada troca de comando, como citado acima, o código do ROS que  recebe estes valores mantêm um contador geral para tomada de decisão e avaliação de LOG de execução.