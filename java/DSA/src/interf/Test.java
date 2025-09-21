package interf;

interface A {
    default void f() {
        System.out.println("A");
    }
}

interface B {
    default void f() {
        System.out.println("B");
    }
}

public class Test implements A, B {

    @Override
    public void f() {
        System.out.println("Test");
    }

    public static void main(String[] args) {
        Test t = new Test();
        t.f();
    }
}