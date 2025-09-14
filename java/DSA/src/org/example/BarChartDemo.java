package org.example;
import javax.swing .*;
import java.awt .*;

public class BarChartDemo extends JPanel {
    // Dữ liệu mẫu
    private final String[] categories = {"Java", "Python", "C++", "JavaScript", "R"};
    private final int[] values = {80, 65, 50, 70, 40};

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        int width = getWidth();
        int height = getHeight();
        int maxVal = 0;
        for (int v : values) {
            if (v > maxVal) maxVal = v;
        }

        int barWidth = width / (values.length * 2); // độ rộng cột
        int gap; // khoảng cách
        gap = barWidth;

        int x = gap / 2;
        for (int i = 0; i < values.length; i++) {
            int barHeight = (int) ((double) values[i] / maxVal * (height - 50));

            // Màu cột
            g2.setColor(new Color(100, 150, 240));
            g2.fillRect(x, height - barHeight - 30, barWidth, barHeight);

            // Viền cột
            g2.setColor(Color.BLACK);
            g2.drawRect(x, height - barHeight - 30, barWidth, barHeight);

            // Giá trị trên cột
            g2.setColor(Color.RED);
            g2.drawString(String.valueOf(values[i]), x + barWidth / 4, height - barHeight - 35);

            // Nhãn dưới trục
            g2.setColor(Color.BLACK);
            g2.drawString(categories[i], x + barWidth / 4, height - 10);

            x += barWidth + gap;
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Bar Chart Demo");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(500, 400);
            frame.add(new BarChartDemo());
            frame.setLocationRelativeTo(null);
            frame.setVisible(true);
        });
    }
}