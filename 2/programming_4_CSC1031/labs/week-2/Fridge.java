import java.util.ArrayList;
import java.util.List;

public class Fridge {
  private static List<String> foodItems;
  private static int balance;

    public Fridge(int initialBalance) {
      foodItems = new ArrayList<String>();
      balance = initialBalance;
      if (balance < 0) {
          System.out.println("Error");
          balance = 0;
      }
    }

    public void addFood(String item, int cost) {
        if (balance < cost || cost < 0 || item == null) {
            System.out.println("Error");
        } else {
            balance -= cost;
            foodItems.add(item);
            System.out.println("Item "+ item +" has been added to the fridge.");
        }
    }

    public void getFood(String item) {
        if (!foodItems.remove(item)){
            System.out.println("Error");
        } else {
            System.out.println("Item "+ item +" has been removed from the fridge.");
            
        }
    }

    public void checkStatus() {
        System.out.println("Food items:");
        for (String item : foodItems){
            System.out.println((item));
        }
        if (foodItems.isEmpty()){
            System.out.println("(none)");
        }

        System.out.println("Balance: €" + balance);
    }


}
