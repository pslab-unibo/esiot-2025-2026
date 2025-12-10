package esiot.backend;

import io.vertx.core.Vertx;

/*
 * 
 * Example of simple back-end exposing an http-based API
 * based on Vert.x reactive framework
 *  
 */
public class RunBackend {
	static final int PORT = 8080;
	public static void main(String[] args) {		
		Vertx vertx = Vertx.vertx();
		DataService service = new DataService(PORT);
		vertx.deployVerticle(service);
	}
}