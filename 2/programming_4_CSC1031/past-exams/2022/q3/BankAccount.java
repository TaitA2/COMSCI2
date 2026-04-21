public class BankAccount {
    double balance;

    public BankAccount() {
        this(0);
    }

    public BankAccount(double balance) {
        this.balance = balance;
    }

    public String toString() {
        return "The current balance is: €" + this.balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getBalance() {
        return this.balance;
    }

    public static void main(String[] args) {
        BankAccount ba = new BankAccount();
        BankAccount bb = new BankAccount(1234);

        System.out.println(ba.getBalance());
        System.out.println(bb.getBalance());

        ba.setBalance(23.19);
        bb.setBalance(4321);

        System.out.println(ba.toString());
        System.out.println(bb.toString());
    }

}
