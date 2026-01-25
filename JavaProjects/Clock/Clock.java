
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.text.*;

public class Clock extends JFrame {
    
    JLabel timeLabel, dateLabel;
    JComboBox<String> countrySelector;
    String selectedTimeZone = "Asia/Kolkata"; // Default to India

    Clock() {
        
        // Window Setup
        setTitle("Digital World Clock");
        setLayout(null);
        setSize(500, 350);
        setLocation(500, 200);
        getContentPane().setBackground(new Color(30, 30, 30)); // Dark Theme

        // Header
        JLabel heading = new JLabel("World Clock");
        heading.setBounds(0, 20, 500, 40);
        heading.setHorizontalAlignment(JLabel.CENTER);
        heading.setFont(new Font("Segoe UI", Font.BOLD, 28));
        heading.setForeground(new Color(100, 149, 237)); // Cornflower Blue
        add(heading);

        // Country Selector Dropdown
        String[] countries = {"India", "USA (New York)", "UK (London)", "Japan (Tokyo)"};
        countrySelector = new JComboBox<>(countries);
        countrySelector.setBounds(150, 80, 200, 35);
        countrySelector.setFont(new Font("Segoe UI", Font.PLAIN, 16));
        countrySelector.setBackground(Color.WHITE);
        countrySelector.setFocusable(false);
        add(countrySelector);

        // Time Display
        timeLabel = new JLabel();
        timeLabel.setBounds(0, 140, 500, 70);
        timeLabel.setHorizontalAlignment(JLabel.CENTER);
        timeLabel.setFont(new Font("Consolas", Font.BOLD, 65));
        timeLabel.setForeground(new Color(37, 211, 102)); // Neon Green
        add(timeLabel);

        // Date Display
        dateLabel = new JLabel();
        dateLabel.setBounds(0, 220, 500, 30);
        dateLabel.setHorizontalAlignment(JLabel.CENTER);
        dateLabel.setFont(new Font("Segoe UI", Font.PLAIN, 20));
        dateLabel.setForeground(Color.LIGHT_GRAY);
        add(dateLabel);

        // Action Listener for Dropdown
        countrySelector.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String selected = (String) countrySelector.getSelectedItem();
                switch (selected) {
                    case "India":
                        selectedTimeZone = "Asia/Kolkata";
                        break;
                    case "USA (New York)":
                        selectedTimeZone = "America/New_York";
                        break;
                    case "UK (London)":
                        selectedTimeZone = "Europe/London";
                        break;
                    case "Japan (Tokyo)":
                        selectedTimeZone = "Asia/Tokyo";
                        break;
                }
                updateClock(); // Update immediately when changed
            }
        });

        // Thread to update time every second
        new Thread(() -> {
            while (true) {
                try {
                    updateClock();
                    Thread.sleep(1000);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }).start();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void updateClock() {
        // Get current time for the selected timezone
        Calendar calendar = Calendar.getInstance(TimeZone.getTimeZone(selectedTimeZone));
        
        SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm:ss");
        timeFormat.setTimeZone(TimeZone.getTimeZone(selectedTimeZone));
        
        SimpleDateFormat dateFormat = new SimpleDateFormat("EEEE, dd MMMM yyyy");
        dateFormat.setTimeZone(TimeZone.getTimeZone(selectedTimeZone));

        // Update UI on the Event Dispatch Thread
        SwingUtilities.invokeLater(() -> {
            timeLabel.setText(timeFormat.format(calendar.getTime()));
            dateLabel.setText(dateFormat.format(calendar.getTime()));
        });
    }

    public static void main(String[] args) {
        new Clock();
    }
}