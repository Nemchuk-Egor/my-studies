package ru.appline.demo.controller;

import org.springframework.web.bind.annotation.*;
import ru.appline.demo.logic.Pet;
import ru.appline.demo.logic.PetModel;

import java.util.Map;

import java.util.Objects;
import java.util.concurrent.atomic.AtomicInteger;

@RestController
public class Controller {
    private static final PetModel petModel = PetModel.getInstance();
    private static final AtomicInteger newId = new AtomicInteger(1);

    @PutMapping(value = "/updatePet")
    public String updatePet(@RequestBody Map<String, Object> petData) {
            int id = (int) petData.get("id");
            String name = (String) petData.get("name");
            String type = (String) petData.get("type");
            int age = (int) petData.get("age");

            Pet existingPet = petModel.getId(id);

            if (existingPet == null) {
                return "Питомец с ID " + id + " не найден.";
            }

            existingPet.setName(name);
            existingPet.setType(type);
            existingPet.setAge(age);

            return "Питомец с ID " + id + " успешно обновлен.";
    }


    @DeleteMapping(value = "/deletePet", produces = "text/plain")
    public String deletePet(@RequestBody Map<String, Integer> idMap) {
        int id = idMap.get("id");
        petModel.getAll().remove(id);
        return "Питомец с ID " + id + " удален.";
    }

    @PostMapping(value = "/createPet", consumes = "application/json", produces = "text/plain")
    public String createPet(@RequestBody Pet pet) {
        int id = newId.getAndIncrement();

        petModel.add(pet, id);

        return id == 1 ? "Первый питомец создан" : "Питомец создан";
    }

    @GetMapping(value = "/getAll", produces = "application/json")
    public Map<Integer, Pet> getAll() {
        return petModel.getAll();
    }


    @PostMapping(value = "/getPet", consumes = "application/json", produces = "application/json")
    public Pet getPet(@RequestBody Map<String, Integer> id) {
        return petModel.getId(id.get("id"));
    }
}
