import java.util.ArrayList;
import java.util.List;

class Product{
    public String productName;
    public long price;
    public boolean inStock;
    private List<String> tags;

    public Product(){
        this("Unknown", 0, false, new ArrayList<String>());
    }
    public Product(String productName){
        this(productName, 0, false, new ArrayList<String>());
    }
    public Product(String productName, long price){
        this(productName, price, false, new ArrayList<String>());
    }
    public Product(String productName, long price, boolean inStock){
        this(productName, price, inStock, new ArrayList<String>());
    }
    public Product(String productName, long price, List<String> tags){
        this(productName, price, false, tags);
    }
    public Product(String productName, long price, boolean inStock, List<String> tags){ 
        this.productName = productName;
        this.price = price;
        this.inStock = inStock;
        this.tags = new ArrayList<String>();
        if (tags != null){
            this.tags.addAll(tags);
        }
        if (productName == null){
            this.productName = "Unknown";
        }
        if (price < 0){
            this.price = 0;
        }
    }

    public Product(Product product){
        this(product.productName, product.price, product.inStock, product.tags);
    }

    public List<String> getTags(){
        return this.tags;
    }

    public void setTags(List<String> tags){
        this.tags = new ArrayList<String>();
        if (tags != null){
            this.tags.addAll(tags);
        }
    }

    public void addTag(String tag){
        this.tags.add(tag);
    }


    @Override
    public String toString() {
        return "Product{" +
                "productName='" + productName + '\'' +
                ", price=" + price +
                ", inStock=" + inStock +
                ", tags=" + tags +
                '}';
    }    
    public void main(){
        Product product = new Product();
        System.out.println(product);
    }
}
