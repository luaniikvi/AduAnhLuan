package sortOOP;

import java.util.ArrayList;

public class test {
    public static void main(String[] args) {
        ArrayList<SanPham> ds = new ArrayList<SanPham>();

        // constructor



        ds.add(new SanPham("beta", 1300));
        ds.add(new SanPham("adu", 1700));

        ds.set(1,new SanPham(ds.get(1).getName(), 9999));


        ds.sort(SanPham::compareToIgnoreCase);
        for (SanPham sp : ds) {
            System.out.println(sp.toString());
        }
        System.out.println("--------------");
        ds.sort(SanPham::compareToCost);
        for (SanPham sp : ds) {
            System.out.println(sp.toString());
        }
    }
}
