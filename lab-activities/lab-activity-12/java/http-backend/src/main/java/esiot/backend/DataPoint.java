package esiot.backend;

class DataPoint {
	private double value;
	private long time;
	private String place;
	
	public DataPoint(double value, long time, String place) {
		this.value = value;
		this.time = time;
		this.place = place;
	}
	
	public double getValue() {
		return value;
	}
	
	public long getTime() {
		return time;
	}
	
	public String getPlace() {
		return place;
	}
}
