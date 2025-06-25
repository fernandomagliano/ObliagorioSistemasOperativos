FROM debian:bullseye-slim

RUN apt-get update && \
    apt-get install -y openssh-server rsync

RUN mkdir -p /home/users/documentos && \
    echo "Archivo sin alarma" > /home/users/documentos/archivo1.txt && \
    echo "Alarma detectada" > /home/users/documentos/archivo2.txt

RUN mkdir -p /root/.ssh
COPY authorized_keys /root/.ssh/authorized_keys
RUN chmod 600 /root/.ssh/authorized_keys

RUN mkdir -p /run/sshd

EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
