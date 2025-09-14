package interf;

public class A extends Person{
    public A(){
        super();
    }
    public A(String name){
        super(name);
    }

    @Override
    public String getName() {
        return this.name;
    }

    public static void main(String[] args) {
        while (true) {
            Person nguoi = new A("haha");
            System.out.println(nguoi.getName());
        }
    }
}