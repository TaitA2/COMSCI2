import java.util.List;
import java.util.ArrayList;

class Network{
    ArrayList<CellTower> towers;
    ArrayList<Operator> operators;
    ArrayList<Client> clients;

    public Network(){
        this.towers = new ArrayList<CellTower>();
        this.operators = new ArrayList<Operator>();
        this.clients = new ArrayList<Client>();
    }

    public void moveClient(String phoneNumber, int x, int y){
        Client client = this.findClient(phoneNumber);

        client.x = x;
        client.y = y;

        setNearestTower(client);
    }

    public void changeOperator(String phoneNumber, String operatorName){
        Client client = findClient(phoneNumber);
        Operator operator = findOperator(operatorName);

        client.operator = operator;
        setNearestTower(client);
    }

    public int getTowerClientCount(String towerID){
        int count = 0;
        for (Client client : this.clients){
            if (client.tower != null && client.tower.ID.equals(towerID)) {
                count++;
            }
        }
        return count;
    }

    public int getOperatorSubscriberCount(String operatorName){
        int count = 0;
        for (Client client : this.clients){
            if (client.operator != null && client.operator.name.equals(operatorName)){
                count++;
            }
        }
        return count;
    }

    
    public void addClient(String phoneNumber, String operatorName, int x, int y){
        Operator operator = findOperator(operatorName);
        Client client = new Client(phoneNumber,x,y, operator);
        setNearestTower(client);
        this.clients.add(client);
        
    }

    public void removeClient(String phoneNumber){
        this.clients.removeIf(client -> client.phoneNumber.equals(phoneNumber));
    }

    public void addTower(String ID, int x, int y, int radius){
        this.towers.add(new CellTower(ID, x, y, radius));
    }

    public void registerOperatorTower(String operatorName, String towerID){
        Operator operator = findOperator(operatorName);
        CellTower tower = findTower(towerID);
        operator.towers.add(tower);
        tower.operator = operator;
    }

    public void removeTower(String towerID){
        this.towers.removeIf(tower -> tower.ID.equals(towerID));

        for (Operator operator : this.operators){
            if (operator.towers.removeIf(tower -> tower.ID.equals(towerID))){
                break;
            }
        }
        for (Client client : this.clients){
            if (client.tower != null && client.tower.ID.equals(towerID)){
                setNearestTower(client);
                
            }
        }
    }

    public void getNoSignalCount(){
        for (Operator operator : this.operators){
            int count = 0;
            for (Client client : this.clients){
                if (client.operator != null && client.operator.equals(operator) && !client.hasSignal){
                    count++;
                }
            }
            System.out.println(operator.name + ": " + count + " phones without signal.");
        }
    }

    public void addOperator(String operatorName){
        this.operators.add(new Operator(operatorName));
        
    }

    public Client findClient(String phoneNumber){
        for (Client client : this.clients){
            if (client.phoneNumber.equals(phoneNumber)){
                return client;
            }
        }
        Client client = new Client(phoneNumber);
        this.clients.add(client);
        return client;
    
}

    public CellTower findTower(String towerID){
        for (CellTower tower : this.towers){
            if (tower.ID.equals(towerID)){
                return tower;
            }
        }
        return null;
    }

    public Operator findOperator(String operatorName){
         for (Operator op : this.operators){
            if (op.name.equals(operatorName)){
                return op;
            }
        }
        return null;
    }

    public static class CellTower{
        String ID;
        int x;
        int y;
        int radius;
        Operator operator;
    
        public CellTower(String ID, int x, int y, int radius){
            this.ID = ID;
            this.x = x;
            this.y = y;
            this.radius = radius;
        }

    }
    public static class Operator{
        String name;
        List<Client> clients;
        List<CellTower> towers;
    
        private Operator(String name, List<Client> clients, List<CellTower> towers){
            this.name = name;
            this.clients = clients;
            this.towers = towers;
        }

        public Operator(){
            this("Unknown", new ArrayList<Client>(), new ArrayList<CellTower>());
        }
        public Operator(String name){
            this(name, new ArrayList<Client>(), new ArrayList<CellTower>());
        }
    }
    public static class Client{
        String phoneNumber;
        int x;
        int y;
        Operator operator;
        CellTower tower;
        boolean hasSignal;

    
        public Client(String phoneNumber, int x, int y, Operator operator){
            this.phoneNumber = phoneNumber;
            this.x = x;
            this.y = x;
            this.operator = operator;

 }

        public Client(String phoneNumber){
            this("Unknown", 0,0,null);
        }
    }
        private void setNearestTower(Client client){
            if (client.operator == null) {
                return;
            }
            double nearestDistance = -1;
            CellTower nearestTower = null;

            for (CellTower tower : client.operator.towers){
                double distance = Math.sqrt(Math.pow(tower.x-client.x,2)+Math.pow(tower.y-client.y,2));

                if (distance <= tower.radius && (nearestDistance == -1 || distance <= nearestDistance)){
                    if (distance == nearestDistance){
                        if (getTowerClientCount(nearestTower.ID) < getTowerClientCount(tower.ID)){
                            continue;
                        }
                    }
                    nearestDistance = distance;
                    nearestTower = tower;
                }

            }
            client.tower = nearestTower;
            client.hasSignal = client.tower != null;
        }
    
    
}
