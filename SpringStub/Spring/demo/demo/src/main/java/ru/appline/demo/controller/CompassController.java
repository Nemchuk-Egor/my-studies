package ru.appline.demo.controller;

import org.springframework.web.bind.annotation.*;
import ru.appline.demo.logic.CompassModel;

import java.util.Map;

@RestController
public class CompassController {
    private static final CompassModel compassModel = CompassModel.getInstance();


    @PostMapping(value = "/setDirections", consumes = "application/json")
    public String setDirections(@RequestBody Map<String, String> directions) {
        compassModel.setDirections(directions);
        return "Диапазоны направлений успешно сохранены.";
    }

    @GetMapping(value = "/getDirection", consumes = "application/json", produces = "application/json")
    public Map<String, String> getDirection(@RequestBody Map<String, Integer> request) {
        int degree = request.get("Degree");
        String direction = compassModel.getDirection(degree);
        return Map.of("Side", direction);
    }
}
