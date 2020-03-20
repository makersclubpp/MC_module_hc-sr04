#include <mc_module_hcsr04.hpp>

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