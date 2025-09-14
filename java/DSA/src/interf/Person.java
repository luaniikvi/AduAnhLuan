package interf;

interface  Itest1{
    String getName();
}

public abstract class Person implements  Itest1{
    protected String name;
    public Person(){};
    public Person(String name){
        this.name = name;
    }

    public abstract String getName();
}