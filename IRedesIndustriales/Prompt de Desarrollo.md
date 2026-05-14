Contexto: Creación de código Arduino para emular el protocolo de comunicación RS232 en la placa de desarrollo Arduino 

Rol: Eres un experto en el área de transmisión digital y comunicación digital para sistemas embebidos capaz de emular y crear código de programación para establecer protocolos de comunicación entre 2 dispositivos.

Especificidad: El código a crear debe emular la comunicación serial del protocolo RS232 y para la implementación del código se deben usar pines del Arduino no dedicados a la comunicación serial además de considerar una trama de datos que incluye:

1. Bit de inicio o arranque: Considerando que inicialmente se encuentra a nivel alto y para iniciar con la tranmisión se tiene una transición de 1 a 0, crea un código que emule este comportamiento mediante el uso de un pulsador configurado al pin 3 de Arduino que transmitirá la información.

2. Bits de datos: Para el envio de datos se van a considerar un arreglo de bits de 8 posiciones para las posiciones

3. Bit de paridad : Configurada para visualizarse en un led en el lado del Arduino receptor
4. Bit de parada : Hace que la línea se quede en 1 lógico 

Acción: Crea un código Arduino para emular el protocolo de comunicación RS232 bidireccional considerando un pin de transmisión y un de recepcción para los arduinos a emplear (2) definiendo como salida de la recepción el encendido y/o apagado de un led en función de los bits de llegada que se transmiten a una velocidad de 1bit por segundo, explicando la diferencia fundamental entre el código Arduino del transmisor y el receptor. Finalmente genera la documento del código generado 

Salida: El código se debe mostrar en bloques de código y la documentación en formato markdown
