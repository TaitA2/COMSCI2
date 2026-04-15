abstract class Vehicle {
    String brand;
    Engine engine;

    public Vehicle(String brand, Engine engine) {
        this.brand = brand;
        this.engine = engine;
    }

    abstract void startEngine();
}

class Engine {
    int horsePower;

    public Engine(int horsePower) {
        this.horsePower = horsePower;
    }
}

class Car extends Vehicle {
    int numDoors;

    public Car(String brand, int numDoors, Engine engine) {
        super(brand, engine);
        this.numDoors = numDoors;
    }

    @Override
    void startEngine() {
        System.out.println("Starting car with " + this.engine.horsePower + " horsepowers");
    }
}

class ElectricCar extends Car {
    int batteryCapacity;

    public ElectricCar(String brand, int numDoors, int batteryCapacity, Engine engine) {
        super(brand, numDoors, engine);
        this.batteryCapacity = batteryCapacity;
    }

    @Override
    void startEngine() {
        System.out.println("Starting electric car silently with " + this.engine.horsePower + " horsepowers");
    }
}

class Bike extends Vehicle {
    boolean hasCarrier;

    public Bike(String brand, boolean hasCarrier, Engine engine) {
        super(brand, engine);
        this.hasCarrier = hasCarrier;
    }

    @Override
    void startEngine() {
        System.out.println("Starting bike with " + this.engine.horsePower + " horsepowers");
    }
}
