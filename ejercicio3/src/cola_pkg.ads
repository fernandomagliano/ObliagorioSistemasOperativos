package Cola_Pkg is
   Max_Cola  : constant := 10;
   type Persona_ID is new Integer;

   task Cola is
      entry Agregar (Persona : Persona_ID);
      entry Sacar (Persona : out Persona_ID);
      entry Esta_Llena (Lleno : out Boolean);
   end Cola;
end Cola_Pkg;
