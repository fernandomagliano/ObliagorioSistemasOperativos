FROM debian:bullseye

RUN apt update && \
    apt install -y rsync cron

COPY backup.sh /usr/local/bin/backup.sh
RUN chmod +x /usr/local/bin/backup.sh

RUN echo "*/2 * * * * root /usr/local/bin/backup.sh >> /var/log/backup.log 2>&1" > /etc/cron.d/backupcron && \
    chmod 0644 /etc/cron.d/backupcron && \
    crontab /etc/cron.d/backupcron

CMD ["cron", "-f"]
