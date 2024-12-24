<%@ page language="java" contentType="text/html; charset=UTF-8"
		 pageEncoding="UTF-8"%>
<%@ page import="com.example.demo.logic.Model"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<title>Insert title here</title>
</head>
<body>
<h1>Домашняя страница по работе с пользователями</h1>
Введите ID пользователя (0 - для вывода всего списка пользователей)
<br/>
Доступно: <% 
	Model model = Model.getInstance();
	System.out.println(model.getFrontList().size());
	int size = model.getFrontList().size();
%>
<%= size %>
<form method="get" action="get">
	<label>ID:
		<input type="text" name="id"><br/>
	</label>
	<button type="submit">Поиск</button>
</form>
<a href="addUser.html">Создать нового пользователя</a>
</body>
</html>