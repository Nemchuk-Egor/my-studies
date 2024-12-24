package com.example.demo.logic;


/* Описали модель работы нашего сервлета*/
import java.io.Serializable;
import java.util.*;


public class Model implements Serializable  {
	private static final Model instance = new Model();
	private final Map<Integer, User> model;
	
	public static Model getInstance() {
		return instance;
	}
	private Model( ) {
		model = new HashMap<>();
		model.put(1, new User ("Tigran","Mantash",55555));
		model.put(2, new User ("Egor", "Nemchuk", 65000));
		model.put(3, new User ("Masha", "Hrush", 22000));
		model.put(4, new User ("eeee", "Hsadad", 22000));
	}
	
	public void add(User user, int id) {
		model.put(id,user);
	}
	public Map<Integer, User> getFrontList(){
		return model;
	}

}
