with Ada.Numerics.Discrete_Random;

package Utils is
   subtype Rango_Entero is Integer range 1 .. 100;
   package Rand is new Ada.Numerics.Discrete_Random (Rango_Entero);
   Gen : Rand.Generator;

   function Random_Duration (Max : Float) return Duration;
end Utils;
