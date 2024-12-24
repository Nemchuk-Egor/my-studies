package com.example.demo;

import com.example.demo.logic.Model;
import com.example.demo.logic.User;
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


@WebServlet(urlPatterns = "/update")
public class ServletUpdate extends HttpServlet {
    Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    @Override
    protected void doPut(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("application/json;charset=utf-8");
        request.setCharacterEncoding("UTF-8");
        PrintWriter pw = response.getWriter();

        // Чтение JSON запроса
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
        if (jobj.has("id") && jobj.has("name") && jobj.has("surname") && jobj.has("salary")) {
            int id = jobj.get("id").getAsInt();
            String name = jobj.get("name").getAsString();
            String surname = jobj.get("surname").getAsString();
            double salary = jobj.get("salary").getAsDouble();

            if (model.getFrontList().containsKey(id)) {
                User user = model.getFrontList().get(id);
                user.setName(name);
                user.setSurname(surname);
                user.setSalary(salary);
                response.setStatus(HttpServletResponse.SC_OK);
                pw.print("{\"message\": \"Пользователь с ID " + id + " успешно обновлен\"}");
            } else {
                response.setStatus(HttpServletResponse.SC_NOT_FOUND);
                pw.print("{\"error\": \"Пользователь с ID " + id + " не найден\"}");
            }
        } else {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            pw.print("{\"error\": \"Неверные данные в запросе\"}");
        }
    }
}

