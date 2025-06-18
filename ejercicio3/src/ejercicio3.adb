with Ada.Text_IO;         use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Utils;               use Utils;
with Cola_Pkg;            use Cola_Pkg;
with Caja_Pkg;            use Caja_Pkg;

procedure Ejercicio3 is
   Total_Personas : Integer;
   Ultimo_ID      : Persona_ID := 0;

   C1 : Caja (1);
   C2 : Caja (2);
   C3 : Caja (3);
   C4 : Caja (4);
begin
   Rand.Reset (Gen);

   Put ("Ingrese la cantidad de personas a crear: ");
   Get (Total_Personas);

   declare
      Contador : Integer := 0;
   begin
      while Contador < Total_Personas loop
         Ultimo_ID := Ultimo_ID + 1;

         declare
            Lleno : Boolean := False;
         begin
            Cola.Esta_Llena (Lleno);
            if not Lleno then
               Cola.Agregar (Ultimo_ID);
               Contador := Contador + 1;
               delay 0.3;
            else
               Put_Line ("Cola de espera llena, no se permiten más personas por ahora.");
               Ultimo_ID := Ultimo_ID - 1;
               delay Random_Duration (3.0);
            end if;
         end;
      end loop;

      delay 30.0;
      Put_Line ("Fin del sistema.");
   end;
end Ejercicio3;