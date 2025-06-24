#!/bin/bash

echo "[BACKUP] Ejecutando backup: $(date)"

for maquina in maquina1 maquina2 maquina3; do
  origen="/mnt/$maquina/"
  destino="/home/backups/$maquina"

  mkdir -p "$destino"
  rsync -av "$origen" "$destino"

done
