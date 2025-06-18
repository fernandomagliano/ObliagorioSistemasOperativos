with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Utils; use Utils;
with Cola_Pkg; use Cola_Pkg;

package body Caja_Pkg is
   task body Caja is
      Persona : Persona_ID;
   begin
    delay 5.0;
      loop
         Cola.Sacar (Persona);

         declare
            Txt : constant String := Persona_ID'Image (Persona);
         begin
            Put_Line ("Persona" & Txt (Txt'First + 1 .. Txt'Last) &
                     " ingresó a la caja " & Integer'Image (Numero));
         end;

         delay Random_Duration (5.0);

         declare
            Txt : constant String := Persona_ID'Image (Persona);
         begin
            Put_Line ("Persona" & Txt (Txt'First + 1 .. Txt'Last) &
                     " saliendo de la caja " & Integer'Image (Numero));
         end;
      end loop;
   end Caja;
end Caja_Pkg;
