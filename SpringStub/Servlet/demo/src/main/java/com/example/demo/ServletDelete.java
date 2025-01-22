package com.example.demo;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;

import com.example.demo.logic.Model;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(urlPatterns = "/delete")
public class ServletDelete extends HttpServlet {
    Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    @Override
    protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("application/json;charset=utf-8");
        request.setCharacterEncoding("UTF-8");
        PrintWriter pw = response.getWriter();

            // Чтение ID из запроса
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
        if (jobj.has("id")) {
            int id = jobj.get("id").getAsInt();
            if (model.getFrontList().containsKey(id)) {
                model.getFrontList().remove(id); // Удаление пользователя
                response.setStatus(HttpServletResponse.SC_OK);
                pw.print("{\"message\": \"Пользователь с ID " + id + " успешно удален\"}");
            } else {
                response.setStatus(HttpServletResponse.SC_NOT_FOUND);
                pw.print("{\"error\": \"Пользователь с ID " + id + " не найден\"}");
            }
        } else {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);
            pw.print("{\"error\": \"ID отсутствует в запросе\"}");
        }
    }
}
