import lejos.nxt.Button;
import lejos.nxt.LCD;

public class Main {
	private static PCCommunicator pcComm;
	
	public static void main(String[] args) {
		System.out.println("NXC-Drawer: NXC Client starting up!");
		System.out.println("Starting the PCCommunicator");
		pcComm = new PCCommunicator();
		
		//Start the connection.
		pcComm.startConnector();
	}

}
