import java.net.*;  // For networking

public class UDPClient {
    public static void main(String[] args) {
        try {
            // 1. Create a DatagramSocket for sending data
            DatagramSocket socket = new DatagramSocket();
            
            // 2. Prepare the message to be sent
            byte[] buffer = "Hello, UDP server!".getBytes();  // Convert message to bytes
            
            // 3. Specify the server's address and port
            InetAddress address = InetAddress.getByName("localhost");  // Server is localhost
            
            // 4. Create a DatagramPacket with the message, address, and port
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length, address, 9876);
            
            // 5. Send the packet to the server
            socket.send(packet);  // Send the data
            
            // 6. Close the socket after sending the message
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();  // Handle exceptions
        }
    }
}
