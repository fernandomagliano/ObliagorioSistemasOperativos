FROM debian:bullseye

RUN apt-get update && apt-get install -y rsync openssh-client cron

COPY id_rsa /root/.ssh/id_rsa
COPY id_rsa.pub /root/.ssh/id_rsa.pub
COPY backup.sh /usr/local/bin/backup.sh

RUN chmod 600 /root/.ssh/id_rsa && \
    chmod +x /usr/local/bin/backup.sh && \
    mkdir -p /home/backups

# Agregar cronjob
RUN echo "*/2 * * * * root /usr/local/bin/backup.sh >> /var/log/backup.log 2>&1" > /etc/cron.d/backupcron && \
    echo "" >> /etc/cron.d/backupcron && \
    chmod 0644 /etc/cron.d/backupcron && \
    crontab /etc/cron.d/backupcron

CMD ["cron", "-f"]
