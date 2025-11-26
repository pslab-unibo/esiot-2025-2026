package esiot.sweeping_system;

/**
 * 
 * An example of Dashboard for the Sweeping Case Study
 * 
 * Partially implemented.
 * 
 */
class DashboardLauncher   {

	static DashboardView view = null;
	static LogView log = null;

	public static void main(String[] args) throws Exception {	
		/*
		if (args.length != 1){
			System.err.println("Args: <serial port>");
			System.exit(1);
		}*/

		view = new DashboardView();
		log = new LogView();
		
		String portName = "/dev/cu.usbmodem112101";
		DashboardController contr = new DashboardController(portName,view,log);
		view.registerController(contr);
		
		view.display();
		log.display();
	}
}