with Utils;

package body Utils is
   function Random_Duration (Max : Float) return Duration is
      R : constant Rango_Entero := Rand.Random (Gen);
   begin
      return Duration (Float (R) / 100.0 * Max);
   end Random_Duration;
end Utils;
