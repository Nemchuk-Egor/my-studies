
# Заглушка на Spring Boot

На Spring Boot, которая обрабатывает HTTP-запросы по двум эндпоинтам: `/message` и `/client`.

## Эндпоинты

### 1. GET /message

- **Описание**: Возвращает JSON с рандомным 6-значным числом в формате `{"id": "168 159"}`.
- **Пример ответа**:
    ```json
    {
        "id": "123 456"
    }
    ```

### 2. POST /client

- **Описание**: Принимает JSON с информацией о клиенте и возвращает подтверждение.
- **Формат входящего JSON**:
    ```json
    {
        "id": "168 159",
        "data": {
            "name": "Vasilii",
            "orgId": "JK0001"
        }
    }
    ```
- **Пример ответа**:
    ```json
    {
        "OK": true,
        "orgId": "JK0001"
    }
    ```

## Запуск

### 1. Запуск проекта
- Перейдите в каталог проекта где находится файл dockerfile и выполните две команды

```
    docker build -t spring-boot-stub .
```

```
    docker run -p 8080:8080 spring-boot-stub
```


