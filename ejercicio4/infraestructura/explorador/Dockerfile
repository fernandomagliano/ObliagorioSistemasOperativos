FROM debian:bullseye

RUN apt update && \
    apt install -y cron apache2

COPY explorar.sh /usr/local/bin/explorar.sh
RUN chmod +x /usr/local/bin/explorar.sh

RUN mkdir -p /home/alertas_detectadas

RUN echo "* * * * * root /usr/local/bin/explorar.sh >> /var/log/explorador.log 2>&1" > /etc/cron.d/exploradorcron && \
    chmod 0644 /etc/cron.d/exploradorcron && \
    crontab /etc/cron.d/exploradorcron

RUN ln -s /home/alertas_detectadas/alertas.log /var/www/html/alertas.log

CMD bash -c "cron && apachectl -D FOREGROUND"
