package ru.appline.demo.logic;

import java.util.Map;
import java.util.TreeMap;
public class CompassModel {
    private static final CompassModel instance = new CompassModel();
    private final TreeMap<String, String> directions = new TreeMap<>();


    private CompassModel() {
    }

    public static CompassModel getInstance() {
        return instance;
    }

    public void setDirections(Map<String, String> newDirections) {
        directions.clear();
        directions.putAll(newDirections);
    }

    public String getDirection(int degree) {
        for (Map.Entry<String, String> entry : directions.entrySet()) {
            String[] range = entry.getValue().split("-");
            int start = Integer.parseInt(range[0]);
            int end = Integer.parseInt(range[1]);
            if ((start <= degree && degree <= end) || (start > end && (degree >= start || degree <= end))) {
                return entry.getKey();
            }
        }
        return "Неизвестное направление";
    }
}
