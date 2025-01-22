package com.example.TestTaskForVtb;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.kafka.annotation.KafkaListener;
import org.springframework.stereotype.Service;

@Service
public class KafkaConsumerService {


    @KafkaListener(topics="msg_topic", groupId = "group_id")
    public void listen(String message) {
        String original_user_id = message;
        System.out.println("Original message consumed: " + original_user_id);
        String modified_user_id = original_user_id + "123";
        System.out.println("Modified message produced: " + modified_user_id);
        kafkaProducerService.sendMessageToTopic2(modified_user_id);
    }
    
    @Autowired
    private KafkaProducerService kafkaProducerService;
}
