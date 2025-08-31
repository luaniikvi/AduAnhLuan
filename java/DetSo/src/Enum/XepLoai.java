package Enum;

public enum XepLoai {
    Yeu("XL yếu"),
    TrungBinh("XL trung bình"),
    Kha("XL khá"),
    Gioi("XL giỏi"),
    XuatXac("XL xuất xắc");

    XepLoai(String msg) {
        this.msg = msg;
    }

    public String  getMsg() {
        return this.msg;
    }
    private String msg;
}
