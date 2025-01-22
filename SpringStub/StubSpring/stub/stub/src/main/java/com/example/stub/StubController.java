package com.example.stub;

import org.springframework.web.bind.annotation.*;

import java.util.Random;
import java.util.HashMap;
import java.util.Map;

@RestController
public class StubController {

    @GetMapping("/message")
    public Map<String, String> getMessage() {
        Random random = new Random();
        int firstPart = 100 + random.nextInt(900);
        int secondPart = 100 + random.nextInt(900);
        Map<String, String> response = new HashMap<>();
        response.put("id", firstPart + " " + secondPart);
        return response;
    }


    @PostMapping("/client")
    public Map<String, Object> postClient(@RequestBody Map<String, Object> request) {
        @SuppressWarnings("unchecked")
        Map<String, Object> data = (Map<String, Object>) request.get("data");
        Map<String, Object> response = new HashMap<>();
        response.put("OK", true);
        response.put("orgId", data.get("orgId"));
        return response;
    }
}

