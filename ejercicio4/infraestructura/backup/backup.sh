#!/bin/bash

echo "[BACKUP] Ejecutando backup con RSA: $(date)"

for i in 1 2 3; do
  origen="root@maquina$i:/home/users/documentos/"
  destino="/home/backups/maquina$i"

  mkdir -p "$destino"
  rsync -av -e "ssh -i /root/.ssh/id_rsa -o StrictHostKeyChecking=no" "$origen" "$destino"
done
