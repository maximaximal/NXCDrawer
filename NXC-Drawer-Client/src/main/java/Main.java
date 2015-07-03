import lejos.nxt.Button;
import lejos.nxt.LCD;

/**
 * Created by maximaximal on 03.07.15.
 */
public class Main {
    public static void main(String args[]) {
        LCD.drawString("Hello!", 1, 1);

        Button.waitForAnyPress();
    }
}
