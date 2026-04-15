import java.util.*;

class DispatchCenter {
    Queue<Passenger> passengerQueue;
    Queue<Taxi> taxiQueue;

    public DispatchCenter() {
        passengerQueue = new LinkedList<>();
        taxiQueue = new LinkedList<>();
    }

    public void registerTaxi(Taxi taxi) {
        taxi.dispatchCenter = this;
        taxiQueue.add(taxi);
    }

    public void requestRide(Passenger passenger) {
        passengerQueue.add(passenger);
        assignTaxi(passenger);
    }

    public void assignTaxi(Taxi taxi) {
        Passenger passenger = passengerQueue.poll();
        if (passenger != null) {
            taxi.passenger = passenger;
            System.out.println("Dispatch assigned Taxi " + taxi.taxiId + " to passenger " + passenger.name + ".");

        }
    }

    public void assignTaxi(Passenger passenger) {
        Taxi taxi = taxiQueue.poll();
        if (!taxi.available) {
            taxiQueue.add(taxi);
        } else {
            taxi.passenger = passenger;
            System.out.println("Dispatch assigned Taxi " + taxi.taxiId + " to passenger " + passenger.name + ".");
        }
    }

}

class Passenger {
    String name;
    String destination;

    public Passenger(String name) {
        this.name = name;
    }

    public void requestRide(String destination, DispatchCenter dispatchCenter) {
        System.out.println("Passenger " + this.name + " requested a ride to " + destination + ".");
        dispatchCenter.requestRide(this);
        this.destination = destination;
    }
}

class Taxi {
    String taxiId;
    Passenger passenger;
    boolean available;
    DispatchCenter dispatchCenter;

    public Taxi(String taxiId) {
        this.taxiId = taxiId;
    }

    public void setAvailable(boolean available) {
        this.available = available;
        if (available) {
            System.out.println("Taxi " + this.taxiId + " is now available.");
            this.dispatchCenter.assignTaxi(this);
        }
    }

    public void respondToRide(boolean response) {
        if (response) {
            System.out.println("Taxi " + this.taxiId + " accepted the ride to " + this.passenger.destination + ".");
            this.setAvailable(false);
        } else {
            System.out.println("Taxi " + this.taxiId + " rejected the ride to " + this.passenger.destination
                    + ". Searching for another taxi...");
            // this.dispatchCenter.registerTaxi(this);
            this.dispatchCenter.requestRide(this.passenger);
            ;
        }
    }

}
