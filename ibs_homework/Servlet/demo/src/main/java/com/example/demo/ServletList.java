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
import java.util.Map;

@WebServlet(urlPatterns = "/get")
public class ServletList extends HttpServlet {
    Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("application/json;charset=utf-8");
        request.setCharacterEncoding("UTF-8");
        PrintWriter pw = response.getWriter();

        // Парсинг JSON
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

        // Обработка JSON запроса
        JsonObject jobj = gson.fromJson(jb.toString(), JsonObject.class);
        if (jobj.has("id")) {
            int id = jobj.get("id").getAsInt();
            if (id == 0) {
                // Возвращаем весь список
                pw.print(gson.toJson(model.getFrontList()));
            } else if (id > 0) {
                if (model.getFrontList().containsKey(id)) {
                    // Возвращаем конкретного пользователя
                    pw.print(gson.toJson(model.getFrontList().get(id)));
                } else {
                    response.setStatus(HttpServletResponse.SC_NOT_FOUND);
                    pw.print("{\"error\": \"Такого пользователя нет\"}");
                }
            } else {
                response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
                pw.print("{\"error\": \"ID должен быть больше 0\"}");
            }
        } else {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            pw.print("{\"error\": \"ID отсутствует в запросе\"}");
        }
    }
}
