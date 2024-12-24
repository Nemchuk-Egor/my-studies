package com.example.demo;


import com.example.demo.logic.Model;
import com.example.demo.logic.User;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonObject;
import com.google.gson.Gson;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.concurrent.atomic.AtomicInteger;

@WebServlet(urlPatterns = "/add")
public class ServletAdd extends HttpServlet {

    private final AtomicInteger counter = new AtomicInteger(5);
    Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        StringBuffer jb = new StringBuffer();
        String line;

        try {
            BufferedReader reader = request.getReader();
            while((line = reader.readLine()) != null) {
                jb.append(line);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        JsonObject jobj = gson.fromJson(String.valueOf(jb), JsonObject.class);
        request.setCharacterEncoding("UTF-8");
        String name = jobj.get("name").getAsString();
        String surname = jobj.get("surname").getAsString();
        double salary = jobj.get("salary").getAsDouble();

        User user = new User (name,surname,salary);
        model.add(user,counter.getAndIncrement());

        response.setContentType("application/json;charset=utf-8");
        PrintWriter pw = response.getWriter();
        JsonObject result = new JsonObject();
        result.addProperty("status", "success");
        result.addProperty("message", "Пользователь добавлен: " + name + " " + surname);
        pw.print(result.toString());

    }
//    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
//        response.setContentType("text/html;charset=utf-8");
//        request.setCharacterEncoding("UTF-8");
//        PrintWriter pw = response.getWriter();
//
//        String name = request.getParameter("name");
//        String surname = request.getParameter("surname");
//        double salary = Double.parseDouble(request.getParameter("salary"));
//
//        User user = new User(name,surname,salary);
//        model.add(user,counter.getAndDecrement());
//
//        pw.print("<html>" + "<h3> Пользователь " + name + " " + surname + " с зарплатой " + salary
//                + " Успешно создан</h3> "
//                + "<a href=\"addUser.html\">Создать нового пользователя</a><br/>"
//                + "<a href=\"index.jsp\">Домой</a>");
//
//    }


}
