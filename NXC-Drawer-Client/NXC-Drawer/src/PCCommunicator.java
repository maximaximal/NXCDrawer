import lejos.nxt.comm.USB;
import lejos.nxt.comm.USBConnection;

public class PCCommunicator {
	private USBConnection usbConn;
	
	public PCCommunicator() {
		
	}
	
	public void startConnector() {
		System.out.println("Connecting using Bluetooth");
		
		System.out.println("Waiting for Bluetooth connections...");
		usbConn = USB.waitForConnection();
	}
}
