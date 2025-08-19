import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Event implements ActionListener {
    private JTextField tf_1, tf_2;
    private JLabel l_1;

    public Event(JTextField tf1, JTextField tf2, JLabel l) {
        this.tf_1 = tf1;
        this.tf_2 = tf2;
        this.l_1 = l;
    }

    public void actionPerformed(ActionEvent a) {
        try {
            double num1 = Double.parseDouble(tf_1.getText());
            double num2 = Double.parseDouble(tf_2.getText());
            double result;

            if (a.getActionCommand().equals("+")) {
                result = num1 + num2;
            } else if (a.getActionCommand().equals("-")) {
                result = num1 - num2;
            } else if (a.getActionCommand().equals("*")) {
                result = num1 * num2;
            } else {
                if (num2 == 0) {
                    throw new ArithmeticException("Cannot divide by zero");
                }
                result = num1 / num2;
            }

            l_1.setText(String.valueOf(result));
        } catch (NumberFormatException ex) {
            if (tf_1.getText().isEmpty() || tf_2.getText().isEmpty()) {
                l_1.setText("Error: Fields cannot be empty!");
            } else {
                if (!isNumeric(tf_1.getText())) {
                    l_1.setText("Error: Illegal data on the 1st-field!");
                } else if (!isNumeric(tf_2.getText())) {
                    l_1.setText("Error: Illegal data on the 2nd-field!");
                }
            }
        } catch (ArithmeticException ex) {
            l_1.setText("Error: Cannot divide by zero!");
        }
    }

    private boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch(NumberFormatException e){
            return false;
        }
    }
}

class Calculator extends JFrame {
    private JButton b_add, b_subtract, b_multiply, b_divide;
    private JTextField tf_num1, tf_num2;
    private JLabel l_num1, l_num2, l_result, l_result_out;

    Calculator() {
        setLayout(new GridBagLayout());
        GridBagConstraints c = new GridBagConstraints();

        this.l_num1 = new JLabel("1st: ");
        c.fill = GridBagConstraints.HORIZONTAL;
        c.gridx = 0;
        c.gridy = 0;
        add(this.l_num1, c);

        this.tf_num1 = new JTextField(10);
        c.gridx = 1;
        c.gridy = 0;
        c.gridwidth = 3;
        add(this.tf_num1, c);

        this.l_num2 = new JLabel("2nd: ");
        c.gridx = 0;
        c.gridy = 1;
        add(this.l_num2, c);

        this.tf_num2 = new JTextField(10);
        c.gridx = 1;
        c.gridy = 1;
        c.gridwidth = 3;
        add(this.tf_num2, c);

        this.b_add = new JButton("+");
        c.gridx = 0;
        c.gridy = 2;
        c.gridwidth = 1;
        add(this.b_add, c);

        this.b_subtract = new JButton("-");
        c.gridx = 1;
        c.gridy = 2;
        add(this.b_subtract, c);

        this.b_multiply = new JButton("*");
        c.gridx = 2;
        c.gridy = 2;
        add(this.b_multiply, c);

        this.b_divide = new JButton("/");
        c.gridx = 3;
        c.gridy = 2;
        add(this.b_divide, c);

        this.l_result = new JLabel("Result: ");
        c.gridx = 0;
        c.gridy = 3;
        c.gridwidth = 1;
        add(this.l_result, c);

        this.l_result_out = new JLabel("");
        c.gridx = 1;
        c.gridy = 3;
        c.gridwidth = 3;
        add(this.l_result_out, c);

        Event a = new Event(this.tf_num1, this.tf_num2, this.l_result_out);
        this.b_add.addActionListener(a);
        this.b_subtract.addActionListener(a);
        this.b_multiply.addActionListener(a);
        this.b_divide.addActionListener(a);
    }

    public static void main(String args[]) {
        Calculator ob = new Calculator();
        ob.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        ob.setTitle("Calculator");
        ob.setSize(400, 200);
        ob.setVisible(true);
    }
}
