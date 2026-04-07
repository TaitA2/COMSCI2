// Vehicle interface
interface Vehicle {
    // Default start and stop methods
    void start();
    void stop();
}

// Car class
class Car implements Vehicle {
    // Overridden start method
    @Override
    public void start() {
        System.out.println("Car is starting...");
    }

    // Overridden stop method
    @Override
    public void stop() {
        System.out.println("Car is stopping...");
    }
}

// Bicycle class
class Bicycle implements Vehicle {
    // Overridden start method
    @Override
    public void start() {
        System.out.println("Bicycle is starting...");
    }

    // Overridden stop method
    @Override
    public void stop() {
        System.out.println("Bicycle is stopping...");
    }
}
