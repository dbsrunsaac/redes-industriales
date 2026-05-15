Docente: Ing. Miguel Angel Chillitupa Carrasco
Alumno: Davis Bremdow Salazar Roa - 200353
## Introducción al protocolo RS232

El protocolo RS232 (Recommended Standard 232), también conocido como EIA232, es uno de los estándares más utilizados para la comunicación serial entre dispositivos electrónicos y ordenadores. Su principal objetivo es permitir el intercambio de datos entre un equipo terminal de datos (DTE), como un ordenador, y otros dispositivos electrónicos como microcontroladores, módems o sistemas embebidos.

La comunicación RS232 es de tipo serial asíncrona, lo que significa que los datos se transmiten bit a bit a través de una sola línea y sin necesidad de una señal de reloj compartida entre transmisor y receptor.

En los ordenadores, los puertos RS232 suelen identificarse como COM1, COM2, etc., y utilizan normalmente conectores DB9 o DB25.

---

# Conectores y señales principales

El estándar RS232 define conectores DB9 y DB25. Para aplicaciones con microcontroladores generalmente se emplea el conector DB9.

## Pines principales del DB9

| Pin | Señal | Función |
|------|--------|----------|
| 2 | RxD | Recepción de datos |
| 3 | TxD | Transmisión de datos |
| 5 | SG | Tierra o referencia común |

Para establecer una comunicación básica entre un ordenador y un microcontrolador solamente son necesarias tres líneas:

- TxD (Transmit Data)
- RxD (Receive Data)
- GND o SG (Signal Ground)

---

# Velocidad de transmisión (Baudios)

La velocidad de transmisión en RS232 se mide en baudios (Baud), que representan la cantidad de bits transmitidos por segundo.

Las velocidades normalizadas más comunes son:

- 300 baudios
- 1200 baudios
- 2400 baudios
- 4800 baudios
- 9600 baudios

En muchos sistemas con microcontroladores se utiliza 9600 baudios debido a su simplicidad y estabilidad.

La duración temporal de cada bit depende de la velocidad seleccionada. Por ejemplo:

## Cálculo del tiempo de un bit a 9600 baudios

Cada bit permanece aproximadamente 104 microsegundos en la línea.

---

# Niveles de voltaje en RS232

Una de las características más importantes del protocolo RS232 es que utiliza niveles de tensión distintos a los niveles TTL de los microcontroladores.

## Lógica negativa

RS232 trabaja con lógica negativa:

| Nivel lógico | Voltaje RS232 |
| ------------ | ------------- |
| 0 lógico     | +3 V a +15 V  |
| 1 lógico     | -3 V a -15 V  |

Los valores más utilizados son:

- +12 V para el bit lógico 0
- -12 V para el bit lógico 1

---

# Región de transición

Existe una zona indefinida entre:

- +3 V
- -3 V

En esta región los niveles no son reconocidos de forma confiable y pueden interpretarse ambiguamente.

---

# Trama de datos RS232

La información transmitida en RS232 se organiza mediante una trama de datos compuesta por varias partes.

## Estructura general de la trama

| Elemento       | Función                      |
| -------------- | ---------------------------- |
| Bit Start      | Indica inicio de transmisión |
| Bits de datos  | Contienen la información     |
| Bit de paridad | Detección de errores         |
| Bits Stop      | Indican final de transmisión |

---

# 1. Bit de inicio (Start)

La transmisión comienza con un bit de inicio.

Características:

- La línea cambia de -12 V a +12 V
- Representa un cambio de 1 lógico a 0 lógico
- Permite al receptor sincronizarse

Duración:

- 1 bit

---

# 2. Bits de datos

Después del Start se transmiten los datos.

Características:

- Generalmente 7 u 8 bits
- Se transmite primero el LSB (Least Significant Bit)
- El MSB (Most Significant Bit) se transmite al final

Ejemplo:

Si se transmite la letra ASCII “V”:

```text
ASCII = 1010110