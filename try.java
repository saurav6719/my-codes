import java.io.*;      // For input/output handling
import java.net.*;     // For networking classes like DatagramSocket and InetAddress

class UDPServer {
    public static void main(String args[]) throws Exception {
        // Creating a DatagramSocket to receive data on port 9876
        DatagramSocket serverSocket = new DatagramSocket(9876);

        // Arrays to store data being received and sent
        byte[] receiveData = new byte[1024];
        byte[] sendData = new byte[1024];

        // Server runs indefinitely to listen for incoming data from clients
        while (true) {
            // Create a packet to receive data from the client
            DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);

            // Receive data from the client (this blocks until data is received)
            serverSocket.receive(receivePacket);

            // Convert the received byte data into a string (this is the client's message)
            String sentence = new String(receivePacket.getData());

            // Get the IP address and port of the client (to send the response back)
            InetAddress IPAddress = receivePacket.getAddress();
            int port = receivePacket.getPort();

            // Convert the received sentence to uppercase
            String capitalizedSentence = sentence.toUpperCase();

            // Convert the capitalized sentence back into bytes to send back to the client
            sendData = capitalizedSentence.getBytes();

            // Create a packet to send the response to the client
            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, IPAddress, port);

            // Send the packet (containing the uppercase sentence) to the client
            serverSocket.send(sendPacket);
        }
    }
}
