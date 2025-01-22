package com.example.TestTaskForVtb;

import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class MessageController {
    private final KafkaProducerService producerService;

    public MessageController(KafkaProducerService producerService) {
        this.producerService = producerService;
    }

    @PostMapping("/user_id")
    public void sendMessage(@RequestBody MessageRequest request) {
        String user_id = request.getMessage_id();
        producerService.sendMessageToTopic1(user_id);
    }
}

