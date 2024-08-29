FROM nginx:1.19.7



RUN apt-get update && apt-get install -y \
    spawn-fcgi \
    libfcgi-dev \
    gcc && rm -rf /var/lib/apt/lists/* \
    && touch /var/run/nginx.pid \
    && chown -R nginx:nginx /var/run/nginx.pid \
    && chown -R nginx:nginx /etc/nginx/nginx.conf \
    && chown -R nginx:nginx /var/cache/nginx \
    && chown -R nginx:nginx /home \
    && chmod u-s /usr/bin/gpasswd \
    && chmod u-s /usr/bin/newgrp \
    && chmod u-s /bin/su \
    && chmod u-s /bin/mount \
    && chmod u-s /bin/umount \
    && chmod u-s /usr/bin/chsh \
    && chmod u-s /usr/bin/chfn \
    && chmod g-s /usr/bin/expiry \
    && chmod g-s /usr/bin/wall \
    && chmod g-s /sbin/unix_chkpwd \
    && chmod g-s /usr/bin/chage \
    && chmod u-s /usr/bin/passwd

COPY server/hello.c /server/hello.c
RUN gcc -o /server/hello /server/hello.c -lfcgi


USER nginx


COPY server/nginx/nginx.conf /etc/nginx/nginx.conf


HEALTHCHECK --interval=30s --timeout=3s CMD curl -f http://localhost/ || exit 1

CMD ["sh", "-c", "spawn-fcgi -p 8080 /server/hello && nginx -g 'daemon off;'"]
