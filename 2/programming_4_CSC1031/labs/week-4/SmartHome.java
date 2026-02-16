import java.util.ArrayList;
import java.util.List;

public class SmartHome {
    private String ownerName;
    private List<Appliance> appliances;

    public SmartHome(String ownerName){
        this.ownerName = ownerName;
        this.appliances = new ArrayList<>();
    }

    public String getOwnerName(){
        return this.ownerName;
    }

    public void addAppliance(Appliance appliance){
        this.appliances.add(appliance);
    }

    public void removeAppliance(Appliance appliance){
        this.appliances.remove(appliance);
    }

    public int getTotalAppliancesInHome(){
        return this.appliances.size();
    }

    public void turnOnAllAppliances(){
        for (Appliance appliance : this.appliances){
            appliance.turnOn();
        }
    }

    public void turnOffAllAppliances(){
        for (Appliance appliance : this.appliances){
            appliance.turnOff();
        }
    }
    
}

class Appliance {
    // attributes
    private final int id;
    private String brand;
    private double powerConsumption;
    private boolean isOn;
    private static int nextId = 1;

    // constructor
    public Appliance(String brand, double powerConsumption){
        this.id = nextId;
        nextId++;
        this.brand = brand;
        this.powerConsumption = powerConsumption;
        this.isOn = false;
    }

    public int getId() {
        return this.id;
    }

    void turnOn(){
        if (this.isOn){
            System.out.println(this.getBrand() + " appliance (ID: "+this.getId()+") is already ON");
        }
        else {
            this.isOn = true;
            System.out.println("Turning on "+this.getBrand()+" appliance (ID: "+this.getId()+")");
        }
    }

    void turnOff(){
        if (this.isOn){
            this.isOn = false;
            System.out.println("Turning off "+this.getBrand()+" appliance (ID: "+this.getId()+")");
        }
        else {
            System.out.println(""+this.getBrand() +" appliance (ID: "+this.getId()+") is already OFF" );
        }
    }

    public boolean isOn(){
        return this.isOn;
    }

    public String getBrand(){
        return this.brand;
    }

    public void setBrand(String brand){
        this.brand = brand;
    }


    public double getPowerConsumption(){
        return this.powerConsumption;
    }

    void setPowerConsumption(double powerConsumption){
        if (powerConsumption <= 0) {
            System.out.println("Invalid value. Must be positive.");
        } else {
            this.powerConsumption = powerConsumption;
        }
    }
}

class WashingMachine extends Appliance {
    private int drumSize;

    public WashingMachine(String brand, double powerConsumption, int drumSize){
        super(brand,powerConsumption);
        this.drumSize = drumSize;
    }

    public void setDrumSize(int drumSize){
        if (drumSize <= 0) {
            System.out.println("Invalid value. Must be positive.");
        } else {
            this.drumSize = drumSize;
        }
    }

    public int getDrumSize(){
        return this.drumSize;
    }

    public void washClothes(){
        if (!this.isOn()){
            System.out.println("Cannot wash clothes. The washing machine is OFF.");
        } else {
            System.out.println("Washing clothes in a " + this.getBrand() + " washing machine");
        }
    }
}

class Refrigerator extends Appliance {
    private double temperature;

    public Refrigerator(String brand, double powerConsumption, double temperature){
        super(brand,powerConsumption);
        this.temperature = temperature;
    }

    public void setTemperature(double temperature){
        this.temperature = temperature;
    }
    public double getTemperature(){
        return this.temperature;
    }

    public void coolItems(){
        if (this.isOn()){
            System.out.println("Cooling items in "+this.getBrand() +" refrigerator at "+this.getTemperature() +"°C (ID: "+this.getId()+")" );
        } else {
            System.out.println("Cannot cool items. The refrigerator is OFF.");
        }
    }
}

class SmartWashingMachine extends WashingMachine{
    private boolean hasWiFi;

    public SmartWashingMachine(String brand, double powerConsumption, int drumSize, boolean hasWiFi){
        super(brand,powerConsumption,drumSize);
        this.hasWiFi = hasWiFi;
    }

    public void connectToWiFi(){
        if (this.isOn()){
            System.out.println("Smart Washing Machine (ID: "+this.getId()+") connected to WiFi.");
        } else {
            System.out.println("Cannot connect to WiFi. The machine is OFF.");
        }
    }

    public boolean hasWiFi(){
        return this.hasWiFi;
    }
    
}
