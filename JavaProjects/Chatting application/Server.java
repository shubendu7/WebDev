import javax.swing.*;//swing comes from java extened package
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;//for implementing action to particular areas
import java.util.*;
import java.text.*;
import java.net.*;
import java.io.*;

public class Server extends JFrame implements ActionListener{//JFrame class comes from swing package
    
    JTextField text;
    JPanel a1;
    static Box vertical = Box.createVerticalBox();
    static DataOutputStream dout;

    //This contains the code of the Window Frame
    Server(){//Constructor 

        setLayout(null);//mentioning swing that we dont want to use the layout and will make ours own

        //Creating a panel obj p1 ( top Coloured one )
        JPanel p1=new JPanel();
        p1.setBackground(new Color(37,67,59));
        p1.setBounds(0,0,450,70);
        p1.setLayout(null);
        add(p1);

        //Setting image in obj i1( Arrow )
        ImageIcon i=new ImageIcon(ClassLoader.getSystemResource("Icons/3.png"));
        Image i_scale= i.getImage().getScaledInstance(25, 25, Image.SCALE_DEFAULT);
        ImageIcon i_use=new ImageIcon(i_scale);
        JLabel Back_button = new JLabel(i_use);
        Back_button.setBounds(5,20,25,25);
        p1.add(Back_button);

        //Adding action to the arrow button to close as clicked
        Back_button.addMouseListener(new MouseAdapter(){//for receiving the mouse events
            public void mouseClicked(MouseEvent ae){
                System.exit(0);
            }
        });

        //pfp
        ImageIcon i1=new ImageIcon(ClassLoader.getSystemResource("Icons/pfp.jpg"));
        Image i_scale1= i1.getImage().getScaledInstance(50, 50, Image.SCALE_DEFAULT);
        ImageIcon i_use1=new ImageIcon(i_scale1);
        JLabel pfp = new JLabel(i_use1);
        pfp.setBounds(40,10,50,50);
        p1.add(pfp);

        //phone
        ImageIcon i2=new ImageIcon(ClassLoader.getSystemResource("Icons/phone.png"));
        Image i_scale2= i2.getImage().getScaledInstance(30,30, Image.SCALE_DEFAULT);
        ImageIcon i_use2=new ImageIcon(i_scale2);
        JLabel phone = new JLabel(i_use2);
        phone.setBounds(300,20,30,30);
        p1.add(phone);

        //video
        ImageIcon i3=new ImageIcon(ClassLoader.getSystemResource("Icons/video.png"));
        Image i_scale3=i3.getImage().getScaledInstance(30,30,Image.SCALE_DEFAULT);
        ImageIcon i_use3=new ImageIcon(i_scale3);
        JLabel video=new JLabel(i_use3);
        video.setBounds(350,20,30,30);
        p1.add(video);

        //3dots
        ImageIcon i4=new ImageIcon(ClassLoader.getSystemResource("Icons/3icon.png"));
        Image i_scale4=i4.getImage().getScaledInstance(15,30,Image.SCALE_DEFAULT);
        ImageIcon i_use4=new ImageIcon(i_scale4);
        JLabel dots=new JLabel(i_use4);
        dots.setBounds(400,20,20,30);
        p1.add(dots);

        //Name Text
        JLabel name =new JLabel("Shubendu Das");
        name.setBounds(110,15,200,18);
        name.setForeground(Color.WHITE);
        name.setFont(new Font("SAN_SERIF",Font.BOLD,18));
        p1.add(name);

        a1 = new JPanel();
        a1.setBounds(5, 75, 440, 570);
        a1.setLayout(new BorderLayout());
        a1.add(vertical, BorderLayout.PAGE_START);
        add(a1);

        text = new JTextField();
        text.setBounds(5, 655, 310, 40);
        text.setFont(new Font("SAN_SERIF", Font.PLAIN, 16));
        add(text);

        JButton send = new JButton("Send");
        send.setBounds(320, 655, 123, 40);
        send.setBackground(new Color(7, 94, 84));
        send.setForeground(Color.WHITE);
        send.addActionListener(this);
        send.setFont(new Font("SAN_SERIF", Font.PLAIN, 16));
        add(send);

        //creating the whole window
        setSize(450,700);
        setLocation(500,100);
        getContentPane().setBackground(Color.WHITE);
        
        setVisible(true);
    }
    public void actionPerformed(ActionEvent ae){
        try {
            String out = text.getText();

            JPanel p2 = formatLabel(out);

            JPanel right = new JPanel(new BorderLayout());
            right.add(p2, BorderLayout.LINE_END);
            vertical.add(right);
            vertical.add(Box.createVerticalStrut(15));

            if (dout != null) {
                dout.writeUTF(out);
            }

            text.setText("");

            repaint();
            invalidate();
            validate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    public static JPanel formatLabel(String out) {
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        JLabel output = new JLabel("<html><p style=\"width: 150px\">" + out + "</p></html>");
        output.setFont(new Font("Tahoma", Font.PLAIN, 16));
        output.setBackground(new Color(37, 211, 102));
        output.setOpaque(true);
        output.setBorder(new EmptyBorder(15, 15, 15, 50));

        panel.add(output);

        Calendar cal = Calendar.getInstance();
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");

        JLabel time = new JLabel();
        time.setText(sdf.format(cal.getTime()));

        panel.add(time);

        return panel;
    }

    public static void main(String[] args){
        Server server = new Server();

        try (ServerSocket skt = new ServerSocket(6001)) {
            while(true) {
                Socket s = skt.accept();
                DataInputStream din = new DataInputStream(s.getInputStream());
                dout = new DataOutputStream(s.getOutputStream());

                while(true) {
                    try {
                        String msg = din.readUTF();
                        JPanel panel = formatLabel(msg);

                        JPanel left = new JPanel(new BorderLayout());
                        left.add(panel, BorderLayout.LINE_START);
                        vertical.add(left);
                        server.validate();
                    } catch (Exception e) {
                        s.close();
                        break;
                    }
                }
            }


        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}