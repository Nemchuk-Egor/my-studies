package com.example.demo;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(urlPatterns = "/calculator")
public class CalculatorServlet extends HttpServlet {
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("application/json;charset=utf-8");
        request.setCharacterEncoding("UTF-8");
        PrintWriter pw = response.getWriter();

        // Чтение JSON-запроса
        StringBuilder jb = new StringBuilder();
        String line;
        try (BufferedReader reader = request.getReader()) {
            while ((line = reader.readLine()) != null) {
                jb.append(line);
            }
        } catch (IOException e) {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            pw.print("{\"error\": \"Ошибка чтения JSON\"}");
            return;
        }

        // Парсинг JSON
        JsonObject jobj = gson.fromJson(jb.toString(), JsonObject.class);
        if (jobj.has("a") && jobj.has("b") && jobj.has("math")) {
            try {
                double a = jobj.get("a").getAsDouble();
                double b = jobj.get("b").getAsDouble();
                String math = jobj.get("math").getAsString();

                double result = 0;
                switch (math) {
                    case "+":
                        result = a + b;
                        break;
                    case "-":
                        result = a - b;
                        break;
                    case "*":
                        result = a * b;
                        break;
                    case "/":
                        if (b == 0) {
                            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
                            pw.print("{\"error\": \"Деление на ноль недопустимо\"}");
                            return;
                        }
                        result = a / b;
                        break;
                    default:
                        response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
                        pw.print("{\"error\": \"Неверная операция. Поддерживаются только +, -, *, /\"}");
                        return;
                }

                // Формирование ответа
                JsonObject responseJson = new JsonObject();
                responseJson.addProperty("result", result);
                pw.print(gson.toJson(responseJson));

            } catch (Exception e) {
                response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
                pw.print("{\"error\": \"Ошибка обработки данных\"}");
            }
        } else {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            pw.print("{\"error\": \"Неверные параметры запроса\"}");
        }
    }
}
