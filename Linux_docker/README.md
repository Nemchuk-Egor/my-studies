# Введение в Docker

## В ходе выполнения этого проекта я научился:

 - Использовать базовый Docker образ с nginx.
 - Осуществлять операции с Docker контейнерами, включая экспорт, импорт и обновление конфигураций.
 - Создавать и настраивать мини-сервер на C с использованием FastCGI.
 - Создавать и тестировать собственные Docker образы.
 - Проверять безопасность Docker образов с помощью инструмента Dockle.
 - Использовать Docker Compose.

## Содержание

- [Технологии](#технологии)
- [Начало работы](#начало-работы)
- [Команда проекта](#команда-проекта)
- [Источники](#Источники)
- [FAQ](#FAQ)


## Технологии
- C11 (Си)
- Docker и Docker compose
- Сервер nginx
- Утилиты FastCGI и swap-fcgi

## Начало работы

В этом проекте создается мини веб-сервер с использованием Docker и nginx. Сборка и запуск образов осуществляется с помощью Docker и Docker Compose.
При обращение к localhost возвращает hello world!

### Требования

Для установки и запуска проекта необходимы:

1. Docker
2. Docker Compose

### Создание образа через Dockerfile

Чтобы выполнить сборку образа:
1. зайдите в директорию src 
2. выполните команду:

```sh
$ sudo docker build -t [Название образа] .
```

## Запуск контейнера через Dockerfile


```sh
$ sudo docker run --name [Название контейнера] -d -p 80:81 [Название образа]
```

## Запуск контейнеров через Docker Compose

```sh
$ sudo docker compose build
$ sudo docker compose up
```

## Команда проекта

    Егор Немчук - Студент школы 21

## Источники

#### [Статья на Habr:](https://habr.com/ru/companies/flant/articles/336654/)

#### [Официальный сайт Docker:](docs.docker.com/)

### FAQ

<div id="header" align="left">
  <img src="https://i.giphy.com/media/v1.Y2lkPTc5MGI3NjExbWVuMWR0MWV1NnAwN3ZmNGwzOXg1eXJkYTVlbTc2YWljZjZ4NDAzZyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/xT5LMsC6iydeziO6nC/giphy.gif" height="300"/>
</div>
