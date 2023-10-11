FROM node:12

WORKDIR /usr/app/

COPY . .

RUN yarn

RUN yarn make

RUN yarn build



FROM node:12.18.3-alpine3.12

WORKDIR /usr/app/

COPY . .

RUN addgroup -S appgroup && \
    adduser -S appuser appgroup && \
    chown -R appuser:appgroup /usr/app

USER appuser

EXPOSE 3000

CMD ["yarn", "start"]
