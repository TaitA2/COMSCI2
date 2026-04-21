public class Student {
    private String name;
    private int mark;

    public Student(String n, int m) {
        name = n;
        mark = m;
    }

    public static int numberPassed(Student[] students) {
        int count = 0;
        for (Student s : students) {
            if (s.mark >= 40) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(numberPassed(
                new Student[] { new Student("adam", 75), new Student("dave", 25), new Student("harry", 85) }));
    }
}
