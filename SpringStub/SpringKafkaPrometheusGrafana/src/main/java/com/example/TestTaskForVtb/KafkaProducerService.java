package com.example.TestTaskForVtb;

import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.stereotype.Service;

@Service
public class KafkaProducerService {
    private static final String TOPIC_1 = "msg_topic";
    private static final String TOPIC_2 = "processed_msg_topic";
    private final KafkaTemplate<String, String> kafkaTemplate;

    public KafkaProducerService(KafkaTemplate<String, String> kafkaTemplate) {
        this.kafkaTemplate = kafkaTemplate;
    }

    public void sendMessageToTopic1(String message) {
        kafkaTemplate.send(TOPIC_1, message);
    }

    public void sendMessageToTopic2(String message) {
        kafkaTemplate.send(TOPIC_2, message);
    }

}
