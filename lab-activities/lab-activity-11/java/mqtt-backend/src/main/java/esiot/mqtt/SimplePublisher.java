package esiot.mqtt;

import org.eclipse.paho.client.mqttv3.*;

public class SimplePublisher {

    public static void main(String[] args) throws Exception {
        String broker = "tcp://broker.mqtt-dashboard.com";
        String clientId = "esiot-2025-" + System.currentTimeMillis();
        String topic = "esiot-2025";

        MqttClient client = new MqttClient(broker, clientId);
        client.connect();

        String payload = "hello from the backend!";
        MqttMessage message = new MqttMessage(payload.getBytes());

        /*
         * Setting the Quality of Service (QoS) - from sender to broker:
         * - 0: at most once (minimum)
         * - 1: at least once
         * - 2: exactly once (maximum)
         */
        message.setQos(1);

        client.publish(topic, message);
        System.out.println("Published message: " + payload);

        client.disconnect();
        client.close();
    }
}
