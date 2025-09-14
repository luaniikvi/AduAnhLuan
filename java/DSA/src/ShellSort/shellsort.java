package ShellSort;

import java.util.Arrays;

public class shellsort {

    /**
     * Hàm thực hiện sắp xếp Shell Sort và in các bước
     * @param arr Mảng cần sắp xếp
     */
    public void sort(int[] arr) {
        int n = arr.length;

        System.out.println("Mảng ban đầu: " + Arrays.toString(arr));
        System.out.println("------------------------------------");

        // Bắt đầu với một khoảng cách (gap) lớn, sau đó giảm dần
        for (int gap = n / 2; gap > 0; gap /= 2) {

            System.out.println("Bắt đầu sắp xếp cho các phần tử cách nhau một khoảng gap = " + gap);

            // Thực hiện sắp xếp chèn (insertion sort) cho các phần tử
            // trong các mảng con "ảo" được xác định bởi gap.
            for (int i = gap; i < n; i++) {
                // Lưu lại phần tử hiện tại
                int temp = arr[i];

                // Di chuyển các phần tử phía trước của mảng con (đã được sắp xếp)
                // mà lớn hơn temp lên một vị trí
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }

                // Đặt temp vào đúng vị trí của nó
                arr[j] = temp;
            }

            // In ra mảng sau khi hoàn thành vòng lặp với gap hiện tại
            System.out.println("-> Mảng sau khi sắp xếp với gap = " + gap + ": " + Arrays.toString(arr));
            System.out.println("------------------------------------");
        }

        System.out.println("Mảng cuối cùng đã được sắp xếp: " + Arrays.toString(arr));
    }

    public static void main(String[] args) {
        // Mảng ví dụ giống như trong phần giải thích
        int[] data = {8, 3, 1, 5, 9, 2, 7, 4};

        shellsort sorter = new shellsort();
        sorter.sort(data);
    }
}