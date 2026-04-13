import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

interface Reader {
    Scanner scanner = new Scanner(System.in);
}

abstract class Document implements Reader {
    protected List<String> content = new ArrayList<>();
    protected String type;

    // Templaete method
    public final void generateDocument() {
        createHeader();
        createBody();
        createFooter();
        printDocument();
    }

    private void createHeader() {
        System.out.print("Enter company name: ");
        String companyName = scanner.nextLine();
        if (companyName.isEmpty()) {
            System.out.println("Error: Company name cannot be empty.");
            System.exit(0);
        }

        System.out.print("Enter date (DD/MM/YYYY): ");
        String date = scanner.nextLine();
        if (date.isEmpty())
            throw new IllegalArgumentException("Date cannot be empty.");

        // Add lines to the document
        content.add("Company: " + companyName);
        content.add("Date: " + date);

    }

    abstract void createBody();

    private void createFooter() {

    }

    private void printDocument() {
        System.out.println();
        System.out.println("=== Printing Document ===");
        System.out.println("=== " + this.type + " ===");
        for (String line : content) {
            System.out.println(line);
        }
        System.out.println("=========================");
    }
}

public class DocumentGenerator implements Reader {
    public static void main(String[] args) {
        try {
            System.out.println("Choose document type: (INV) Invoice, (REP) Report, (REC) Receipt");
            String choice = scanner.nextLine();
            Document document;
            switch (choice) {
                case "INV":
                    document = new Invoice();
                    document.type = "INVOICE";
                    break;
                case "REP":
                    document = new Report();
                    document.type = "REPORT";
                    break;
                case "REC":
                    document = new Receipt();
                    document.type = "RECEIPT";
                    break;
                default:
                    System.out.println("Invalid choice. Exiting.");
                    return;
                // throw new IllegalArgumentException("Invalid document choice.");

            }
            document.generateDocument();
        } finally {
        }
    }
}

final class Invoice extends Document {

    @Override
    void createBody() {
        System.out.print("Enter total amount: ");
        String total = scanner.nextLine().strip();
        if (total.isEmpty())
            throw new IllegalArgumentException("Total cannot be empty.");
        try {
            double t = Double.parseDouble(total);
            if (t <= 0) {
                System.out.println("Error: Total amount must be positive.");
                System.exit(0);
            }
        } catch (NumberFormatException e) {
            System.out.println("Error: Total amount must be numeric.");
            System.exit(0);
        }
        content.add("Total Due: €" + total);
        content.add("Prepared by: AutoDoc System");
        content.add("Document Type: INVOICE");
    }

}

final class Report extends Document {

    @Override
    void createBody() {
        System.out.print("Enter report summary: ");
        String summary = scanner.nextLine().strip();
        if (summary.isEmpty())
        System.out.println("Warning: Summary is empty.");
        content.add("Report Summary: " + summary);
        content.add("Reviewed by: Management Department");
    }
}

final class Receipt extends Document {

    @Override
    void createBody() {
        System.out.print("Enter amount paid: ");
        String total = scanner.nextLine().strip();
        if (total.isEmpty())
            throw new IllegalArgumentException("Total cannot be empty.");
        try {
            double t = Double.parseDouble(total);
            if (t <= 0) {
                System.out.println("Error: Total amount must be positive.");
                System.exit(0);
            }
        } catch (NumberFormatException e) {
            System.out.println("Error: Total amount must be numeric.");
            System.exit(0);
        }
        System.out.print("Enter number of items: ");
        String count = scanner.nextLine().strip();
        if (count.isEmpty())
            throw new IllegalArgumentException("count cannot be empty.");
        try {
            double t = Double.parseDouble(count);
            if (t <= 0) {
                System.out.println("Error: Items count must be positive.");
                System.exit(0);
            }
        } catch (NumberFormatException e) {
            System.out.println("Error: count must be numeric.");
            System.exit(0);
        }
        content.add("Total Paid: €" + Double.parseDouble(total));
        content.add("Items Purchased: " + count);
        double avg = Double.parseDouble(total) / Double.parseDouble(count) ;
        content.add("Price per Item: €" + avg);
        content.add("Prepared by: AutoDoc System");
        content.add("Document Type: RECEIPT");
    }

}
