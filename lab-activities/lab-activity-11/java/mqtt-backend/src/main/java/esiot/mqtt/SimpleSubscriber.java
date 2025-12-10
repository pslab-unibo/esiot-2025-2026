package esiot.mqtt;

import org.eclipse.paho.client.mqttv3.*;

/**
 * 
 * A simple example of Java MQTT client subscribing
 * a topic, using PAHO Eclipse library.
 * 
 * 
 */

public class SimpleSubscriber {

    public static void main(String[] args) throws Exception {
        String broker = "tcp://broker.mqtt-dashboard.com";
        String clientId = "esiot-2025-" + System.currentTimeMillis();
        String topic = "esiot-2025";

        MqttClient client = new MqttClient(broker, clientId);

        // Callback to handle messages and connection events
        client.setCallback(new MqttCallback() {
            @Override
            public void connectionLost(Throwable cause) {
                System.out.println("Connection lost! " + cause.getMessage());
            }

            @Override
            public void messageArrived(String topic, MqttMessage message) {
                System.out.println("Received message on topic " + topic + ": "
                        + new String(message.getPayload()));
            }

            @Override
            public void deliveryComplete(IMqttDeliveryToken token) {
                // Not used for subscribers
            }
        });

        client.connect();
        
        
        /*
         * Subscribing - second param is the QoS (from broker to receiver)
         * 
         * - 0: at most once (minimum)
         * - 1: at least once
         * - 2: exactly once (maximum)
         */
        client.subscribe(topic, 1);

        System.out.println("Subscribed to topic: " + topic);

        // Keep the program running to listen for messages
        Thread.sleep(60000);
        client.disconnect();
        client.close();
    }
}
