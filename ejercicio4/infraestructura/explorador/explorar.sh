#!/bin/bash

output="/home/alertas_detectadas/alertas.log"
fecha=$(date '+%Y-%m-%d')
hora=$(date '+%H:%M:%S')

for file in $(find /mnt/backups -type f); do
  if grep -q "Alarma" "$file"; then
    total=$(wc -w < "$file")
    termina_a=$(grep -oE '\b\w*a\b' "$file" | wc -l)
    echo "$fecha $hora | $file | Palabras: $total | Terminan en a: $termina_a" >> "$output"
  fi
done
