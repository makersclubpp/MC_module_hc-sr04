![Volver](https://github.com/makersclubpp/MC_Indice/blob/master/img/BackIcon.png) [Volver](https://github.com/makersclubpp/MC_Indice)

# ![LOGO](https://github.com/makersclubpp/MC_Indice/blob/master/img/LOGO_makers_64x64.png) Makers Club ![LOGO](https://github.com/makersclubpp/MC_Indice/blob/master/img/LOGO_makers_64x64.png)
## Módulo sensor ultrasonico HC-SR04


### Descripción
Lo más singular del sensor de ultrasonidos HC-SR04 es quizás su "par de ojos", estos no son más que un emisor y un receptor de ultrasonidos que trabajan a una frecuencia de 40KHz (una frecuencia inaudible para las personas).

![Sensor ultrasónico HC-SR04](https://github.com/makersclubpp/MC_module_hc-sr04/blob/master/img/HCSR04.jpg)

Este sensor consta de 4 pines, alimentación (Vcc), un disparador (Trig), el receptor (Echo) y masa (GND). Para el correcto funcionamiento del sensor es necesario el conectar estos 4 pines.

Las características básicas de este sensor y que se deben de tener en cuenta al trabajar con él son:

| Característica        | Valor           |
| --- | :---: |
| Alimentación          | +5V DC          |
| Frecuencia de trabajo | 40kHz           |
| Consumo (Stand-By)    | <2mA            |
| Consumo (Power ON)    | 15mA            |
| Águnlo efectivo       | 15°             |
| Distancia             | de 2cm a 400cm* |
| Resolución            | 0,3 cm          |

*A partir de 250cm la resolución no es buena


### Como funciona

El principio en el que se basa su funcionamiento es muy sencillo, tan solo hay que generar una onda sónica en el emisor mediante un pulso en la patilla que pone "trig" (trigger o disparador), esta onda al encontrarse con algún obstáculo rebotará, volviendo al sensor y siendo registrada por el receptor, traduciéndose esta en un pulso en la patilla "Echo".

Esquema onda

Con esto podemos hacer dos cosas, detectar un obstáculo esperando simplemente que Arduino reciba un "Echo" o contar el tiempo que transcurre desde que se manda el pulso por el trigger hasta que se recibe, de esta forma, y conociendo cual es la velocidad del sonido, podemos determinar de forma muy sencilla la distancia exacta a la que se encuentra el objeto en el que esta rebotando la señal.

Para aclarar un poco el factor de multiplicación que vamos a introducir en Arduino, basta con decir que la velocidad es igual al espacio dividido por el tiempo que se tarda en recorrer dicho espacio. La velocidad del sonido es conocida (343,2 m/s) y el tiempo lo vamos a determinar, como el tiempo que transcurre desde que efectuamos el disparo hasta que recibimos el eco.

---
Tener en cuenta que este tiempo será doble, ya que la onda hace el camino de ida y el de regreso.

---

Aquí tenéis un pequeño resumen del cálculo que hay que hacer:
                 
velocidad (del sonido) = espacio / tiempo

velocidad del sonido en el aire = 343,2 m/s = 0,03432 cm/µs

espacio = velocidad * tiempo = 0,03432 * tiempo

Pero como la onda ha recorrido el camino dos veces (ida y vuelta) hay quye dividir entre dos para conocer la distancia a la que se encuentra el objeto. Además, si hacemos la inversa de esa velocidad nos da un valor que que facilita los cálculos en programación.


### Ejemplo de uso
#### Conexiones

![Sensor ultrasónico HC-SR04](https://github.com/makersclubpp/MC_module_hc-sr04/blob/master/img/HCSR04.svg)

#### Código

```Arduino
#include "mc_module_hcsr04.hpp"

MC_M_HCSR04 ultrasonido(3, 2);

void setup() {
  Serial.begin(9600); 
}

void loop()
{
  Serial.print(ultrasonido.getDistance());
  Serial.println(" cm" );
  delay(100);
}
```