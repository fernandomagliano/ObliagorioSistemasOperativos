FROM debian:bullseye-slim

RUN mkdir -p /home/users/documentos && \
    echo "Archivo sin alarma" > /home/users/documentos/archivo1.txt && \
    echo "Alarma detectada en el sistema" > /home/users/documentos/archivo2.txt

CMD tail -f /dev/null
