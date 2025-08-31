package Enum;

public class testEnum {
    public static void main(String[] args) {
        System.out.println(XepLoai.Yeu.ordinal());
        System.out.println(XepLoai.Kha.ordinal());
        System.out.println(XepLoai.TrungBinh.ordinal());
        System.out.println(XepLoai.Gioi.ordinal());
        System.out.println(XepLoai.XuatXac.ordinal());

        System.out.println(XepLoai.Yeu.getMsg());
    }
}
