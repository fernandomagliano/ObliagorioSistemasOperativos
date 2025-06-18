with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
package body Cola_Pkg is
   type Cola_Array is array (1 .. Max_Cola) of Persona_ID;

   task body Cola is
      Lista    : Cola_Array := (others => 0);
      Cantidad : Natural := 0;
   begin
      loop
         select
            when Cantidad < Max_Cola =>
               accept Agregar (Persona : Persona_ID) do
                  if Cantidad > 0 then
                     Put_Line ("Hay" & Integer'Image (Cantidad) &
                        " personas esperando en la cola...");
                  end if;

                  Cantidad := Cantidad + 1;
                  Lista (Cantidad) := Persona;

                  declare
                     Txt : constant String := Persona_ID'Image (Persona);
                  begin
                     Put_Line ("Usuario" & Txt (Txt'First + 1 .. Txt'Last) &
                        " entra a la cola de espera.");
                  end;
               end Agregar;

         or
            when Cantidad > 0 =>
               accept Sacar (Persona : out Persona_ID) do
                  Persona := Lista (1);
                  for I in 1 .. Max_Cola - 1 loop
                     Lista (I) := Lista (I + 1);
                  end loop;
                  Lista (Max_Cola) := 0;
                  Cantidad := Cantidad - 1;

                  declare
                     Txt : constant String := Persona_ID'Image (Persona);
                  begin
                     Put_Line ("Usuario" & Txt (Txt'First + 1 .. Txt'Last) &
                        " sale de la cola de espera.");
                  end;
               end Sacar;

         or
            accept Esta_Llena (Lleno : out Boolean) do
               Lleno := Cantidad = Max_Cola;
            end Esta_Llena;

         or
            terminate;
         end select;
      end loop;
   end Cola;
end Cola_Pkg;
