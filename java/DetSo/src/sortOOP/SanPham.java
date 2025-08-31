package sortOOP;

public class SanPham implements Comparable<SanPham>{
    private String name;
    private int cost;

    public SanPham(String name, int cost) {
        this.name = name;
        this.cost = cost;
    }

    public SanPham() {}

    public String getName() {
        return this.name;
    }

    public int getCost() {
        return cost;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCost(int cost) {
        this.cost = cost;
    }

    @Override
    public String toString() {
        return "name: " + this.name + ", cost: " + this.cost;
    }

    @Override
    public int compareTo(SanPham o) {
        if(this.cost < o.cost) return -1;
        else if(this.cost > o.cost) return 1;
        return 0;
    }

    public int compareToCost(SanPham o) {
        if(this.cost < o.cost) return -1;
        else if(this.cost > o.cost) return 1;
        return 0;
    }

    public int compareToIgnoreCase(SanPham o) {
        return this.name.compareToIgnoreCase(o.name);
    }
}
